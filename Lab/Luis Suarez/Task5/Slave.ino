//Slave Arduino Code:
//SPI SLAVE (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST
//Pramoth.T

// Works with Gordan Konevski's code

#include <SPI.h>

#define redLight 0
#define yellowLight 1
#define greenLight 2
#define redYellowLight 3
#define pressed 1
#define reset 0
#define pRed 4
#define pGreen 5

int Red = 13;
int Yellow = 12;
int Green = 11;
int pRED = 10;
int pGREEN = 9;
int Button = 2;

int state = 0;
int ButtonState = 0;
int pedestrian = pGreen;
volatile byte Slavereceived,Slavesend;

void setup()
{
  
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), ButtonPressed, RISING)

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
}

void loop()
{ 
    if (Slavereceived == 2) 
     {
		 switch(pedestrian){
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
		    digitalWrite(Yellow,LOW);
		    digitalWrite(Red, HIGH);
		    pedestrian = pGreen;
		    delay(20000);
		    state = yellowLight;

		    break;

		    case yellowLight:
		    digitalWrite(Red, LOW);
		    digitalWrite(Yellow, HIGH);
		    delay(5000);
		    state = greenLight;
		    pedestrian = pRed;
		    break;

		    case greenLight:
		    digitalWrite(Yellow, LOW);
		    digitalWrite(Green, HIGH);
		    delay(10000);
		    for(int i = 0; i < 5; i++){
		      if(ButtonState == pressed){
			ButtonState = reset;
		       break;
		      }
		      delay(1000);
		    }
		    state = redYellowLight;
		    break;

		    case redYellowLight:
		    digitalWrite(Green, LOW);
		    digitalWrite(Red, HIGH);
		    digitalWrite(Yellow, HIGH);
		    delay(5000);
		    state = redLight;
		    pedestrian = pGreen;
		    break;

	  }
	}
    
    if (Slavesend == 1)
      Slavesend = 2;
    else
      Slavesend = 0;
                            
    SPDR = Slavesend;                           //Sends the x value to master via SPDR 
    delay(1000);
}


void pButtonPressed(){
  pButtonState = pressed;
  Serial.println("pedestrian button pressed");
}
