/*****************************************************************************************

         DRAWINGS

 *****************************************************************************************/
char printBuffer[128];
//char label[50];
void prepareString(char label[], float val) {
  strcpy(printBuffer, label);
  dtostrf(val, 2, 2, &printBuffer[strlen(printBuffer)]);
}


void initDisplay(void){
  u8g.setColorIndex(1);         // pixel on
}



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
  prepareString("   KM :", totKm);
  u8g.drawStr( 5, 40, printBuffer);
  prepareString("Inter :", interKm);
  u8g.drawStr( 5, 60, printBuffer);

  //  u8g.drawStr( 5, 60, (char) prepareString("Inter : ",interKm));

}

void draw2(void) {
  char buf[30];
  u8g.setFont(u8g_font_9x15);

  snprintf (buf, 30, "Moyenne : %i", avgSpeed);
  u8g.drawStr( 5, 40, buf);
  snprintf (buf, 30, "Target : %i", targetSpeed);
  u8g.drawStr( 5, 60, buf);

}



void draw3(void) {
  char buf[30];
  u8g.setFont(u8g_font_9x15);

  snprintf (buf, 30, "%i Km/h", currSpeed);
  u8g.drawStr( 5, 50, buf);
}

void draw4(void) {
  char buf[30];
  u8g.setFont(u8g_font_9x18);


  snprintf (buf, 20, "Speed D : %i", 0);
  u8g.drawStr( 5, 30, "Spd: 58 ; 90");
  u8g.drawStr( 5, 50, buf);

}

void drawHead(void) {
  /* 128 * 64 */
  /* font: 8 */

  u8g.setFont(u8g_font_5x8);
  u8g.drawStr( 2, 8, "hh:mi");

  prepareString("GPS: ", sats);
  u8g.drawStr( 97, 8, printBuffer);

  u8g.drawFrame(0, 0, 30, 10);
  u8g.drawFrame(95, 0, 33, 10);

}

void draw(void) {
  drawHead();
  if (mode == '1') draw1();
  if (mode == '2') draw2();
  if (mode == '3') draw3();
  if (mode == '4') draw4();
}



// Function called by loop
void processDisplay(void){
    // picture loop
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
}

