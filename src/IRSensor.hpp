#pragma once

#include <stdint.h>
#include <Arduino.h>

class IRSensor {
  private:
    uint8_t _pin;
    int8_t _weight;
    const char* _name;
  
  public:
    IRSensor(uint8_t pin, int8_t weight, const char* name) : _pin(pin), _weight(weight), _name(name) {}

    int8_t read() {
      int8_t value = digitalRead(_pin) * _weight;

      Serial.print("Leitura do sensor - ");
      Serial.print(_name);
      Serial.print(": ");
      Serial.println(value);

      return value;
    }
};