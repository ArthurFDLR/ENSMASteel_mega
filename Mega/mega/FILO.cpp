#include "FILO.h"

void FILO::pop()
{
	if (currentPos > -1)
	{
		currentPos--;
	}
}

PaletE FILO::getCurrentPalet()
{
	if (currentPos > -1)
	{
		return palets[currentPos];
	}
	else
	{
		return PaletE::VIDE;		// Si jamais c'est vide
	}
}

void FILO::addPalet(PaletE couleur)
{
	if (currentPos < (TAILLE_FILO - 1))
	{
		currentPos++;
		palets[currentPos] = couleur;
	}
}

FILO::FILO()
{
	currentPos = -1;	// FILO vide
}

FILO::~FILO()
{
}
