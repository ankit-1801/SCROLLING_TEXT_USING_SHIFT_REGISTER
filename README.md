//# SCROLLING_TEXT_USING_SHIFT_REGISTER
//1.Scrolling text on 8x8 LED matrix using shift register(74HC595)....

#define DATA 2
#define SHIFT 3
#define STORE 4
unsigned long previousMillis = 0;
const long SCROLLspeed = 500;


int pic[] = {0,0,0,0,0,0,
                 255,24,24,255,0,    //H
                 255,153,153,129,0,  //E
                 255,1,1,1,0,        //L
                 255,1,1,1,0,        //L
                 126,129,129,126,0,  //O
                 108,98,2,98,108,    //smiley
             0,0,0,0,0,0};   
int arraysize = 42;


/*int pic[] = {0,0,B11111110,
                 B00100000,
                 B00010000, //  N 
                 B00001000,
                 B11111110,
                 0,0
                 };   */
void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(SHIFT, OUTPUT);
  pinMode(STORE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  picture(pic);
  }

void store() {
  digitalWrite(STORE, HIGH);
  delayMicroseconds(10);
  digitalWrite(STORE, LOW);
  delayMicroseconds(10);
}

void picture(int b[])
{
int i,j,k;
  delay(5);
 for( j=0;j<arraysize-8;j++) 
 {
 
 while(1) 
 { unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= SCROLLspeed) {
    previousMillis = currentMillis;
    break;
  }
    
    for ( i=0;i<8;i++) {
    shiftOut(DATA, SHIFT, LSBFIRST, ~b[j+i]);
    shiftOut(DATA, SHIFT, LSBFIRST, 128>> i);
    store();
    }
 }
 }

  
  }
