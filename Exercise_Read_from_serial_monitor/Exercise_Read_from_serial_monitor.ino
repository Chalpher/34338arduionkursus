#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 0
#define LED8 1

char letter;
String number;

void setup() {
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT); 
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(7,OUTPUT);
}

void readLetter(){
  letter=Serial.read();
}

void setLED(int l1, int l2, int l3, int l4, int l5){
  digitalWrite(LED1,l1);
  digitalWrite(LED2,l2);
  digitalWrite(LED3,l3);
  digitalWrite(LED4,l4);
  digitalWrite(LED5,l5);
}

void ledControl(){
  switch(letter){

    case 'a':
    setLED(1,1,1,1,1);
    break;

    case 'b':
    setLED(1,1,1,1,1);
    break;

    case 'c':
    setLED(1,1,1,1,1);
    break;

    case 'd':
    setLED(1,1,1,1,1);
    break;

    case 'e':
    setLED(1,1,1,1,1);
    break;
    
    default:
    setLED(0,0,0,0,0);
    break;
  } 
}
/*
void convertDecToBinary(){
  int valA=number;
  int valB;
  int[2] binaryNumber;
  while(ValA>0){
    valB=valA%2;
    if(valB==1)
  }
}
*/

void readNumber(){
  number=Serial.readStringUntil('\n');
}

void numberLightShow(){
  int cNumber=number.toInt()*4;
  PORTD=cNumber;  
}

void loop() {
  if(Serial.available()>0){
    //readLetter();
    //ledControl(); 
    readNumber(); 
    numberLightShow();
    
  }

}
