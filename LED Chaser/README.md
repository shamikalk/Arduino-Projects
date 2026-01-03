# 🔦 Dynamic LED Chaser using Arduino UNO

## 📌 Project Overview

In many electronics projects, creating dynamic lighting effects can require complex circuits and advanced programming.  
The **Dynamic LED Chaser** project simplifies this process by using an **Arduino UNO** to control multiple LEDs in a sequential (chasing) pattern.

This project is perfect for beginners who want to learn:
- Arduino basics  
- LED animation  
- Breadboard circuit design  
- Timing and sequencing logic  

This is one of the **12 amazing projects** that can be built using this electronics kit.

---

## 🧰 Components Required

- Arduino UNO Board x 1
- LEDs x 12
- 220 Ohm Resistors x 12
- Breadboard x 1
- Jumper Wires  
- Double Battery Holder with DC Jack & Switch x 1
- 3.7 V Rechargeable Batteries x 2

---

## 🔌 Circuit Description

- Each LED is connected to an Arduino digital pin through a 220Ω resistor.
- The negative (cathode) side of each LED is connected to GND.
- The Arduino turns the LEDs ON and OFF one by one, creating a chasing effect.
- Power can be supplied via USB or using the battery holder with switch.

<p align="center">
  <img src="./Diagram.jpg" alt="Smart Waste Segregator" width="400">
</p>

---

## 💻 Software & Code

- Platform: Arduino  
- Board: Arduino UNO  

The program uses:
- `pinMode()` to set LED pins as outputs  
- `digitalWrite()` to control LEDs  
- `delay()` to control the chasing speed  

Upload the provided `.ino` file to the Arduino using **Arduino IDE**.

---

## 🚀 How to Run

1. Build the circuit on a breadboard
2. Connect the Arduino to your PC
3. Open Arduino IDE
4. Select **Board: Arduino UNO**
5. Select the correct **COM Port**
6. Upload the code
7. Power the circuit and observe the LED chaser effect

---

## 📷 Applications

- Learning Arduino basics  
- LED animation projects  
- Educational electronics kits  
- Decorative lighting  

---

## 🛠️ Future Enhancements

- Speed control using a potentiometer  
- Different LED patterns  
- RGB LED support  
- Button-controlled modes  
