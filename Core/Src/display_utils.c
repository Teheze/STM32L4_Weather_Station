#include "display_utils.h"
#include "lps25hb.h"
#include "ds18b20.h"
#include "hagl.h"
#include "hagl_hal.h"
#include "wchar.h"
#include "font6x9.h"
#include "font9x18B-ISO8859-2.h"


static float temp_in, temp_out, pressure;


// converting temperature and pressure from float into wchar_t
// and put text on display
static void update_text(void)
{
    wchar_t buffer[10];

    swprintf(buffer, 10, L"%.1f°C", temp_in);
    hagl_put_text(L"Temperatura", 5, 15, WHITE, font6x9);
    hagl_put_text(L"wewnętrzna", 8, 25, WHITE, font6x9);
    hagl_put_text(buffer, 8, 35, WHITE, font9x18B_ISO8859_2);


    swprintf(buffer, 10, L"%.1fhPa", pressure);
    hagl_put_text(L"Ciśnienie", DISPLAY_WIDTH/2+11, 15, WHITE, font6x9);
    hagl_put_text(L"atmosferyczne", DISPLAY_WIDTH/2, 25, WHITE, font6x9);
    hagl_put_text(buffer, DISPLAY_WIDTH/2, 35, WHITE, font9x18B_ISO8859_2);


    swprintf(buffer, 10, L"%.1f°C", temp_out);
    hagl_put_text(L"Temperatura", 5, DISPLAY_HEIGHT/2+15, WHITE, font6x9);
    hagl_put_text(L"zewnętrzna", 8, DISPLAY_HEIGHT/2+25, WHITE, font6x9);
    hagl_put_text(buffer, 8, DISPLAY_HEIGHT/2+35, WHITE, font9x18B_ISO8859_2);
}

static void draw_borders(void)
{
	//vertical line
	hagl_draw_line(DISPLAY_WIDTH/2-5, DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2-5, DISPLAY_HEIGHT, WHITE);
	//horizontal line
	hagl_draw_line(0, DISPLAY_HEIGHT/2, DISPLAY_WIDTH, DISPLAY_HEIGHT/2, WHITE);
}

void get_measurements(const uint8_t* rom_code)
{
	temp_in = lps25hb_read_temp();
    pressure = lps25hb_read_pressure();
    temp_out = ds18b20_get_temp(rom_code);
    ds18b20_start_measure(rom_code);
}

void update_foreground(void)
{
	update_text();
	draw_borders();
}
