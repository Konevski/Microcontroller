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

void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pButton, INPUT); 
  attachInterrupt(digitalPinToInterrupt(pButton), ButtonPressed, RISING)
 ;
}

void loop()
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
        state = yellowLight;
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
void ButtonPressed(){
  ButtonState = pressed;
}

// and happy ending for the pedestrian
