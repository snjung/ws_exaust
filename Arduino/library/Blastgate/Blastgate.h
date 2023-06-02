
// Blastgate.h

#ifndef Blastgate_h
#define Blastgate_h

#include <Arduino.h>
#include <Servo.h>

class Blastgate 
{
    public:
        Blastgate(int PinLED, int PinServo, int posClose, int posOpen);
        void openGate();
        void closeGate();
        void init();
        int getState();
    private:
        Servo blastgate_servo;
        int _PinLED;
        int _PinServo;
        int _posClose;
        int _posOpen;
        unsigned char _gateState;
};

#endif