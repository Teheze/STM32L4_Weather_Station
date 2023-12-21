#pragma once

#include "stm32l4xx.h"


// return - HAL_OK or HAL_ERROR
HAL_StatusTypeDef wire_reset(void);


// Read 8 bits and combine into a byte
// return - byte
uint8_t wire_read(void);

// Send data via 1-wire
void wire_write(uint8_t byte);

// Count the checksum
// data - data block
// len - length of the data block
uint8_t wire_crc(const uint8_t* data, int len);
