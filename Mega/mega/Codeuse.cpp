#include "Codeuse.h"

void Codeuse::actuate(float dt)
{
  ticks=enc->read();
  dPos=(ticks-oldTicks)*tickToPos/dt;
  pos+=dPos*dt;
  oldTicks=ticks;
}

Codeuse::Codeuse(uint8_t pin1,uint8_t pin2,float tickToPos)
{ 
  enc=new Encoder(pin1,pin2);
  ticks=0;
  oldTicks=0;
  pos=0.0;
  dPos=0.0;
  this->tickToPos=tickToPos;
}

Codeuse::Codeuse()
{  
}
