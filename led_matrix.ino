#define DATA 2
#define SHIFT 3
#define STORE 4
unsigned long previousMillis = 0;
const long interval = 600;          //time for one character...
 


int pic1[] = {0,0,255,24,24,255,0,0};          // H
int pic2[] = {60,66,169,133,133,169,66,60};    // smiley
  
void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(SHIFT, OUTPUT);
  pinMode(STORE, OUTPUT);
}

void loop() {
 picture(pic1);
 picture(pic2);
}
void picture(int b[])
{
   while(1) 
 { unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    break;
  }
    for (int i=0; i<8; i++) {
    shiftOut(DATA, SHIFT, LSBFIRST, ~b[i]);
    shiftOut(DATA, SHIFT, LSBFIRST, 128 >> i);
    store();
    }
  
 } 
 delay(1);

  
  }
void store() {
  digitalWrite(STORE, HIGH);
  delayMicroseconds(10);
  digitalWrite(STORE, LOW);
  delayMicroseconds(10);
}
