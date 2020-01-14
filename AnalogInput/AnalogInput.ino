#define LED1 3
#define LED2 5
#define LED3 6

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float volt;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(A0, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}


void readInput(){
  sensorValue = analogRead(sensorPin);  
  Serial.println(sensorValue);
}

//Converts the meassured value to voltage 
void convertToVoltage(){
  float dive=1023;
  volt=5*sensorValue/dive;
}

void setLED(int b, int g, int r){
  analogWrite(LED1,b);
  analogWrite(LED2,g);
  analogWrite(LED3,r);
}

//Turns on the LEDS depending on the voltage 
void ledControl(){
  if(sensorValue>=0 && sensorValue<=255){
    setLED(sensorValue,0,0);
  }else if(sensorValue>=256 && sensorValue<=511){
    setLED(0,sensorValue-256,0);
  }else if(sensorValue>=512 && sensorValue<=767){
    setLED(0,0,sensorValue-512);
  }else if(sensorValue>=768 && sensorValue<=1023){
    setLED(sensorValue-768,sensorValue-768,sensorValue-768);
  }
}

void loop() {
  readInput();
  convertToVoltage();
  Serial.println(volt,3);
  ledControl();
  delay(1000);
}
