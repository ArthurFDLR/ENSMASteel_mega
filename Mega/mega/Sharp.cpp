#include "Sharp.h"

Sharp::Sharp()
{
    //ctor
}

Sharp::Sharp(uint8_t pin, uint16_t seuil_alerte, uint16_t seuil_classique)
{
    this->pin=pin;
    pinMode(pin,INPUT);
    this->seuil_alerte=seuil_alerte;
    this->seuil_proximity=seuil_proximity;
    this->lastState=SharpState::Normal;
}
#define HYSTERESIS 50
SharpState Sharp::getState()
{
    uint16_t value=analogRead(pin);
    if (value>seuil_alerte)           //Pas d'hyste montante
    {
        lastState=SharpState::Alerte;
        return SharpState::Alerte;
    }
    else if(value<seuil_alerte-HYSTERESIS && lastState==SharpState::Alerte) //Hyste descente
    {
        lastState=SharpState::Proximity;
        return SharpState::Proximity;
    }
    else if(value>seuil_proximity && lastState==SharpState::Normal) //Pas d'hyste montante
    {
        lastState=SharpState::Proximity;
        return SharpState::Proximity;
    }
    else if(value<seuil_proximity-HYSTERESIS && lastState==SharpState::Proximity) //Hyste descente
    {
        lastState=SharpState::Normal;
        return SharpState::Normal;
    }
    else
        return lastState;
}

uint16_t Sharp::debug()
{
    return analogRead(pin);
}
