#include<pt.h>

#define R_light 0
#define Y_light 1
#define G_light 2
#define RY_light 3
#define pRed 4
#define pGreen 5
#define pressed 1

  int GREEN = 8;
  int YELLOW = 9;
  int RED = 7;
  int pRED = 2;
  int pGREEN = 4;
  int pBUTTON = 3;

  int stateTraffic = R_light;
  int statePedestrian = pGREEN;	
  int pButtonstate = 0;
  int order = 0;
  byte MasterSend = 0;
  byte MasterReceive = 0;

void setup(void)
{
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pBUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(pBUTTON), pButtonpressed, RISING);
  
  SPI.beegin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS,HIGH);
}

  void loop (void)
  {
    if(MasteReceive == 0)
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

   switch(state){
    case R_light:
     digitalWrite(YELLOW, LOW);
     digitalWrite(RED, HIGH);
     delay(20000);
     order = 0;
     state = Y_light;
     statePedestrian = pRed;
   break;
        
    case RY_light:
      digitalWrite(YELLOW, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
     delay(5000);
   if (order == 0)
     state = G_light;
   else{
     state = R_light;
     statePedestrian = pGreen;
   }
   break;
    case G_light:
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      delay(10000);
   for(int i = 0; i < 5; i++){
    if(pButtonstate == pressed){
       pButtonstate = reset;
       state = Y_light;
    break;
     }
     delay(1000);
   }
     order = 1;
     state = Y_light;
     statePedestrian = pGreen;
   break;
    }
   switch (MasterSend)
      case 1:
    	MasterSend = 2;
      case 2:
    	MasterSend = 0;
      default:
    	MasterSend = 1;
   digitalWrite(SS, LOW);
    MasterReceive=SPI.transfer(MasterSend)
      delay(1000);
  }
   void pButtonpressed(){
     pButtonstate = pressed;
    }