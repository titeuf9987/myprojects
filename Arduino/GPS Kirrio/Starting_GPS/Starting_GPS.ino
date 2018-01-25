#include<SoftwareSerial.h>

// GPS Setup
#define rxGPS 0
#define txGPS 1
#define ledPin 13
SoftwareSerial serialGPS = SoftwareSerial(rxGPS, txGPS);
String stringGPS = "";

void setup() {
  pinMode(rxGPS, INPUT);
  pinMode(txGPS, OUTPUT);
  pinMode(ledPin, OUTPUT); 
  
  digitalWrite(ledPin, LOW);


  Serial.begin(9600);
  Serial.println("Started");

  // GPS Setup
  serialGPS.begin(4800);
  digitalWrite(txGPS,HIGH);

  // Cut first gibberish
  while(serialGPS.available()){
    Serial.println("Available");
    if (serialGPS.read() == '\r')
      break;}
}

void loop()
{
  String s = checkGPS();
  //Serial.println(s);
  if(s && s.substring(0, 6) == "$GPGGA")
  {
    Serial.println(s);
  }
}

// Check GPS and returns string if full line recorded, else false
String checkGPS()
{
  if (serialGPS.available())
  {
    char c = serialGPS.read();
    Serial.println(c);
    if (c != '\n' && c != '\r')
    {
      stringGPS  = c;
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      if (stringGPS != "")
      {
        //String tmp = stringGPS;
        String tmp = "toto";
        stringGPS = "";
        return tmp;
      }
    }
  }
  digitalWrite(ledPin, LOW);
  return "";
}
