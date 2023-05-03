/*
 * my_fnd.h
 *
 *  Created on: Oct 27, 2022
 *      Author: tj-bu
 */


#ifndef INC_MY_FND_LIB_H_
#define INC_MY_FND_LIB_H_

#include "stm32l1xx_hal.h"
#include "main.h"
#include "my_gpio_lib_v3_2.h"

const unsigned char fnd_font[] =
{
   // 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   H,   L,   E,   o,   P,  F,
   0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x76,0x38,0x79,0x5c,0x73,0x71,
   // C,    d,    A,    u,    T,    r,   b,  blk
   0x39, 0x5e, 0x77, 0x1c, 0x44, 0x50, 0x7c, 0x00
};

// fnd maseg display
#define O   0x0d   //o display
#define F   0x0f    // F display
#define H   0x0a    // H   "
#define L   0x0b    // L   "
#define E   0x0c    // E   "
#define P   0x0e    // P   "
#define C   0x10    // C   "
#define D   0x11    // d   "
#define A   0x12    // A   "
#define U   0x13    // u   "
#define T   0x14    // t   "
#define R   0x15    // r   "
#define b   0x16    // b   "
#define BLK 0x00   // fnd blk display

int8_t scan = 0;

void fnd_dis(uint16_t d_buf)
{
  scan++;
  if(scan > 4) scan = 1;

  switch(scan)
  {
   case 1: // x1000
	      Out_Bit(X_1_GPIO_Port, X_1_Pin, 0); //fnd off
	      PortB_out_L(~fnd_font[d_buf/1000]);
	      Out_Bit(X_1000_GPIO_Port, X_1000_Pin, 1); //fnd off
	   break;

   case 2: // x100 자리
	       Out_Bit(X_1000_GPIO_Port, X_1000_Pin, 0); //fnd off
	   	   PortB_out_L(~fnd_font[d_buf%1000/100]);
	   	   Out_Bit(X_100_GPIO_Port, X_100_Pin, 1); //fnd off
       break;

   case 3: // x10자리
	      Out_Bit(X_100_GPIO_Port, X_100_Pin, 0); //fnd off
	  	  PortB_out_L(~fnd_font[d_buf%100/10]);
	  	  Out_Bit(X_10_GPIO_Port, X_10_Pin, 1); //fnd off
       break;

   case 4: // x1
	      Out_Bit(X_10_GPIO_Port, X_10_Pin, 0); //fnd off
	   	  PortB_out_L(~fnd_font[d_buf%10]);
	   	  Out_Bit(X_1_GPIO_Port, X_1_Pin, 1); //fnd off
      break;
  }
}




#endif /* INC_MY_FND_LIB_H_ */
