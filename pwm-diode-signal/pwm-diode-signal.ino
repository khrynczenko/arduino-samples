#define DIODE_PIN 3

byte fill = 0;
int change = 5;


void setup() {
  pinMode(DIODE_PIN, OUTPUT);   
}

void loop() {
  analogWrite(DIODE_PIN, fill);
  fill = fill + 1;

  delay(1000);
}
