#pragma once

#include "basedrive.h"
#include <consoleio.h>
#include <system_imu.h>
#include <ArduPID.h>




#if defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_PORTENTA_H7_M7)

//using namespace mbed;
#else
#include <analogWrite.h>
typedef int PinName; 
#endif

//CMotorController mc1(PA_8,PC_6,PC_5);
//https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/issues/25
/*
Faulhaber SC1801

PWM   : 96 KHz

Up    : Power electronics
Umot  : Power motor
Unsol : Speed
FG    : Hall effect sensor
DIR   : Direction
GND   : Ground

TBeam Interrupt on Pin 25
*/

    

class PWMCounter {
private:

//https://forum.arduino.cc/t/interrupts-using-m7-vs-m4-core/675577
//need to fix  see this
    PinName _interrupt;
    char _axis='X';
    double _rps=0.0;

    unsigned long lastCount=0;
    unsigned long prevT=0;
    unsigned long lastT=0;    
    
public:
    PWMCounter();
    void axis(char s) {_axis=s;}
    char axis(){return _axis;}
    
    void config(PinName pin);

    unsigned long read();

    unsigned long getCount();
    double RPM();
    double RPS();
};


class CMotorController:public CBaseDrive{
private:
  CIMU *_pIMU=NULL;

  double _Setpoint=0.0, _Input=0.0, _Output=0.0,_Output_last=0.0;
  char _axis='X';
  double _Kp=2.0, _Ki=5.0, _Kd=1.0;

  PWMCounter pwmCounter;

  ArduPID myPID;

public:
  CMotorController();
  ~CMotorController();

  void setup(){setState("PLAY");}
  void loop();
  void off();  

  void config(PinName sig, PinName fg,PinName dir);
  void config(CMsg &msg);

  void init();
  void initMode(CMsg &msg);
  double RPM();
  double RPS();
  unsigned long getCount();
  void setIMU(CIMU *pIMU){_pIMU=pIMU;}


  void runOnce(CMsg &msg);

  void configLock(CMsg &msg);
  void configSpeed(CMsg &msg);
  void configSpeedSimple(CMsg &msg);
  void configRotation(CMsg &msg);
  void configRamp(CMsg &msg);
  void configPWM(CMsg &msg);

  void loopLock(CMsg &msg);
  void loopSpeed(CMsg &msg);
  void loopSpeedSimple(CMsg &msg);
  void loopRotation(CMsg &msg);
  void loopRamp(CMsg &msg);
  void loopPWM(CMsg &msg);


  void writeStats();
  void Speed(int s=10,unsigned long dur=0){activateDrive(s);}
  
  void setPoint(double sp,unsigned long dur=10000000){_Setpoint=sp; changed();setDuration(dur);}
  
  void activateDrive(int val);
  void test(CMsg &msg);
};

