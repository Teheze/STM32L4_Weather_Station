#pragma once

#include "stdint.h"


// rom_code - sensor address or NULL
void get_measurements(const uint8_t* rom_code);

// show everything on the screen (lines, time and text)
void update_foreground(void);
