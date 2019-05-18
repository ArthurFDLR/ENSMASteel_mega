#include "Barillet.h"
#include "Arduino.h"

Barillet::Barillet(uint8_t pin_codeuse_A,uint8_t pin_codeuse_B,uint8_t pin_sens,uint8_t pin_pwr)
{
  pidBarillet=new PID(true,0,0,50,100,0);
  codeuseBarillet=new Codeuse(pin_codeuse_A,pin_codeuse_B,0.0007469789);
}

void Barillet::AddPalet(int trouId, PaletE couleur)
{
	trous[trouId].addPalet(couleur);
}

void Barillet::Actuate(float dT)
{
	codeuseBarillet->actuate(dT);
}

int Barillet::get_angle()
{
	return codeuseBarillet->pos;
}

void Barillet::set_angle(float angle)
{

}

void Barillet::turn(float angle)
{

}

Barillet::Barillet()
{

}
