#define blueLED 13
#define greenLED 12
#define btnPin 7
#define waitTimeGreen 500
#define waitTimeBlue 1000
#define btnRegTime 10

unsigned long lastTimeGreen, lastTimeBlue;

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);

  turnLEDON(blueLED);
  turnLEDON(greenLED);
  lastTimeGreen = lastTimeBlue = millis();
}

void loop() {
  lastTimeBlue = checkTimePast(lastTimeBlue, waitTimeBlue, blueLED);
  lastTimeGreen = checkTimePast(lastTimeGreen, waitTimeGreen, greenLED);
  if (checkBtnState(btnPin)) {
    switchOnOff(greenLED);
    switchOnOff(blueLED);
    lastTimeGreen = lastTimeBlue = millis();
  }
  delay(10);
}

bool checkBtnState (int pin) {
  bool state = false;
  if (!digitalRead(pin)) {
    state = true;
  }
  while (!digitalRead(pin)) {}
  return state;
}

unsigned long checkTimePast(int lastTime, int waitTime, int pin) {
  if (lastTime + waitTime < millis()) {
    switchOnOff(pin);
    return millis();
  }
  return lastTime;
}

void turnLEDON(int pin) {
  digitalWrite(pin, HIGH);
}

void turnLEDOFF(int pin) {
  digitalWrite(pin, LOW);
}

void switchOnOff(int pin) {
  int state = digitalRead(pin);
  digitalWrite(pin, !state);
}

void setLEDBrightness(int pin, int perc) {
  int brightness = map(perc, 0, 100, 0, 255);
  analogWrite(pin, brightness);
}
