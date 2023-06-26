#define FAN_PIN 33
#define FAN_DELAY 5000

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
}

void loop() {
  digitalWrite(FAN_PIN, HIGH);
  delay(FAN_DELAY);
  digitalWrite(FAN_PIN, LOW);
  delay(FAN_DELAY);
}
