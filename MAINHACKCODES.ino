#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT
#include <RemoteXY.h>

#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200 // speed for the wifi serial 
#define REMOTEXY_WIFI_SSID "Smart_Alert" // Wifi SSID
#define REMOTEXY_WIFI_PASSWORD "abcd1234" // WIFI PASSWORD
#define REMOTEXY_SERVER_PORT 6377 // WIFI server port

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   
  { 255,5,0,0,0,53,0,16,111,1,129,0,1,6,42,7,133,83,77,65,
  82,84,32,65,108,101,114,116,0,8,0,15,20,35,35,8,2,0,6,63,
  50,25,37,165,95,94,79,78,0,79,70,70,0,130,1,53,2,8,8,137 };
  
// defines all the variables and events of control interface 
struct {
  float compass_1; // from 0 to 359.999 for compass reading in degrees
  uint8_t switch_1; // 1 if switch ON and 0 if OFF 

  uint8_t connect_flag;  // 1 if wire connected in arduino else =0 

} RemoteXY;
#pragma pack(pop)

#define PIN_SWITCH_1 4 //define switch D4 to buzzer in default in Arduino Uno

void setup() 
{
  RemoteXY_Init (); 
  pinMode (PIN_SWITCH_1, OUTPUT); //output for the buzzer from the switch 
}

void loop() 
{ 
  RemoteXY_Handler ();
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
}
