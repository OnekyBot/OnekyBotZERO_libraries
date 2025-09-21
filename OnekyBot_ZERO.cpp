#include "OnekyBot_ZERO.h"

#define AIN1 PB10
#define AIN2 PB11
#define PWMA PB1
#define EncoderA1 PC15
#define EncoderA2 PC14
#define BIN1 PB8
#define BIN2 PB12
#define PWMB PA8
#define EncoderB1 PC13
#define EncoderB2 PB9
#define CIN1 PA13
#define CIN2 PA14
#define PWMC PA9
#define DIN1 PA15
#define DIN2 PB3
#define PWMD PA10

SSD1306AsciiWire oled;

int8_t Now_ValueA = 0;
int8_t Now_ValueB = 0;
uint8_t s_pin;
int8_t Last_ValueA;
int8_t Last_ValueB;
int16_t encoderA_pos;
int16_t encoderB_pos;
int32_t pulseWidth;
int now_time;

void Oneky_Setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, PWM);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, PWM);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);
  pinMode(PWMC, PWM);
  digitalWrite(CIN1, HIGH);
  digitalWrite(CIN2, LOW);
  analogWrite(PWMC, 0);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, LOW);
  pinMode(PWMD, PWM);

  pinMode(PB4, OUTPUT);
  pinMode(PB5, OUTPUT);
  pinMode(PB13, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PB15, OUTPUT);

  pinMode(EncoderA1, INPUT_PULLDOWN);
  pinMode(EncoderA2, INPUT_PULLDOWN);
  pinMode(EncoderB1, INPUT_PULLDOWN);
  pinMode(EncoderB2, INPUT_PULLDOWN);

  disableOnlyJTAG_with_volatile();
  digitalWrite(PB13, HIGH);
  digitalWrite(PB14, HIGH);
  digitalWrite(PB15, HIGH);

  Wire.begin();
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(System5x7);

  motorRun(1, 0);
  motorRun(2, 0);
  motorRun(3, 0);
  motorRun(4, 0);
}

void motorRun(uint8_t motor_n, int16_t motor_speed) {
  motor_speed = constrain(motor_speed, -100, 100);
  motor_speed = map(motor_speed, -100, 100, -255, 255);
  switch (motor_n) {
    case 1:
      if (motor_speed > 0)
      {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        analogWrite(PWMA, motor_speed);
      }
      else if (motor_speed < 0)
      {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, -motor_speed);
      }
      else
      {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, 0);
      }
      break;
    case 2:
      if (motor_speed > 0)
      {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        analogWrite(PWMB, motor_speed);
      }
      else if (motor_speed < 0)
      {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        analogWrite(PWMB, -motor_speed);
      }
      else
      {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, LOW);
        analogWrite(PWMB, 0);
      }
      break;
    case 3:
      if (motor_speed > 0)
      {
        digitalWrite(CIN1, LOW);
        digitalWrite(CIN2, HIGH);
        analogWrite(PWMC, motor_speed);
      }
      else if (motor_speed < 0)
      {
        digitalWrite(CIN1, HIGH);
        digitalWrite(CIN2, LOW);
        analogWrite(PWMC, -motor_speed);
      }
      else
      {
        digitalWrite(CIN1, LOW);
        digitalWrite(CIN2, LOW);
        analogWrite(PWMC, 0);
      }
      break;
    case 4:
      if (motor_speed > 0)
      {
        digitalWrite(DIN1, LOW);
        digitalWrite(DIN2, HIGH);
        analogWrite(PWMD, motor_speed);
      }
      else if (motor_speed < 0)
      {
        digitalWrite(DIN1, HIGH);
        digitalWrite(DIN2, LOW);
        analogWrite(PWMD, -motor_speed);
      }
      else
      {
        digitalWrite(DIN1, LOW);
        digitalWrite(DIN2, LOW);
        analogWrite(PWMD, 0);
      }
      break;
  }
}

void servoWrite(uint8_t servo_n, uint8_t angle) {
  switch (servo_n) {
    case 1:
      s_pin = PB13;
      break;
    case 2:
      s_pin = PB14;
      break;
    case 3:
      s_pin = PB15;
      break;
    case 4:
      s_pin = PB4;
      break;
    case 5:
      s_pin = PB5;
      break;
  }
  now_time = millis();
  while ((millis() - now_time) <= 1500) {
    angle = constrain(angle, 0, 130);
    pulseWidth = map(angle, 0, 130, 500, 2400);
    digitalWrite(s_pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(s_pin, LOW);
    delayMicroseconds(20000 - pulseWidth);
  }
  digitalWrite(s_pin, LOW);
}

int16_t enc1() {
  Now_ValueA = digitalRead(EncoderA1);
  if (Now_ValueA != Last_ValueA) {
    if (digitalRead(EncoderA2) != Now_ValueA) {
      encoderA_pos++;
    } else if (digitalRead(EncoderA2) == Now_ValueA) {
      encoderA_pos--;
    }
    //Serial.println(encoderA_pos);
  }
  Last_ValueA = Now_ValueA;
  return encoderA_pos;
}

int16_t enc2() {
  Now_ValueB = digitalRead(EncoderB1);
  if (Now_ValueB != Last_ValueB) {
    if (digitalRead(EncoderB2) != Now_ValueB) {
      encoderB_pos++;
    } else if (digitalRead(EncoderB2) == Now_ValueB) {
      encoderB_pos--;
    }
  }
  Last_ValueB = Now_ValueB;
  return encoderB_pos;
}

void Encoder_Reset() {
  encoderA_pos = 0;
  encoderB_pos = 0;
}

bool SWA() {
  int16_t sw = analogRead(PB0);
  if (sw < 900) {
    return true;
  }
  else {
    return false;
  }
}

bool SWB() {
  int16_t sw = analogRead(PB0);
  if (sw > 1000 && sw < 3000) {
    return true;
  }
  else {
    return false;
  }
}

void disableOnlyJTAG_with_volatile() {
  *(volatile uint32_t*)0x40021018 |= (1 << 0);

  *(volatile uint32_t*)0x40010004 &= ~(0b111 << 24);

  *(volatile uint32_t*)0x40010004 |=  (0b010 << 24);
}
