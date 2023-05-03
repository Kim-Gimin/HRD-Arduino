
#ifndef __My_motor_LIB__
#define __My_motor_LIB__

//define
#define M1_pin  8
#define M2_pin  9
#define EN_pin  10

#define FAN1_pin 11
#define FAN2_pin 12


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

#endif