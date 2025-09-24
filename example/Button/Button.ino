#include<OnekyBot_ZERO.h>

void setup() {
  Oneky_Setup();
  oled.clear();
}

void loop() {
  oled.clear();
  if (SWA()) {
    oled.print("Button A pessed");
  } else if (SWB()) {
    oled.print("Button B pessed");
  }
  delay(100);
}
