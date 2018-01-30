
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

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


/***************************
 * Display variables
 *************************/

// OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI


/***************************
 * Other variables
 *************************/

char mode = '1';


void setup() {
  Serial.begin(57600);

  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

  u8g.setColorIndex(1);         // pixel on

  gpsPort.begin(9600);

}

void loop() {
  char key = keypad.getKey();

  // Reading key
  if (key) {
    Serial.println(key);
  }

  // picture loop
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );

  if (gps.available( gpsPort )) {
    gps_fix fix = gps.read();
    currSpeed = fix.speed_kph();

    sats = fix.satellites;
    currSpeed = fix.speed_kph();
    currLat = fix.latitude ();
    currLon = fix.longitude();
    alt = fix.altitude ();

    /*
      float bearingToLondon = fix.location.BearingToDegrees( London );
      bool  validDT         = fix.valid.date & fix.valid.time;

      print(             fix.satellites       , fix.valid.satellites, 3             );
      print(             fix.hdop/1000.0      , fix.valid.hdop      , 6, 2          );
      print(             fix.latitude ()      , fix.valid.location  , 10, 6         );
      print(             fix.longitude()      , fix.valid.location  , 11, 6         );
      print(             fix.dateTime         , validDT             , 20            );
      print(             fix.altitude ()      , fix.valid.altitude  , 7, 2          );
      print(             fix.speed_kph()      , fix.valid.speed     , 7, 2          );
      print(             fix.heading  ()      , fix.valid.heading   , 7, 2          );
      print( compassDir( fix.heading  () )    , fix.valid.heading   , 4             );
      print( fix.location.DistanceKm( London ), fix.valid.location  , 5             );
      print(             bearingToLondon      , fix.valid.location  , 7, 2          );
      print( compassDir( bearingToLondon )    , fix.valid.location  , 4             );

      print( gps.statistics.chars , true, 10 );
      print( gps.statistics.ok    , true,  6 );
      print( gps.statistics.errors, true,  6 );
    */
  }
}


