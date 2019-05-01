#include "PID.h"
#include "Arduino.h"
#define MAXPWM 255

float normalize(float x)
{
  //TODO   Doit renvoyer un x entre -PI et PI
  return 1;
}

float PID::compute(float dt,float aim,float pos,float dPosRaw)
{
      float error=(needNormalizing)?(normalize(aim-pos)):(aim-pos);
      dPosFiltered.in(dPosRaw,dt);
      I+=error*dt;
      float order=constrain(KP*error + KI*I - KD*dPosFiltered.out(),-MAXPWM , MAXPWM);
      return ((int32_t)order );
}

PID::PID(bool needNormalizing, float KP, float KI, float KD,float cutFrequency,float initValue)
{
  this->needNormalizing=needNormalizing;
  this->I=0;
  this->KP=KP;this->KI=KI;this->KD=KD;
  this->dPosFiltered=*(new Filtre(initValue,cutFrequency,LOWPASS2));
}
