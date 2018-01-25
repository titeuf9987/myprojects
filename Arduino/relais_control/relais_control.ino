

const byte speedPin = 4;
const byte delayPin = 3;
const byte relayPin = 2;

int ledPin = 13; 

int speedPinStatus;
int delayPinStatus;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, INPUT);
  pinMode(delayPin, INPUT);
  pinMode(relayPin, OUTPUT);

  pinMode(ledPin, OUTPUT);  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 speedPinStatus=analogRead(speedPin);
 delayPinStatus=analogRead(delayPin);


 digitalWrite(ledPin, HIGH);  // turn the ledPin on
 digitalWrite(relayPin, HIGH);  // turn the ledPin on
 delay(speedPinStatus);

 digitalWrite(ledPin, LOW);
 digitalWrite(relayPin, LOW);
 delay(delayPinStatus);

 

}
