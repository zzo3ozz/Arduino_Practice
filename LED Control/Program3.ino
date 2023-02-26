const int buttonPin = 5;
const int red = 8;
const int green = 9;
int buttonState = 0;

void pushbotton()
{
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW)
  {
    digitalWrite(green, HIGH);
  } else
  {
    digitalWrite(green, LOW);
  }
}
void setup() {
  pinMode(red, OUTPUT);pinMode(green, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  digitalWrite(red, HIGH);
  for(int timer = 0; timer <= 1000; timer += 100)
  {
    delay(100);
    pushbotton();
  }
  digitalWrite(red, LOW);
  for(int timer = 0; timer <= 1000; timer += 100)
  {
    digitalWrite(red, LOW);
    delay(100);
    pushbotton();
  }
}
