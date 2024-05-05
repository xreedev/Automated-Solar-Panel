

<div align="center">
  <h1>Sun Tracking Solar Panel</h1>
  <p>Automated solar panel tracking system using ESP32</p>
</div>

## Description
This project is an automated solar panel tracking system developed using an ESP32 microcontroller. It tracks the sun's position using latitude and longitude coordinates and adjusts the solar panel accordingly to maximize solar energy generation.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributors](#contributors)
- [License](#license)

## Features
- Automatically tracks the sun's position and adjusts the solar panel angle.
- Web interface for updating the solar panel location.
- Supports manual input of latitude and longitude coordinates.

## Requirements
- ESP32 microcontroller
- Servo motor
- SolPos library
- Adafruit PWM Servo Driver library
- Arduino IDE
- Wi-Fi network for ESP32 connectivity

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/automated-solar-panel.git
   ```
2. Open the Arduino IDE and navigate to **File > Open**. Select the `sun-tracking-solar-panel.ino` file from the cloned repository.
3. Connect your ESP32 board to your computer using a USB cable.
4. Select your ESP32 board from **Tools > Board** menu.
5. Install the required libraries:
   - SolPos library
   - Adafruit PWM Servo Driver library
6. Upload the code to your ESP32 board.

## Usage
1. Power on your ESP32 board.
2. Connect your computer to the same Wi-Fi network as your ESP32 board.
3. Open a web browser and enter the IP address of your ESP32 board.
4. Update the location of the solar panel manually or use the automatic sun tracking feature.
5. The servo motor will adjust the solar panel to maximize solar energy generation.

## Contributors
- [Sreedev TS](https://github.com/xreedev)
-  Jafar N
-  Inthresh S
-  Aadith Vijji

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
