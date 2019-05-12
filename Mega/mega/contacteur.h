#ifndef CONTACTEUR_INCLUDED
#define CONTACTEUR_INCLUDED
#include "Arduino.h"

class contacteur
{
  uint8_t pin;
  
  public:
	  contacteur(uint8_t pin);
	  contacteur();
	  bool isPressed();
};


#endif
