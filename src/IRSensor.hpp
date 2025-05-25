#pragma once

#include <stdint.h>
#include <Arduino.h>
#include <ir_config.h>

class IRSensor {
  private:
    uint8_t _pin;
    int8_t _weight;
    const char* _name;
  
  public:
    IRSensor() : _pin(0), _weight(0), _name("") {}
    IRSensor(const ir_sensor_config_t& config) : _pin(config.pin), _weight(config.weight), _name(config.name) {}

    int8_t read() {
      int8_t value = digitalRead(_pin) * _weight;

      Serial.print("Leitura do sensor - ");
      Serial.print(_name);
      Serial.print(": ");
      Serial.println(value);

      return value;
    }
};