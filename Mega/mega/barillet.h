#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"
#include "Codeuse.h"
#include "1_CONSTANTS.h"
#include "FILO.h"

class Barillet
{
	public:
		Codeuse *codeuseBarillet;
		PID *pidBarillet;
		FILO trous[6];

		Barillet();
		void AddPalet(int trouId, PaletE couleur);
		void Actuate(float dT);
		int get_pos();	// obtenir position actuelle
		void set_pos(int pos);	// aller à la position souhaité
		void turn(int nb); // tourner de nb case (+ sens trigo, - sens horraire)
	
	private:
		int m_pos;
};

#endif
