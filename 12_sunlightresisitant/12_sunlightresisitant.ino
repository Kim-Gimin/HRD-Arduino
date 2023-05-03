#define cds 10

int ad_buf;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0xff;
  pinMode(cds, INPUT);
  Serial.begin(9600);
}

void loop() {

  ad_buf = analogRead(cds);
  Serial.println(ad_buf, DEC);
  delay(300);
  // put your main code here, to run repeatedly:

}
