#include "MegaServo.h"
#include "Servo.h"
MegaServo::MegaServo(uint8_t pin,uint16_t microsRetracted,uint16_t microsHalf,uint16_t microsExtended)
{
  this->pin=pin;
  genuinServo.attach(pin);
  this->pos=ServoPosition::Extended;
  this->predefinedMicros[ServoPosition::Retracted]=microsRetracted;
  this->predefinedMicros[ServoPosition::Half]=microsHalf;
  this->predefinedMicros[ServoPosition::Extended]=microsExtended;
  set(ServoPosition::Half);
}

void MegaServo::set(ServoPosition pos)
{
  this->pos=pos;
  genuinServo.writeMicroseconds(predefinedMicros[pos]);
}

ServoPosition MegaServo::get()
{
  return pos;
}

MegaServo::MegaServo()
{
  
}
