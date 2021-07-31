#define PIN_TRIGGER 12
#define PIN_ECHO 11
#define PIN_BUZZER 7

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  digitalWrite(PIN_BUZZER, LOW);
}

void initialize_measuring() {
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);
}

int measure_distance() {
    const int divisor_for_centimers = 58;
    int pulse_length = pulseIn(PIN_ECHO, HIGH);
    // pulse length corresponds to distance to an abstacle
    // it is actually a time it took for a sound to go to an obstacle and go back to the sensor
    // we divide this time by 58 to get distance in centimeters
    Serial.print("Pulse raw length = ");
    Serial.print(pulse_length);
    Serial.println("");
    return pulse_length / divisor_for_centimers;
}

void loop() {
  initialize_measuring();
  int distance_cm = measure_distance();

  Serial.print("Distance (cm) = ");
  Serial.print(distance_cm);
  Serial.println("");
  if(distance_cm < 50) {
    digitalWrite(PIN_BUZZER, HIGH);
    Serial.println("BUZZ");
  } else {
    digitalWrite(PIN_BUZZER, LOW);
  }
  delay(500);
}
