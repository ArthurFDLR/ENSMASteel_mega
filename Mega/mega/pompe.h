#ifndef POMPE_INCLUDED
#define POMPE_INCLUDED
#include "Moteur.h"

class Pompe
{
  public:
	  Pompe(uint8_t pinMoteurPwr,uint8_t pinMoteurSens,uint8_t pinMoteurBrake, uint8_t pinAmp);
	  Pompe();
	  void suck();
	  void blow();
	  void stop();
	  bool isSucked();

  private:
      Motor * moteur;
      uint8_t pinAmp;

  bool taken;
};


#endif
