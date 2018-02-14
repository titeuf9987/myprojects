/*****************************************************************************************

         DRAWINGS

 *****************************************************************************************/




char printBuffer[128];
//char label[50];


void prepareString(char label[], float val,char suffix[]) {
  strcpy(printBuffer, label);
  dtostrf(val, 2, 2, &printBuffer[strlen(printBuffer)]);
  strcat(printBuffer,suffix);
}


void initDisplay(void){
  u8g.setColorIndex(1);         // pixel on
}

void drawHead(void) {
  /* 128 * 64 */
  /* font: 8 */

  u8g.setFont(u8g_font_5x8);
  u8g.drawStr( 2, 8, "hh:mi");

  prepareString("GPS: ", sats,"");
  u8g.drawStr( 97, 8, printBuffer);

  u8g.drawFrame(0, 0, 30, 10);
  u8g.drawFrame(95, 0, 33, 10);

}

long lastD=0;

// Function called by loop
void processDisplay(void){
  // If redraw at each loop ==> problem with GPS
  if (millis()-lastD > 250) {
        // picture loop
        u8g.firstPage();
        do {
          drawHead();
          if (mode == '1') draw1();
          if (mode == '2') draw2();
          if (mode == '3') draw3();
          if (mode == '4') draw4();  
        } while ( u8g.nextPage() );
        lastD=millis();
  }
  
}

