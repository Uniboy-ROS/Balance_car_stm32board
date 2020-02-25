int i = 0;
void setup() {  
  pinMode(PB13, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
}

void loop() {
  
  Serial.println("77");
  digitalWrite(PB13, HIGH);   
  delay(500);             

  Serial2.print("99");
  digitalWrite(PB13, LOW);   
  delay(500);              
  
  if (Serial2.available() > 0) {
    char i = Serial2.read();
    Serial.println(i);
  }

}
