#include "My_Aduino_LIB.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M1_pin 8
#define M2_pin 9
#define EN_pin 10

#define FAN1_pin 11
#define FAN2_pin 12

unsigned int cnt;
char d_buf[30];
char run_flag = 0;

void m_cw(){
  d_out(EN_pin, ON);
  bit_set(PORTB, M1_pin); // d_out(M1_pin, ON);
  d_out(M2_pin, 0); //bit_clr(PORTB, OFF); 

  d_out(LED5, OFF);
  d_out(LED3, ON);
}

void m_ccw(){
  d_out(EN_pin, ON);
  d_out(M1_pin, OFF); // 0
  d_out(M2_pin, ON); // 1
  d_out(LED5, ON);
  d_out(LED3, OFF);
}

void m_stop(){
  bit_clr(PORTB, M1_pin);
  bit_clr(PORTB, M2_pin);
  d_out(EN_pin, OFF);
}

void m_stop_to_run(){
  if(run_flag == 0) d_out(EN_pin, OFF);
  else if(run_flag == 1) d_out(EN_pin, ON);
}

void fan_cw(){
  d_out(FAN1_pin, ON);
  d_out(FAN2_pin, OFF);
}

void fan_ccw(){
  d_out(FAN1_pin, OFF);
  d_out(FAN2_pin, ON);
}

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xfe; //0b11111110

  pinMode(M1_pin, OUTPUT);
  pinMode(M2_pin, OUTPUT);
  pinMode(EN_pin, OUTPUT);
  pinMode(FAN1_pin, OUTPUT);
  pinMode(FAN2_pin, OUTPUT);

  Serial.begin(115200);
  m_stop();
}

void loop() {
  // put your main code here, to run repeatedly:
   
  m_cw();
  fan_cw();
  delay(5000);  
  fan_ccw();
  m_ccw();
  delay(5000);
  m_stop();
  exit(0);
}
