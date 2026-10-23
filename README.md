# Magic Box: Multi-Sensor Finite-State Puzzle & Lock Box


[![Firmware CI](https://github.com/ParthDalakoti/magic-box-interactive-controller/actions/workflows/firmware-ci.yml/badge.svg)](https://github.com/ParthDalakoti/magic-box-interactive-controller/actions) [![Wokwi Simulation](https://img.shields.io/badge/Simulation-Wokwi_Virtual_Lab-00B4D8.svg?style=for-the-badge&logo=espressif)](https://wokwi.com)

[![Microcontroller](https://img.shields.io/badge/MCU-Arduino_Uno-E7352C.svg?style=for-the-badge)](https://www.espressif.com/)
[![Protocols](https://img.shields.io/badge/Protocols-Finite_State_Machine,_Servo_Lock,_Sensors-blue.svg?style=for-the-badge)]()
[![Status](https://img.shields.io/badge/Status-Tested_%26_Verified-success.svg?style=for-the-badge)]()
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

> **Embedded Hardware & Firmware Project | Graphic Era Hill University (B.Tech ECE 2023–2027)**  
> **Author:** Parth Dalakoti (*President, Robotics & Automation Club, GEHU*)  
> **Contact:** `parthdalakoti482@gmail.com` | [LinkedIn](https://linkedin.com/in/parthdalakoti)

---

## ⚡ Executive Engineering Summary
Interactive Puzzle & Security Lock Box using Multi-Sensor Finite State Machine (FSM) Logic. This project is an independent engineering system designed, built, and tested by **Parth Dalakoti** during his B.Tech in Electronics & Communication Engineering.

---

## 🛠️ Hardware Stack & Specifications
* **Target Microcontroller:** `Arduino Uno`
* **Primary Protocols & Interfaces:** `Finite State Machine, Servo Lock, Sensors`
* **Firmware Location:** [`firmware/`](firmware/)
* **Technical Documentation & Reports:** [`docs/`](docs/)
* **Hardware Wiring & Schematics:** [`hardware/`](hardware/)

---

## 🔌 Hardware Connections & Architecture

```mermaid
graph LR
    Sensors[Sensors / Input Interface] -->|Finite State Machine, Servo Lock, Sensors| MCU[Arduino Uno]
    MCU -->|PWM / Driver Control| Actuator[Actuator / Load Output]
    MCU -->|Status / Telemetry| Display[Status Output / Feedback]
```

---

## 🚀 How to Build & Flash
1. Open the source code in [`firmware/`](firmware/) using **Arduino IDE** or **VS Code PlatformIO**.
2. Select target board: `Arduino Uno`.
3. Configure serial baud rate (115200 or 9600 baud as defined in firmware).
4. Connect board and flash.

---

## 👨‍💻 Engineering Author
**Parth Dalakoti**  
*President, Robotics & Automation Club*  
*B.Tech in Electronics & Communication Engineering (2023–2027)*  
*Graphic Era Hill University (GEHU), Bhimtal Campus*  
*Contact:* `parthdalakoti482@gmail.com` • [GitHub Profile](https://github.com/ParthDalakoti)

---

## 📸 Hardware Bench Test Photos

![Hardware Prototype Setup](media/hardware_demo_1.jpg)

