#pragma once

#include <stdint.h>
#include <Arduino.h>
#include <ir_config.h>

class IRSensor {
  private:
    uint8_t _pin;
    int8_t _weight;
    const char* _name;
    uint16_t _threshold = 0;
    uint32_t _interval = 3000, _last_print = 0;
  
  public:
    IRSensor() : _pin(0), _weight(0), _name("") {}
    IRSensor(const ir_sensor_config_t& config)
      : _pin(config.pin), _weight(config.weight), _name(config.name) {
      pinMode(_pin, INPUT);
    }

    int16_t read(IR_MODES mode) {
      int16_t value = 0;
      int16_t analogValue = 0;

      if (mode == DIGITAL_SENSOR) value = digitalRead(_pin);
      else {
        analogValue = analogRead(_pin);

        if (analogValue >= _threshold) value = 1;
        else value = 0;
      }

      if (millis() - _last_print >= _interval) {
        Serial.printf("Limiar do sensor: %d\n", _threshold);
        Serial.printf("Leitura do sensor - %s: %d (%d)\n", _name, mode == DIGITAL_SENSOR ? value : analogValue, value * _weight);

        _last_print = millis();
      }

      value *= _weight;
      
      return value;
    }

    void setInterval(uint32_t interval) {
      _interval = interval;
    }

    void setThreshold(uint16_t threshold) {
      _threshold = threshold;
    }
};