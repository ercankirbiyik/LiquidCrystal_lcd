
#include <LiquidCrystal.h>

LiquidCrystal lcd(0x27, 16, 2);

int TrigPin = 9;
int PulsePin = 8;

long dist = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(TrigPin, OUTPUT);
  pinMode(PulsePin, INPUT);
}

void loop() {
  Trigger();
  dist = getDistance();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(dist);
  lcd.print(" cm");
  delay(10);
}

void Trigger() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(TrigPin, LOW);
}

long getDistance() {
  long temp = pulseIn(PulsePin, HIGH, 2000);
  temp = temp/29/2;
  return temp; 
}
