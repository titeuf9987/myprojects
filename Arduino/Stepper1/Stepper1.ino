#include <OliStepper.h>

unsigned long deb;
bool first=true;
OliStepper moteur1(8, 9, 10, 11, 512);

void setup() {
  moteur1.setDirection (_CW);
  moteur1.setRPM(4);
  //deb = millis();
  moteur1.setOrigin();
  moteur1.setAngle(180);

}


void loop() {
  moteur1.oliRun ();

 if (moteur1.stopped)  {
     moteur1.setAngle(10);
    //delay(1000);
 }
  
}


