// WIRING: https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/
// image converter: https://www.mischianti.org/images-to-byte-array-online-converter-cpp-arduino/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 'batman', 32x13px
const unsigned char closed[] PROGMEM = {
    // 'm6i_s7ii_400x400(2)', 128x64px
    0xff,
    0xff,
    0xc0,
    0x7f,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0xff,
    0xff,
    0x80,
    0xff,
    0xff,
    0xff,
    0x00,
    0x01,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0xff,
    0xff,
    0x81,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x03,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xff,
    0x83,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x03,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xff,
    0x03,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc7,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xff,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xff,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe7,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xfe,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc1,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0xff,
    0xfe,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x00,
    0xff,
    0xfc,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x0f,
    0xff,
    0xfe,
    0x00,
    0x00,
    0xff,
    0xfc,
    0x1f,
    0xfe,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x03,
    0xff,
    0xfc,
    0x08,
    0x00,
    0xff,
    0xfc,
    0x3f,
    0xfc,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xf8,
    0x3f,
    0xfc,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xf8,
    0x7f,
    0xff,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0x7f,
    0xfc,
    0x08,
    0x00,
    0xff,
    0xf0,
    0xff,
    0xff,
    0x83,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x1f,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xf0,
    0xff,
    0xff,
    0xc1,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x0f,
    0xff,
    0xc0,
    0x00,
    0xff,
    0xe1,
    0xff,
    0xff,
    0xe0,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x03,
    0xff,
    0x00,
    0x00,
    0xff,
    0xe1,
    0xff,
    0xff,
    0xf0,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x00,
    0x01,
    0xff,
    0x00,
    0x00,
    0xff,
    0xc3,
    0xff,
    0xff,
    0xfc,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf8,
    0x00,
    0x01,
    0xfe,
    0x00,
    0x00,
    0xff,
    0x83,
    0xff,
    0xff,
    0xfe,
    0x01,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xfe,
    0x00,
    0x00,
    0xff,
    0x07,
    0xff,
    0xff,
    0xff,
    0x80,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x00,
    0x00,
    0x18,
    0x00,
    0x00,
    0xfe,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x03,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x00,
    0x00,
    0x10,
    0x00,
    0x00,
    0xfe,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xf8,
    0x01,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x10,
    0x00,
    0x00,
    0xfe,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x03,
    0xff,
    0xff,
    0xff,
    0x00,
    0xf8,
    0x00,
    0x00,
    0x00,
    0x00,
    0xfe,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf8,
    0x03,
    0xfe,
    0x00,
    0x00,
    0x00,
    0x00,
    0xfe,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0xff,
    0xff,
    0x00,
    0x00,
    0x00,
    0x00,
    0xfc,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc1,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x00,
    0x00,
    0xf8,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x81,
    0xff,
    0xff,
    0xe0,
    0x00,
    0x00,
    0x00,
    0xf8,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x81,
    0xff,
    0xff,
    0xf0,
    0x00,
    0x00,
    0x00,
    0xf0,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x07,
    0xff,
    0xff,
    0xf8,
    0x00,
    0x00,
    0x00,
    0xf0,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x1f,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x00,
    0x00,
    0xf0,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x3f,
    0xff,
    0xff,
    0xfe,
    0x00,
    0x00,
    0x00,
    0xe0,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf8,
    0x03,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0x00,
    0x01,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x61,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0x00,
    0x81,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x70,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x00,
    0x83,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x38,
    0x7f,
    0xff,
    0xff,
    0x80,
    0x00,
    0x00,
    0x03,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x3c,
    0x3f,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x00,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x1e,
    0x0f,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x00,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xef,
    0xff,
    0x1f,
    0x07,
    0xff,
    0xff,
    0x80,
    0x00,
    0x00,
    0x07,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xef,
    0xff,
    0xdf,
    0x80,
    0x3f,
    0xff,
    0x80,
    0x00,
    0x00,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe7,
    0xff,
    0xdf,
    0xc0,
    0x1f,
    0xff,
    0x80,
    0x00,
    0x00,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc7,
    0xff,
    0xff,
    0xe0,
    0x0f,
    0xff,
    0x80,
    0x00,
    0x00,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0x3f,
    0xfe,
    0x03,
    0xff,
    0xff,
    0xf0,
    0x01,
    0xff,
    0x80,
    0x00,
    0x00,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x1f,
    0xfc,
    0x01,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x3f,
    0x80,
    0x00,
    0x00,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x1f,
    0xf8,
    0x03,
    0xff,
    0xff,
    0xff,
    0x80,
    0x0f,
    0x00,
    0x00,
    0x00,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x0f,
    0xf0,
    0x73,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x0f,
    0x00,
    0x00,
    0x00,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x0d,
    0xe8,
    0xfa,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x0f,
    0x00,
    0x00,
    0x00,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x1f,
    0xc1,
    0xf8,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x00,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0xff,
    0x80,
    0xfe,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0xff,
    0x80,
    0x7e,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x00,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0xbf,
    0x00,
    0x7f,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0x20,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0x40,
    0x7f,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x3e,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0x80,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x3e,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x58,
    0x3f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe8,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x40,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc8,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x00,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xc0,
    0x00,
    0x7f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf6,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xe0,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x01,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf0,
    0x0f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfc,
    0x1f,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xf8,
    0x00,
    0x00,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xfe,
    0x00,
    0x00,
};

const unsigned char opened[] PROGMEM = {
    // 'm6i_s7ii_400x400(1)', 128x64px
    0xff, 0xff, 0xc0, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xff, 0x07, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xfe, 0x0f, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 0x80, 0x00,
    0xff, 0xfe, 0x0f, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xc0, 0x00,
    0xff, 0xfc, 0x1f, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xfe, 0x00, 0x00,
    0xff, 0xfc, 0x1f, 0xfe, 0x0f, 0x80, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xfc, 0x08, 0x00,
    0xff, 0xfc, 0x3f, 0xfe, 0x3f, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xf8, 0x3f, 0xfc, 0x7e, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xf8, 0x7f, 0xff, 0x3e, 0x00, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xfc, 0x08, 0x00,
    0xff, 0xf0, 0xff, 0xff, 0xde, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xfc, 0x00, 0x00,
    0xff, 0xf0, 0xff, 0xff, 0xe4, 0x20, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xc0, 0x00,
    0xff, 0xe1, 0xff, 0xff, 0xe0, 0x00, 0xa7, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0x00, 0x00,
    0xff, 0xe1, 0xff, 0xff, 0xfe, 0x01, 0xbf, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x01, 0xff, 0x00, 0x00,
    0xff, 0xc3, 0xff, 0xff, 0xff, 0x61, 0x9f, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xfe, 0x00, 0x00,
    0xff, 0x83, 0xff, 0xff, 0xff, 0xf1, 0xdf, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xfe, 0x00, 0x00,
    0xff, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x18, 0x00, 0x00,
    0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x10, 0x00, 0x00,
    0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x10, 0x00, 0x00,
    0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00,
    0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00,
    0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00,
    0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00,
    0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0x80, 0x1f, 0xfc, 0x00, 0x00, 0x00,
    0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3e, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x06, 0x10, 0x00, 0xff, 0x00, 0x00, 0x00,
    0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x63, 0xf8, 0x00, 0x3f, 0x00, 0x00, 0x00,
    0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xf0, 0x00, 0x17, 0x00, 0x00, 0x00,
    0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xe0, 0x00, 0x0e, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xe0, 0x00, 0x0e, 0x80, 0x00, 0x00,
    0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x80, 0x00, 0x03, 0x80, 0x00, 0x00,
    0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xdf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xdf, 0xe0, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf0, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x03, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfc, 0x01, 0xff, 0xff, 0xfc, 0x00, 0x13, 0x00, 0x00, 0x00,
    0x3f, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x03, 0x00, 0x00, 0x00,
    0x3f, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xf0, 0x73, 0xff, 0xff, 0xff, 0xf8, 0x07, 0x00, 0x00, 0x00,
    0x3f, 0xff, 0xff, 0xff, 0xf0, 0x0d, 0xe8, 0xfa, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0x00, 0x00, 0x00,
    0x7f, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xc1, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x80, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x80, 0x7e, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0xbf, 0x00, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x20, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x58, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe8, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x40, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc8, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00};

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// ------------------- For i2c -------------------
//// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ------------------- For SPI -------------------
// Declaration for SSD1306 display connected using software SPI (default case):
// #define OLED_MOSI   D7
// #define OLED_CLK   D5
// #define OLED_DC    D2
// #define OLED_CS    D8
// #define OLED_RESET D1
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()
{
  Serial.begin(115200);

  delay(2000);
  Serial.println(F("Starting!"));

  // ------------------- For SPI -------------------
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  //  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
  //    Serial.println(F("SSD1306 allocation failed"));
  //    for(;;); // Don't proceed, loop forever
  //  }

  //  ------------------- For i2c -------------------
  //  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  Serial.println(F("Initialized!"));
}

void loop()
{

  // Show initial display buffer contents on the screen --
  display.clearDisplay();
  display.drawBitmap(0, 0, closed, 128, 64, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.drawBitmap(0, 0, opened, 128, 64, WHITE);
  display.display();
  delay(1000);
  display.stopscroll();
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  for (int x = 20; x > -560; x -= 5)
  {
    display.clearDisplay();
    display.setCursor(x, 10);
    display.setTextWrap(false);
    display.println("Nice cock, bro");
    display.display();
  }
}