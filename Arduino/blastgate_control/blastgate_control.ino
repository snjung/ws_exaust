#include <Blastgate.h>

Blastgate blastgate(8, 3, 0, 180); 

void setup() {
  //serial.begin(9600);
  blastgate.init();
}

void loop() {
  blastgate.openGate();
}

