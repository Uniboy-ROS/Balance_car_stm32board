int i = 0;

void setup() {
  pinMode(PC13, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
}

void loop() {
  String bb = "";

  Serial.println("1");
  digitalWrite(PC13, HIGH);
  delay(500);
  
  Serial2.write("3");
  digitalWrite(PC13, LOW);
  delay(500);
  
  if (Serial2.available() > 0) {
    char i = Serial2.read();
    char j = Serial2.read();
    bb = bb + i ;
    bb = bb + j;
    Serial.println(bb);
  }

}
