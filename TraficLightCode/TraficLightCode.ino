#define red_light 1    //states
#define redyellow_light 2
#define green_light 3
#define yellow_light 4

int GREEN = 4;      //variables
int YELLOW = 5;
int RED = 6;
int pedGREEN = 7;
int pedRED = 8;
int busB = 2;
int pedB = 3;
int time = 2000;
int redDelay;
int halfGreenDelay;
int state = red_light;  
int pbState;
int bbState; 
int bbRushChecker = 0; 
int pbRushChecker = 0; 


void setup()        //pinmode setup and monitoring initiation
{
    Serial.begin(9600);
    pinMode(pedRED, OUTPUT);
    pinMode(pedGREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(pedB, INPUT_PULLUP); 
    pinMode(busB, INPUT_PULLUP); 
}

void loop()
{
    switch (state)     //light states
    {
    case red_light:             
      Serial.println("State = RED");
       redDelay=100;                   //waiting time in red state range from 8 seconds to 18 depending on if and when the bus button is pushed
       digitalWrite(GREEN, LOW);
       digitalWrite(YELLOW, LOW);
       digitalWrite(RED, HIGH);
       digitalWrite(pedRED, LOW);
       digitalWrite(pedGREEN, HIGH); 
       for (int i = 1; i <= redDelay; i+=1)        //10 seconds counter time for button to be pushed, otherwise waiting time is 18 seconds
        {
         bbState = digitalRead(busB);
          if (bbState == 0 && bbRushChecker== 0){ 
                bbRushChecker = 1;                      //makes sure the button isn't pushed twice
              Serial.println("Bus Button Pressed, time remaining 8 seconds");
            state=redyellow_light;         //switches to state redyellow
            break;
            }
         delay(100);
        }
		delay(8000);
       state=redyellow_light;
    break;
    case redyellow_light:                   //yellow states don't get affected by button rushes, as they serve as warnings
    Serial.println("State = REDYELLOW");       
       digitalWrite(GREEN, LOW);
       digitalWrite(YELLOW, HIGH);
       digitalWrite(RED, HIGH);
       digitalWrite(pedRED, HIGH);
       digitalWrite(pedGREEN, LOW);
       delay(time);
       state=green_light;
    break;
    case green_light:                      //the green state is split in 2 waiting periods, if the buttons are pressed in one period they cannot be pressed in the other one. Total waiting time without buttons is 30 seconds.
      Serial.println("State = GREEN");
        halfGreenDelay=150;
        bbRushChecker = 0;
      pbRushChecker = 0;                   //saves the state of the pedestrian button so it isnt pressed twice
       digitalWrite(GREEN, HIGH);
       digitalWrite(YELLOW, LOW);
       digitalWrite(RED, LOW);
       digitalWrite(pedRED, HIGH);
       digitalWrite(pedGREEN, LOW);
       for (int i = 1; i <= halfGreenDelay; i+=1)         //standard time is 15 seconds, if the pedestrian button is pressed, waiting time becomes 3 seconds + 2nd half
        {
            pbState = digitalRead(pedB);
            bbState = digitalRead(busB);
          if (pbState == 0 && pbRushChecker == 0){
            Serial.println("Pedestrian Button Pressed, time remaining 18 seconds");
            pbRushChecker = 1;
            delay(3000);
            break;
          }
          else if (bbState == 0 && pbState != 0){           //button can be pressed by the bus driver to increase the state time by 10 seconds. It doesnt work if the pedestrian button has been pushed.
            Serial.println("Bus button pressed, time increased by 10 seconds");
            bbRushChecker = 1;
            delay(10000);
            break;
          }
         delay(100);
        }
      for (int i = 1; i <= halfGreenDelay;i+=1)
        {
            pbState = digitalRead(pedB);
            bbState = digitalRead(busB);
          if (pbState == 0 && pbRushChecker == 0){         //if the pedestrian button hasn't been pushed in the first half, then the button brings the remaining time to 5 seconds.
            Serial.println("Pedestrian Button Pressed, time remaining 5 seconds");
            pbRushChecker = 1;
            delay(5000);
            state=yellow_light;
            break;
          }
        else if (bbState == 0 && pbState != 0 && bbRushChecker != 1 && pbRushChecker !=1){
            Serial.println("Bus button pressed, time increased by 10 seconds");
            bbRushChecker = 1;
            delay(10000);
            
          }
         delay(100);
        }
       state=yellow_light;
    break;
    case yellow_light:
    Serial.println("State = YELLOW");
       digitalWrite(GREEN, LOW);
       digitalWrite(YELLOW, HIGH);
       digitalWrite(RED, LOW);
       digitalWrite(pedRED, HIGH);
       digitalWrite(pedGREEN, LOW);
      bbRushChecker=0;
       delay(time);    
       state=red_light;
    break;
}
}
  
