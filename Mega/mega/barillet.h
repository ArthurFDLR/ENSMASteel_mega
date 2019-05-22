#ifndef BARILLET_INCLUDED
#define BARILLET_INCLUDED
#include "PID.h"
#include "Codeuse.h"
#include "1_CONSTANTS.h"
#include "FILO.h"
#include "Contacteur.h"
#include "Moteur.h"
class Barillet
{
	public:

	Barillet(uint8_t pinContacteur,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos,uint8_t pinMoteurPwr,uint8_t pinMoteurSens,uint8_t pinMoteurBrake);
    Barillet();
    Contacteur *contacteurBarillet;
    Codeuse *codeuseBarillet;
	  PID *pidBarillet;
     Motor *moteurBarillet;
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
