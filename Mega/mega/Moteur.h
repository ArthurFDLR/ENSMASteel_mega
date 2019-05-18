#ifndef MOTEUR_INCLUDED
#define MOTEUR_INCLUDED

#include "1_CONSTANTS.h"
#include "Arduino.h"

class Motor
{
public:
    uint8_t pinPWR,pinSens,pinBrake;   //Pin de puissance (PWM) et les deux pin pour donner le sens de rotation
    int32_t order,masterOrder;              //Le regime moteur entre -65535 et 65535
    float health=1.0;
    bool bypass=false;
    Motor();
    Motor(uint8_t in_pinPWR, uint8_t in_pinSens1, uint8_t in_pinSens2,float health);
    void actuate();                     //Actualisation de la puissance moteur
};

#endif
