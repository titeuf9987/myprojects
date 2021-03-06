
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
#include <Arduino.h>

const int gpsInterval = 3000;

/***************************
 * Display variables
 *************************/

// OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI





/***************************
 * GPS variables
 *************************/



int sats = 0;
int currSpeed = 0;
float currLat;
float currLon;
float distHome;
float bearingHome;
int alt;
boolean firstValidGPS=false;


NMEAGPS     gps;
gps_fix fix;
NeoGPS::Location_t prevPosition;



/***************************
 * Key pad variables
 *************************/
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 5}; //connect to the column pinouts of the keypad



Keypad keypad= Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



/***************************
 * Other variables
 *************************/

char mode = '1';

void setup() {
  Serial.begin(57600);
  gpsPort.begin(9600);
  
  Serial.println("Setup");
  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

  initDisplay();
  initKeypad();
  initGPS();

  
}

void loop() {

  
  getGPS();
 
  char key = keypad.getKey();
  doComputes();
  
  processDisplay();
  
}


