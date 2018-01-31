long prevMeasure = millis();
NeoGPS::Location_t prevLocation;

void initGPS(void) {
  gpsPort.begin(9600);
}

void saveLocation(void) {
  prevPosition = fix.location;
}

void getGPS(void) {
  // mesure à intervalle régulier
  if (millis() - prevMeasure >= gpsInterval) {
    // si GPS est disponible
    if (gps.available( gpsPort )) {
      // sauve data (quand et position)
      prevMeasure = millis();
      fix = gps.read();
      
      // vitesse
      if (fix.valid.speed) {
        currSpeed = fix.speed_kph();
        if (currSpeed < 3) currSpeed=0;
      }
      // Nombre de satellites
      if (fix.valid.satellites) {
        sats = fix.satellites;
      }

      // calcul sur emplacement
      if (fix.valid.location) {
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
        }
        
        /*
          float bearingToLondon = fix.location.BearingToDegrees( London );
          bool  validDT         = fix.valid.date & fix.valid.time;

          print(             fix.satellites       , fix.valid.satellites, 3             );
          print(             fix.hdop/1000.0      , fix.valid.hdop      , 6, 2          );
          print(             fix.latitude ()      , fix.valid.location  , 10, 6         );
          print(             fix.longitude()      , fix.valid.location  , 11, 6         );
          print(             fix.dateTime         , validDT             , 20            );
          print(             fix.altitude ()      , fix.valid.altitude  , 7, 2          );
          print(             fix.speed_kph()      , fix.valid.speed     , 7, 2          );
          print(             fix.heading  ()      , fix.valid.heading   , 7, 2          );
          print( compassDir( fix.heading  () )    , fix.valid.heading   , 4             );
          print( fix.location.DistanceKm( London ), fix.valid.location  , 5             );
          print(             bearingToLondon      , fix.valid.location  , 7, 2          );
          print( compassDir( bearingToLondon )    , fix.valid.location  , 4             );

          print( gps.statistics.chars , true, 10 );
          print( gps.statistics.ok    , true,  6 );
          print( gps.statistics.errors, true,  6 );
        */
      }

    }


  }

}

