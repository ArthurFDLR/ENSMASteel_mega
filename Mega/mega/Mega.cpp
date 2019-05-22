#include "Mega.h"
#include "Contacteur.h"
void Mega::actuate()
{
    float m=millis();
    float dt=(m-millisActu)/1000.0;
    this->sharpARD.actuate(dt);
    this->sharpARG.actuate(dt);
    this->sharpAVD.actuate(dt);
    this->sharpAVG.actuate(dt);
    this->sharpPaletD.actuate(dt);
    this->sharpPaletG.actuate(dt);
    millisActu=m;
    //barillet.Actuate(dt);
    pinces.actuate();
    elevator.actuate(dt);
    comm.actuate();
    if (tirette.isJustPressed())
    {
        comm.send(MessageE::Tirette);
    }
    switch (comm.lastMessage)
    {
    case MessageE::Pince_Extended:
        pinces.bothPincesSet(ServoPosition::Extended);
        comm.taken();
        break;
    case MessageE::Pince_Half_Extended:
        pinces.bothPincesSet(ServoPosition::HalfExtended);
        comm.taken();
        break;
    case MessageE::Pince_Half_Retracted:
        pinces.bothPincesSet(ServoPosition::HalfRetracted);
        comm.taken();
        break;
    case MessageE::Pince_Retracted:
        pinces.bothPincesSet(ServoPosition::Retracted);
        comm.taken();
        break;
    }
    if (sharpPaletD.getState()==Proximity)
        doigtDroit.set(Retracted);
    else
        doigtDroit.set(Extended);
    if (sharpPaletG.getState()==Proximity)
        doigtGauche.set(Retracted);
    else
        doigtGauche.set(Extended);


    if(comm.anticol==AnticolE::Front)
    {
        if(sharpAVD.getState()==Alerte)
            comm.send(Evitemment);
        if(sharpAVG.getState()==Alerte)
            comm.send(Evitemment);
            
        #ifdef STATE
        Serial.println("evitemment sent");
        #endif
    }
    if(comm.anticol==AnticolE::Back)
    {
        if(sharpARD.getState()==Alerte)
            comm.send(Evitemment);
        if(sharpARG.getState()==Alerte)
            comm.send(Evitemment);
        #ifdef STATE
        Serial.println("evitemment sent");
        #endif
    }


//    Serial.print("AVG ");Serial.print(sharpAVG.raw());Serial.print("\t");
//    Serial.print("AVD ");Serial.print(sharpAVD.raw());Serial.print("\t");
//    Serial.print("ARG ");Serial.print(sharpARG.raw());Serial.print("\t");
//    Serial.print("ARD ");Serial.print(sharpARD.raw());Serial.print("\t");
//    Serial.print("Palet Gauche raw ");Serial.print(sharpPaletG.raw());Serial.print("\t");
//    Serial.print("Palet Droite raw ");Serial.print(sharpPaletD.raw());Serial.print("\t");
//    Serial.print("amp pompe Gauche ");pompeG.isSucked();Serial.print("\t");
//    Serial.print("amp pompe Droite ");pompeD.isSucked();Serial.println("\t");

}


void Mega::init()
{
    Serial2.begin(250000);
    elevator=Elevator(ELEVATOR_PIN_CONTACTEUR,ELEVATOR_PIN_CODEUSE_A,ELEVATOR_PIN_CODEUSE_B,0.000000042,ELEVATOR_PIN_MOTEUR_PWR,ELEVATOR_PIN_MOTEUR_SENS,ELEVATOR_PIN_MOTEUR_BRAKE);
    elevator.init();
    barillet=Barillet(BARILLET_PIN_CONTACTEUR,BARILLET_PIN_CODEUSE_A,BARILLET_PIN_CODEUSE_B,0.0007469789,BARILLET_PIN_MOTEUR_PWR,BARILLET_PIN_MOTEUR_SENS,BARILLET_PIN_MOTEUR_BRAKE);
    brasGauche=MegaServo(BRAS_GAUCHE_PIN,BRAS_GAUCHE_RETRACTED,BRAS_GAUCHE_HALF_RETRACTED,BRAS_GAUCHE_HALF_EXTENDED,BRAS_GAUCHE_EXTENDED);
    brasDroit=MegaServo(BRAS_DROIT_PIN,BRAS_DROIT_RETRACTED,BRAS_DROIT_HALF_RETRACTED,BRAS_DROIT_HALF_EXTENDED,BRAS_DROIT_EXTENDED);
    doigtGauche=MegaServo(DOIGT_GAUCHE_PIN,DOIGT_GAUCHE_RETRACTED,DOIGT_GAUCHE_HALF_RETRACTED,DOIGT_GAUCHE_HALF_EXTENDED,DOIGT_GAUCHE_EXTENDED);
    doigtDroit=MegaServo(DOIGT_DROIT_PIN,DOIGT_DROIT_RETRACTED,DOIGT_DROIT_HALF_RETRACTED,DOIGT_DROIT_HALF_EXTENDED,DOIGT_DROIT_EXTENDED);
    pinces=Pinces(true);
    sharpARD=Sharp(SHARP_ARD_PIN,SHARP_ANTICOL_AR_SEUIL,SHARP_ANTICOL_AR_SEUIL/2.0);
    sharpARG=Sharp(SHARP_ARG_PIN,SHARP_ANTICOL_AR_SEUIL,SHARP_ANTICOL_AR_SEUIL/2.0);
    sharpAVD=Sharp(SHARP_AVD_PIN,SHARP_ANTICOL_AV_SEUIL_ALERT,SHARP_ANTICOL_AV_SEUIL_PROXIMITY);
    sharpAVG=Sharp(SHARP_AVG_PIN,SHARP_ANTICOL_AV_SEUIL_ALERT,SHARP_ANTICOL_AV_SEUIL_PROXIMITY);
    sharpPaletD=Sharp(SHARP_PALET_DROITE_PIN,4242,SHARP_PALET_SEUIL);
    sharpPaletG=Sharp(SHARP_PALET_GAUCHE_PIN,4242,SHARP_PALET_SEUIL);
    pompeG=Pompe(POMPE_GAUCHE_PIN_MOTEUR_PWR,POMPE_GAUCHE_PIN_MOTEUR_SENS,POMPE_GAUCHE_PIN_MOTEUR_BRAKE,POMPE_GAUCHE_PIN_AMP,true);
    pompeD=Pompe(POMPE_DROITE_PIN_MOTEUR_PWR,POMPE_DROITE_PIN_MOTEUR_SENS,POMPE_DROITE_PIN_MOTEUR_BRAKE,POMPE_DROITE_PIN_AMP,false);
    tirette=Contacteur(PIN_TIRETTE);
    comm=Comm();
    millisInit=millis();
    millisActu=millis();
}
