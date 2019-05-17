#ifndef CODEUSE_INCLUDED
#define CODEUSE_INCLUDED

#include "Arduino.h"
#include "Encoder.h"

class Codeuse
{
  public:
	  float dPos,pos;        //Vitesse et avance du robot AU NIVEAU DE LA ROUE CODEUSE
	  void actuate(float dt);     //Actualise (transforme les ticks en vitesse puis en avance)
	  Codeuse();
	  Codeuse(uint8_t pin1,uint8_t pin2,float tickToPos);  
  
  private:
	  float tickToPos;
	  int32_t ticks,oldTicks;     //Nombre de ticks compté, nombre de ticks compté au dernier appel
	  Encoder *enc;
};
#endif
