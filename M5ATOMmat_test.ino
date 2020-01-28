#include <Adafruit_NeoPixel.h>

#define LED 27

#define N_PIX 25

Adafruit_NeoPixel pixels(N_PIX, LED, NEO_GRB + NEO_KHZ800);

#define DELAY 20

void setup(){
  pixels.begin();
}

#define BRIGHTNESS 20

int color = 1;
int r = BRIGHTNESS, g = 0, b = 0;

void loop() {
  int i;
//  pixels.clear();
  for(i = 0; i < N_PIX; i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAY);
  }
  color = (color + 1) % 8;
  if (color == 0) color = 1;
  if (color & 0x01) r = BRIGHTNESS; else r = 0;
  if (color & 0x02) g = BRIGHTNESS; else g = 0;
  if (color & 0x04) b = BRIGHTNESS; else b = 0;
}
