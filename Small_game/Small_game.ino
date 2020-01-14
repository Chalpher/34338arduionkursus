#include <LiquidCrystal_I2C.h>

#include <stdlib.h>

#define button 7
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12
int ledArray[]={LED1,LED2,LED3,LED4,LED5};
int targetPos=2;
int state=0;
int lastState=0;
int newTime=0;
int lastTime=0;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  for(int i=0;sizeof(ledArray)/sizeof(int)>i;i++){
    pinMode(ledArray[i],OUTPUT);
    digitalWrite(ledArray[i],LOW);  
  }
}

void nextLED(int level, int *currentLED){
  int nextLED; 
  if(level<8){
    *currentLED=(*currentLED+1)%5;
  }else{
    do{
      nextLED=random(0,5);
    } while(*currentLED==nextLED);
    *currentLED=nextLED;
  }
  setLED(0,0,0,0,0);
  digitalWrite(ledArray[*currentLED],1);
}




void setLED(int first, int second, int third, int fourth, int fifth){
  digitalWrite(ledArray[0], first);
  digitalWrite(ledArray[1], second);
  digitalWrite(ledArray[2], third);
  digitalWrite(ledArray[3], fourth);
  digitalWrite(ledArray[4], fifth);
}

void succes(int level){
  setLED(0,0,0,0,0);  
  for(int i=0;5>i;i++){
    digitalWrite(ledArray[targetPos],1);
    delay(100);
    digitalWrite(ledArray[targetPos],0);
    delay(100);
  }
}

//What if button is released
void buttonPress(int *currentLED, int *level){
  state=digitalRead(button);
  if(0==state && lastState==1){
    if(*currentLED==targetPos){
      succes(*level);
      (*level)++;
    } else {
      fail();
      if(*level>0){
        (*level)--;  
      }
    }
  }
  lastState=state;
}

void fail(){
  setLED(0,0,0,0,0);
  for(int i=0;5>i;i++){
    setLED(1,1,0,1,1);
    delay(100);
    setLED(0,0,0,0,0);
    delay(100);
  }  
}

void gameLoop(){
  static int currentLED=0;
  static int level=0;
  newTime=millis();
  if(newTime>lastTime+1000-level*100){
    nextLED(level, &currentLED); 
    lastTime=newTime; 
    lcd.clear();
    lcd.print("Level:");
    lcd.print(level);
  }
  buttonPress(&currentLED, &level);
  if(level>9){
    lcd.clear();
    lcd.print("YOU WIN!");    
  }
}

void loop() {
  gameLoop();  

}
