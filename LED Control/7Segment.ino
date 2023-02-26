const int a = 4, b = 5, c = 19, d = 20, e = 21, f = 3, g = 2, dp = 18;

void setup() {
  pinMode(a,OUTPUT);  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);  pinMode(dp,OUTPUT);
}

void turnon(int num)
{
  switch(num)
  {
    case 0:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);    digitalWrite(f, HIGH);      digitalWrite(g, LOW);    digitalWrite(dp, LOW);
      break;
    case 1:
      digitalWrite(a, LOW);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, LOW);
      digitalWrite(e, LOW);    digitalWrite(f, LOW);      digitalWrite(g, LOW);    digitalWrite(dp, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, LOW);    digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);    digitalWrite(f, LOW);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
    case 3:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, LOW);    digitalWrite(f, LOW);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;    
    case 4:
      digitalWrite(a, LOW);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, LOW);
      digitalWrite(e, LOW);    digitalWrite(f, HIGH);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
    case 5:
      digitalWrite(a, HIGH);    digitalWrite(b, LOW);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, LOW);    digitalWrite(f, HIGH);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
    case 6:
      digitalWrite(a, HIGH);    digitalWrite(b, LOW);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);    digitalWrite(f, HIGH);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
    case 7:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, LOW);
      digitalWrite(e, LOW);    digitalWrite(f, LOW);      digitalWrite(g, LOW);    digitalWrite(dp, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);    digitalWrite(f, HIGH);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
    case 9:
      digitalWrite(a, HIGH);    digitalWrite(b, HIGH);      digitalWrite(c, HIGH);    digitalWrite(d, HIGH);
      digitalWrite(e, LOW);    digitalWrite(f, HIGH);      digitalWrite(g, HIGH);    digitalWrite(dp, LOW);
      break;
  }
    
}
void loop() {
  turnon(0);  delay(1000);
  turnon(1);  delay(1000);
  turnon(2);  delay(1000);
  turnon(3);  delay(1000);
  turnon(4);  delay(1000);
  turnon(5);  delay(1000);
  turnon(6);  delay(1000);
  turnon(7);  delay(1000);
  turnon(8);  delay(1000);
  turnon(9);  delay(1000);
}
