#define FAN_PIN 33
#define FAN_DELAY 10000
#define PIR_PIN 32

bool fanState = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
}

void loop() {
  static unsigned long onTimer = 0;
  static unsigned long offTimer = 0;

  if (digitalRead(PIR_PIN) == HIGH) {
    fanOn();
  }
  else {
    fanOff();
  }

  // Print fan state every time it changes
  static bool lastFanState = false;
  if (fanState != lastFanState) {
    Serial.print("Fan state: ");
    Serial.println(fanState ? "ON" : "OFF");
    lastFanState = fanState;

    if (fanState) {
      onTimer = millis();
      Serial.print("Time fan was off: ");
      Serial.println(millis() - offTimer);
    } else {
      offTimer = millis();
      Serial.print("Time fan was on: ");
      Serial.println(millis() - onTimer);
    }
  }
}

void fanOn() {
  digitalWrite(FAN_PIN, HIGH);
  fanState = true;
}

void fanOff() {
  digitalWrite(FAN_PIN, LOW);
  fanState = false;
}
