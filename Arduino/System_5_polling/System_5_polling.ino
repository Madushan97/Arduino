void setup() {
  
  pinMode(13, OUTPUT);        // pin 13 as output
  pinMode(8, OUTPUT);         // pin 8 as output
  pinMode(2, INPUT_PULLUP);   // pin 2 input pullup
  
}

void loop() {
 
  digitalWrite(13, !digitalRead(13));
  delay(200);

  if(!digitalRead(2)){
    digitalWrite(8, !digitalRead(8));
    delay(200);
  }
}
