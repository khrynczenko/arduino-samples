void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
}

float convert_adc_read_to_voltage(int read_value) {
  return (5.0 / 1024.0) * read_value;
}
void loop() {
  int read_value  = analogRead(A5);
  float voltage = convert_adc_read_to_voltage(read_value);
  int read_threshold  = analogRead(A4);
  float threshold = convert_adc_read_to_voltage(read_threshold);
  
  Serial.print("ADC read: ");
  Serial.print(read_value);
  Serial.print("\n");
  Serial.print("ADC read (in Volts): ");
  Serial.print(voltage);
  Serial.print("\n");

  boolean room_is_dark = voltage < threshold;
  if (room_is_dark) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
