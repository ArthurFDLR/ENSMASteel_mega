#include "Pinces.h"
#include "1_CONSTANTS.h"
#include "Arduino.h"
Pinces::Pinces()
{
    pinceDroite=MegaServo(PINCE_DROITE_PIN,PINCE_DROITE_RETRACTED,PINCE_DROITE_HALF_RETRACTED,PINCE_DROITE_HALF_EXTENDED,PINCE_DROITE_EXTENDED);
    delay(500);
    pinceGauche=MegaServo(PINCE_GAUCHE_PIN,PINCE_GAUCHE_RETRACTED,PINCE_GAUCHE_HALF_RETRACTED,PINCE_GAUCHE_HALF_EXTENDED,PINCE_GAUCHE_EXTENDED);
    ordresDroit=ServoPosition::Extended;
    ordresGauche=ServoPosition::Extended;
    millisNextActionDroite=millis();
    millisNextActionGauche=millis();
}

void Pinces::actuate()
{
    if (millis()>millisNextActionDroite)
        pinceDroite.set(ordresDroit);
    if (millis()>millisNextActionGauche)
        pinceDroite.set(ordresGauche);
}

void Pinces::pinceGaucheSet(ServoPosition pos, bool wait)
{
    if (wait)
        millisNextActionGauche=millis()+MILLIS_CLEAR;
    else
        millisNextActionGauche=millis()-1;

    if (pinceGauche.get()==ServoPosition::Retracted)  //On me demande de sortir
    {
        if (ordresDroit!=ServoPosition::Retracted)    //Je verifie que l'autre n'est pas retracte
            ordresGauche=pos;
        else
        {
            #ifdef STATE
            Serial.print("COLLISION PINCES")
            #endif // STATE
        }
    }
}

void Pinces::pinceDroiteSet(ServoPosition pos, bool wait)
{
    if (wait)
        millisNextActionDroite=millis()+MILLIS_CLEAR;
    else
        millisNextActionDroite=millis()-1;

    if (pinceDroite.get()==ServoPosition::Retracted)  //On me demande de sortir
    {
        if (ordresGauche!=ServoPosition::Retracted)    //Je verifie que l'autre n'est pas retracte
            ordresDroit=pos;
        else
        {
            #ifdef STATE
            Serial.print("COLLISION PINCES")
            #endif // STATE
        }
    }
}


void Pinces::bothPincesSet(ServoPosition pos)
{
    if (pos==ServoPosition::Retracted)//On doit ranger les pinces
    {
        //TODO a modifier en fonction de la couleur
        pinceGaucheSet(ServoPosition::Retracted,false);
        pinceDroiteSet(ServoPosition::Retracted,true);
    }
    if (pinceGauche.get()==ServoPosition::Retracted || pinceDroite.get()==ServoPosition::Retracted) //On doit sortir les pinces
    {
        //TODO a modifier en fonction de la couleur
        pinceGaucheSet(pos,false);
        pinceDroiteSet(pos,true);
    }
}
