//code for arduino "B"
//this arduino waits for arduino "A" to send a message, sends back "Thank you" and prints the received message


char message1[14];
int checkState = 0;

#define notSet 0
#define setState 1

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0 && checkState == notSet) {
    Serial.readBytes(message1,14);
    
    Serial.write("Thank you");
    Serial.println("-----------------");
    Serial.print("I received: ");
    Serial.println(message1);

    checkState = setState;
    Serial.end();
  }
  delay(500);
}
