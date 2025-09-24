#include<OnekyBot_ZERO.h>

void setup() {
  Oneky_Setup();

  Serial.begin(115200);

  pinMode(P1,INPUT);
  pinMode(P2,INPUT);
  pinMode(P3,INPUT);
  pinMode(P4,INPUT);
  pinMode(P5,INPUT);
  pinMode(P6,INPUT);
  pinMode(P7,INPUT);
  pinMode(P8,INPUT);
}

void loop() {
  Serial.print("P1 Value = ");
  Serial.println(analogRead(P1));
  Serial.print("P2 Value = ");
  Serial.println(analogRead(P2));
  Serial.print("P3 Value = ");
  Serial.println(analogRead(P3));
  Serial.print("P4 Value = ");
  Serial.println(analogRead(P4));
  Serial.print("P5 Value = ");
  Serial.println(analogRead(P5));
  Serial.print("P6 Value = ");
  Serial.println(analogRead(P6));
  Serial.print("P7 Value = ");
  Serial.println(analogRead(P7));
  Serial.print("P8 Value = ");
  Serial.println(analogRead(P8));
  delay(500);
  
}
