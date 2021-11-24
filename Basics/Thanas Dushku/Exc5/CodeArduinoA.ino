//code for arduino "A"
//when the button connected to pin 2 is pressed this arduino sends a message to arduino "B" saying "Button pressed"
//then it receives a message back saying "Thank you"


int buttonState = 0;   
int buttonPin = 2;
int buttonCheck;
char message2[9];
int checkState = 0;

#define pressedBefore 1
#define notPressedBefore 0
#define setState 1
#define notSet 0

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if(buttonCheck == notPressedBefore){
    Serial.write("Button pressed");
    buttonCheck = pressedBefore;
    Serial.println("-----------------");
    }
  }
  if (buttonState == LOW) {
    buttonCheck = notPressedBefore;
  }
  
  if (Serial.available() > 0 && checkState == notSet) {
    Serial.readBytes(message2,9);
    Serial.println(message2);
    checkState = setState;
    Serial.end();
  }
  delay(50); 
}
