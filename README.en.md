<div align="right">
  <a href="README.en.md">🇬🇧 English</a> |
  <a href="README.md">🇹🇷 Türkçe</a>
</div>

# 🔥 Nixie Tube Driver with ESP8266

A Wi-Fi enabled, ESP8266-based Nixie tube driver board. Designed for Nixie clock and numerical display projects; it automatically calibrates the time via the internet and drives multiple tubes simultaneously using time-division multiplexing.

<p align="center">
  <img src="V5.1-Community-Edition/5.1_PCB_Image-3.jpg" alt="V5.2 Image" width="380">
  <img src="V5.1-Community-Edition/5.1_PCB_Image-4.jpg" alt="V5.2 Image" width="380">
</p>
<p align="center">
    <img src="V6-Professional-Edition/poster.png" alt="V6-VFD Image" width="380">
  <img src="V6-VFD-NEC-LD8051-Professional-Edition/NEC-LD8051-DEMO-IMAGE.jpg" alt="V6-VFD Image" width="380">
</p>

---

## 📖 Table of Contents

- [About the Project](#-about-the-project)
- [Features](#-features)
- [Hardware Requirements](#-hardware-requirements)
- [Installation and Usage](#-installation-and-usage)
- [Gallery](#-gallery)
- [Version Notes](#-version-notes)
- [Roadmap](#-roadmap)
- [License](#-license)
- [Contributing](#-contributing)

---

## 🧭 About the Project

This project combines the high-voltage switching circuit, microcontroller firmware, and PCB design required to drive Nixie tubes (designed for IN-16, but compatible with other tubes like IN-12/IN-14/IN-18 / the Pro version also features a design suitable for NEC-8051 / IV-3 VFD tubes). The board connects to the internet via the ESP8266 to automatically synchronize its time with NTP, eliminating the need for an external RTC battery replacement or manual time adjustment.

### Open-Core - Community Edition
As a believer in the open-source philosophy, I am sharing the schematics, source codes, and CAM files of this Nixie clock's basic version as the **v5.1 Community Edition**, so anyone can build it at home. If you want to program your own ESP8266, tinker with shift registers, and build high-voltage circuits like a 170V DC-DC boost converter yourself, everything you need is right here in this repository!

### Professional Edition
However, if you'd rather not deal with soldering, sourcing components, or handling high voltages; and would prefer a fully equipped, plug-and-play product featuring a much more advanced web interface, extra animation modes, and a flawless design, you can contact me via the channels below to purchase one.

*   **Website:** teknosunar.com / oztetik.com.tr
*   **Email:** info@teknosunar.com / ege@oztetik.com.tr
*   **GitHub:** KetumKeton
*   **LinkedIn:** ege-oztetik

## ✨ Features

**Hardware**
- 🔥 Optimized driver circuit for IN-16 Nixie tubes; also compatible with other Nixie types
- 🔄 Simultaneous driving of 4 tubes via time-division multiplexing (16-transistor switching)
- ⚡ 150V DC high voltage generation with onboard MC34063 DC-DC converter (no external transformer required — V5 and later)
- 🔋 Switching design optimized for low power consumption
- 🎨 Aesthetics-focused, tight-layout PCB design (80×100 mm, V5)
- 🖥️ Optional OLED display connection (alternative/auxiliary output)
- 🟦 Blue background LED support for Nixie tubes

**Software / Firmware**
- 📶 Automatic Wi-Fi connection via ESP8266
- 🕒 Real-time clock calibration via internet with NTP
- 💡 Adjustable brightness and smooth fade effects
- 🔌 Serial communication support (for testing and configuration)
- 🧩 Digit driving via CD4094 shift registers

## 🛠 Hardware Requirements

| Component | Note |
|---|---|
| Microcontroller | ESP8266 (ESP-12) |
| Nixie Tubes | Designed for IN-16 (also compatible with IN-12, IN-14, IN-18) |
| High Voltage Source | 150V DC (Generated onboard with MC34063 in V5) |
| Driver IC | CD4094 (shift register), ULN2003 (in small SMD version) |

## 🚀 Installation and Usage

1. **Clone the repository**
   ```sh
   git clone https://github.com/Ketonkeko/Nixie-Tube-Driver-with-ESP8266.git
   cd Nixie-Tube-Driver-with-ESP8266
   ```

2. **Get the Gerber files for manufacturing**
   - Extract the zip file in the relevant version folder; pull out the drill and copper Gerber files and send them to your PCB manufacturer.

3. **Upload the firmware**
   - Open the Arduino/ESP8266 project located in the relevant version folder.
   - Enter your Wi-Fi network credentials into the corresponding variables in the code.
   - Connect the board with a USB-to-serial converter and upload the firmware to the ESP8266.

4. **First run**
   - When powered on, the board will connect to the defined Wi-Fi network and fetch the time from the NTP server.
   - Ensure the circuit is unpowered before connecting the high-voltage supply (150V) and the tube sockets.

> ⚠️ **Safety Warning:** This board operates with dangerously high voltages like 150V DC. Only power the board if you have experience working with high-voltage circuits.

## 🖼 Gallery

<table>
  <tr>
    <td align="center">
      <img src="V5.1-Community-Edition/nixie-clock-3D-v5-2.png" alt="V5.2 3D View" width="380"><br>
      <sub>V5.2 — 3D model</sub>
    </td>
    <td align="center">
      <img src="V5.1-Community-Edition/nixie-clock-pcb-v5-2.png" alt="V5.2 PCB View" width="380"><br>
      <sub>V5.2 — PCB layout</sub>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="V5.1-Community-Edition/nixie-clock-schematic-v5-2.png" alt="V5.2 Schematic" width="380"><br>
      <sub>V5.2 — Schematic</sub>
    </td>
    <td align="center">
      <img src="V5.1-Community-Edition/v4.png" alt="V4 Application Image" width="380"><br>
      <sub>V4 — Example application</sub>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="V6-Professional-Edition/v6.png" alt="V6 Application Image" width="380"><br>
      <sub>V6 — Example application</sub>
    </td>
    <td align="center">
      <img src="V6-VFD-NEC-LD8051-Professional-Edition/V6.1.0-VFD-UI-Image.png" alt="V6 VFD Test" width="380"><br>
      <sub>V6 — NEC LD8051 VFD test</sub>
    </td>
  </tr>
    <tr>
    <td align="center">
      <img src="V6-VFD-NEC-LD8051-Professional-Edition/V6.1.0-VFD-PCB-Image.png" alt="V6 VFD Prototype" width="380"><br>
      <sub>V6 — Example application</sub>
    </td>
    <td align="center">
      <img src="V6-VFD-NEC-LD8051-Professional-Edition/V6.1.0-VFD-3D-Image.png" alt="V6 VFD Prototype" width="380"><br>
      <sub>V6 — NEC LD8051 VFD test</sub>
    </td>
  </tr>
    <tr>
    <td align="center">
      <img src="V6-VFD-NEC-LD8051/NEC-LD8051-TEST-IMAGE.jpg" alt="V6 VFD Prototype" width="380"><br>
      <sub>V6 — Example application</sub>
    </td>
    <td align="center">
      <img src="V6-VFD-NEC-LD8051/NEC-LD8051-DEMO-IMAGE2.jpg" alt="V6 VFD Prototype" width="380"><br>
      <sub>V6 — NEC LD8051 VFD test</sub>
    </td>
  </tr>
</table>

## 🗂 Version Notes

### V6 — VFD Support
- Added experimental testing support for NEC LD8051 VFD (vacuum fluorescent display).

### V5 Notes
- Integrated onboard MC34063 DC-DC converter instead of using an external transformer.
- Fixed the bug in the anode driver.
- Added extra capacitors for power filtering.
- Added internal diodes to the power inputs.
- PCB was redesigned with 80×100 mm dimensions.
- Changed CD4094 to an SO16 package.
- Thickened some traces.
- Updated pin header dimensions.
- Changed 0402 package capacitors to 0603.
- Moved the OLED display to a more visible location.
- Changed Nixie blue LED resistors to 1206 packages.
- Updated Nixie tube socket size.

### V4 Notes
- Changed the microcontroller from AT89C4051 to ESP8266.
- Removed RS485 communication and added Wi-Fi.
- Achieved simultaneous driving of 4 tubes with 16-transistor time-division multiplexing.
- Added bitmap support for better PCB design.
- Changed packaging from DIP to SMD for manufacturing and size optimization.
- Routed HV and 12V inputs to an external power supply (transformer).
- Added OLED display pins as an alternative output option.

## 🗺 Roadmap

- [x] Write the clock program with ESP8266 E-12
- [x] Smaller PCB design with SMD and ULN2003 IC
- [x] 3D case design for the clock
- [x] PCB and program tests
- [x] Bill of materials (BOM) and cost calculation
- [ ] Alarm and time zone configuration via local server on ESP8266

## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! You can send a **pull request** or open an **issue**.