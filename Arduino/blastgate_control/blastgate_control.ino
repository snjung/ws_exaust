#include <Blastgate.h>
#include <JC_Button.h>

Blastgate blastgateBandsaw(8, 3, 0, 180); 
Blastgate blastgatePlaner(12, 5, 0, 180); 
Blastgate blastgateTablesaw(13, 6, 0, 180); 
int PinVacControl = 7;

Button buttonBandsaw(0);
Button buttonPlaner(1);
Button buttonTablesaw(2);

void setup() {
  serial.begin(9600);
  blastgateBandsaw.init();
  blastgatePlaner.init();
  blastgateTablesaw.init();
  buttonBandsaw.begin();
  buttonPlaner.begin();
  buttonBandsaw.begin();  
}

void loop() {
  buttonPlaner.read();
  if (buttonPlaner.wasReleased()) {
    if(blastgatePlaner.getState){
      blastgatePlaner.closeGate();
    }
    else{
      blastgatePlaner.openGate();
    }
  }
}

