#ifndef ELEVATOR_INCLUDED
#define ELEVATOR_INCLUDED
#include "Arduino.h"

#define LONGUEUR_COURSE 0.1

class contacteur;
class Codeuse;
class PID;

enum state_elev {UP,DOWN};

class elevator
{
  private:
	  state_elev state;
	  float pos,aim;
	  contacteur *contacteurHaut;
	  contacteur *contacteurBas;
	  Codeuse *codeuseElevator;
	  PID *pidElevator;

  public:
  
	  elevator(uint8_t pinContacteurBas, uint8_t pinContacteurHaut,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos);
	  elevator();
  
	  void up(); // faire monter les ventouses
	  void down(); // faire descendre les ventouses
	  bool init();
};

#endif
