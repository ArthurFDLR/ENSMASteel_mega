#ifndef MEGASERVO_INCLUDED
#define MEGASERVO_INCLUDED
#include "Servo.h"
enum ServoPosition {Retracted,Half,Extended};
class MegaServo
{
  public:
  MegaServo(uint8_t pin,uint16_t microsRetracted,uint16_t microsHalf,uint16_t microsExtended);
  MegaServo();
  void set(ServoPosition pos);
  ServoPosition get();
  
  private:
  Servo genuinServo;
  uint8_t pin;
  ServoPosition pos;
  uint16_t predefinedMicros[3];
};


#endif
