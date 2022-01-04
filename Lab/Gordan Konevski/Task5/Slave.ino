
//Slave Arduino Code:
//SPI SLAVE (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST
//Pramoth.T

#include <SPI.h>

#define redLight 0
#define redYellowLight 1
#define greenLight 2
#define yellowLight 3
#define pRed 4
#define pGreen 5

#define pressed 1
#define reset 0

int RED = 9;
int YELLOW = 8;
int GREEN = 7;
int pRED = 5;
int pGREEN = 4;
int pButton = 2;

int stateTraffic = redLight;
int statePedestrian = pGreen;
int pButtonState = 0;
volatile byte Slavereceived,Slavesend;

void setup()
{
  
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), pButtonPressed, RISING);

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
}

void loop()
{ 
    if (Slavereceived == 1) 
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

		switch(stateTraffic){
		  case redLight:
		  digitalWrite(YELLOW,LOW);
		  digitalWrite(RED, HIGH);
		  delay(20000);
		  stateTraffic = redYellowLight;
		  statePedestrian = pRed;
		  break;

		  case redYellowLight:
		  digitalWrite(YELLOW, HIGH);
		  delay(5000);
		  stateTraffic = greenLight;
		  break;

		  case greenLight:
		  digitalWrite(RED, LOW);
		  digitalWrite(YELLOW, LOW);
		  digitalWrite(GREEN, HIGH);
		  delay(10000);
		  for(int i = 0; i < 10; i++){
			if(pButtonState == pressed){
			  pButtonState = reset;
			  Serial.println("button reset");
			  stateTraffic = yellowLight;
			  break;
			}
			delay(1000);
		  }
		  stateTraffic = yellowLight;
		  break;

		  case yellowLight:
		  digitalWrite(YELLOW, HIGH);
		  digitalWrite(GREEN, LOW);
		  delay(5000);
		  stateTraffic = redLight;
		  statePedestrian = pGreen;
		  break;
		}	 
	}
    
    if (Slavesend == 1)
      Slavesend = 0;
    else
      Slavesend = 1;
                            
    SPDR = Slavesend;                           //Sends the x value to master via SPDR 
    delay(1000);
}


void pButtonPressed(){
  pButtonState = pressed;
  Serial.println("pedestrian button pressed");
}
