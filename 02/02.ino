#include "My_Aduino_LIB.h"

unsigned char cnt = 0;
unsigned char dp = 0b00000001; // 0x01;
// #define ON 1
// #define OFF 0

// #define _ON 0
// #define _OFF 1


// // //사용병
// // d_out(LED1, ON);
// // bit_set(PORTD, 5);
// // bit_clr(PORTD, 3);
// // if(bit_chk(PIND, 3) == 0){}
// // bit_tg(PORTD, 0);
// // delay(400);
// unsigned char cnt = 0;
unsigned char flag = 0;
unsigned char d1[] = {0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char d2[6] = {0x81,0x42,0x24,0x18};
void setup() {
  //pinMode(LED1, OUTPUT);
  //pinMode(LED2, OUTPUT);
  //digitalWrite(LED1, ON);//HIGH, 1
  // put your setup code here, to run once:
  DDRD = 0xff;
  //PORTD = 0xff;
  
}



void loop() {
//1번부터 8번 와리가리
  PORTD = dp;
  dp <<= 1;
  delay(50);

  if(dp == 0b00000000){
    for(dp = 0b10000000; dp>=0; dp >>= 1){
      PORTD = dp;
      delay(200);

      if(dp == 0b00000001)
        break;
    }
  }
}

  // 양방향 반복
//   for(int i = 0; i <= 3; i++){
//     PORTD = d2[i];
//     delay(200);
//   }
//   for(int i = 3; i >= 0; i--){
//     PORTD = d2[i];
//     delay(200);
//   }
//   delay(200);
// }





//   // put your main code here, to run repeatedly:
  // for(cnt = 0; cnt <= 255; cnt++){
  //   PORTD = cnt;
    // byte_out(cnt);
    // digitalWrite(LED8, 1);
    // delay(200);
    // digitalWrite(LED8, OFF);
//     delay(200);
//     }
//   exit(0);





