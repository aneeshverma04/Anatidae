void setup() {
  // Setup pin 1 which is connected to Sample LED as Output
  pinMode(1,OUTPUT);
}

void loop() {
  // Infinite Blinking..reduce delay for faster blinking and vice versa
  digitalWrite(1,HIGH);
  delay(300);
  digitalWrite(1,LOW);
  delay(300);
}
