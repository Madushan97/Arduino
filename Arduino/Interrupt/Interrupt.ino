void setup() {

  pinMode (8, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (2, INPUT_PULLUP);

  int intNum = digitalPinToInterrupt(2);
  attachInterrupt(intNum, toggle, FALLING);
}

void loop() {

  digitalWrite(13, !digitalRead(13));
  delay(200);

}

void toggle(){

  digitalWrite(8, !digitalRead(8));
}
