# ArduinoPIDMotortemperaturecontrol
This project implements a **PID controller** on an Arduino to regulate a motor (e.g., fan) speed based on temperature input from a **TMP36 sensor**. A **potentiometer** is used to set the desired temperature, and the motor responds accordingly through a PWM signal.

---

## 📦 Hardware Components

- Arduino Uno (or compatible)
- DC Motor with an encoder
- TMP36 Temperature Sensor
- Potentiometer
- Breadboard & jumper wires
- Power supply (USB or battery)

---

## ⚙️ How It Works

- **Potentiometer** sets the temperature setpoint (target).
- **TMP36** measures the real-time ambient temperature.
- The **PID controller** compares the actual temperature to the setpoint and adjusts motor speed using PWM.
- This allows smooth, proportional fan control based on temperature.

---

## 🧪 PID Tuning Parameters

```cpp
float KP = 0.1;
float KI = 0.0001;
float KD = 0.001;
```

These values were tuned manually to ensure stable temperature tracking with minimal overshoot. You can adjust these based on your setup.

---

## 📁 Project Files

- [`motor temperature PID control.ino`](motor%20temperature%20PID%20control.ino) – Main Arduino source code
- `schematicDiagram.pdf` – Schematic diagram (PDF)
- `tinkerCADsimulation.png` – Simulated circuit in Tinkercad (PNG)

---

## 🖥️ Serial Output Sample

```
Temp: 111.78 | Target: 36 | PWM: 129
```

---

## 🚀 Getting Started

1. Build the circuit as shown in the schematic or TinkerCAD image.
2. Upload the `.ino` file to your Arduino using the Arduino IDE.
3. Open the Serial Monitor at 9600 baud to view temperature, target, and PWM values.
4. Adjust the potentiometer and watch the motor respond to temperature error.

---

## 📚 License

MIT License. You’re free to use, modify, and distribute.

---

## ✍️ Author

**Yusuf Solomon Badasz**  
Robotics & Embedded Systems Enthusiast  
