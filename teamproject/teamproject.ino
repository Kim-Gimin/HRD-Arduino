#include "my_arduino_lib.h"
unsigned char cnt = 0;
unsigned char dp = 0b00000001; //   0x01;
char flag = 0;

unsigned char d1[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char d2[6] = {0x81, 0x42, 0x24, 0x18};
int ad_buf1, ad_buf2;

const int BUZZER = 10;
const int trigPin = 11;
const int echoPin = 12;
const int melody[8] = {262, 294, 330, 349, 393, 440, 494, 523};

void setup(){
Serial.begin(9600);
DDRD = 0xff;
DDRB = 0xff;
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long distance = pulseIn(echoPin, HIGH) / 58;

  Serial.print(distance, DEC);
  Serial.println("CM");

  if(distance <= 10) {
    d_out(LED1, ON); 
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, ON);
    d_out(LED6, ON);
    d_out(LED7, ON);
    d_out(LED8, ON);
    tone(BUZZER, melody[0]);
  }
  else if(distance > 10 && distance <= 15){

    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, ON);
    d_out(LED6, ON);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[2]);
  }
  else if(distance > 15 && distance <= 20){
    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[4]);
  }

  else if(distance > 20 && distance <= 25){
    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, OFF);
    d_out(LED4, OFF);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[6]);
  }

  else if(distance > 25){
    d_out(LED1, OFF);
    d_out(LED2, OFF);
    d_out(LED3, OFF);
    d_out(LED4, OFF);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
  }
  delay(100);
}