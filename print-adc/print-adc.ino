void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  Serial.println("Below are the information regarding current voltage read on the potentiometer.");
  
}

void loop() {
  int read_value  = analogRead(A5);
  Serial.print("Raw value given by the ADC (10bit) is  ");
  Serial.print(read_value, DEC);
  Serial.println("");
  Serial.print("\t(DEC): ");
  Serial.print(read_value, DEC);
  Serial.println("");
  Serial.print("\t(HEX): ");
  Serial.print(read_value, HEX);
  Serial.println("");
  Serial.print("\t(BIN): ");
  Serial.print(read_value, BIN);
  Serial.println("");
  float voltage = map(read_value, 0, 1023, 0, 500) / 100.0;
  Serial.print("Estimated voltage is ");
  Serial.print(voltage);
  Serial.println("");
  
  delay(5000);
}
