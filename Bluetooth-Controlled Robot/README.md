# 🚗 Bluetooth Controlled Car

## 📌 Project Description
This project demonstrates how to build a **Bluetooth-Controlled Car** using **Arduino Uno**, an **L298N Motor Driver**, **DC gear motors**, and an **HC-05 Bluetooth module**.  
The car can be controlled wirelessly using a **smartphone**, helping you learn the basics of **robotics, motor control, power systems, and Arduino programming**.

This project is ideal for **students and beginners** who want hands-on experience with embedded systems and Bluetooth communication. 🤖📱

---

## 🧰 Components Required
Make sure you have **all** the following components before starting:

| Component | Quantity |
|---------|----------|
| DC Gear Motors | 4 |
| 4-Wheel Car Chassis | 1 |
| Arduino Uno | 1 |
| L298N Motor Driver | 1 |
| HC-05 Bluetooth Module | 1 |
| Jumper Wires | As required |
| Double Battery Holder with Switch | 1 | 
| Lithium-ion Cells | 2 |
| USB Cable | 1 |
| Smartphone | 1 |

---

## 🖼️ Project Diagram

<p align="center">
  <img src="./Diagram.jpg" alt="Bluetooth Controlled Car" width="800">
</p> 

---

## 📱 Bluetooth Control App

### 📲 Recommended Android Apps for Control

You can use any of these free Bluetooth controller apps from Google Play Store:

01. Arduino Bluetooth Controller (Most Recommended)
    -  Simple interface with directional buttons
    - Customizable button layout
    - Available for free on Play Store
02. Bluetooth RC Controller
    - Specifically designed for RC vehicles
    - Joystick and button control modes
    - Supports multiple control layouts
03. BT Voice Control for Arduino
    - Voice control option available
    - Button and joystick modes
    - Easy to configure
### 🔽 Download Links
Download Bluetooth RC Controller APK [View](https://roboarmypublicfiles.s3.ap-south-1.amazonaws.com/code/Bluetooth+RC+Controller.apk)

## 📚 Required Arduino Libraries (Very Important ⚠️)

Before uploading the code, you **must install** the following Arduino libraries:

- **Servo Library**
- **Bluetooth Library**

### 🔽 How to Check if Libraries Are Installed
1. Open **Arduino IDE**
2. Go to **File → Examples**
3. Scroll down and check for **“Examples from Custom Libraries”**
4. If the required libraries appear there, they are correctly installed ✅

### 🔽 How to Install Libraries (If Not Installed)
1. Open **Arduino IDE**
2. Press **Ctrl + Shift + I** to open **Library Manager**
3. In the **Search box**, type the library name:
   - `Servo`
   - `Bluetooth`
4. Click **Install**
5. If already installed, check for **Updates** and update if available 🔄
6. If errors appear after installation:
   - Close Arduino IDE ❌
   - Reopen Arduino IDE ✅
   - Try again

---

## 🔋 Power System Connection Guide

Follow these steps carefully when connecting the **Double Battery Holder** to the **DC Jack**:

- The **red wire** is the **positive (+)**
- The **black wire** is the **negative (−)**

### 🔌 Wiring Steps:
1. Connect the **red wire** from the battery holder to **one pin of the switch**
2. Connect the **other pin of the switch** to the **positive terminal of the DC Jack**
3. Connect the **black wire** directly to the **negative terminal of the DC Jack**

⚠️ **Ensure correct polarity** to avoid damaging components.

---

## 📱 Bluetooth Control
- Pair your smartphone with the **HC-05 Bluetooth Module**
- Use a compatible **Bluetooth Controller App**
- Control the car’s movement wirelessly 🚀

---

## 🎯 Learning Outcomes
By completing this project, you will learn:
- Arduino motor control
- Bluetooth communication
- Power management using battery systems
- Basic robotics assembly
- Embedded system programming

---

## 📎 Notes
- Always disconnect power before changing wiring 🔌
- Double-check connections before uploading code
- Use fully charged lithium-ion batteries for best performance 🔋