void getGPS(void){
    if (gps.available( gpsPort )) {
    gps_fix fix = gps.read();
    currSpeed = fix.speed_kph();

    sats = fix.satellites;
    currSpeed = fix.speed_kph();
    currLat = fix.latitude ();
    currLon = fix.longitude();
    alt = fix.altitude ();

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

