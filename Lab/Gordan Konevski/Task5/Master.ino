//SPI MASTER (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST

//Works with Thanas Dushku's code

#include <SPI.h>

#define redLight 0
#define yellowLight 1
#define greenLight 2
#define pressed 1
#define reset 0
#define pRed 4
#define pGreen 5

int RED = 9;
int YELLOW = 8;
int GREEN = 7;
int pRED = 5;
int pGREEN = 4;
int pButton = 2;

int order = 0;
int state = redLight;
int pButtonState = 0;
int statePedestrian = pGreen;
byte Mastersend = 0;   
byte Mastereceive = 0;

void setup (void)
{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), pButtonPressed, RISING);
  
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop (void)
{
  
  if (Mastereceive == 0)
  {
    switch(statePedestrian){
      case pRed:
      digitalWrite(pGREEN, LOW);
      digitalWrite(pRED, HIGH);    
      break;

      case pGreen:
      digitalWrite(pGREEN, HIGH);
      digitalWrite(pRED, LOW);
      break;
    }

    switch(state){
      case redLight:
      digitalWrite(YELLOW,LOW);
      digitalWrite(RED, HIGH);
      delay(20000);    
      order = 0;
      state = yellowLight;
      statePedestrian = pRed;
      break;

      case yellowLight:
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(GREEN, LOW);
      delay(5000);
      if (order == 0)
        state = greenLight;
      else{
          state = redLight;
        statePedestrian = pGreen;
      }

      break;

      case greenLight:
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      delay(10000);
      for(int i = 0; i < 5; i++){
        if(pButtonState == pressed){
          pButtonState = reset;
          state = yellowLight;
          break;
        }
        delay(1000);
      }
      order = 1;
      state = yellowLight;
      statePedestrian = pGreen;
      break;

    }
    
    switch (Mastersend)
      case 1:
        Mastersend = 2
      case 2:
      Mastersend = 0;
    
   digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master                          
   Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
   delay(1000);
  
}

void pButtonPressed(){
  pButtonState = pressed;
}
