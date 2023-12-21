#pragma once
#include "stm32l4xx.h"


// Wake up and automatic measurements
// return - HAL_OK or HAL_ERROR
HAL_StatusTypeDef lps25hb_init(void);

// return - result in degrees C
float lps25hb_read_temp(void);

// Odczyt ciśnienia
// return - result in hPa
float lps25hb_read_pressure(void);

// Calibrate the pressure sensor
// value - 16-bit measurement correction
void lps25hb_set_calib(uint16_t value);
