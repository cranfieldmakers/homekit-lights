#include <Arduino.h>

// XIAO ESP32-S3 D10 (GPIO9) drives the MOSFET gate signal.
constexpr uint8_t LED_PIN = D10;
constexpr uint8_t PWM_BITS = 8;
constexpr uint32_t PWM_FREQUENCY_HZ = 5000;
constexpr uint32_t CYCLE_PERIOD_MS = 10000;
constexpr uint32_t HALF_CYCLE_MS = CYCLE_PERIOD_MS / 2;
constexpr uint8_t PWM_MAX = (1 << PWM_BITS) - 1;

int previousDuty = -1;

void setup() {
  analogWriteResolution(LED_PIN, PWM_BITS);
  analogWriteFrequency(LED_PIN, PWM_FREQUENCY_HZ);
  analogWrite(LED_PIN, 0);
}

void loop() {
  const uint32_t phase = millis() % CYCLE_PERIOD_MS;
  const uint32_t rampPosition =
      (phase <= HALF_CYCLE_MS) ? phase : CYCLE_PERIOD_MS - phase;
  const int duty = (rampPosition * PWM_MAX) / HALF_CYCLE_MS;

  // Update only when the 8-bit PWM value changes.
  if (duty != previousDuty) {
    analogWrite(LED_PIN, duty);
    previousDuty = duty;
  }
}
