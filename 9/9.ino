#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "My_key_LIB.h"
//int8_t tg_flag = 0;
int8_t tg_flag = 0; // char와 같음
int8_t tg_flag2 = 0;
#include "My_Aduino_LIB.h"
#include "my_fnd_lib.h"
#include "uart.c"
#include "io.h"
// char와 같음
long cnt = 123456; // unsigned char와 같음
//uint8_t cnt = 123456;
int t_loop = 0;
int cnt_2 = 3451;

struct ck{
  int time_loop;
  char hour;
  int8_t min;
  char sec;

}time{0, 0, 0, 0};

unsigned char key_buf;
struct chk{
  char key_flag;
  char run_flag;
  int bit_flag;
  char byte_flag;
  unsigned int kb_flag;
  char key_d[10];
  float dk_flag;
}flag = {0,0,0,0};

unsigned char mode_cnt = 1;
char d_buf[20];

char key_bit_in(){
  // bit 방식읽기 = Arduino Mode
  char buf = '0';
  // (UP_key == 1) ? buf = 1 : (DN_key == 1) ? buf = 2 : (RUN_key == 1) ? buf = 3 :
  // (STOP_key == 1) ? buf = 4 : (MODE_key == 1) ? buf = 5 : buf = 0;
  // 같은거
  if(d_in(UP_key) == 1) buf = '1';
  else if(d_in(DN_key) == 1) buf = '2';
  else if(d_in(RUN_key) == 1) buf = '3';
  else if(d_in(STOP_key) == 1) buf = '4';
  else if(d_in(MODE_key) == 1) buf = '5';
  else buf = '0';

  while(PINC != 0x00){} 
  //Serial.println(buf);
  
  /*
  Serial.println(digitalRead(UP_key));

  if(digitalRead(UP_key) == 1){
    Serial.println("Up Key Input");
    flag.key_flag = 1;
  }
  */
  if(buf != 0) flag.key_flag = 1;
  return buf;
  
}
#define byte_key 1 // bit_key

char key_byte_in(){
  // byte 방식읽기 = MCU Mode
  char buf;

  if(PINC != 0){
    buf = (PINC & 0x3f);
    //sprintf(d_buf, "%d\n", buf);
    Serial.print(buf);
    flag.key_flag = 1;
  }
  //if(digitalRead(UP_key) == 0)
 
  return buf;
}

void key_chk(){
  //키 판단
  flag.key_flag = 0;


//#ifdef bit_key
  switch(key_buf){
    case '1': // up key
    case 0x01:
      cnt_2++;
      // tx_str("\033[2J"); //화면클리어
      // tx_str("\x1b[43m"); //배경색
      // tx_str("\x1b[41m"); //글자색
      Serial.println(cnt_2);
      break;
    case '2': // dn key
    case 0x02:
      cnt_2--;
      Serial.println(cnt_2);
      break;
    case '3': // run key
    case 0x04:
      flag.run_flag = 1;
      break;
    case '4': // stop key
    case 0x08:
      flag.run_flag = 0;
      break;
    //if((key_buf == 5) || (key_buf ==0x10)){

   // }
    case '5': // mode key
    case 0x10:
      mode_cnt++;
      if(mode_cnt > 2) mode_cnt = 1;
      break;
  }
  //#endif

  #ifdef byte_key

  #endif
}

char key_rd(){
  
  #ifdef bit_key
    char buf = '0';
    buf = key_bit_in();
  #endif;

  #ifdef byte_key
    char buf = '0';
    buf = key_byte_in();
  #endif;

  return buf;
}
void up_cnt(){
  for(; cnt_2<= 9999; ){
    cnt_2 += 5;
    sprintf(d_buf, "Count = %4d", cnt_2);
    Serial.println(d_buf);
    delay(200);
    key_buf = key_bit_in();

    if(flag.key_flag == 1){
      key_chk();
      break;
    }
  }
}
// time.sec++;
// time.sec = 35;
// time.min = time.sec;
void dn_cnt(){
  cnt_2 -= 5;
  sprintf(d_buf, "Count = %4d", cnt_2);
  Serial.println(d_buf);
  delay(200);
}


void setup() {


  // put your setup code here, to run once:
  DDRD = 0xf0;
  DDRB = 0xff;
  //mcu 방식
  DDRC = 0x00; // 입력포트 설정
  PORTD = 0xff; // 풀업저항 활성화
  //arduino 방식
  // pinMode(14, INPUT_PULLUP);
  // pinMode(15, INPUT_PULLUP);
  // pinMode(16, INPUT_PULLUP);
  // pinMode(17, INPUT_PULLUP);
  // pinMode(18, INPUT_PULLUP);
  // pinMode(19, INPUT_PULLUP);


Serial.begin(9600);

attachInterrupt(0, key_irq, CHANGE);
attachInterrupt(1, key_irq_1, FALLING);
}
void key_irq(){
  // 상승 = sw0
  Serial.println("RISING");
}
void key_irq_1(){
  // 하강 = sw1
  Serial.println("FALLING");
}



void loop() {
  // put your main code here, to run repeatedly:
  /*delay(1);
  t_loop++;
  if(t_loop > 300){ 
    t_loop = 0;
    cnt++;
    //if(tg_flag == 0)  tg_flag = 1;
    //else tg_flag = 0;
    (tg_flag = 0) ? tg_flag = 1 : tg_flag = 0;
  }
  fnd_time(time.hour, time.min, time.sec);
 //fnd_dis(cnt);
  */
  /*
  delay(1);
  time.time_loop++;
  if(time.time_loop >= 1000){
      time.time_loop = 0;
      time.sec++;

      (tg_flag == 0) ? tg_flag = 1 : tg_flag = 0; // sec
      (tg_flag2 == 0) ? tg_flag2 = 1 : tg_flag2 = 1; // hour.min 

      if(time.sec > 59){
        time.sec = 0;
        time.min++;
        if(time.min > 59) {// 1hour chk sum{
          time.min = 0;
          time.hour++;
          if(time.hour > 23) time.hour = 0;
      }
    }
  }
  fnd_time(time.hour, time.min, time.sec);
  */
  /*
  #ifdef bit_key
    key_buf = key_bit_in)();
  #endif
  
  #ifdef byte_key  
    key_buf = key_byte_in();
  #endif
  */
  key_buf = key_rd();
  if(flag.key_flag == 1) key_chk();
  
  if(flag.run_flag == 1){
    
    switch(mode_cnt){
      case 1 : up_cnt(); break;
      case 2 : dn_cnt(); break;
    //   case 3 : env_cnt(); break;
    //   case 4 : odd_cnt(); break;
    //   case 5 : mul(); break;
    }
  
  delay(1);
  }
}
