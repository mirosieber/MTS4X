
# MTS4X Digital Temperature Sensor Library

This repository contains an Arduino library for communication with MTS4X Digital Temperature Sensors via I2C.  The library provides a simple interface to access temperature data with configurable measurement modes, averaging options, and power management features.

The library is designed to work with MTS4, MTS4P, MTS4Z, MTS4B temperature sensors and supports all Arduino-compatible boards with I2C capability, including ESP32, ESP8266, AVR, SAMD, STM32, and more.

## Features

- **Easy Integration**: A simple API for accessing temperature data with minimal setup
- **Multiple Measurement Modes**: Support for continuous and one-shot measurement modes
- **Configurable Averaging**: Choose from 1, 2, 4, or 8 sample averaging for noise reduction
- **Power Management**: Low-power standby mode for battery-operated applications
- **Flexible I2C Support**: Works with any Arduino board that has I2C capability

## Installation

To install the library:

**Download via Arduino Library Manager (MTS4X)** or install manually:

1. Download the latest version of the library as a ZIP file
2. Open the Arduino IDE
3. Go to **Sketch → Include Library → Add .ZIP Library.. .**
4. Select the downloaded ZIP file
5. The library is now installed and ready for use

## Usage
```cpp
#include  <MTS4X.h>
MTS4X tempSensor;

void  setup()  {
Serial.begin(115200);
tempSensor.begin(SDA, SCL, MEASURE_CONTINUOUS);
} 

void  loop()  {
float temperature = tempSensor.readTemperature();
Serial.printf("Temperature: %.2f °C\n", temperature);
delay(1000);
}
```

## Hardware Connection

Connect the MTS4X sensor to your Arduino board: 

| MTS4X Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 3.3V or 5V  |
| GND       | GND         |
| SDA       | SDA         |
| SCL       | SCL         |

**Note**: MTS4X sensors support both 3.3V and 5V operation.  Check your sensor's datasheet for voltage requirements.

## Troubleshooting

**Sensor not detected:**
- Check I2C connections (SDA, SCL)
- Verify power supply voltage
- Ensure pull-up resistors are present on SDA and SCL lines (usually built into Arduino boards)
- Try scanning for I2C devices using an I2C scanner sketch

**Incorrect readings:**
- Allow sensor to stabilize after power-on (typically 1-2 seconds)
- Increase averaging to reduce noise

## License

This library is released under the MIT License. See LICENSE file for details. 

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Author

Miro Sieber