#include "My_Aduino_LIB.h"

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xff;

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("song");


  for(int i = 0; i <= 9999; i++){
    
    
    //Serial.println(i);
    
    Serial.write(i/1000 + 0x30);
    Serial.write(i%1000/100 + '0');
    Serial.write(i%100/10 + 0x30);
    Serial.write(i%10 + '0');
    Serial.write('\n');
    Serial.write('\007');
    delay(20);
    //if(i >= 100) break;
  }
    
}
