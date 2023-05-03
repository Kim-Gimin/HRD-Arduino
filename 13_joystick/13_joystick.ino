#define jx    A0
#define jy    A1
#define j_sw  8
#define ry    9

int ad_buf;


void setup() {
  // put your setup code here, to run once:
  pinMode(j_sw, INPUT_PULLUP);
  pinMode(ry, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(j_sw) == 0) digitalWrite(ry, 1);
  else digitalWrite(ry, 0);
  // put your main code here, to run repeatedly:

}
