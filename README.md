# Temperature and Humidity Monitoring with OLED Display and LEDs

## Overview
This project uses an **ESP32** (or another compatible microcontroller) to measure temperature and humidity using a **DHT11** sensor. The data is displayed on an **OLED screen (SSD1306)**, and two LEDs provide a visual indication of the temperature and humidity levels.

## Components Used
- **ESP32 / Arduino** (or compatible microcontroller)
- **DHT11 Temperature & Humidity Sensor**
- **OLED Display (SSD1306, 128x64 pixels, I2C)**
- **Red LED (D18) for high temperature/humidity alert**
- **Green LED (D19) for normal conditions**
- **Resistors (if necessary for LEDs)**
- **Jumper wires and breadboard**

## Wiring Diagram
| Component | ESP32 Pin |
|-----------|----------|
| DHT11 Data | GPIO 5 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Red LED | GPIO 18 |
| Green LED | GPIO 19 |

## Code Explanation
1. **Libraries Used:**
   - `Wire.h`: Handles I2C communication for the OLED display.
   - `Adafruit_GFX.h` and `Adafruit_SSD1306.h`: Control the OLED display.
   - `DHT.h`: Interface with the DHT11 sensor.

2. **Initialization (`setup`)**
   - Starts the OLED display and serial communication.
   - Initializes the DHT11 sensor.
   - Configures the LED pins as outputs.

3. **Main Loop (`loop`)**
   - Reads temperature and humidity from the DHT11 sensor.
   - Displays the readings on the OLED screen.
   - Controls the LEDs based on temperature and humidity:
     - **Red LED ON**: Temperature > 35°C or Humidity > 60%
     - **Green LED ON**: Temperature < 35°C and Humidity between 30% and 60%
     - **Both LEDs OFF**: If the readings are outside the defined ranges.

## Installation and Usage
1. **Install Required Libraries** in the Arduino IDE:
   - `Adafruit SSD1306`
   - `Adafruit GFX`
   - `DHT Sensor Library`
2. **Connect the components** as per the wiring diagram.
3. **Upload the code** to your ESP32/Arduino board.
4. **Observe the OLED display and LED indicators** based on the environmental conditions.

## Expected Output
- OLED Display:
  ```
  Temp: 29.00 C
  Umid: 55 %
  ```
- LED Indicators:
  - **Red LED** turns ON for high temperature/humidity.
  - **Green LED** turns ON for normal conditions.
  - Both LEDs OFF for undefined states.

