#include "Mega.h"

void Mega::Actuate(float dT)
{
	barillet.Actuate(dT);
}

Mega::Mega()
{
	elevator.init();
}

Mega::~Mega()
{
}
