#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"

class barillet
{
	public:
	
	barillet();
	PID pidBarillet;
	int get_pos();	// obtenir position actuelle
	void set_pos(int pos);	// aller à la position souhaité
	void turn(int nb); // tourner de nb case (+ sens trigo, - sens horraire)
	
	
	private:
	
	int m_pos;
};

#endif
