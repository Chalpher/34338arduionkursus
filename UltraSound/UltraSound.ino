#include <LiquidCrystal_I2C.h>

#define trigPin 3
#define echoPin 4
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.begin();
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin,LOW);

}

void sendData(){
  float transmitTime=0.01;
  digitalWrite(trigPin,HIGH);
  delay(transmitTime);
  digitalWrite(trigPin,LOW);
}


void loop() {
  sendData();
  int theSpeed=340;
  int highLevelTime=pulseIn(echoPin,HIGH);
  //From the datasheet we see that the formula is the time of the received signal/58.
  lcd.clear();
  lcd.print("distance: ");
  lcd.print(highLevelTime/58);
  delay(300);
}
