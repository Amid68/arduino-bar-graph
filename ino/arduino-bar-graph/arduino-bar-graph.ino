const int analogPin = A0; // Pin connected to the potentiometer
const int ledCount = 9; // num of LEDs
int ledPins[] = {2,3,4,5,6,7,8,9,10}; // Pins connected to LEDs

void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);  // set the LED pins as output
  }
}

void loop() {
  int sensorReading = analogRead(analogPin);  // analog input
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) { // turn on LEDs in sequence
      digitalWrite(ledPins[thisLed], HIGH);
    } else { // turn off LEDs in sequence
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
