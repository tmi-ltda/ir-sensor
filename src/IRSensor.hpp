#pragma once

#include <stdint.h>
#include <Arduino.h>
#include <ir_config.h>

class IRSensor {
  private:
    uint8_t _pin;
    int8_t _weight;
    const char* _name;
    uint32_t _interval = 100, _last_read = 0;
  
  public:
    IRSensor() : _pin(0), _weight(0), _name("") {}
    IRSensor(const ir_sensor_config_t& config) : _pin(config.pin), _weight(config.weight), _name(config.name) {
      pinMode(_pin, INPUT);
    }

    int16_t read(IR_MODES mode) {
      int16_t value = 0;

      if (millis() - _last_read >= _interval) {
        if (mode == DIGITAL_SENSOR) value = digitalRead(_pin) * _weight;
        else value = analogRead(_pin) * _weight;

        Serial.print("Leitura do sensor - ");
        Serial.print(_name);
        Serial.print(": ");
        Serial.println(value);  

        _last_read = millis();
      }

      return value;
    }

    void setInterval(uint32_t interval) {
      _interval = interval;
    }
};