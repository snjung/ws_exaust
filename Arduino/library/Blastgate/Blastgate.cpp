// BLASTGATE.cpp
#include <Arduino.h>
#include "Blastgate.h"
#include <Servo.h>

Blastgate::Blastgate(int PinLED, int PinServo, int posClose, int posOpen) {
  _PinLED   = PinLED;
  _PinServo = PinServo;
  _posOpen = posOpen; 
  _posClose = posClose;
  pinMode(_PinLED, OUTPUT);
  _gateState = LOW;
}

void Blastgate::init() {
  blastgate_servo.attach(_PinServo);
  _gateState = LOW;
  blastgate_servo.write(_posClose);
}

void Blastgate::openGate() {
  _gateState = HIGH;
  blastgate_servo.write(_posOpen);
  digitalWrite(_PinLED, _gateState);
}

void Blastgate::closeGate() {
  _gateState = LOW;
  blastgate_servo.write(_posClose);
  digitalWrite(_PinLED, _gateState);
}

int Blastgate::getState() {
  return _gateState;
}
