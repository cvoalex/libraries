
#pragma once


#if defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_PORTENTA_H7_M7)
#else
#include <systemobject.h>
#include <string>
#include <TinyGPS++.h>
#include <axp20x.h>
#include <boards.h>

#define _LAT "LAT"
#define _LON "LON"
#define _ALT "ALT"

#define _SATSV "SATSV"
#define _GPSTIME "GPSTIME"
#define _LATLON "LATLON"
#define _GPS "GPS"

class CGPS :public CSystemObject {
 
  TinyGPSPlus gps;
  AXP20X_Class axp;



  float latitude=0.0;
  float longitude=0.0;
  float altitude=0.0;
  char SIV=' ';
  int Yr=0;
  int Mon=0;
  int Day=0;
  int Hr=0;
  int Min=0;
  int Sec=0;
  long Speed=0;
  long last = 0UL;
public:

  CGPS();
  ~CGPS();
  void setup();

  void loop();
  void init();
  void output();
  void runOnce(CMsg &msg);  
  void fillData();

};

#endif
