/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
 const unsigned int dotTime=500;
 const unsigned int dashTime=2000;
 const unsigned int spaceTime=500;
 const unsigned int newLetter=2000;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

//Funktion som tager antallet af dashes der ønskes og blinker LED tilsvarende til dette og skriver til serial monitor
void dash(int dashes){
  for(int i=0;dashes>i;i++){
    digitalWrite(13, HIGH);           
    Serial.print("-");
    delay(dashTime);                       
    digitalWrite(13, LOW); 
    delay(spaceTime);   
  }
}


//Funktion som tager antallet af prikker der ønskes og blinker LED tilsvarende til dette og skriver til serial monitor
void dot(int dots){
  for(int i=0;dots>i;i++){
    digitalWrite(13, HIGH);           
    Serial.print(".");
    delay(dotTime);                       
    digitalWrite(13, LOW); 
    delay(spaceTime);   
  }
}
//Funktion som tager et bogstav og skriver det som morsekode, vist ved blink på LED og skrives også i serial monitor
void chooseLetter(char letter){
  switch(letter){

    case 'A':
    Serial.print("\n A");
    dot(1);
    dash(1);
    delay(newLetter);
    break;

    case 'B':
    Serial.print("\n B");
    dash(1);
    dot(3);
    delay(newLetter);
    break;

    case 'C':
    Serial.print("\n C");
    dash(1);
    dot(1);
    dash(1);
    dot(1);
    delay(newLetter);
    break;

    case 'D':
    Serial.print("\n D");
    dash(1);
    dot(2);
    delay(newLetter);
    break;

    case 'E':
    Serial.print("\n E");
    dot(1);
    delay(newLetter);
    break;

    case 'F':
    Serial.print("\n F");
    dot(2);
    dash(1);
    dot(1);
    break;

    case 'G':
    Serial.print("\n G");
    dash(2);
    dot(1);
    delay(newLetter);
    break;

    case 'H':
    Serial.print("\n H");
    dot(4);
    delay(newLetter);
    break;

    case 'I':
    Serial.print("\n I");
    dot(2);
    delay(newLetter);
    break;

    case 'J':
    Serial.print("\n J");
    dot(1);
    dash(3);
    break;

    case 'K':
    Serial.print("\n K");
    dash(1);
    dot(1);
    dash(1);
    delay(newLetter);
    break;

    case 'L':
    Serial.print("\n L");
    dot(1);
    dash(1);
    dot(2);
    delay(newLetter);
    break;

    case 'M':
    Serial.print("\n M");
    dash(2);
    delay(newLetter);
    break;

    case 'N':
    Serial.print("\n N");
    dash(1);
    dot(1);

    case 'O':
    Serial.print("\n O");
    dash(3);
    delay(newLetter);
    break;

    case 'P':
    Serial.print("\n P");
    dot(1);
    dash(2);
    dot(1);
    delay(newLetter);
    break;
    
    case 'Q':
    Serial.print("\n Q");
    dash(2);
    dot(1);
    dash(1);
    delay(newLetter);
    break;

    case 'R':
    Serial.print("\n R");
    dot(1);
    dash(1);
    dot(1);
    delay(newLetter);
    break;

    case 'S':
    Serial.print("\n S");
    dot(3);
    delay(newLetter);
    break;

    case 'T':
    Serial.print("\n T");
    dash(1);
    delay(newLetter);
    break;

    case 'U':
    Serial.print("\n U");
    dot(2);
    dash(1);
    delay(newLetter);
    break;

    case 'V':
    Serial.print("\n V");
    dot(3);
    dash(1);

    case 'W':
    Serial.print("\n W");
    dot(1);
    dash(2);
    delay(newLetter);
    break;

    case 'X':
    Serial.print("\n X");
    dash(1);
    dot(2);
    dash(1);
    delay(newLetter);
    break;

    case 'Y':
    Serial.print("\n Y");
    dash(1);
    dot(1);
    dash(2);
    delay(newLetter);
    break;

    case 'Z':
    Serial.print("\n Z");
    dash(2);
    dot(2);
    delay(newLetter);
    break;
    
  }  
}


void writeMorse(String text){
  for(int i=0; text.length()>i;i++){
    chooseLetter(text[i]);
  }
  
}

// the loop function runs over and over again forever
void loop() {
  String text;
  if(Serial.available()){
    text=Serial.readStringUntil('\n');
    writeMorse(text);
  }
  
  //writeMorse("FREDERIK");

  
  /*
  chooseLetter('F');
  chooseLetter('R');
  chooseLetter('E');
  chooseLetter('D');
  chooseLetter('E');
  chooseLetter('R');
  chooseLetter('I');
  chooseLetter('K');
  */
  /*
  Serial.print("T");
  digitalWrite(13, HIGH);                //Letter T
  Serial.println("-");
  delay(dashTime);                       // Create dot
  digitalWrite(13, LOW); 
  delay(newLetter);                       // Create space

  Serial.print("J");
  digitalWrite(13, HIGH);                 //Letter J
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime);    
  digitalWrite(13, HIGH);                 
  Serial.print("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);                 
  Serial.print("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime);  
  digitalWrite(13, HIGH);                 
  Serial.println("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(newLetter);                    

  Serial.print("A");
  digitalWrite(13, HIGH);     //A               
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);               
  Serial.println("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(newLetter); 

  Serial.print("L");
  digitalWrite(13, HIGH);     //L              
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime);
  digitalWrite(13, HIGH);               
  Serial.print("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);               
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime);  
  digitalWrite(13, HIGH);               
  Serial.println(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(newLetter); 

  Serial.print("F");
  digitalWrite(13, HIGH);    //F           
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);               
  Serial.print(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);               
  Serial.print("-");
  delay(dashTime);                       
  digitalWrite(13, LOW);    
  delay(spaceTime); 
  digitalWrite(13, HIGH);               
  Serial.println(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(newLetter); 

  Serial.print("E");
  digitalWrite(13, HIGH);   //E              
  Serial.println(".");
  delay(dotTime);                       
  digitalWrite(13, LOW);    
  delay(newLetter); 
  */
}
