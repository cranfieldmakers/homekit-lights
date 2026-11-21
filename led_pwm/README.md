# XIAO ESP32-S3 HomeKit LED Dimmer

This Arduino sketch exposes the MOSFET-controlled LED on D10 (GPIO9) as a dimmable HomeKit light. HomeKit controls its on/off state and brightness using 5 kHz PWM.

## Requirements

- Seeed XIAO ESP32-S3 board
- Arduino-ESP32 core 3.3.0 or newer
- HomeSpan library 2.1.8 or newer
- An app partition of at least 1.9 MB

Install HomeSpan from Arduino IDE's Library Manager. In the IDE, open `led_pwm.ino`, select the XIAO ESP32-S3 board and a partition layout with at least 1.9 MB for the app, then upload.

## Wi-Fi and HomeKit setup

Open Serial Monitor at 115200 baud with **Newline** selected. At the HomeSpan prompt:

1. Enter `W` and follow the prompts to connect the device to Wi-Fi.
2. Enter `S <your-unique-8-digit-code>` to set a unique HomeKit pairing code.
3. In Apple's Home app, add an accessory and enter that pairing code.

## Wiring

Connect D10 to the MOSFET signal input. Use appropriate current limiting for the LED and connect the LED supply ground to the XIAO ground.
