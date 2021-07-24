void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
}

float convert_adc_read_to_voltage(int read_value) {
  return (5.0 / 1024.0) * read_value;
}
void loop() {
  int read_value  = analogRead(A5);
  
  Serial.print("ADC read: ");
  Serial.print(read_value);
  Serial.print("\n");
  Serial.print("ADC read (in Volts): ");
  Serial.print(convert_adc_read_to_voltage(read_value));
  Serial.print("\n");

//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(read_value);
//  digitalWrite(LED_BUILTIN, LOW);
  int led_is_on = map(read_value, 0, 1023, 0, 2);
  if (led_is_on) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
