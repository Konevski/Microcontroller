#define redLight 0
#define yellowLight 1
#define greenLight 2
#define pressed 1
#define reset 0

int RED = 10;
int YELLOW = 9;
int GREEN = 8;
int pRED = 5;
int pGREEN = 4;
int pButton = 2;

int order = 0;
int state = redLight;
int pButtonState = 0;


void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), pButtonPressed, RISING);
}

void loop()
{
  switch(state){
    case redLight:
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(pRED, LOW);
    digitalWrite(pGREEN, HIGH);
    delay(20000);    
    order = 0;
    state = yellowLight;
    break;
    
    case yellowLight:
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(pGREEN, LOW);
    digitalWrite(pRED, HIGH);
    delay(5000);
    if (order == 0)
    	state = greenLight;
    else
      	state = redLight;
    
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
    break;
    
  }
}


void pButtonPressed(){
  pButtonState = pressed;
}

// WHAT IS YOUR PROBLEM GREEN? GREEN WHAT IS OUR PROBLEM? PUTA!
