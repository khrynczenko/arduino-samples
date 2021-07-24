#define RED_LED_PIN 9
#define GREEN_LED_PIN 8

String chosen_color = "";

void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    chosen_color = Serial.readStringUntil('\n');

    if (chosen_color == "red") {
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
    }
    else if (chosen_color == "green") {
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
    }
    else {
      Serial.println("Wrong color! Choose 'green' or 'red'!");
    }
  }
}
