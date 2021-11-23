#define redLight 0
#define yellowLight 1
#define greenLight 2
#define redYellowLight 3

int RED = 10;
int YELLOW = 9;
int GREEN = 8;

int pRED = 3;
int pGREEN = 2;

int state = 0;


void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(pRED, OUTPUT);
  pinMode(pGREEN, OUTPUT);
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
    state = yellowLight;
    break;
    
    case yellowLight:
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(pGREEN, LOW);
    digitalWrite(pRED, HIGH);
    delay(5000);
    state = greenLight;
    break;
    
    case greenLight:
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    delay(15000);
    state = redYellowLight;
    break;
    
    case redYellowLight:
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    delay(5000);
    state = redLight;
    break;
    
  }
}
