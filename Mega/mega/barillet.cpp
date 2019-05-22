#include "Barillet.h"
#include "Arduino.h"

Barillet::Barillet(uint8_t pinContacteur,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos,uint8_t pinMoteurPwr,uint8_t pinMoteurSens,uint8_t pinMoteurBrake)
{
  pidBarillet=new PID(true,0,0,50,100,0);
  moteurBarillet=new Motor(pinMoteurPwr,pinMoteurSens,pinMoteurBrake);
  codeuseBarillet=new Codeuse(pin1Codeuse,pin2Codeuse,tickToPos);
  contacteurBarillet=new Contacteur(pinContacteur);
  angle=0;
  celluleDroite=-1;
}

void Barillet::addPalet(int trouId, PaletE couleur)
{
	trous[trouId].addPalet(couleur);
}

void Barillet::actuate(float dt)
{
	codeuseBarillet->actuate(dt);
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
