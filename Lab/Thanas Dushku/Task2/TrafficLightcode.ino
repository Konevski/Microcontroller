#define redLight 0
#define redYellowLight 1
#define greenLight 2
#define yellowLight 3

#define pressed 1
#define reset 0

int RED = 10;
int YELLOW = 9;
int GREEN = 8;
int pRED = 5;
int pGREEN = 4;
int pButton = 2;

int state = 0;
int pButtonState = 0;

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
}

void loop()
{
  switch(state){
    case redLight:
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(pGREEN, HIGH);
    digitalWrite(pRED, LOW);
    delay(20000);
    state = redYellowLight;
    break;

    case redYellowLight:
    digitalWrite(YELLOW, HIGH);
    digitalWrite(pGREEN, LOW);
    digitalWrite(pRED, HIGH);
    delay(5000);
    state = greenLight;
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
        state = yellowLight;
        break;
      }
      delay(1000);
    }
    state = yellowLight;
    break;
    
    case yellowLight:
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    delay(5000);
    state = redLight;
    break;
    
  }
}

void pButtonPressed(){
  pButtonState = pressed;
  Serial.println("pedestrian button pressed");
}
