#include <SoftwareSerial.h>
//#include <TinyGPS.h>
#include "TinyGPS++.h"
//TinyGPSPlus gps;

#include <LiquidCrystal.h>// include the library code
//LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
LiquidCrystal lcd(13,12,11,10,9,8);


#define GPSDELAY 2000
#define LCDDELAY 1000

// GPS variables
TinyGPSPlus gps;
SoftwareSerial ss(7, 6);


// Declaring pins
const byte ledPin = 13;
const byte shiftPin1 = 2;
const byte resetPin1 = 3;
const byte beepPin = 5;
int shiftPin1State;
int resetPin1State;



// Time computation
//unsigned long StartTime = millis();
//unsigned long currentTime;

// Display
#define NTITLES 7
int currDisplay1=0;
int currDisplay2=0;
//String displayTitles[]={"Time","Position","Current Speed","Avg Speed","Total Avg Speed","Distance","Total Distance","Heading"};
String displayTitles[]={"Hr: ","Pos: ","Spd: ","AvgSpd1: ","SpdTot: ","dRst: ","dTot: ","head: "};
//char* displayValues[NTITLES];

String currentTime;
String currentPos;
String currentSpeed;
String currentHeading;

long totDist1;
long totDist2;

long totSpeed;
long totSpeed1;
long totSpeed2;

long speed_;
long speed1;
long speed2;


int nMeasures;
int nMeasures1;
int nMeasures2;





// Locking
unsigned long shiftLockedUntil;
unsigned long resetLockedUntil;
unsigned long gpsLockedUntil;
unsigned long lcdLockedUntil;

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows: 
  lcd.print("hello, world!");
  
  //Serial.begin(9600);
  Serial.begin(19200);
  ss.begin(9600);

  Serial.println("setup");
  delay(1000);

  beep();
  
  pinMode(ledPin, OUTPUT);
  pinMode(beepPin, OUTPUT);
  pinMode(shiftPin1, INPUT);
  pinMode(resetPin1, INPUT);

}

void loop() {

  //unsigned long CurrentTime = millis();
  //unsigned long ElapsedTime = CurrentTime - StartTime;

  //Serial.println("loop");

  shiftPin1State=digitalRead(shiftPin1);
  resetPin1State=digitalRead(resetPin1);

  if(shiftPin1State==HIGH) {/*Serial.println("shiftPin1State = HIGH");*/}
  if(resetPin1State==HIGH) {/*Serial.println("resetPin1State = HIGH");*/}

  if (shiftPin1State==HIGH && resetPin1State==HIGH) {reset1();} else {digitalWrite(ledPin,LOW);}
  if (shiftPin1State==HIGH && resetPin1State!=HIGH) {shiftDisplay1();}

  //currentTime = millis();

  gpsData();

  refreshDisplay();
}

void reset1(){
  if (millis()>resetLockedUntil) {
    beep();
    digitalWrite(ledPin,HIGH);
    //Serial.print(currentTime);  
    Serial.println(" -- Resetting1");
    resetLockedUntil = millis()+500;
  }
}


void shiftDisplay1(){
  if (millis()>shiftLockedUntil) {
    beep();
    currDisplay1++;
    if (currDisplay1>NTITLES) currDisplay1=0;
    Serial.println(displayTitles[currDisplay1]);
    shiftLockedUntil = millis()+500;
  }
}

void refreshDisplay(){
  if (millis()<lcdLockedUntil) return;
  
  Serial.println("refreshDisplay");
  //Serial.println(displayTitles[currDisplay1]);
  String line1;
  String line2;

  // "Time","Position","Current Speed","Avg Speed","Total Avg Speed","Distance","Total Distance","Heading"
  line1 = displayTitles[currDisplay1];
  line2 = displayTitles[currDisplay2];
  switch (currDisplay1) {
      case 0:
              line1+=currentTime;
              break;
      case 1:
              line1+=currentPos;
              break;
      case 2:
              line1+=currentSpeed;
              break;
      case 3:
              line1+=speed1+" km/h";
              break;
      case 4:
              line1+=speed_+" km/h";
              break;
      case 5:
              break;
      case 6:
              line1+=currentHeading;
              break;
      
  }

  lcd.clear();
  
  lcd.setCursor(0, 0); // top left
  //lcd.print(displayTitles[currDisplay1]);
  lcd.print(line1);
  
  
  lcd.setCursor(0, 1); // bottom left
  //lcd.print(displayTitles[currDisplay2]);
  lcd.print(line1);

  lcdLockedUntil = millis()+LCDDELAY;
}


void beep(){
    tone( beepPin,4500, 100);
}



void gpsData(){

  // do not execute before not locked anymore
  if (gpsLockedUntil > millis()) return;
  
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      //Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
        //Serial.println("newData");
       }
  }

  if (newData)
  {
    //Serial.println("newData Print");

    currentTime = gps.time.hour()+":"+gps.time.minute();
    currentPos = String(gps.location.lat(),6) +";"+String(gps.location.lng(),6)+"(alt:"+ String(gps.altitude.meters(),0) +")";
    currentSpeed =String(gps.speed.kmph(),0)+"Km/h";

    currentHeading = gps.course.deg();

    totSpeed+=gps.speed.kmph();
    totSpeed1+=gps.speed.kmph();
    totSpeed2+=gps.speed.kmph();

    nMeasures++;
    nMeasures1++;
    nMeasures2++;

    speed_=totSpeed/nMeasures;
    speed1=totSpeed1/nMeasures1;
    speed2=totSpeed2/nMeasures2;
  
  }


  gpsLockedUntil = millis()+GPSDELAY;
    
}
