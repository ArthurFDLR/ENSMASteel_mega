#include "Elevator.h"
#include "Contacteur.h"
#include "Codeuse.h"
#include "PID.h"
#include "Moteur.h"
Elevator::Elevator(uint8_t pinContacteur,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos,uint8_t pinMoteurPwr,uint8_t pinMoteurSens,uint8_t pinMoteurBrake)
{
  moteurElevator=new Motor(pinMoteurPwr,pinMoteurSens,pinMoteurBrake);
  contacteurElevator=new Contacteur(pinContacteur);
  codeuseElevator=new Codeuse(pin1Codeuse,pin2Codeuse,tickToPos);
  aim=0;
  pidElevator=new PID(false, 42, 24, 12, 50, 0);
}

Elevator::Elevator()
{

}

void Elevator::actuate(float dt)
{
    codeuseElevator->actuate(dt);
    //moteurElevator->order=pidElevator->compute(dt,aim,codeuseElevator->pos,codeuseElevator->dPos);
    moteurElevator->order=20;
    moteurElevator->actuate();
}


bool Elevator::init()
{
  float t=millis();
  float tIni=t;
  while (!contacteurElevator->isPressed() and t-tIni<10000)
  {
    t=millis();
    moteurElevator->order=-25;   //On fait descendre l'elevator doucement
    moteurElevator->actuate();
  }
  moteurElevator->order=0;// On arrete l'elevateur
  moteurElevator->actuate();
  if (t-tIni>10000)return false;
  else
  {
    codeuseElevator->pos=0.0;
    aim=0.0;
    return true;
  }
  
}
