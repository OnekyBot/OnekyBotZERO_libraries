#include<OnekyBot_ZERO.h>

void setup() {
  Oneky_Setup();
}

void loop() {
  motorRun(1,100);
  motorRun(2,100);
  motorRun(3,100);
  motorRun(4,100);

  delay(1000);

  motorRun(1,0);
  motorRun(2,0);
  motorRun(3,0);
  motorRun(4,0);

  delay(1000);
  
}
