#include <pt.h>   // include protothread library

#define redLight 0
#define yellowLight 1
#define greenLight 2
#define pressed 1
#define reset 0
#define pRed 4
#define pGreen 5

int RED = 10;
int YELLOW = 9;
int GREEN = 8;
int pRED = 5;
int pGREEN = 4;
int pButton = 2;

int order = 0;
int state = redLight;
int pButtonState = 0;
int statePedestrian = pGreen;

static struct pt pt1, pt2; // each protothread needs one of these

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), protothread1, RISING);
  
  /* initialise the two protothread variables */
  PT_INIT(&pt1);  
  PT_INIT(&pt2);
}

static int protothread1(struct pt *ptl) {
  PT_BEGIN(pt);
  pButtonState = pressed;
  PT_END(pt);
  
}

/* exactly the same as the protothread1 function */
static int protothread2(struct pt *pt2) {
  PT_BEGIN(pt);
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
  PT_END(pt);
}

void loop()
{
  protothread1(&pt1); // schedule the two protothreads
  protothread2(&pt2); // by calling them infinitely
}
