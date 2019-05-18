#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"
#include "Codeuse.h"
#include "1_CONSTANTS.h"
#include "FILO.h"
#include "Contacteur.h"
class Barillet
{
	public:

	Barillet(uint8_t pin_codeuse_A,uint8_t pin_codeuse_B,uint8_t pin_sens,uint8_t pin_pwr,uint8_t pin_contacteur);
    Barillet();
    Contacteur *contacteurBarillet;
    Codeuse *codeuseBarillet;
	PID *pidBarillet;
	int get_angle();
	void set_angle(float angle);
	void turn(float angle);
	FILO trous[6];
    void addPalet(int trouId, PaletE couleur);
    void actuate(float dT);
    void init();

	private:

	float angle;
    int celluleDroite; //Reference de la cellule au dessus de l'encoche droite (-1 indique un deplacement en cours)
    //Apres l'init, c'est la cellule 1 qui est sous cette encoche
};

#endif
