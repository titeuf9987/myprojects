#include <dht.h>
#include <SD.h>
#include <SPI.h>


dht DHT;
#define DHT11_PIN 7


int CS_PIN = 10;

File file;

void setup(){
  Serial.begin(9600);

  initializeSD();
  createFile("temp.csv");
  String data="millis;temperature;humidity";
  writeToFile(data);
  closeFile();
  
  
  
}

void loop()
{
  // Reading data 
  String data;
  int chk = DHT.read11(DHT11_PIN);
  data=String(millis())+";"+DHT.temperature+";"+DHT.humidity;  
  Serial.println(data);

  // Logging to file
  initializeSD();
  createFile("temp.csv");
  writeToFile(data);
  closeFile();

  delay(60*1000*10); //10 minutes

}

//************************************************************************************
// READ & WRITE PROCEDURES
//************************************************************************************
void initializeSD()
{
  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
}

int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    Serial.println("File created successfully.");
    return 1;
  } else
  {
    Serial.println("Error while creating file.");
    return 0;
  }
}

int writeToFile(String text)
{
  if (file)
  {
    file.println(text);
    Serial.println("Writing to file: ");
    Serial.println(text);
    return 1;
  } else
  {
    Serial.println("Couldn't write to file");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    Serial.println("File closed");
  }
}

int openFile(char filename[])
{
  file = SD.open(filename);
  if (file)
  {
    Serial.println("File opened with success!");
    return 1;
  } else
  {
    Serial.println("Error opening file...");
    return 0;
  }
}

String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}


