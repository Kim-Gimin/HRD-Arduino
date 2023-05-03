// std lib

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

 

// my lib

#include "My_Aduino_LIB.h"

 

// prj func

//#include "motor_drv.h"

 

//define

#define M1_pin  8

#define M2_pin  9

#define EN_pin  10

 

#define FAN1_pin 11

#define FAN2_pin 12

 

unsigned int cnt;

char d_buf[30];

char run_flag = 0;

 

volatile unsigned char rx_buf[20];  // low Data

volatile char rx_end_flag = 0;

volatile char rx_cnt = 0;




void m_cw()

{

  d_out(EN_pin, ON);

 

  bit_set(PORTB, M1_pin); // d_out(M1_pin, ON);

  d_out(M2_pin, 0);       // bit_clr(PORTB, OFF);

 

  d_out(LED5, OFF);

  d_out(LED3, ON);

}

 

void m_ccw()

{

  d_out(EN_pin, ON);

 

  d_out(M1_pin, OFF); // 0

  d_out(M2_pin, ON);  // 1

 

  d_out(LED3, OFF);

  d_out(LED5, ON);

}

 

void m_stop()

{

  bit_clr(PORTB, M1_pin);

  bit_clr(PORTB, M2_pin);

  d_out(EN_pin, OFF);

}

 

void m_stop_to_run()

{

  if(run_flag == 0) d_out(EN_pin, OFF);

  else if(run_flag == 1) d_out(EN_pin, ON);

}

 

void fan_m_cw()

{

  d_out(FAN1_pin, 1);

  d_out(FAN2_pin, 0);

}

 

void fan_m_ccw()

{

 d_out(FAN1_pin, OFF); //0

 d_out(FAN2_pin, ON);  // 1

}

 

void fan_m_stop()

{

  d_out(FAN1_pin, OFF);

  d_out(FAN2_pin, OFF);

}

 

void com_chk()

{

  rx_end_flag = 0;

  sprintf(d_buf, "%s", rx_buf);

  Serial.println(d_buf);

  memset(rx_buf, 0, sizeof(char) * 20);

}

void setup() {
  DDRD = 0xfe; // 0b11111110
  pinMode(M1_pin, OUTPUT);
  pinMode(M2_pin, OUTPUT);
  pinMode(EN_pin, OUTPUT);
  pinMode(FAN1_pin, OUTPUT);
  pinMode(FAN2_pin, OUTPUT);
  Serial.begin(9600); // 115200
  m_stop();
  fan_m_stop();
}
void loop() {
 if(rx_end_flag == 1) com_chk();
 bit_tg(PORTD, LED8);
  delay(500);
}
void serialEvent(){
   unsigned char buf;
   if(Serial.available()) {
     buf = Serial.read();
     if(buf == 0x0d){ 
       rx_cnt = 0;
       rx_end_flag = 1;
       Serial.println("벌래 이상없음");
     }
    else{rx_buf[rx_cnt] = buf;
          rx_cnt++;
        }
   }
}
