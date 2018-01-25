const byte ledPin = 13;
const byte shiftPin1 = 2;
const byte resetPin1 = 3;


unsigned long StartTime = millis();



void setup() {
  Serial.begin(9600);

  Serial.println("setup");
  
  pinMode(ledPin, OUTPUT);
  pinMode(shiftPin1, INPUT);
  pinMode(resetPin1, INPUT);
}

void loop() {
  //digitalWrite(ledPin, state);

  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;

  Serial.println("loop");
  

}


