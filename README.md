# Nixie-Tube-Driver-with-RTC-RS485
Nixie Driver for Nixie Clock and Display Project with Wifi.
![Ekran görüntüsü 2025-02-23 164856](https://github.com/user-attachments/assets/7326dce2-711e-4d75-aef4-e887b155dccb)
![Ekran görüntüsü 2025-02-23 164843](https://github.com/user-attachments/assets/9a8f1a49-18ba-4dc8-bff9-4d0e7dfcc2dd)
![Ekran görüntüsü 2025-03-02 134058](https://github.com/user-attachments/assets/3b2ddd5a-3833-4a28-b4ae-37ccf3e6f8c9)

# 🔥 Nixie Driver for Nixie Clock & Display

This project is a **Nixie tube driver** designed for **Nixie clock and display applications**, featuring **RTC (Real-Time Clock) support** and **RS485 communication**. The driver controls Nixie tubes for displaying time or numerical data while maintaining accurate timekeeping and supporting serial communication.

## 📌 Features

- 🕰 ~~**RTC Integration** – Keeps accurate time even when powered off.  ~~ (V4)
- ~~🔗 **RS485 Communication** – Enables long-distance and reliable data transmission. ~~ (V4)
- 🔥 **Nixie Tube Control** – Supports various Nixie tube displays.  
- 🔄 **Adjustable Brightness & Effects** – Smooth transitions and dimming support.  
- 🔋 **Low Power Consumption** – Optimized for efficient operation.  
-  **Beautiful Design for PCB** – PCB has designed for better . (V4)
- **Wifi Connection and Real Time Clock Configration** ESP8266 Nixie Watch has internal wifi module, and it connect automaticaly to internet and make calibrating clock. (V4)

## 🛠 Requirements

Ensure you have the following components and dependencies:

- **Microcontroller** (e.g., STM32, ATmega, ESP32, etc.)  (ESP8266)
- **Nixie Tubes** (e.g., IN-12, IN-14, IN-18, etc.) (This PCB designed for IN-16) 
- **Nixie HV Power Supply** (150V DC)  
- ~~**RTC Module** (DS1307) ~~ (V4 esp8266 has internal RTC) 
- ~~**RS485 Transceiver** (MAX485) ~~(V4 has wifi)

## 🔧 Installation & Setup

1. **Clone the repository**  
   ```sh
   git clone https://github.com/Ketonkeko/Nixie-Tube-Driver-with-RTC-RS485.git
   cd Nixie-Tube-Driver-with-RTC-RS485
   ```

2. **Get Gerber Files for Manufacturing**  
   - open the zip file and get drill and copper gerber files


## 📝 To-Do

- [X] Make Clock Program with ~~AT89C4051~~ ESP8266 E-12 (V4)
- [/] Make a smaller pcb with smd and ULN2003 IC
- [X] Make 3D Case for watch
- [ ] Make PCB and program tests
- [ ] make part list and price calculation
- [ ] make a local server on esp8266 and set alarm and timezone

V4 Notes
Microcontroller chanced (AT89C4051 to ESP8266)
Removed RS485 cominication and added wifi.
Nixie Driver has drive 4 nixie tubes same time with 16 transistor. (Multiplexing)
Added Bitmap for better design pcb.
changed package dip to smd for manifacturing and size improvements.
HV and 12V input connected to external power supply (transformer)

## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Feel free to submit **pull requests** or open **issues**.
