/*****************************************************************************************

         PROCESSINGS

 *****************************************************************************************/

float interKm = 115;
float totKm = 116;

int targetSpeed = 30;
int avgSpeed = 0;
boolean computeAvgSpeed = false;



void processMode1(char key) {
  Serial.println(key);
  if (key == '#') {
    // RST all
    totKm = 0;
    interKm = 0;
  }
  if (key == '*') {
    // RST inter
    interKm = 0;
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



void processMode2(char key) {
  if (key == '#') {
    // startAvg
    avgSpeed = 0;
  }
  if (key == 'A') {
    // RST inter
    targetSpeed += 10;
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

void processMode3(char key) {
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

void processMode4(char key) {

}


