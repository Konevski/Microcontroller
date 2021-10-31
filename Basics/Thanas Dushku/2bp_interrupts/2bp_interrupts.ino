#define strongNotTaken 0           //the states of the 2bp  (00;01;10;11)
#define weakNotTaken 1
#define weakTaken 2
#define strongTaken 3
                                   //setting up the pins
const byte Bit0 = 11;              //pin 11 is B0 of the predictor
const byte Bit1 = 9;               //pin 9 is B1 of the predictor
const byte interruptPin1 = 2;      //this pin is used for interrupting when the event bit is 0 or LOW
const byte interruptPin2 = 3;      //this pin is used for interrupting when the event bit is 1 or HIGH
int eventState = 2;

int state = strongNotTaken;        //the initial state of the 2BP, 00

void setup()                       //setting up the pins and interrupts
{
  pinMode(interruptPin1, INPUT); 
  pinMode(interruptPin2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Bit0, OUTPUT);
  pinMode(Bit1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), event0, RISING);        //whenever the value of pin 2 linked to the interrupt is changed from a 0 to a 1 the function "event0" happens
  attachInterrupt(digitalPinToInterrupt(interruptPin2), event1, RISING);        //used when the event is 1 and runs function "event1"
}

void loop()                         //main code of the 2BP
{
  switch(state){
    case strongNotTaken:            //first state of the 2BP, displayed by the LED lights connected to pins 11 and 9
    	digitalWrite(Bit0,LOW);
    	digitalWrite(Bit1,LOW);
    	if(eventState == 1){          //if interrupt 2 has occured we swap to state weakNotTaken
          state = weakNotTaken;
    	}
    eventState = 2;                 //resets the eventState variable so it doesnt get reused after an interrupt
    break;
    
    case weakNotTaken:
    	digitalWrite(Bit0,LOW);
    	digitalWrite(Bit1,HIGH); 
      if(eventState == 0){          //swaps to strongNotTaken or weakTaken based on what interrupt occured
          state = strongNotTaken;
    	}
    	if(eventState == 1){
          state = weakTaken;
    	}
    eventState = 2;
    break;
    
    case weakTaken:               
    	digitalWrite(Bit0,HIGH);
    	digitalWrite(Bit1,LOW); 
      if(eventState == 0){
          state = weakNotTaken;
    	}
    	if(eventState == 1){
          state = strongTaken;
    	}
    eventState = 2;
    break;
    
    case strongTaken:
    	digitalWrite(Bit0,HIGH);
    	digitalWrite(Bit1,HIGH); 
    	if(eventState == 0){
          state = weakTaken;
    	}
    eventState = 2;
    break;
  }
  delay(5); 
}

void event0() {               //ISR function that gets called when event0 happens and promts the state to switch to another before breaking out of it    
	eventState = 0;
}
void event1() {               //acts as ISR for when the event bit is 1
	eventState = 1;
}
