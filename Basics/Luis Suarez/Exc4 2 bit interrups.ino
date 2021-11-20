#define strongNotTaken 
#define weakNotTaken 
#define weakTaken 
#define strongTaken 
#define notTakenEvent 
#define takenEvent 
#define resetEvent 

const byte Bit0 = 13;
const byte Bit1 = 8;
const byte interruptPin1 = 2;
const byte interruptPin2 = 3;

int eventState = resetEvent;
int state = strongNotTaken;

void setup() {
  
  pinMode(interruptPin1, INPUT);
  pinMode(interruptPin2, INPUT);
  pinMode(Bit0, OUTPUT);
  pinMode(Bit1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), event0, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), event1, RISING);
}

void loop() 
{
  switch(state){
  case strongNotTaken:
    digitalWrite(Bit0,LOW);
    digitalWrite(Bit1,LOW);
    if(eventState == takenEvent){
       state = weakNotTaken;
    }
    eventState = resetEvent;
  break;

  case weakNotTaken:
    digitalWrite(Bit0,LOW);
    digitalWrite(Bit1,HIGH);
    if(eventState == notTakenEvent){
       state = strongNotTaken;
    }
    if(eventState == takenEvent){
       state = weakTaken;
    }
    eventState = resetEvent;
  break;

  case weakTaken:
    digitalWrite(Bit0,HIGH);
    digitalWrite(Bit1,LOW);
    if(eventState == notTakenEvent){
       state = weakNotTaken;
    }
    if(eventState == takenEvent){
        state = strongTaken;
    }
    eventState = resetEvent; 
  break;

  case strongTaken:
    digitalWrite(Bit0,HIGH);
    digitalWrite(Bit1,HIGH);
    if(eventState == notTakenEvent){
       state = weakTaken;
    }
    eventState = resetEvent;
  break;
 }
 delay(30);
 }
  void event0(){
    eventState = notTakenEvent;
  }
  void event1(){
    eventState = takenEvent;
  }

