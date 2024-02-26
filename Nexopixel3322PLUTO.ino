/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL 8  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 150   // The number of LEDs (pixels) on NeoPixel

#define DELAY_INTERVAL 10  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {

  // turn pixels to green one by one with delay between each pixel
    NeoPixel.setBrightness(255);
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.
    delay(DELAY_INTERVAL);                                     // pause between each pixel
  }
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 0, 255));  // it only takes effect if pixels.show() is called
    NeoPixel.show();                                           // send the updated pixel colors to the NeoPixel hardware.
    delay(DELAY_INTERVAL);                                     // pause between each pixel
  }
  for (int bright = 255; bright > 0 ; bright--) {
    NeoPixel.setBrightness(bright);
    NeoPixel.show();
  }
  NeoPixel.clear();


}
