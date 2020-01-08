boolean light;
int state;
boolean pressed;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(8,INPUT);
  light=0;
  state=0;
  Serial.begin(9600);
}

//Checks if the button is pressed, and changes state. 0=no light button not pressed, 1=light button not pressed, 2=button pressed
void buttonCheck(){
  if(digitalRead(8)==0 && state==0){
    light=1;
    state=2;
    Serial.println(state);
} else if(digitalRead(8)==0 && state==1){
    state=2;
    light=0;
    Serial.println(state);
  } else if (digitalRead(8)==1 && state==2){
    state=light;
    Serial.println(state);
  }
}

void setLED(){
  digitalWrite(12,light);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(8) == 0) {
    while(digitalRead(8) == 0) {
      
    }
    light = !light;
    
    
  }
  buttonCheck();
  setLED();
}
