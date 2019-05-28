#include "Mega.h"
#include "Contacteur.h"
void Mega::actuate()
{
    //Actualisation des parametres
    float m=millis();
    float dt=(m-millisActu)/1000.0;
    millisActu=m;
    if (dt>0.5)
        dt=0.005;
    this->sharpARD.actuate(dt);
    this->sharpARG.actuate(dt);
    this->sharpAVD.actuate(dt);
    this->sharpAVG.actuate(dt);
    this->sharpPaletD.actuate(dt);
    this->sharpPaletG.actuate(dt);
    this->AmperemetrePompeDroit.actuate(dt);
    this->AmperemetrePompeGauche.actuate(dt);
    pinces.actuate();
    elevator.actuate(dt);
    barillet.actuate(dt);
    comm.actuate();

    //Communication
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
    case MessageE::MontePalet:
        elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
        elevator.moteurElevator->actuate();
        brasDroit.set(ServoPosition::Retracted);
        brasGauche.set(ServoPosition::Retracted);
        elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMReadyToTakeOnFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
        elevator.moteurElevator->actuate();

        if (sharpPaletD.getState()==Proximity and (sharpPaletD.getState()==Proximity))
        {
            pompeG.suck();
            pompeD.suck();
            elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMTakeOnFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
            elevator.moteurElevator->actuate();
            elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveFinger,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
            elevator.moteurElevator->actuate();
            elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMDepositOneFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
            elevator.moteurElevator->actuate();
            pompeG.blow();
            pompeD.blow();
            elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
            elevator.moteurElevator->actuate();
            pompeG.stop();
            pompeD.stop();
            barillet.moteurBarillet->order=barillet.pidBarillet->compute(dt,2*BARILLET_AngleToNext,barillet.codeuseBarillet->pos,barillet.codeuseBarillet->dPos);
            barillet.moteurBarillet->actuate();
        }
        else
        {
            if (sharpPaletD.getState()==Proximity)
            {
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                brasGauche.set(ServoPosition::Extended);
                brasDroit.set(ServoPosition::Retracted);
                pompeD.suck();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMTakeOnFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveFinger,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMDepositOneFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                pompeD.blow();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                pompeD.stop();
                barillet.moteurBarillet->order=barillet.pidBarillet->compute(dt,BARILLET_AngleToNext,barillet.codeuseBarillet->pos,barillet.codeuseBarillet->dPos);
                barillet.moteurBarillet->actuate();
            }
            if (sharpPaletG.getState()==Proximity)
            {
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                brasGauche.set(ServoPosition::Retracted);
                brasDroit.set(ServoPosition::Extended);
                pompeG.suck();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMTakeOnFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveFinger,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMDepositOneFloor,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                pompeG.blow();
                elevator.moteurElevator->order=elevator.pidElevator->compute(dt,AIMAboveBarel,elevator.codeuseElevator->pos,elevator.codeuseElevator->dPos);
                elevator.moteurElevator->actuate();
                pompeG.stop();
                barillet.moteurBarillet->order=barillet.pidBarillet->compute(dt,BARILLET_AngleToNext,barillet.codeuseBarillet->pos,barillet.codeuseBarillet->dPos);
                barillet.moteurBarillet->actuate();

            }
        }
        break;
    }


    if(comm.anticol==AnticolE::Front)
    {
        if(sharpAVD.getState()==Alerte || sharpAVG.getState()==Alerte)
        {
            if(!evitting)
                comm.send(Evitemment);
            evitting=true;
            #ifdef STATE
            Serial.println("Evitemment avant");
            #endif // STATE
        }
        else
        {
            if (evitting)
            {
                comm.send(Evitemment_Clear);
                #ifdef STATE
                Serial.println("Fin evitemment");
                #endif // STATE
                evitting=false;
            }

        }
    }

    if(comm.anticol==AnticolE::Back)
    {
        if(sharpARD.getState()==Alerte || sharpARG.getState()==Alerte)
        {
            if(!evitting)
                comm.send(Evitemment);
            evitting=true;
            #ifdef STATE
            Serial.println("Evitemment Arriere");
            #endif // STATE
        }
        else
        {
            if (evitting)
            {
                comm.send(Evitemment_Clear);
                #ifdef STATE
                Serial.println("Fin evitemment");
                #endif // STATE
                evitting=false;
            }
        }
    }

    if(evitting && comm.anticol==AnticolE::No)
    {
        #ifdef STATE
        Serial.print("Fin evitemment");
        #endif // STATE
        comm.send(Evitemment_Clear);
        evitting=false;
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
    evitting=false;
    elevator=Elevator(ELEVATOR_PIN_CONTACTEUR,ELEVATOR_PIN_CODEUSE_A,ELEVATOR_PIN_CODEUSE_B,ELEVATOR_TickToPos,ELEVATOR_PIN_MOTEUR_PWR,ELEVATOR_PIN_MOTEUR_SENS,ELEVATOR_PIN_MOTEUR_BRAKE);
    barillet=Barillet(BARILLET_PIN_CONTACTEUR,BARILLET_PIN_CODEUSE_A,BARILLET_PIN_CODEUSE_B,BARILLET_TickToPos,BARILLET_PIN_MOTEUR_PWR,BARILLET_PIN_MOTEUR_SENS,BARILLET_PIN_MOTEUR_BRAKE);
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
    AmperemetrePompeDroit=Sharp(AMPEREMETRE_POMPE_Droit_PIN,AMPEREMETRE_POMPE_Droit_SEUIL_DETECTED,AMPEREMETRE_POMPE_Droit_SEUIL_PROXIMITY);
    AmperemetrePompeGauche=Sharp(AMPEREMETRE_POMPE_Gauche_PIN,AMPEREMETRE_POMPE_Gauche_SEUIL_DETECTED,AMPEREMETRE_POMPE_Gauche_SEUIL_PROXIMITY);
    pompeG=Pompe(POMPE_GAUCHE_PIN_MOTEUR_PWR,POMPE_GAUCHE_PIN_MOTEUR_SENS,POMPE_GAUCHE_PIN_MOTEUR_BRAKE,POMPE_GAUCHE_PIN_AMP,true);
    pompeD=Pompe(POMPE_DROITE_PIN_MOTEUR_PWR,POMPE_DROITE_PIN_MOTEUR_SENS,POMPE_DROITE_PIN_MOTEUR_BRAKE,POMPE_DROITE_PIN_AMP,false);
    tirette=Contacteur(PIN_TIRETTE);
    comm=Comm();
    elevator.init();
    Serial.println("Fin de la contaction de l'elevator. On remonte");
    while (abs(elevator.codeuseElevator->pos - elevator.aim)>0.5)
    {
        actuate();
        delay(1);
    }
    Serial.println("Fin de la remontee de l'elevator. On fait tourner le barrillet");
    barillet.init();
    Serial.println("Fin de la contaction du barillet. On Se place");
    while (!barillet.goodenough())
    {
        actuate();
        delay(1);
    }
    barillet.codeuseBarillet->reset();
    Serial.println("Fin du palcement");
    millisInit=millis();
    millisActu=millis();

}
