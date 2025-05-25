#pragma once

#include <stdint.h>

typedef struct {
  uint8_t pin;
  const char* name;
  int8_t weight;
} ir_sensor_config_t;