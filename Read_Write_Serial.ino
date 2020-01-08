char incomingByte;
void setup() {
  Serial.begin(9600);

}
int readMonitor(){
  if(Serial.available()>0){
   int text;
   text=Serial.read(); 
  }
}

void writeMonitor(int text){
  Serial.println(text, DEC); 
}

void loop() {
  if(Serial.available() >0){
    incomingByte=Serial.read();

      Serial.print("We got:");
      Serial.println(incomingByte);
      
  }
}
