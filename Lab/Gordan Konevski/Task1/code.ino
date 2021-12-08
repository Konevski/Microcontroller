#define redLight 0
#define yellowLight 1
#define greenLight 2

int RED = 10;
int YELLOW = 9;
int GREEN = 8;

int order = 0;
int state = redLight;


void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop()
{
  switch(state){
    case redLight:
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED, HIGH);
    delay(20000);    
    order = 0;
    state = yellowLight;
    break;
    
    case yellowLight:
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    delay(5000);
    if (order == 0)
    	state = greenLight;
    else
      	state = redLight;
    break;
    
    case greenLight:
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    delay(15000);
    order = 1;
    state = yellowLight;
    break;
    
  }
}
