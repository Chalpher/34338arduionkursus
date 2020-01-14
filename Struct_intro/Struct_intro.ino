float usToDKK=6.5;

typedef struct Wallet{
  float DKK;
  float USD;
} wallet_t ;

void initWallet(wallet_t myWallet){
  myWallet.DKK=100;
  myWallet.USD=0;
}

void setup() {
  Serial.begin(9600);  

}

void loop() {
  float usDollars;
  wallet_t redWallet;
  initWallet(redWallet);
  usDollars=redWallet.DKK/usToDKK; //Calculate usd from DKK in wallet
  redWallet.USD=usDollars;
  Serial.print("My money in DKK:");
  Serial.print(redWallet.DKK);
  Serial.print("My money in DKK:");
  Serial.print(redWallet.USD);
    
}
