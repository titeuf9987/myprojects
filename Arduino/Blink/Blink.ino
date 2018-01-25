/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial.print('Initialized');
  Serial.println('/');
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  char inByte = ' ';
  if(Serial.available()){ // only send data back if data has been sent
    char inByte = Serial.read(); // read the incoming data
    Serial.println(inByte); // send the data back in a new line so that it is not all one long line
    if (inByte=='1') {
          digitalWrite(13, HIGH);    // turn the LED off by making the voltage LOW

      } else {
          digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

        }
      

  }
  delay(100); // delay for 1/10 of a second
}
    
  

