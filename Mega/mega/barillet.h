#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"
#include "Codeuse.h"

class barillet
{
	public:
		Codeuse *codeuseBarillet;
		PID *pidBarillet;

		barillet();
		int get_pos();	// obtenir position actuelle
		void set_pos(int pos);	// aller à la position souhaité
		void turn(int nb); // tourner de nb case (+ sens trigo, - sens horraire)
	
	private:
		int m_pos;
};

#endif
