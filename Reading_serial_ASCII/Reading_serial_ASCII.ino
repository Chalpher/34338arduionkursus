#define LEG1 3
#define LEG2 GND
#define LEG3 5
#define LEG4 6

int input;
int R,G,B;
int storage[3];
int intSize=3;

void setup() {
  Serial.begin(9600);
  pinMode(LEG1,OUTPUT);
  pinMode(LEG3,OUTPUT);
  pinMode(LEG4,OUTPUT);
 
}

//Reads a string and saves it in the input string
//**Add an exception for wrongly written input
void readNumbers(){
    for(int i=0;intSize>=i;i++){
      storage[i]=Serial.parseInt();
    }
}

void setLED(){
  digitalWrite(LEG1,storage[0]);
  digitalWrite(LEG3,storage[1]);
  digitalWrite(LEG4,storage[2]);
}



void loop() {
  if(Serial.available()>0){
  readNumbers();
  setLED(); 
  }
}
