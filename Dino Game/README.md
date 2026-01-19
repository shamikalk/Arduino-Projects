# Arduino UNO Dino Game 🌵🦖

This project demonstrates how to create a simple obstacle avoidance game inspired by the classic Chrome Dino game, running on an **Arduino UNO** with a **16x2 character LCD display** using an **I2C interface**, powered by a **rechargeable battery** system.

Using I2C reduces wiring complexity and makes the project clean and efficient 🔧✨

---

## 🧰 Components Required

| Component | Quantity |
|---------|----------|
| Arduino UNO Board | 1 |
| 16x2 LCD Display | 1 | 
| I2C Module | 1 | 
| Breadboard | 1 | 
| Jumper Wires | As required | 
| Double Battery Holder with DC Jack & Switch | 1 | 
| 3.7V Rechargeable Batteries | 2 | 

---

## 🖼️ Project Diagram

<p align="center">
  <img src="./Diagram.jpg" alt="Dino Game" width="800">
</p> 

----

## 📝 Project Description

This project allows the Arduino UNO to display text on a **16x2 LCD** using the **I2C communication protocol**.  
The I2C module uses only **two data lines (SDA & SCL)**, reducing the number of jumper wires required.

The system is powered using **two 3.7V rechargeable batteries**, making it portable and suitable for standalone Arduino projects 🔋🚀

---

## 📚 Required Library Installation (Important ⚠️)

The **LiquidCrystal I2C** library **must be installed** in the Arduino IDE before uploading the code.

---

### ✅ Check If the Library Is Installed

1. Open **Arduino IDE**
2. Go to **File → Examples**
3. Scroll down and look for  
   **Examples from Custom Libraries**
4. If **LiquidCrystal I2C** appears there, the library is correctly installed ✔️

---

### 📥 How to Install / Update the Library

1. Open **Arduino IDE**
2. Press **Ctrl + Shift + I** to open **Library Manager**
3. In the **Search box**, type:

```
LiquidCrystal I2C
```
4. Click **Install**
5. If already installed, check for **updates** and update if available 🔄
6. If errors appear after installation:
- Close Arduino IDE ❌
- Reopen Arduino IDE ✅
- Try again

---

## 🔌 Power System Wiring Instructions

Correct wiring is very important to avoid damage ⚡

### 🔋 Double Battery Holder to DC Jack Connection

The **Double Battery Holder** has:
- **Red wire** – Positive (+)
- **Black wire** – Negative (-)

#### Wiring Steps:

1. Connect the **Black wire** directly to the **Negative (-) terminal of the DC Jack**
2. Connect the **Red wire** to **one pin of the Switch**
3. Connect the **other pin of the Switch** to the **Positive (+) terminal of the DC Jack**

This allows the power to be controlled safely using the switch ✅

---

## 🧩 I2C Module Installation (Very Important ⚠️)

The **I2C Module must be attached to the back of the 16x2 LCD Display**.

📌 Make sure the I2C module is mounted **directly under the LCD** to ensure:
- Correct pin alignment  
- Stable communication  
- Clean and compact design 🛠️

---

## 📌 Final Notes

- Double-check all connections before powering ON 🔍
- Ensure the correct **I2C address** is used in the code
- Use fully charged batteries for stable performance 🔋
- Ideal for **beginners and portable Arduino projects**