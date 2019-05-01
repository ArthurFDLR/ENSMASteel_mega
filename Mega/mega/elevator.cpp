#include "elevator.h"
#include "contacteur.h"
#include "Codeuse.h"
#include "PID.h"



elevator::elevator(uint8_t pinContacteurBas, uint8_t pinContacteurHaut,uint8_t pin1Codeuse,uint8_t pin2Codeuse,float tickToPos)
{
  contacteurHaut=new contacteur(pinContacteurHaut);
  contacteurBas=new contacteur(pinContacteurBas);
  codeuseElevator=new Codeuse(pin1Codeuse,pin2Codeuse,tickToPos);
  pos=0,aim=0;
  pidElevator=new PID(false, 42, 24, 12, 50, 0);
}

elevator::elevator()
{
  
}

bool elevator::init()
{
  float t=millis();
  float tIni=t;
  while (!contacteurHaut->isPressed() and t-tIni<10000)
  {
    t=millis();
    aim=0.1*t/1000.0;   //On fait monter l'elevator doucement
    //moteurElevator->setOrder(pidElevator->compute(0.001,aim,codeuseElevator->pos,codeuseElevator->dPos));   //TODO, creer la classe moteur et en instancier un pour l'elevator
    delayMicroseconds(1000);
  }
  if (t-tIni>10000)return false;
  else
  {
    pos=LONGUEUR_COURSE;
    aim=LONGUEUR_COURSE;
    return true;
  }
}
