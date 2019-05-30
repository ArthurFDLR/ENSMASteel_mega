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
    case MessageE::Jaune:
        barillet.coteviolet=false;
        comm.taken();
        break;
    case MessageE::Violet:
        barillet.coteviolet=true;
        comm.taken();
        break;
    case MessageE::Start_Chaos:
        Serial.println("START CHAOS");
        actionCourante=Chaos;
        etapeChaos= PrepChaos;
        comm.taken();
        break;
     case MessageE::Start_Goldonium:
        actionCourante=RecupGoldonium;
        etapeRecupGoldonium=Safety;
        comm.taken();
     break;

     case MessageE::Depose_Goldonium:
        actionCourante=DeposeGoldonium;
        etapeRecupGoldonium=Safety;
        comm.taken();
     break;

       case MessageE::PoussePaletBleuAccel:
        actionCourante=PoussePaletBleu;
        etapePaletBleu=SafetyPal;
        comm.taken();
     break;
    }


//------------------------------------------------Evitemement--------------------------------
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

//--------------------------------------------------doigt bloc palet-------------------------

    if(sharpPaletD.getState()== Proximity )
    {
        doigtDroit.set(Retracted);
    }
    else
    {
        doigtDroit.set(Extended);
    }
    if(sharpPaletG.getState()== Proximity )
    {
        doigtGauche.set(Retracted);
    }
    else
    {
        doigtGauche.set(Extended);
    }


//--------------------------------------------------Sous actions------------------------
    switch(actionCourante)
    {
    case (Chaos):
        switch(etapeChaos)
        {
        case (PrepChaos):
            pompeD.stop();
            pompeG.stop();
            brasDroit.set(Retracted);
            brasGauche.set(Retracted);
            elevator.aim=AIMAboveBarel;
            if (abs(elevator.codeuseElevator->pos-elevator.aim)<0.005 and sharpPaletD.getState()== Proximity and sharpPaletG.getState()==Proximity)
            {
                etapeChaos= DescentSouffletSol;
            }
            break;
        case (DescentSouffletSol):
            pompeD.suck();
            pompeG.suck();
            elevator.aim=AIMTakeOnFloor;
            if (abs(elevator.codeuseElevator->pos-elevator.aim)<0.001) // and AmperemetrePompeDroit.getState()==Alerte and AmperemetrePompeGauche.getState()==Alerte){
            {
                etapeChaos = RemontePalet;
            }
            //contremesure descendre plus bas mais peu se faire indéfiniment, on fait confiance aux pompes
            break;
        case (RemontePalet):
            elevator.aim=AIMAboveFinger;
            if (abs(elevator.codeuseElevator->pos-elevator.aim)<0.001)
            {
                etapeChaos = DeposeOneFloor;
            }
            break;
        case (DeposeOneFloor):
            elevator.aim=AIMDepositOneFloor;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.001)
            {
                etapeChaos = DeposeRemonte;
            }
            break;
        case(DeposeRemonte):
            pompeD.stop();
            pompeG.stop();
            elevator.aim=AIMAboveBarel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                etapeChaos = TourneBarillet;
                Serial.println("je passe au tourne palet");
            }
            break;
        case (TourneBarillet):

            Serial.println("je suis dans tourne palet mais je ne tourne pas");
            //barillet.goToDelta(2.0*iPosBarillet*BARILLET_AngleToNext);
            barillet.goTo(2.0*iPosBarillet*BARILLET_AngleToNext);
            if(barillet.goodenough())
            {
                iPosBarillet++;
                etapeChaos = PrepChaos;
            }
            break;
        }
 //---------------------------------------action recup goldo----------------------------
        case (RecupGoldonium):
          switch(etapeRecupGoldonium){
           case(Safety):
               elevator.aim=AIMAboveBarel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                etapeRecupGoldonium = Recup;
            }
           break;
            case(Recup):
              pompeD.suck();
              pompeG.suck();
              brasDroit.set(Extended);
              brasGauche.set(Extended);
              elevator.aim=AIMBlueiumAcceleratorLevel;
            break;
          }
 //---------------------------------------action deposegoldo goldo---------------------------- 
            case(DeposeGoldonium):
             elevator.aim=AIMBalanceLevel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                pompeD.stop();
                pompeG.stop();
            }
            break;
//-----------------------------------------On pousse le palet bleu--------------------------------
            case(PoussePaletBleu):
                  switch(etapePaletBleu){
                      case(SafetyPal):
               elevator.aim=AIMAboveBarel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                etapePaletBleu = Pousse;
            }
           break;
            case(Pousse):
              brasDroit.set(Extended);
              brasGauche.set(Extended);
              elevator.aim=AIMInAccelerator -0.02;
            break;
                  }
                  break;
 //------------------------------------depose sol-------------------------      
      case(DeposePaletSol):
           switch(etapeDeposePaletSol){
            case(SafetyetapeDeposePaletSol):
            elevator.aim=AIMAboveBarel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
              
                etapeDeposePaletSol = AttrapePaletBarillet;
            }
            break;
            case (AttrapePaletBarillet):
              pompeD.suck();
              pompeG.suck();
              brasDroit.set(Retracted);
              brasGauche.set(Retracted);
            elevator.aim=AIMTakeOneFloor;
                 if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                etapeDeposePaletSol = (RemontePaletPourDepose);
            }
            break;
            case(RemontePaletPourDepose):
                        elevator.aim=AIMAboveBarel;
            if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
                etapeDeposePaletSol = PretADeposeSol;
            }
            break;
            case(PretADeposeSol):
                elevator.aim=AIMDistribLevel;
                    if(abs(elevator.codeuseElevator->pos-elevator.aim)<0.005)
            {
              pompeD.stop();
              pompeG.stop();
              etapeDeposePaletSol = TourneBarilletPourDeposeSol;
              
            }
            break;
            case(TourneBarilletPourDeposeSol):
            barillet.goTo(2.0*iPosBarillet*BARILLET_AngleToNext);
            if(barillet.goodenough()and iPosBarillet)
            {
                iPosBarillet++;
                etapeDeposePaletSol = PrepChaos;
            }
            break;
            }      
            
            
              
           
     
        
        break ;
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
    actionCourante=Distrib;
    evitting=false;
    elevator=Elevator(ELEVATOR_PIN_CONTACTEUR,ELEVATOR_PIN_CODEUSE_A,ELEVATOR_PIN_CODEUSE_B,ELEVATOR_TickToPos,ELEVATOR_PIN_MOTEUR_PWR,ELEVATOR_PIN_MOTEUR_SENS,ELEVATOR_PIN_MOTEUR_BRAKE);
    barillet=Barillet(BARILLET_PIN_CONTACTEUR,BARILLET_PIN_CODEUSE_A,BARILLET_PIN_CODEUSE_B,BARILLET_TickToPos,BARILLET_PIN_MOTEUR_PWR,BARILLET_PIN_MOTEUR_SENS,BARILLET_PIN_MOTEUR_BRAKE, coteviolet, this);
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

#ifdef STATE
    Serial.println("Fin de la contaction de l'elevator. On remonte");
#endif // STATE
    while (abs(elevator.codeuseElevator->pos - elevator.aim)>0.005 || abs(elevator.codeuseElevator->dPos)>0.005)
    {
        actuate();
        delay(1);
    }
    elevator.moteurElevator->order=0;
    elevator.moteurElevator->actuate();
#ifdef STATE
    Serial.println("Fin de la remontee de l'elevator. On fait tourner le barrillet");
#endif // STATE
    barillet.init();
#ifdef STATE
    Serial.println("Fin de la contaction du barillet. On Se place");
#endif // STATE
    while (!barillet.goodenough())
    {
        actuate();
        delay(1);
    }
    barillet.codeuseBarillet->reset();
    barillet.goTo(0.0);

#ifdef STATE
    Serial.println("Fin du palcement, init terminee");
#endif // STATE
    //barillet.RedefinitionPosBleuium();
    millisInit=millis();
    millisActu=millis();



}
