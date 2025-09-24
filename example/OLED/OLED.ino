#include<OnekyBot_ZERO.h>

void setup() {
  Oneky_Setup();

  oled.clear();
  oled.println("OnekyBot setup finish");
}

void loop() {
  oled.println("Hello World");
  delay(500);
}
