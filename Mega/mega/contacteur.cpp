#include "contacteur.h"

contacteur::contacteur(uint8_t pin)
{
  this->pin=pin;
  pinMode(pin,INPUT_PULLUP);
}

contacteur::contacteur()
{
}

bool contacteur::isPressed()
{
	return digitalRead(pin);
}
