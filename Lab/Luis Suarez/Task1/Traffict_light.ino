
#define redLight 0
#define yellowLight 1
#define greenLight 2
#define redYellowLight 3

int Red = 13;
int Yellow = 12;
int Green = 11;

int state = 0;


void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
 ;
}

void loop()
{
  switch(state){
    case redLight:
    digitalWrite(Yellow,LOW);
    digitalWrite(Red, HIGH);
    delay(20000);
    state = yellowLight;
    break;
    
    case yellowLight:
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, HIGH);
     delay(5000);
    state = greenLight;
    break;
    
    case greenLight:
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
    delay(15000);
    state = redYellowLight;
    break;
    
    case redYellowLight:
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
    digitalWrite(Yellow, HIGH);
    delay(5000);
    state = redLight;
    break;
    
  }
}
