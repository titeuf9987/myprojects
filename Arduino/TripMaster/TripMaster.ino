
/* @file TrimMaster
  || @version 0.1
  || @author Vincent Streignard
  || @contact N/A
  ||
  || @description
  || | My TripMaster - uring OLED + GPS + keypad
  || #
*/
#include <Keypad.h>
#include "U8glib.h"


#include <NMEAGPS.h>
#include <GPSport.h>

/***************************
 * GPS variables
 *************************/
NMEAGPS     gps;

int sats = 0;
int currSpeed = 0;
float currLat;
float currLon;
int alt;


gps_fix fix;
NeoGPS::Location_t prevPosition;


/***************************
 * Other variables
 *************************/

char mode = '1';

void setup() {
  Serial.begin(57600);
  initDisplay();
  initKeyboard();
  initGPS();
}

void loop() {
  getGPS();
  doComputes();
  processDisplay();
}


