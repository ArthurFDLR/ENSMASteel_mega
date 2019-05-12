#ifndef MEGA_INCLUDED
#define MEGA_INCLUDED
#include "Barillet.h"
#include "pompe.h"
#include "elevator.h"

class Mega
{
public:
	Barillet barillet;
	Pompe pompeG, pompeD;
	Elevator elevator;

	void Actuate(float dT);
	Mega();
	~Mega();

private:

};

#endif // !MEGA_INCLUDED
