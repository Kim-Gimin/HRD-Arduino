#include "My_Aduino_LIB.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "motor_drv.h"

  unsigned int cnt;
  char d_buf[30];

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xff;
  Serial.begin(115200);
}

void loop() {
  for(cnt = 0; cnt <= 9999; cnt++){
  // put your main code here, to run repeatedly:
  sprintf(d_buf, "Counter = %4d\n", cnt);
  Serial.write(d_buf);
  delay(200);  }
}
