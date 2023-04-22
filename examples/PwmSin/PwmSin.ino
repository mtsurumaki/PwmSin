#include <PwmSin.h>
#define SER 13
#define RCLK 12
#define SRCLK 11
#define SAMPLE 1024

uint8_t puttrns[SAMPLE];

void setup() {
  uint16_t i;

  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  PwmSin_Gen(puttrns, SAMPLE);

  while(1){
    for(i = 0; i < SAMPLE; i++){
      digitalWrite(RCLK, LOW);
      shiftOut(SER, SRCLK, MSBFIRST, puttrns[i]);
      digitalWrite(RCLK, HIGH);
      delayMicroseconds(500);
    }
  }
}

void loop() {
  /* nop */
}
