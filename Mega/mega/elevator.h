#ifndef ELEVATOR_INCLUDED
#define ELEVATOR_INCLUDED
#include "Arduino.h"
#include "Moteur.h"
#include "1_CONSTANTS.h"

class contacteur;
class Codeuse;
class PID;

class Elevator
{
  private:
	  Moteur mot;
	  ElevatorStateE state;
	  float pos,aim;
	  contacteur *contacteurHaut;
	  contacteur *contacteurBas;
	  Codeuse *codeuseElevator;
	  PID *pidElevator;

  public:
  
	  Elevator(uint8_t pinContacteurBas, uint8_t pinContacteurHaut,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos);
	  Elevator();
  
	  void up(); // faire monter les ventouses
	  void down(); // faire descendre les ventouses
	  bool init();
};

#endif
