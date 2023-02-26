const int buttonPin = 5;
const int ledPin = 9;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
  } else
  {
    digitalWrite(ledPin, LOW);
  }
}
