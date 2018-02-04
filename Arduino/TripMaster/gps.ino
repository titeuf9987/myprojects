long prevMeasure = millis();
NeoGPS::Location_t prevLocation;
/*50°31'54.0"N 4°37'10.3"E*/
/* 50.531628, 4.619511 */
NeoGPS::Location_t home( 4619511L, 50531628L );

void initGPS(void) {
  Serial.println("Init GPS");
  gpsPort.begin(9600);
}

void saveLocation(void) {
  prevPosition = fix.location;
}

void getGPS(void) {
    if (gps.available( gpsPort )) {
      gps_fix fix1 = gps.read();
      Serial.println(fix1.satellites);
    }
       /*
  
  // mesure à intervalle régulier
  //if (millis() - prevMeasure >= gpsInterval) {
    // si GPS est disponible
    if (gps.available( gpsPort )) {
       fix = gps.read();
       Serial.println("Valid Message ");
       Serial.println(fix.satellites);
      // sauve data (quand et position)

      //fix = gps.read();

      if (fix.valid.satellites) {
        Serial.println("GPS OK");
        prevMeasure = millis();

        
        sats = fix.satellites;
        Serial.println("Valid Sat ");
        Serial.println( fix.satellites);
      

        // Nombre de satellites
        if (!firstValidGPS) {
          prevLocation = fix.location;
          firstValidGPS=true;
        }
        

        currSpeed = fix.speed_kph();
        if (currSpeed < 3) currSpeed=0;

      
        // position courante
        currLat = fix.latitude ();
        currLon = fix.longitude();
        alt = fix.altitude ();

        float dist;
        dist = fix.location.DistanceKm( prevLocation );
        
        // calcule les distance et vitesse moyenne que si la distance entre précédent et courant est >= 50m
        if (dist >= 50) {
          totKm +=dist/1000;
          interKm +=dist/1000;
          // sauve position précédente
          prevLocation = fix.location;
          // calcul vitesse moyenne
          avgSpeed = interKm / ((millis()-interStart)/3600);

          // distance à SOmbreffe
          distHome = fix.location.DistanceKm( home );
          bearingHome = fix.location.BearingToDegrees( home );
        }
      }

    }
*/

  //}

}

