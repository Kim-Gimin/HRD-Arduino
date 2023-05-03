#ifndef __My_Aduino_LIB__
#define __My_Aduino_LIB__


#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7

#define bit_set(ADDRESS, BIT) (ADDRESS |= (1<<BIT))
#define bit_clr(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT))
#define bit_chk(ADDRESS, BIT) (ADDRESS & (1<<BIT))
#define bit_tg(PORT, BIT) (PORT ^= (1<<BIT))

#define d_out(pin, value) digitalWrite(pin,value)


#define ON 1
#define OFF 0

#define _ON 0
#define _OFF 1



void byte_out(unsigned char data){
  
  d_out(LED1, data%2);
  d_out(LED2, data/2%2);
  d_out(LED3, data/4%2);
  d_out(LED4, data/8%2);
  d_out(LED5, data/16%2);
  d_out(LED6, data/32%2);
  d_out(LED7, data/64%2);
  d_out(LED8, data/128%2);
}

#endif

