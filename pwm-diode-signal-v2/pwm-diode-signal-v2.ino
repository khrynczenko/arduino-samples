#define PIN_DIODE 3

byte duty_cycle = 20;
bool duty_cycle_is_increasing = true;

bool is_duty_cycle_direction_to_change() {
  if(duty_cycle > 240 || duty_cycle < 20) {
    return true;
  }
  return false;
}


void update_duty_cycle() {
  if (duty_cycle_is_increasing) {
    duty_cycle += 10;
  } else {
    duty_cycle -= 10;
  }
}

void setup() {
  Serial.begin(9600);
  analogWrite(PIN_DIODE, duty_cycle);
}


void loop() {
  if (is_duty_cycle_direction_to_change()) {
    duty_cycle_is_increasing = !duty_cycle_is_increasing;
  }
  update_duty_cycle();
  Serial.println(duty_cycle, DEC);
  analogWrite(PIN_DIODE, duty_cycle);
  delay(300);
}
