#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// ====== WiFi ======
const char* ssid     = "WIFI_ADINIZ";
const char* password = "WIFI_SIFRENIZ";

// ====== NTP (Türkiye UTC+3, yaz-kış sabit) ======
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3*3600, 60*1000);

// ====== 4094 Sinyalleri ======
#define PIN_DATA   13   // SER
#define PIN_CLK    12   // SRCLK
#define PIN_LATCH  14   // RCLK (STROBE)
#define PIN_OE     9   // /OE (LOW=enable). Blanking için kullanacağız.

const bool INVERT_KATOT = false;  // katot sürücü lojik ters ise true yap
const bool INVERT_ANOT  = false;  // anot sürücü lojik ters ise true yap
const bool INVERT_DOT   = false;  // noktalar ters lojikse true

// ====== Multiplex zamanlama ======
const uint16_t ON_US_PER_TUBE = 2000;  // her tüpe ~2ms
// 4 tüp -> ~8ms frame -> ~125Hz per-tube refresh (flicker yok)

// ====== Bit Dizilimi (LSB->MSB sırayla kaydırılacak 16 bit frame) ======
// Bit 0..8  : digit 1..9 katotları
// Bit 9     : digit 0 katodu
// Bit 10    : sol nokta
// Bit 11    : sağ nokta
// Bit 12..15: Anot seçimi (4 tüp)
enum {
  BIT_D1 = 0, BIT_D2, BIT_D3, BIT_D4, BIT_D5, BIT_D6, BIT_D7, BIT_D8, BIT_D9,
  BIT_D0,
  BIT_DOT_L,
  BIT_DOT_R,
  BIT_AN0, BIT_AN1, BIT_AN2, BIT_AN3
};

// 0..9 için katot bit maskesi (senin söylediğin mapping'e göre)
uint16_t katotMaskForDigit(uint8_t d) {
  switch (d) {
    case 0: return (1u << BIT_D0);
    case 1: return (1u << BIT_D1);
    case 2: return (1u << BIT_D2);
    case 3: return (1u << BIT_D3);
    case 4: return (1u << BIT_D4);
    case 5: return (1u << BIT_D5);
    case 6: return (1u << BIT_D6);
    case 7: return (1u << BIT_D7);
    case 8: return (1u << BIT_D8);
    case 9: return (1u << BIT_D9);
    default: return 0;
  }
}

// Lojik invert yardımcıları
inline uint16_t maybeInvertKatot(uint16_t m) { return INVERT_KATOT ? ~m : m; }
inline uint16_t maybeInvertAnot(uint16_t m)  { return INVERT_ANOT  ? ~m : m; }
inline uint16_t maybeInvertDot(uint16_t m)   { return INVERT_DOT   ? ~m : m; }

// 16-bit değeri 4094’lere (seri) kaydır: LSB-first
void shift16_LSBfirst(uint16_t value) {
  digitalWrite(PIN_LATCH, LOW);
  for (uint8_t i = 0; i < 16; i++) {
    digitalWrite(PIN_CLK, LOW);
    digitalWrite(PIN_DATA, (value >> i) & 0x1);
    digitalWrite(PIN_CLK, HIGH);
  }
  digitalWrite(PIN_LATCH, HIGH);
}

// Blanking kontrol (/OE: LOW=enable, HIGH=tri-state)
inline void outputsEnable(bool en) {
  digitalWrite(PIN_OE, en ? LOW : HIGH);
}

// Tek bir tüp için frame oluştur (katot + anot + noktalar)
uint16_t buildFrame(uint8_t digit, uint8_t tubeIndex, bool dotL, bool dotR) {
  uint16_t frame = 0;

  // Katot
  uint16_t k = katotMaskForDigit(digit);
  if (INVERT_KATOT) {
    // sadece katot bitlerini tersle
    uint16_t katotBits = 0;
    // katot bit alanı: 0..9
    for (uint8_t b = 0; b <= BIT_D0; b++) katotBits |= (1u << b);
    k = (~k) & katotBits;
  }
  frame |= k;

  // Noktalar (bit10, bit11)
  if (dotL ^ INVERT_DOT) frame |= (1u << BIT_DOT_L);
  if (dotR ^ INVERT_DOT) frame |= (1u << BIT_DOT_R);

  // Anot seçimi (bit12..15)
  uint16_t a = 0;
  switch (tubeIndex) {
    case 0: a = (1u << BIT_AN0); break;
    case 1: a = (1u << BIT_AN1); break;
    case 2: a = (1u << BIT_AN2); break;
    case 3: a = (1u << BIT_AN3); break;
  }
  if (INVERT_ANOT) {
    // sadece anot bitlerini tersle
    uint16_t anotBits = (1u << BIT_AN0) | (1u << BIT_AN1) | (1u << BIT_AN2) | (1u << BIT_AN3);
    a = (~a) & anotBits;
  }
  frame |= a;

  return frame;
}

// ========= Setup =========
void setup() {
  Serial.begin(115200);

  pinMode(PIN_DATA,  OUTPUT);
  pinMode(PIN_CLK,   OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
//  pinMode(PIN_OE,    OUTPUT);
  outputsEnable(false); // Başta kapalı (tri-state)

  // WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - t0 < 15000) {
    delay(300);
    Serial.print(".");
  }
  Serial.println(WiFi.status() == WL_CONNECTED ? "\nWiFi OK" : "\nWiFi FAIL");

  timeClient.begin();
  // TR sabit UTC+3, ek işlem yok
}

// HH:MM’yi 4 digit diziye ayır
void getTimeDigits(int d[4], bool &dotBlink) {
  timeClient.update();

  int h = timeClient.getHours();
  int m = timeClient.getMinutes();
  int s = timeClient.getSeconds();

  d[0] = (h / 10) % 10;
  d[1] =  h % 10;
  d[2] = (m / 10) % 10;
  d[3] =  m % 10;

  dotBlink = (s % 2 == 0); // 1 Hz yanıp sönme
}

// ========= Loop =========
void loop() {
  int digits[4];
  bool dots;
  getTimeDigits(digits, dots);

  // 4 tüpü sırayla göster
  for (uint8_t t = 0; t < 4; t++) {
    // tüpler arası ghosting’i önle: önce çıkışları kapat
    outputsEnable(false);

    // noktalar: ortadaki iki tüp arasına gelecekse sağ/sol kullanımı
    bool dotL = (t == 1) ? dots : false; // 2. tüp sağında nokta (HH:MM görünümü için)
    bool dotR = (t == 2) ? dots : false; // 3. tüp solunda nokta

    uint16_t frame = buildFrame(digits[t], t, dotL, dotR);

    // yeni frame'i kaydır ve latch'le
    shift16_LSBfirst(frame);

    // aktif et ve belirlenen süre açık tut
    outputsEnable(true);
    delayMicroseconds(ON_US_PER_TUBE);
  }
}
