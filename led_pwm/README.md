# XIAO ESP32-S3 LED PWM

This sketch fades an LED on and off using a MOSFET controlled by the XIAO ESP32-S3's D10 pin (GPIO9). The cycle takes 10 seconds: 5 seconds up to full brightness, then 5 seconds back to off.

## Use

Open `led_pwm.ino` in Arduino IDE, select the Seeed XIAO ESP32-S3 board, and upload it. The cycle starts automatically.

Connect D10 to the MOSFET signal input. Use appropriate current limiting for the LED and connect the LED supply ground to the XIAO ground.
