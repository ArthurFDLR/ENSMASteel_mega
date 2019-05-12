#ifndef FILO_INCLUDE
#define FILO_INCLUDE
#include "1_CONSTANTS.h"

// FILO (first in last out) pour compter l'ensemble des palets se trouvant dans 1 des 6 conteneurs 
// currentPos = -1 -> vide

class FILO
{
public:
	PaletE palets[TAILLE_FILO];
	int currentPos;

	void pop();						// Enleve le palet de dessus
	PaletE getCurrentPalet();		// Donne la couleur du palet de dessus
	void addPalet(PaletE couleur);

	FILO();
	~FILO();

private:

};

#endif // !FILO_INCLUDE
