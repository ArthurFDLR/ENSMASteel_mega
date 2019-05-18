#include "Contacteur.h"

Contacteur::Contacteur(uint8_t pin)
{
  this->pin=pin;
  pinMode(pin,INPUT);
}

Contacteur::Contacteur()
{
}

bool Contacteur::isPressed()
{
	return digitalRead(pin);
}
