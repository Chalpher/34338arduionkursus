#include <stdio.h>
void setup() {
  Serial.begin(9600);  

}
//Checks amount of cash in ur wallet
void checkCash(float *ptrWallet){
  if(*ptrWallet<=0){
    Serial.println("You are broke with 42");
  } else{
    Serial.print("Amount of cash in my wallet as DKK:");
    Serial.println(*ptrWallet);
  }
}

//First try to compare just two numbers
void numberCompare(){
  int noNumbers=2;
  int storage[noNumbers];
  int *ptrOne;
  int *ptrTwo;
  Serial.println("Please enter two numbers seperated by a comma:");
  while(!Serial.available()>0){  
  }
  for(int i=0;i>noNumbers;i++){
    storage[i]=Serial.parseInt();  
  }
  ptrOne=&storage[0];
  ptrTwo=&storage[1];
  Serial.print(max(*ptrOne,*ptrTwo));
}


//One function to compare many numbers but this is first draft.
void numberComparelv2(){
  int siz;
  int biggestVal=NULL;
  int *ptrOne;
  Serial.println("Please enter size of array:");
  while(!Serial.available()>0){  
  }
  siz=Serial.parseInt();
  int storage[siz];
  Serial.print("Please enter ");
  Serial.print(siz);
  Serial.println(" numbers seperated by comma");
  while(!Serial.available()>0){  
  }
  for(int i=0;siz>i;i++){
    storage[i]=Serial.parseInt();
  }
  ptrOne=storage;
  for(int i=0;siz>i;i++){
    if(biggestVal<*ptrOne){
      biggestVal=*ptrOne;
    }
    *ptrOne++;
  }
  Serial.println("Hurraay, the biggest value entered was:");
  Serial.println(biggestVal);
  
}

void getArraySize(int *arraySize){
  int limit=sizeof(int);
  int number;
  Serial.println("Hello.");
  Serial.println("Please enter the amount of numbers you want to compare (My limit is:");
  Serial.println(limit);
  while(Serial.available()==0){
    //Wait for user input
  }
  do{
  number=Serial.parseInt();
  if(number<limit){
    break;
  } }while(true);
}



void loop() {
  /*
   * float myDKK;
  float myUSDollars;
  float *ptrWalletCash;  
  ptrWalletCash=&myDKK;
  checkCash(ptrWalletCash);
  //Get in US
  myUSDollars=*ptrWalletCash/6.5;
  Serial.print("In USA I would have USD:");
  Serial.print(myUSDollars);
  */
  numberComparelv2();
}
