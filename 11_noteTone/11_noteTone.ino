

const int BUZZER = 10;
//const int melody[8] = {262,294,330,349,393,440,494,523};
char note[] = "ggaaggeggeed ggaaggegedec";
char beat[] = "11111121111221111112111122";
int note_length = sizeof(note)/sizeof(note[0])-1;
int tempo = 300;
int freq(char note){
  char note_name[] = {'c','d','e','f','g','a','b','c'};
  int note_freq[] = {262,294,330,349,393,440,494,523};
  for(int i = 0; i< sizeof(note_name)/sizeof(note_name[0]); i++){
    if(note_name[i] == note) {
      return note_freq[i];
      }
    }
  }
int duration(char beat){
  return beat - '0';
}
void setup() {
  // put your setup code here, to run once:
//   for(int note = 0; note <= 7; note++){
//     tone(BUZZER, melody[note]);
//     delay(500);
//   }
//   noTone(BUZZER);
// }
for(int i = 0; i < note_length; i++){
  if(note[i] != ' '){
    tone(BUZZER, freq(note[i])); 
  }
  delay(tempo * duration(beat[i]));
  noTone(BUZZER);
  delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
