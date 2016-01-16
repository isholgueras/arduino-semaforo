
int redLightPin = 7;
int yellowLightPin = 6;
int greenLightPin = 5;

int redTime = 10000;
int yellowTime = 4000;
int yellowTimeInterval = 500;
int greenTime = 10000;

void setup()
{
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
}

void loop() 
{
  redLight();
  greenLight();
  yellowLight();
}

void redLight() {  
  resetLights();
  digitalWrite(redLightPin, HIGH);
  delay(redTime);
  
}

void yellowLight() {
  int events = yellowTime / (yellowTimeInterval * 2);

  resetLights();
  for (int i = 1; i < events; i++) {
    digitalWrite(yellowLightPin, HIGH);
    delay(yellowTimeInterval);
    digitalWrite(yellowLightPin, LOW);
    delay(yellowTimeInterval);
  }
}

void greenLight() {
  resetLights();
  digitalWrite(greenLightPin, HIGH);
  delay(greenTime);
}

void resetLights() {
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
}
