// SPDX-FileCopyrightText: 2017 Mikey Sklar for Adafruit Industries
//
// SPDX-License-Identifier: MIT

// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <Adafruit_NeoPixel.h>
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
 #include <avr/power.h>
#endif

#define PIN 0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);

uint8_t  mode   = 0, // Current animation effect
         offset = 0; // Position of spinny eyes
uint32_t color  = 0x00FF00; // Start green
uint32_t prevTime;

void setup() {
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  if(F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.setBrightness(85); // 1/3 brightness
}

void loop() {
  uint8_t  i;
  uint32_t t;

    i = random(32);
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(10);
    pixels.setPixelColor(i, 0);
  }
