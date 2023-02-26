//Serial : PC
//Serial1 : GPS
//Serial2 : Bluetooth
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iReadValue = 0;
  if(Serial.available())
  {
    Serial.write(Serial.read());
  }
  if(Serial1.available())
  {
    iReadValue = Serial1.read();
    Serial.write(iReadValue);
    Serial2.write(iReadValue);
  }
  if(Serial2.available())
  {
    Serial.write(Serial2.read());
  }
}
