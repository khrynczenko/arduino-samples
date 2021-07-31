#include <Servo.h>

Servo servo;
byte servo_position = 0;

const int MAX_LIGHT_VOLTAGE = 454;
const int MIN_LIGHT_VOLTAGE = 227;


void setup() {
  servo.attach(11);
  Serial.begin(9600);
}

void loop() {
  int read_value  = analogRead(A5);
  int voltage = map(read_value, 0, 1023, 0, 500);
  int normalized_voltage = map(voltage, 0, 500, MIN_LIGHT_VOLTAGE, MAX_LIGHT_VOLTAGE);
  servo_position = map(normalized_voltage, MIN_LIGHT_VOLTAGE, MAX_LIGHT_VOLTAGE, 0, 180);
  servo.write(servo_position);
  
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
  
  Serial.print("Estimated voltage is ");
  Serial.print(voltage);
  Serial.println("");
  Serial.print("Normalize voltage is ");
  Serial.print(normalized_voltage);
  Serial.println("");
  Serial.print("Servo position is");
  Serial.print(servo_position);
  Serial.println("");
  
  delay(2000);
}
