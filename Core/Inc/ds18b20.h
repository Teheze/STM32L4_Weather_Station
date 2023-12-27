#pragma once

#include "stm32l4xx.h"

#define DS18B20_ROM_CODE_SIZE 8


// return - HAL_OK/HAL_ERROR
HAL_StatusTypeDef ds18b20_init(const uint8_t* rom_code);

// Read the sensor address and calculate the CRC
// rom_code - place to save read data
// return - HAL_OK/HAL_ERROR
HAL_StatusTypeDef ds18b20_read_address(uint8_t* rom_code);

// Start measuring temperature
// rom_code - sensor address or NULL
// return - HAL_OK/HAL_ERROR
HAL_StatusTypeDef ds18b20_start_measure(const uint8_t* rom_code);

// Get the temperature
// rom_code - sensor address or NULL
// return - temperature in Celsius
float ds18b20_get_temp(const uint8_t* rom_code);
