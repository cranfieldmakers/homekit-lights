#include "HomeSpan.h"

constexpr uint8_t MOSFET_SIGNAL_PIN = D10;
constexpr uint16_t PWM_FREQUENCY_HZ = 5000;

struct DimmableMosfetLight : Service::LightBulb {
  SpanCharacteristic *power;
  SpanCharacteristic *brightness;
  LedPin *led;

  DimmableMosfetLight(uint8_t pin) : Service::LightBulb() {
    power = new Characteristic::On();
    brightness = new Characteristic::Brightness(100);
    led = new LedPin(pin, 0, PWM_FREQUENCY_HZ);
  }

  boolean update() override {
    const int level = power->getNewVal() ? brightness->getNewVal() : 0;
    led->set(level);
    return true;
  }
};

void setup() {
  Serial.begin(115200);
  homeSpan.begin(Category::Lighting, "LED Dimmer");

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new DimmableMosfetLight(MOSFET_SIGNAL_PIN);
}

void loop() {
  homeSpan.poll();
}
