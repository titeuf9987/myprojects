/*
   BYJ48 Stepper motor code
   Connect :
   IN1 >> D8
   IN2 >> D9
   IN3 >> D10
   IN4 >> D11
   VCC ... 5V Prefer to use external 5V Source
   Gnd
   written By :Mohannad Rawashdeh
  http://www.instructables.com/member/Mohannad+Rawashdeh/
     28/9/2013
  */

#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

#define COMMON_ANODE

#define INITIALLOOPS 50 // should be 50
#define KEEPCHARGED 10 // should be 10


int redPin = 7;
int greenPin = 6;
int bluePin = 5;

int currentStep = 0;
int lSpeed=3; // speed (delay between two steps (2 is lowest))


boolean currentDirection = false;// gre (false=clockwise)
unsigned long last_time;
unsigned long currentMillis ;

boolean bFirstloop=true;

void setup()
{
  Serial.begin(115200);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);   
  
  // démarrage=rouge
  setColor(255, 0, 0);  // red
  
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  delay(1000);

}


void loop()
{
  // pour la première fois: 50 loops: recharge la montre.
  if (bFirstloop){
    windInit();
  } else {
    // tourne=vert
    setColor(0, 255, 0);  // green

    for(int i=0;i<KEEPCHARGED;i++){
      oneTurn();
      halfTurn();
      
    }
  }
  
  // jaune en pause
  setColor(255, 255, 0);  // yellow
  
  delay(15*60*1000);

}

void windInit(){
      // init = bleu
    setColor(0, 0, 255);  // blue
    lSpeed=2;
    for(int i=0;i<INITIALLOOPS;i++){
      //halfTurn();
      oneTurn();
      halfTurn();
      currentDirection=!currentDirection;
      }
    bFirstloop=false;
//    lSpeed=3;


  }


void setColor(int red, int green, int blue)
{

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}


void halfTurn(){
  steps(4094/2); 
  //currentDirection=!currentDirection;
}


void oneTurn(){
  steps(4095); 
  //currentDirection=!currentDirection;
}


void steps(int xw){
  for (int x=0;x<xw;x++){
  switch(currentStep){
   case 0:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   case 1:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
   break; 
   case 2:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 3:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 4:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 5:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
     case 6:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 7:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   default:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
}
  delay(lSpeed);
  computeNextStep();
}
} 

void computeNextStep(){
  if(currentDirection==1){ currentStep++;}
  if(currentDirection==0){ currentStep--; }
  if(currentStep>7){currentStep=0;}
  if(currentStep<0){currentStep=7; }
}

