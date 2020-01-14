#define LEG1 3
#define LEG2 GND
#define LEG3 5
#define LEG4 6
#define button 4

int input;
int R,G,B;
int storage[3];
int intSize=3;
boolean pressed;

void setup() {
  Serial.begin(9600);
  pinMode(LEG1,OUTPUT);
  pinMode(LEG3,OUTPUT);
  pinMode(LEG4,OUTPUT);
 randomSeed(analogRead(A0));
}

//Reads a string and saves it in the input string
//**Add an exception for wrongly written input
void readNumbers(){
    for(int i=0;intSize>=i;i++){
      storage[i]=Serial.parseInt();
    }
}

void setLED(){
  analogWrite(LEG1,storage[0]);
  Serial.println(storage[0]);
  analogWrite(LEG3,storage[1]);
  analogWrite(LEG4,storage[2]);
}

void partySet(){

  int valA=random(0,255);
  analogWrite(LEG1,valA);
  valA=random(0,255);
  Serial.println(valA);
  analogWrite(LEG3,valA);
  valA=random(0,255);
  Serial.println(valA);
  analogWrite(LEG4,valA);
  Serial.println(valA);
}

void partyMode(){
  partySet();
  delay(random(0,200));
}

void digitalPress(){
  if(Serial.available()>0){
  partySet();
  Serial.read();
  }
}


void buttonPress(){
  while(button){
  }
  partySet();
}

void loop() {
/* if(Serial.available()>0){
  readNumbers();
  setLED(); 
  }
  */
 digitalPress();
}
