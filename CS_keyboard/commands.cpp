#include "kb.h"
 
void CKeyboard::myInit(){
  _simpleCMDs[std::string("normal")]=std::string("SYS:SAT~ACT:NEWSTATE~V:NORMAL~ACK:0");
  _simpleCMDs[std::string("lowpower")]=std::string("SYS:SAT~ACT:NEWSTATE~V:LOWPOWER~ACK:0");
  _simpleCMDs[std::string("deploy")]=std::string("SYS:SAT~ACT:NEWSTATE~V:DEPLOY~ACK:0");  
  _simpleCMDs[std::string("adcs")]=std::string("SYS:SAT~ACT:NEWSTATE~V:ADCS~ACK:0");
  _simpleCMDs[std::string("detumble")]=std::string("SYS:SAT~ACT:NEWSTATE~V:DETUMBLE~ACK:0");
  _simpleCMDs[std::string("payload")]=std::string("SYS:SAT~ACT:NEWSTATE~V:PAYLOAD~ACK:0");
  _simpleCMDs[std::string("alex")]=std::string("SYS:SAT~ACT:NEWSTATE~V:ALEX~ACK:0");
  _simpleCMDs[std::string("addalex")]=std::string("SYS:SAT~ACT:ADDSTATE~V:ALEX~ACK:0");
  _simpleCMDs[std::string("addgps")]=std::string("SYS:ALEX~ACT:ADDSYSTEM~V:GPS~ACK:0");

  _simpleCMDs[std::string("set")]=std::string("SYS:RELAY~to:all~V:Hello World~ACK:0");
  _simpleCMDs[std::string("get")]=std::string("SYS:RELAY~ACT:GET~to:all~ACK:0");
  
  _simpleCMDs[std::string("stats")]=std::string("SYS:SAT~ACT:STATS~ACK:0");
  _simpleCMDs[std::string("reset")]=std::string("SYS:SAT~ACT:RESET~ACK:0");
  _simpleCMDs[std::string("counts")]=std::string("SYS:SAT~ACT:COUNTS");
  _simpleCMDs["beacon"]=std::string("SYS:SAT~ACT:BEACON");

  _simpleCMDs[std::string("transmitdata")]=std::string("SYS:SAT~ACT:TRANSMITDATA~ACK:0");
  _simpleCMDs[std::string("datalistclear")]=std::string("SYS:SAT~ACT:DATALISTCLEAR~ACK:0"); 
  _simpleCMDs[std::string("messagelistclear")]=std::string("SYS:SAT~ACT:MESSAGESLISTCLEAR~ACK:0");
  _simpleCMDs[std::string("transmitlistclear")]=std::string("SYS:SAT~ACT:TRANSMITLISTCLEAR~ACK:0");
  _simpleCMDs[std::string("transmittedlistclear")]=std::string("SYS:SAT~ACT:TRANSMITTEDLISTCLEAR~ACK:0");
  _simpleCMDs[std::string("datatest")]=std::string("SYS:SAT~ACT:OUTPUT~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999");   
  _simpleCMDs[std::string("acktest")]=std::string("SYS:SAT~ACT:OUTPUT~ACK:0~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999"); 

  _simpleCMDs["switchradios"]=std::string("SYS:SAT~ACT:UPDATERADIOS~TRANSMITTER:RADIO");
  _simpleCMDs["switchradios2"]=std::string("SYS:SAT~ACT:UPDATERADIOS~TRANSMITTER:RADIO2");
  _simpleCMDs["sleepradios"]=std::string("SYS:SAT~ACT:UPDATERADIOS~SLEEP:RADIO");
  _simpleCMDs["sleepradios2"]=std::string("SYS:SAT~ACT:UPDATERADIOS~SLEEP:RADIO2");
 
  _simpleCMDs[std::string("gps")]=std::string("SYS:GPS~ACT:START~ACK:0");
   
  _simpleCMDs[std::string("phonegps")]=std::string("SYS:PHONE~ACT:CGPS~ACK:0");
  _simpleCMDs[std::string("phonetime")]=std::string("SYS:PHONE~ACT:CTIME~ACK:0");
  _simpleCMDs[std::string("photo")]=std::string("SYS:PHONE~ACT:CPHOTO(B,50%,100,100,AUTO)");    
  _simpleCMDs[std::string("light")]=std::string("SYS:LIGHT~ACT:START");  
  
  _simpleCMDs[std::string("irx")]=std::string("SYS:IRX1~ACT:START");  
  _simpleCMDs[std::string("irxout")]=std::string("SYS:IRX1~ACT:OUTPUT~TYPE:A");  
  _simpleCMDs[std::string("irxsend")]=std::string("SYS:MGR~ACT:ADD~_SYS:IRX1~_ACT:OUTPUT~TYPE:A~_INTERVAL:60000~_START:0~_STOP:1000000");  
  _simpleCMDs[std::string("forwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  _simpleCMDs[std::string("backwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  _simpleCMDs[std::string("forwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  _simpleCMDs[std::string("backwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  _simpleCMDs[std::string("forwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  _simpleCMDs[std::string("backwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
   
  _simpleCMDs[std::string("dur1")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~D:000000000000000000000000001111111111111111111111111111112222222222222222222222222333333333333333333333344444444444"); 

  _simpleCMDs["chktemperature"]=std::string("SYS:MGR~ACT:CHKTEMPERATURE");
  _simpleCMDs["chkradio"]=std::string("SYS:MGR~ACT:CHKRADIO");
  _simpleCMDs["chkbattery"]=std::string("SYS:MGR~ACT:CHKBATTERY");
  _simpleCMDs["chkrotation"]=std::string("SYS:MGR~ACT:CHKROTATION");
  _simpleCMDs["chkmessages"]=std::string("SYS:MGR~ACT:CHKMESSAGES");
  _simpleCMDs["chkirarrays"]=std::string("SYS:MGR~ACT:CHKIRARRAYS");

  _simpleCMDs["filldata"]=std::string("SYS:MGR~ACT:FILLDATA");
  
  _simpleCMDs["radio"]=std::string("SYS:MGR~ACT:RADIO");
  _simpleCMDs["highbw"]=std::string("SYS:RADIO2~ACT:MODEM~VAL:HIGHBW");
  _simpleCMDs["mediumbw"]=std::string("SYS:RADIO2~ACT:MODEM~VAL:MEDIUMBW");
  _simpleCMDs["lowbw"]=std::string("SYS:RADIO~ACT:MODEM~VAL:LOWBW");
  _simpleCMDs["normalbw"]=std::string("SYS:RADIO2~ACT:MODEM");

  
  _simpleCMDs["mag"]=std::string("SYS:MGR~ACT:MAG");
  _simpleCMDs["magx"]=std::string("SYS:MGR~ACT:MAGX");
  _simpleCMDs["magy"]=std::string("SYS:MGR~ACT:MAGY");
  _simpleCMDs["magz"]=std::string("SYS:MGR~ACT:MAGZ");

  _simpleCMDs["motorx"]=std::string("SYS:MGR~ACT:MOTORX~SETPOINT:2767~MODE:PWM~DURATION:10000");  //SPEED  SIMPLE  ROTATION RAMP  PWM
  _simpleCMDs["motory"]=std::string("SYS:MGR~ACT:MOTORY~SETPOINT:2767~MODE:PWM~DURATION:10000");
  _simpleCMDs["motorz"]=std::string("SYS:MGR~ACT:MOTORZ~SETPOINT:2767~MODE:PWM~DURATION:10000");

  _simpleCMDs["newmode"]=std::string("SYS:MOTORX~ACT:NEWMODE~MODE:PWM~SETPOINT:1600~DURATION:10000");
  
  _simpleCMDs["magdx"]=std::string("SYS:MGR~ACT:MAGDX");
  _simpleCMDs["magdy"]=std::string("SYS:MGR~ACT:MAGDY");
  _simpleCMDs["magdz"]=std::string("SYS:MGR~ACT:MAGDZ");

  _simpleCMDs["mblogic"]=std::string("SYS:MGR~ACT:MBLOGICON");
  _simpleCMDs["mblogicoff"]=std::string("SYS:MGR~ACT:MBLOGICOFF");

  _simpleCMDs["sensorson"]=std::string("SYS:MGR~ACT:SENSORSON");
  _simpleCMDs["sensorsoff"]=std::string("SYS:MGR~ACT:SENSORSOFF");

  _simpleCMDs["65Von"]=std::string("SYS:MGR~ACT:65VON");
  _simpleCMDs["65Voff"]=std::string("SYS:MGR~ACT:65VOFF");
  
  _simpleCMDs["allon"]=std::string("SYS:MGR~ACT:ALLON");
  _simpleCMDs["alloff"]=std::string("SYS:MGR~ACT:ALLOFF");
  
  _simpleCMDs["pinson"]=std::string("SYS:MGR~ACT:PINSON");
  _simpleCMDs["pinsoff"]=std::string("SYS:MGR~ACT:PINSOFF");
  _simpleCMDs["phoneon"]=std::string("SYS:MGR~ACT:PHONEON");
  _simpleCMDs["phoneoff"]=std::string("SYS:MGR~ACT:PHONEOFF");  
  
  _simpleCMDs["imuspi"]=std::string("SYS:IMUSPI~ACT:START");  
  _simpleCMDs["imui2c"]=std::string("SYS:IMUI2C~ACT:START");
  
  _simpleCMDs["imui2ct"]=std::string("SYS:MGR~ACT:IMUI2C");
  _simpleCMDs["imuspit"]=std::string("SYS:MGR~ACT:IMUSPI");
  
  _simpleCMDs["i2c0"]=std::string("SYS:MGR~ACT:I2C0");
  _simpleCMDs["i2c1"]=std::string("SYS:MGR~ACT:I2C1");
  _simpleCMDs["i2c2"]=std::string("SYS:MGR~ACT:I2C2");

  _simpleCMDs["reseti2c0"]=std::string("SYS:MGR~ACT:RESETI2C0");
  _simpleCMDs["reseti2c1"]=std::string("SYS:MGR~ACT:RESETI2C1");
  _simpleCMDs["reseti2c2"]=std::string("SYS:MGR~ACT:RESETI2C2");

  _simpleCMDs["irx1"]=std::string("SYS:MGR~ACT:IRX1");
  _simpleCMDs["irx2"]=std::string("SYS:MGR~ACT:IRX2");
  _simpleCMDs["iry1"]=std::string("SYS:MGR~ACT:IRY1");
  _simpleCMDs["iry2"]=std::string("SYS:MGR~ACT:IRY2");
  _simpleCMDs["irz1"]=std::string("SYS:MGR~ACT:IRZ1");
  _simpleCMDs["irz2"]=std::string("SYS:MGR~ACT:IRZ2");

  _simpleCMDs["tempx1"]=std::string("SYS:MGR~ACT:TEMPX1");
  _simpleCMDs["tempy1"]=std::string("SYS:MGR~ACT:TEMPY1");
  _simpleCMDs["tempz1"]=std::string("SYS:MGR~ACT:TEMPZ1");

  _simpleCMDs["tempx2"]=std::string("SYS:MGR~ACT:TEMPX2");
  _simpleCMDs["tempy2"]=std::string("SYS:MGR~ACT:TEMPY2");
  _simpleCMDs["tempz2"]=std::string("SYS:MGR~ACT:TEMPZ2");

  _simpleCMDs["tempobc"]=std::string("SYS:MGR~ACT:TEMPOBC");
  _simpleCMDs["enablei2c"]=std::string("SYS:MGR~ACT:ENABLEI2C");
  _simpleCMDs["disablei2c"]=std::string("SYS:MGR~ACT:DISABLEI2C");
   
  _simpleCMDs["H"]=std::string("SYS:MGR~ACT:H4");
  _simpleCMDs["L"]=std::string("SYS:MGR~ACT:L4");
  _simpleCMDs["W"]=std::string("SYS:MGR~ACT:PWM4");  
}
