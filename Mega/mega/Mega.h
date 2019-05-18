#ifndef MEGA_INCLUDED
#define MEGA_INCLUDED
#include "Barillet.h"
#include "Pompe.h"
#include "Elevator.h"
#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Pinces.h"
class Mega
{
public:
	Barillet barillet;
	Pompe pompeG, pompeD;
	Elevator elevator;
    MegaServo brasGauche,brasDroit,doigtGauche,doigtDroit;
    Pinces pinces;

	void actuate(float dt);
	Mega();
    Mega(float x);
	~Mega();

private:

};

#endif // !MEGA_INCLUDED
