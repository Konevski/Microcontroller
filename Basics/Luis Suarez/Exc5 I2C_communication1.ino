// I2C communication Protocol
/// Master 
/// communication between 2 arduinos
#include <Wire.h> // Library
int pushButton= A0; // button connected to A0 port
int x=0; // Variable that takes the push button
void setup()
{
  Wire.begin(1); // start communication 
  pinMode(pushButton, INPUT); // Setting the value of the button when its push 
  Wire.onRequest(Request); // Creating the event that would take place when its called from the slave
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(1); // Transmitting the value
  x = digitalRead(pushButton);// x taking the value from pushbutton
  Wire.write(x);// sending the inf as x
 
  Wire.endTransmission(); // Finishing the transmission
  delay(500);
  
}

void Request(){
  
  Serial.print("Message Requested, Sending"); //Printing when the slave calls
  Wire.write("Button Pressed");// sending the message and printing it when it is done the requested
}

// I2C communication Protocol
/// Slave 1
/// communication between 2 arduinos
////////////////////////////////////////////

#include <Wire.h>
int pinLed=13; // led set in pin 13
int x = 0; // Variable taking the value of the button
char message1; //Defining the char to get the message


void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop()

  {
    
}

void receiveEvent(int howMany){
  
x= Wire.read(); // REading the value of x from arduino master

if (x == 1){ // when buttong is high o pressed
    
    digitalWrite(pinLed,HIGH); // led is on
    Wire.requestFrom(1,19);// requesting the chanel inf from master 1 from 19 char (19 bits)
    message1=Wire.read();// saving the message "button pressed" in messsage1 
    Serial.print(message1); // printing the message 
    Serial.println("Thank you");// Printing Message back
     delay(1000);
    
  }
  else{
        
        digitalWrite(pinLed,LOW); // led off
      }
  
  delay(2500);
    
    
}   
    
