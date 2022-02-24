void setup() {
  pinMode (8, OUTPUT);
  pinMode(9, INPUT);
  int prevState, curState;

}

void loop() {

  digitalWrite(9, INPUT_PULLUP);    //pull up 9  

  if(digitalRead(9)== HIGH){    //check the status of 9
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  }else{
    digitalWrite(8, HIGH);
    delay(200);
    digitalWrite(8, LOW);
    delay(200);
  }
 

}
