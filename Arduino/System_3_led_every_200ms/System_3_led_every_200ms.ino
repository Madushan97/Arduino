void setup() {
  pinMode (8, OUTPUT);
  pinMode (13, OUTPUT);
}

void loop() {
  digitalWrite (8, HIGH);
  digitalWrite (13, HIGH);
  delay(200);
  digitalWrite (8, LOW);
  digitalWrite (13, LOW);
  delay(200);
  
}
