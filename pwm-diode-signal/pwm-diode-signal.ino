#define DIODE_PIN 3

byte fill = 0;
int change = 5;
bool increasing_is_active = true;


void setup() {
  pinMode(DIODE_PIN, OUTPUT);   
}

void loop() {
  analogWrite(DIODE_PIN, fill);
  if (increasing_is_active && fill > 240) {
    increasing_is_active = false;
  }
  if (!increasing_is_active && fill < 20){
    increasing_is_active = true;
  }
  if (increasing_is_active) {
      fill = fill + 10;
  } else {
    fill = fill - 10;
  }


  delay(100);
}
