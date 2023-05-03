


#include "my_Arduino_lib.h"

char run_flag = 0;
#include "my_motor_lib.h"


unsigned char rx_buf[20];
char rx_cnt = 0;
char rx_end_flag = 0;
#include "uart.c"




void com_chk()
{
  rx_end_flag = 0;
   

  switch(rx_buf[0])
   {
     case '1': m_ccw(); tx_send('k'); break;
     case '2': m_stop(); tx_send('y');break;
   }
}

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xf2;
  DDRB = 0xff;

  // all int en
  SREG |= 0x80;
   uart_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(rx_end_flag == 1) com_chk();
  

 /*
  _delay_ms(200);  // 컴파일러 에서 제공하는 delay 함수 = 잘 동작 함 = 직접코딩 함
  tx("song\n\r");
 // tx_send('\007');
  tx_send('a');
  _delay_ms(200);
  */
   
}

// UART int 
ISR(USART_RX_vect)
{
  unsigned char buf;
  buf = UDR0;
  tx_send(buf);

  if(buf == '\n')
  {
    rx_cnt = 0;
    rx_end_flag = 1;
  }
  else
   {
     rx_buf[rx_cnt] = buf;
     rx_cnt++;
   }
}
