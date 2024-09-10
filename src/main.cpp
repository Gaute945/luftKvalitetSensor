#include <Arduino.h>

const int potentiometerPin = A5;
const int one = 2;
const int two = 3;
const int three = 4;
const int four = 5;
const int five = 6;

int lastLed = 2;

void setup() {
  Serial.begin(9600);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
}

float normalizeToRange(int value, int old_min, int old_max, int new_min, int new_max) {
    float normalized_value = (float)(value - old_min) / (old_max - old_min) * (new_max - new_min) + new_min;  
    int rounded_value = (int)round(normalized_value);
    return rounded_value;
}

void loop() {
  int potValue = analogRead(potentiometerPin);
  int NormalPotValue = normalizeToRange(potValue, 0, 1023, 0, 5);
  Serial.print("Normalized Potentiometer Value: ");
  Serial.println(NormalPotValue);

  switch (NormalPotValue)
  {
  case 1:
    digitalWrite(lastLed, LOW);
    digitalWrite(one, HIGH); 
    lastLed = one;
    break;

  case 2:
    digitalWrite(lastLed, LOW);
    digitalWrite(two, HIGH);
    lastLed = two;
    break;

  case 3:
    digitalWrite(lastLed, LOW);
    digitalWrite(three, HIGH);
    lastLed = three;
    break;

  case 4:
    digitalWrite(lastLed, LOW);
    digitalWrite(four, HIGH);
    lastLed = four;
    break;

  case 5:
    digitalWrite(lastLed, LOW);
    digitalWrite(five, HIGH);
    lastLed = five;
    break;
    
  default:
    break;
  }

  delay(100);
}

