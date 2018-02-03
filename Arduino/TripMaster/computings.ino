/*****************************************************************************************

         PROCESSINGS

 *****************************************************************************************/



float interKm = 0;
float totKm = 0;
int interStart=0;

int targetSpeed = 30;
int avgSpeed = 0;
boolean computeAvgSpeed = false;

void doComputes(void){
  switch(mode){
    case 1: processMode1();
            break;
    case 2: processMode2();
            break;     
    case 3: processMode3();
            break;
    case 4: processMode4();
            break;
  }
}


/*****************************************
 *   MODE 1 = Km et intermédiaires
 *   
 *   
 *   --------------
 *      KM: XXX.X
 *   Inter: XXX.X
 *   --------------
 *   
 *   
 */
void draw1(void) {
  /****************
     Original
  */
  /*
    char buf[30];
    char key = keypad.getKey();
    u8g.setFont(u8g_font_9x15);

    snprintf (buf, 30, "KM : %i", totKm);
    u8g.drawStr( 5, 40, buf);
    snprintf (buf, 30, "Inter : %i", interKm);
    u8g.drawStr( 5, 60, buf);
  */
  u8g.setFont(u8g_font_9x15);
  prepareString(" Dist: ", totKm,"");
  u8g.drawStr( 5, 30, printBuffer);
  prepareString("Inter: ", interKm,"");
  u8g.drawStr( 5, 50, printBuffer);

  //  u8g.drawStr( 5, 60, (char) prepareString("Inter : ",interKm));

}

void processMode1(void){
  
}


void processKeyMode1(char key) {
  Serial.println(key);
  if (key == '#') {
    // RST all
    totKm = 0;
    interKm = 0;
    interStart=millis();
  }
  if (key == '*') {
    // RST inter
    interKm = 0;
    interStart=millis();
  }
  if (key == 'A') {
    // RST inter
    interKm += 1;
    totKm += 1;
  }
  if (key == 'B') {
    // RST inter
    interKm += 0.1;
    totKm += 0.1;
  }
  if (key == 'C') {
    // RST inter
    interKm -= 0.1;
    totKm -= 0.1;
  }
  if (key == 'D') {
    // RST inter
    interKm -= 1;
    totKm -= 1;
  }


}






/*****************************************
 *   MODE 2 = XXXXXX
 *   
 *   --------------
 *    Cible: XXX
 *     Km/h: XXX.X
 *      Moy: XXX.X
 *   ?????
 *   --------------
 *   
 *   
 *   
 *   
 */

void processMode2(void){

}

void draw2(void) {
  u8g.setFont(u8g_font_6x13);
  prepareString("  Cible:", targetSpeed," Km/h");
  u8g.drawStr( 5, 24, printBuffer);
  prepareString("Moyenne:", avgSpeed," Km/h");
  u8g.drawStr( 5, 40, printBuffer);
  prepareString("  Dist.:", interKm," Km");
  u8g.drawStr( 5, 56, printBuffer);

}



void processKeyMode2(char key) {
  if (key == '#') {
    // startAvg
    avgSpeed = 0;
    interKm = 0;
    interStart=millis();

  }
  if (key == 'A') {
    // RST inter
    targetSpeed += 10;
    interKm = 0;
    interStart=millis();
  }
  if (key == 'B') {
    // RST inter
    targetSpeed += 1;
  }
  if (key == 'C') {
    // RST inter
    targetSpeed -= 1;
  }
  if (key == 'D') {
    // RST inter
    targetSpeed -= 10;
  }


}


/*****************************************
 *   MODE 3 = Vitesse
 *   
 *   
 *   --------------
 *     Km/h: XXX.X
 *   --------------
 *   
 */

 void draw3(void) {
  u8g.setFont(u8g_font_10x20);
  prepareString("  ", currSpeed," Km/h");
  u8g.drawStr( 5, 45, printBuffer);
}



void processMode3(void){
  
}


void processKeyMode3(char key) {
  if (key == '#') {
    // RST all
    avgSpeed = 0;
    computeAvgSpeed = true;
  }
  if (key == '*') {
    // RST all
    avgSpeed = 0;
  }
}

/*****************************************
 *   MODE 4 = GPS / Position
 *   
 *   
 *   
  *   --------------
 *      Lat/lon: X°XX'XX.X" / X°XX'XX.X"
 *    Direction:  XXX.X°
 *    Sombreffe: XXX.X Km
 *   ?????
 *   --------------
*   
 *   
 */

void draw4(void) {
/*
float currLat;
float currLon;
float distHome;
float bearingHome;
 */

  
  u8g.setFont(u8g_font_9x15);
  prepareString("Home: ", distHome," Km");
  u8g.drawStr( 5, 30, printBuffer);
  prepareString("Dir.: ", bearingHome,"");
  u8g.drawStr( 5, 50, printBuffer);


} 

void processMode4(void){
  
}
void processKeyMode4(char key) {

}


