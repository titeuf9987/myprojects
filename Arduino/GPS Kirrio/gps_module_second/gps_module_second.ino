#include "TinyGPS.h"

TinyGPS gps;

void setup() {
 Serial.begin(9600);
}

void loop() {
  /*
  Serial.println("Looping");
 while (Serial.available()) {
   Serial.print("In the while-loop.  ");
   int c = Serial.read();
   gps.encode(c);
   Serial.println("Oh no, I'm never gonna exit this while loop");
 }

 long latitude, longitude;
 gps.get_position(&latitude, &longitude, NULL);
 Serial.print("Latitude:  "); Serial.println(latitude);
 Serial.print("Longitude:  "); Serial.println(longitude);
 
 unsigned long chars;
 unsigned short sentences, failed_checksum;
 gps.stats(&chars, &sentences, &failed_checksum);
 */
}
