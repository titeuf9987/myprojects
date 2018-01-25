#define analogPin A0 //the thermistor attach to 
#define beta 4090.0 //the beta of the thermistor


#define THERMISTORNOMINAL 1020.0      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25.0  
// how many samples to take and average, more takes longer
// the value of the 'other' resistor
#define SERIESRESISTOR 10000.0    


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //Begin serial communcation
  Serial.println("Setup");
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Loop");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second

  
  long a =analogRead(analogPin);
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  Serial.print("1st: ");
  Serial.println(tempC);
  
  
  Serial.print("3rd: ");
  Serial.println(Thermistor(analogRead(analogPin)));
  

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    
}


double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}
