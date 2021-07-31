#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  Serial.println("To change position of a servo, senf value from 0 to 180.");
  servo.attach(9);
}

void loop() {
  if (Serial.available() > 0) {
      const String reply = Serial.readStringUntil('\n');
      const int servo_position = reply.toInt(); // if conversion fails returns 0
      servo.write(servo_position);
  }
}
