#ifndef CONTACTEUR_INCLUDED
#define CONTACTEUR_INCLUDED
#include "Arduino.h"

class Contacteur
{
  uint8_t pin;

  public:
	  Contacteur(uint8_t pin);
	  Contacteur();
	  bool isPressed();
};


#endif
