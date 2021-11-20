
#include <Wire.h> // 
int pushButton= A0; // button connected to A0 port
int x=0; // Variable that takes the push button
void setup()
{
  Wire.begin(1);
  pinMode(pushButton, INPUT);
  Wire.onRequest(Request);
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(1);
  x = digitalRead(pushButton);
  Wire.write(x);
 
  Wire.endTransmission();
  delay(500);
  
}

void Request(){
  
  Serial.print("Message Requested, Sending");
  Wire.write("Button Pressed");
}