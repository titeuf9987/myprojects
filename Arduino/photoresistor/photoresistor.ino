/*----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------
*/

int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
    
}

void loop()
{

    int light = analogRead(lightPin);

    int ledLight = light - 385;
    ledLight = ledLight * (255 / 40);
    if (ledLight < 0) ledLight = 0;
    
    Serial.println(ledLight);
    
    //Serial.println(analogRead(light)); //Write the value of the photoresistor to the serial monitor.
    analogWrite(ledPin, ledLight);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
                                                
   delay(100); //short delay for faster response to light.
}
