#include <Arduino.h>

int r1Pin = D3;
int y1Pin = D1;
int g1Pin = D2;

int r2Pin = D5;
int y2Pin = D6;
int g2Pin = D7;

void setup()
{
  pinMode(r1Pin, OUTPUT);
  pinMode(y1Pin, OUTPUT);
  pinMode(g1Pin, OUTPUT);
  pinMode(r2Pin, OUTPUT);
  pinMode(y2Pin, OUTPUT);
  pinMode(g2Pin, OUTPUT);
}

void loop()
{
  digitalWrite(g1Pin, HIGH);
  delay(100);
  digitalWrite(g1Pin, LOW);
  digitalWrite(y1Pin, HIGH);
  delay(100);
  digitalWrite(y1Pin, LOW);
  digitalWrite(r1Pin, HIGH);
  delay(100);
  digitalWrite(r1Pin, LOW);
  digitalWrite(g2Pin, HIGH);
  delay(100);
  digitalWrite(g2Pin, LOW);
  digitalWrite(y2Pin, HIGH);
  delay(100);
  digitalWrite(y2Pin, LOW);
  digitalWrite(r2Pin, HIGH);
  delay(100);
  digitalWrite(r2Pin, LOW);
}

// #include "SimpleLED.h"

// SimpleLED led1(LED_BUILTIN, false, 100, 400);
// SimpleLED led2(LED_BUILTIN_AUX, false, 100, 300);
// long stateTime[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// void setup()
// {
//   long start = millis();
//   led1.setup(start);
//   led2.setup(start);
// }

// void loop()
// {
//   long now = millis();
//   led1.update(now);
//   led2.update(now);
// }