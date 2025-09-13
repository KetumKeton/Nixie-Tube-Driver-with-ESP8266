# Nixie-Tube-Driver-with-ESP8266
Nixie Driver for Nixie Clock and Display Project with Wifi.

V5 Photos

<img width="783" height="820" alt="Ekran görüntüsü 2025-09-13 172655" src="https://github.com/user-attachments/assets/ed151df6-7bdc-4514-8768-c026d15e282c" />
<img width="968" height="826" alt="Ekran görüntüsü 2025-09-13 172811" src="https://github.com/user-attachments/assets/da04cf70-9ded-4959-a171-0b254787be2e" />
<img width="1493" height="819" alt="Ekran görüntüsü 2025-09-13 172850" src="https://github.com/user-attachments/assets/1a553609-4833-4b5c-81fb-1796cebf24e3" />
<img width="683" height="774" alt="Ekran görüntüsü 2025-09-13 165822" src="https://github.com/user-attachments/assets/a84a09ac-cf14-42a8-9b22-8baa10a82bc5" />

V4 Photos
<img width="1209" height="835" alt="Ekran görüntüsü 2025-08-31 001054" src="https://github.com/user-attachments/assets/8d849aa2-8e42-4691-bbe2-91f55f53f14b" />




# 🔥 Nixie Driver for Nixie Clock & Display

This project is a **Nixie tube driver** designed for **Nixie clock and display applications**, featuring **RTC (Real-Time Clock) support** and **RS485 communication**. The driver controls Nixie tubes for displaying time or numerical data while maintaining accurate timekeeping and supporting serial communication.

## 📌 Features

- 🕰 ~~**RTC Integration** – Keeps accurate time even when powered off.~~ (V4)
- ~~🔗 **RS485 Communication** – Enables long-distance and reliable data transmission.~~ (V4)
- 🔥 **Nixie Tube Control** – Supports various Nixie tube displays.  
- 🔄 **Adjustable Brightness & Effects** – Smooth transitions and dimming support.  
- 🔋 **Low Power Consumption** – Optimized for efficient operation.  
-  **Beautiful Design for PCB** – PCB has been designed with improved aesthetics (V4)
- **Wifi Connection and Real Time Clock Configuration** The ESP8266 Nixie driver includes an internal Wi-Fi module. It automatically connects to the internet to calibrate the clock. (V4)

## 🛠 Requirements

Ensure you have the following components and dependencies:

- **Microcontroller** (e.g., STM32, ATmega, ESP32, etc.)  (ESP8266)
- **Nixie Tubes** (e.g., IN-12, IN-14, IN-18, etc.) (This PCB designed for IN-16) 
- **Nixie HV Power Supply** (150V DC)  
- ~~**RTC Module** (DS1307)~~ (V4 ESP8266 has an internal RTC) 
- ~~**RS485 Transceiver** (MAX485)~~(V4 has wifi)

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
- [X] Make a smaller pcb with smd and ULN2003 IC
- [X] Make 3D Case for watch
- [ ] Make PCB and program tests
- [X] make part list and price calculation
- [ ] make a local server on esp8266 and set alarm and timezone

**V5 Notes**

- The anode driver error was corrected.
- Additional capacitors were added to the power supplies for filtering.
- Internal diodes were added to the power inputs.
- The PCB was redrawn to 80x100mm.
- The CD4094 was redrawn to SO16.
- Some traces were thickened.
- The pin header sizes were adjusted.
- The capacitors in the 402 package were converted to 603.
- The OLED display was placed in a more visible location.
- The resistors for the Nixie Blue LEDs were converted to 1206 packages.
- The socket size for the Nixie tubes was adjusted.

**V4 Notes**

- Microcontroller changed (from AT89C4051 to ESP8266)
- Removed RS485 communication and added wi-fi.
- Nixie Driver has drive 4 nixie tubes same time with 16 transistor. (Multiplexing)
- Added Bitmap for better design pcb.
- Changed package from DIP to SMD for manufacturing and size improvements.
- HV and 12V input connected to external power supply (transformer)
- Added OLED display pins as an alternative output option

## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Feel free to submit **pull requests** or open **issues**.
