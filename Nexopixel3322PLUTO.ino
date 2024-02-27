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

#define DELAY_INTERVAL 2000  // 250ms pause between each pixel
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);
bool intakeIsFull = false;

void setup() {
  NeoPixel.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  
    NeoPixel.setBrightness(1000000);
    pinMode(40, INPUT);
}

void setLed(int r, int g, int b){
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {    
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(r, g, b));   
  }
  NeoPixel.show();
}

void loop() {
  if(intakeIsFull){
    setLed(0,255,0);
    delay(200);
    setLed(0,0,0);
    delay(200);
  }
  else{
    showLed(0,150,255);
  }
  if(digitalRead(40) == HIGH){
    intakeIsFull = true;
  }
  else{
    intakeIsFull = false;
  }
}

