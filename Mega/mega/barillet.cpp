#include "Barillet.h"
#include "Arduino.h"

Barillet::Barillet()
{
  pidBarillet=new PID(true,500,20,50,20,0);
  codeuseBarillet = new Codeuse(BARILLET_PIN_A, BARILLET_PIN_B, PI*0.4/11500.0);
}

void Barillet::AddPalet(int trouId, PaletE couleur)
{
	trous[trouId].addPalet(couleur);
}

void Barillet::Actuate(float dT)
{
	codeuseBarillet->actuate(dT);
}

int Barillet::get_pos()
{
	return codeuseBarillet->pos;
}

void Barillet::set_pos(int pos)
{

}

void Barillet::turn(int nb)
{
}
