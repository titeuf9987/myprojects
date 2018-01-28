
/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 */
#include <Keypad.h>
#include "U8glib.h"


#include <NMEAGPS.h>
#include <GPSport.h>

NMEAGPS     gps;




// OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

boolean blink = false;
boolean ledPin_state;

int i=0;
char mode='1';

int totKm = 16;
int interKm = 15;

int targetSpeed=30;
int avgSpeed=40;
int currSpeed=68;


/*****************************************************************************************
 * 
 *       PROCESSINGS
 * 
 *****************************************************************************************/

void processMode1(char key){
  if (key=='#') {
    // RST all
    totKm ++;
    interKm++;
  }
  if (key=='*') {
    // RST inter
    interKm++;
  }
  if (key=='A') {
    // RST inter
    totKm+=10;
  }
  if (key=='B') {
    // RST inter
    totKm+=1;
  }
  if (key=='C') {
    // RST inter
    totKm-=1;
  }
  if (key=='D') {
    // RST inter
    totKm-=10;
  }


}



void processMode2(char key){
  if (key=='#') {
    // startAvg
    avgSpeed=44;
  }
  if (key=='A') {
    // RST inter
    targetSpeed+=10;
  }
  if (key=='B') {
    // RST inter
    targetSpeed+=1;
  }
  if (key=='C') {
    // RST inter
    targetSpeed-=1;
  }
  if (key=='D') {
    // RST inter
    targetSpeed-=10;
  }


}

void processMode3(char key){
  if (key=='#') {
    // RST all
    currSpeed+=15;
  }
  if (key=='*') {
    // RST all
    currSpeed-=15;
  }
}




/*****************************************************************************************
 * 
 *       DRAWINGS
 * 
 *****************************************************************************************/
void draw1(void){
  char buf[30];
  char key = keypad.getKey();
  u8g.setFont(u8g_font_9x15);

  snprintf (buf, 30, "KM : %i", totKm);
  u8g.drawStr( 5, 40, buf);
  snprintf (buf, 30, "Inter : %i", interKm);
  u8g.drawStr( 5, 60, buf);

}

void draw2(void){
  char buf[30];
  char key = keypad.getKey();
  u8g.setFont(u8g_font_9x15);

  snprintf (buf, 30, "Moyenne : %i", avgSpeed);
  u8g.drawStr( 5, 40, buf);
  snprintf (buf, 30, "Target : %i", targetSpeed);
  u8g.drawStr( 5, 60, buf);

}



void draw3(void){
  char buf[30];
  char key = keypad.getKey();
  u8g.setFont(u8g_font_9x15);

  snprintf (buf, 30, "%i Km/h", currSpeed);
  u8g.drawStr( 5, 50, buf);
}

void draw4(void){
char buf[30];
char key = keypad.getKey();
  u8g.setFont(u8g_font_9x18);


snprintf (buf, 20, "Speed D : %i", i);
  u8g.drawStr( 5, 30, "Spd: 58 ; 90");
  u8g.drawStr( 5, 50, buf);

}

void drawHead(void){
/* 128 * 64 */
/* font: 8 */
    
    u8g.setFont(u8g_font_5x8);
    u8g.drawStr( 2, 8, "hh:mi");
    u8g.drawStr( 97, 8, "GPS: 2");
    u8g.drawFrame(0,0,30,10);
    u8g.drawFrame(95,0,33,10);

    
}

void draw(void) {
  drawHead();
if (mode=='1') draw1();
if (mode=='2') draw2();
if (mode=='3') draw3();
if (mode=='4') draw4();
}


void setup(){
    Serial.begin(57600);

    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

    u8g.setColorIndex(1);         // pixel on

    gpsPort.begin(9600);

}

void loop(){
  char key = keypad.getKey();
  
  // Reading key
  if (key) {
      Serial.println(key);
  }

  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  if (gps.available( gpsPort )) {
    gps_fix fix = gps.read();
    currSpeed = fix.speed_kph();
    
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

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        Serial.println(key);
        if (key == '1') {
          mode='1';
        }
        if (key == '2') {
          mode='2';
        }
        if (key == '3') {
          mode='3';
        }
        if (key == '4') {
          mode='4';
        }
        if (mode=='1') processMode1(key);
        if (mode=='2') processMode2(key);
        if (mode=='3') processMode3(key);
        break;

    case RELEASED:
        break;

    case HOLD:
        break;
    }
}

