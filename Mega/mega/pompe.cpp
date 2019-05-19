#include "Pompe.h"

Pompe::Pompe(uint8_t pinMoteurPwr, uint8_t pinMoteurSens, uint8_t pinMoteurBrake, uint8_t pinAmp)
{
    moteur=new Motor(pinMoteurPwr,pinMoteurSens,pinMoteurBrake);
    pinMode(pinAmp,INPUT);
}

Pompe::Pompe()
{

}

void Pompe::suck()
{
    moteur->order=255;
    moteur->actuate();
}

void Pompe::blow()
{
    moteur->order=-255;
    moteur->actuate();
}

void Pompe::stop()
{
    moteur->order=0;
    moteur->actuate();
}

bool Pompe::isSucked()
{
    Serial.println(analogRead(pinAmp));
}
