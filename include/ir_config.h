#pragma once

#include <stdint.h>

typedef struct {
  uint8_t pin;
  const char* name;
  int8_t weight;
  uint16_t threshold;
} ir_sensor_config_t;

enum IR_MODES {
  DIGITAL_SENSOR,
  ANALOG_SENSOR
};