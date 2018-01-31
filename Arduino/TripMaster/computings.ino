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
 *   MODE 1 = XXXXXX
 */
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
 */

void processMode2(void){
  
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
 *   MODE 3 = XXXXXX
 */

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
 *   MODE 4 = XXXXXX
 */

void processMode4(void){
  
}
void processKeyMode4(char key) {

}


