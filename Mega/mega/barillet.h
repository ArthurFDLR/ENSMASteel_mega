#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"
#include "Codeuse.h"
#include "1_CONSTANTS.h"
#include "FILO.h"

class Barillet
{
	public:

	Barillet(uint8_t pin_codeuse_A,uint8_t pin_codeuse_B,uint8_t pin_sens,uint8_t pin_pwr);
  Barillet();
  Codeuse *codeuseBarillet;
	PID *pidBarillet;
	int get_angle();
	void set_angle(float angle);
	void turn(float angle);
	FILO trous[6];
  void AddPalet(int trouId, PaletE couleur);
  void Actuate(float dT);
  
	private:
	
	float angle;
  int celluleGauche; //Reference de la cellule au dessus de l'encoche gauche (-1 indique un deplacement en cours)
};

#endif
