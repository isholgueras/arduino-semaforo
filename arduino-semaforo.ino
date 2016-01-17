
int redLightPin = 7;
int yellowLightPin = 6;
int greenLightPin = 5;
int redPedestrianPin = 3;
int greenPedestrianPin = 2;
int buzzerPin = 8;

int redTime = 10000;
int yellowTime = 4000;
int yellowTimeInterval = 500;
int greenTime = 10000;
int pedestrianBlinkingTime = 3000;
int pedestrianBlinkingInterval = 3000;
int buzzerLongInterval = 1000;
int buzzerShortInterval = 300;
int buzzerShortTime = 3000;

void setup()
{
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(redPedestrianPin, OUTPUT);
  pinMode(greenPedestrianPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
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
  digitalWrite(greenPedestrianPin, HIGH);
  int buzzerLongTime = redTime - buzzerShortTime;
  int buzzerLongEvents = buzzerLongTime / (buzzerLongInterval * 2 );
  int buzzerShortEvents = buzzerShortTime / (buzzerShortInterval * 2);
  
  for (int i = 1; i < buzzerLongEvents; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(buzzerLongInterval);
    digitalWrite(buzzerPin, LOW);
    delay(buzzerLongInterval);
  }
  
  for (int i = 1; i < buzzerShortEvents; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(buzzerShortInterval);
    digitalWrite(buzzerPin, LOW);
    delay(buzzerShortInterval);
  }
  
}

void yellowLight() {
  resetLights();
  
  digitalWrite(redPedestrianPin, HIGH);
  
  int events = yellowTime / (yellowTimeInterval * 2);
  for (int i = 1; i < events; i++) {
    digitalWrite(yellowLightPin, HIGH);
    delay(yellowTimeInterval);
    digitalWrite(yellowLightPin, LOW);
    delay(yellowTimeInterval);
  }
}

void greenLight() {
  resetLights();
  digitalWrite(redPedestrianPin, HIGH);
  digitalWrite(greenLightPin, HIGH);
  delay(greenTime);
}

void resetLights() {
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  digitalWrite(redPedestrianPin, LOW);
  digitalWrite(greenPedestrianPin, LOW);
  digitalWrite(buzzerPin, LOW);
}
