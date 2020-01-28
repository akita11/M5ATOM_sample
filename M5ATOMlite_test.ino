#include <Adafruit_NeoPixel.h>

#define LED 27
#define BTN 39

#define N_PIX 1

Adafruit_NeoPixel pixels(N_PIX, LED, NEO_GRB + NEO_KHZ800);

#define DELAY 20

void setup(){
  pixels.begin();
  pinMode(BTN, INPUT); digitalWrite(BTN, 1);
}

#define BRIGHTNESS 20

int color = 1;

void loop() {
  int i;
  int r = 0, g = 0, b = 0;
  pixels.clear();
  for (i = 0; i < BRIGHTNESS * 2; i++){
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAY);
    if (color & 0x01) if (i < BRIGHTNESS) r++; else r--;
    if (color & 0x02) if (i < BRIGHTNESS) g++; else g--;
    if (color & 0x04) if (i < BRIGHTNESS) b++; else b--;
    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;
    if (digitalRead(BTN) == 0){
      while (digitalRead(BTN) == 0) delay(10);      
      color = (color + 1) % 8;
      if (color == 0) color++;
    }
  }
}
