#include <PwmSin.h>
#define SER 13
#define RCLK 12
#define SRCLK 11
#define SAMPLE 1024

uint8_t puttrns[SAMPLE];

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  PwmSin_Gen(puttrns, SAMPLE);
}

void loop() {
  uint16_t i;

  for(i = 0; i < SAMPLE; i++){
    digitalWrite(RCLK, LOW);
    shiftOut(SER, SRCLK, MSBFIRST, puttrns[i]);
    digitalWrite(RCLK, HIGH);
    delayMicroseconds(500);
  }
}
