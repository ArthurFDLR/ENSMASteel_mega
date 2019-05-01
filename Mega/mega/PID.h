#ifndef PID_INCLUDED
#define PID_INCLUDED

#include "Filtre.h"

float normalize(float x);

class PID
{
  float I,KP,KI,KD;
  bool needNormalizing;
  Filtre dPosFiltered;
  
  public:
  float compute(float dt,float aim,float pos,float dPosRaw);
  PID(bool needNormalizing, float KP, float KI, float KD,float cutFrequency,float initValue);
  PID();
};

#endif
