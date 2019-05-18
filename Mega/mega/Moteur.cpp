#include "Moteur.h"
#include "Arduino.h"
Motor::Motor()
{

}

void Motor::actuate()
{
    //bypass=true;
    //masterOrder=MAXPWM/2.0;

    if (bypass)
    {
        order=masterOrder;
    }
    int orderComp=constrain((int)(order/health),-MAXPWM,MAXPWM);
    if (orderComp>0)
    {
        digitalWrite(pinSens,HIGH);
        digitalWrite(pinBrake,LOW);
        analogWrite(pinPWR,orderComp);
    }
    else if (orderComp<-0)
    {
        digitalWrite(pinSens,LOW);
        digitalWrite(pinBrake,LOW);
        analogWrite(pinPWR,abs(orderComp));
    }
    else
    {
        digitalWrite(pinSens,HIGH);
        digitalWrite(pinBrake,HIGH);
        analogWrite(pinPWR,order);
    }
}

Motor::Motor(uint8_t in_pinPWR, uint8_t in_pinSens, uint8_t in_pinBrake,float health)
{
    this->bypass=false;
    this->pinPWR=in_pinPWR;
    pinMode(this->pinPWR,OUTPUT);
    this->pinSens=in_pinSens;
    pinMode(this->pinSens,OUTPUT);
    this->pinBrake=in_pinBrake;
    pinMode(this->pinBrake,OUTPUT);
    this->order=0;
    this->masterOrder=0;
    this->health=health;
}
