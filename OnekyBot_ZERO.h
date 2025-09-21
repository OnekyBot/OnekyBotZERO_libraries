#ifndef ONEKYBOT_ZERO
#define ONEKYBOT_ZERO

#include<Servo.h>
#include<Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>

#define I2C_ADDRESS 0x3C
#define RST_PIN -1
#define SDA_PIN PB7
#define SCL_PIN PB6

extern SSD1306AsciiWire oled;

const uint8_t P1 = PA7;
const uint8_t P2 = PA5;
const uint8_t P3 = PA3;
const uint8_t P4 = PA1;
const uint8_t P5 = PA6;
const uint8_t P6 = PA5;
const uint8_t P7 = PA2;
const uint8_t P8 = PA0;

void disableOnlyJTAG_with_volatile();
void Oneky_Setup();
void motorRun(uint8_t motor_n, int16_t motor_speed);
void servoWrite(uint8_t servo_n, uint8_t angle);
bool SWA();
bool SWB();
int16_t enc1();
int16_t enc2();
void Encoder_Reset();

#endif
