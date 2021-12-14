#define redLight 0
#define yellowLight 1
#define greenLight 2
#define redYellowLight 3
#define pressed 1
#define reset 0
#include<pt.h>
int Red = 12;
int Yellow = 11;
int Green = 10;
int pRED = 9;
int pGREEN = 8;
int pButton = 2;

int state = 0;
int ButtonState = 0;
static struct pt pt1, pt2;



void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), ButtonPressed, RISING)
PT_INIT(&pt1);  
  PT_INIT(&pt2);
 ;
}


  static int protothread1(struct pt *ptl) {
PT_BEGIN(pt);
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
PT_END(pt);
  }
  static int protothread2(struct pt *pt2) {
  PT_BEGIN(pt);
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
  PT_END(pt);  
  }

void loop()
{
  protothread1(&pt1);
  protothread2(&pt2); 
}
void ButtonPressed(){
  ButtonState = pressed;

}


// and happy ending for the pedestrian
