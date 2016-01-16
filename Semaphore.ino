
int ledPin = 13;
int led2Pin = 5;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() 
{
  digitalWrite(ledPin, HIGH);
  digitalWrite(led2Pin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  digitalWrite(led2Pin, LOW);
  delay(2000);
}
