#ifndef MEGA_INCLUDED
#define MEGA_INCLUDED
//#include "Barillet.h"
#include "Pompe.h"
//#include "Elevator.h"
#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Pinces.h"
#include "Sharp.h"
#include "Contacteur.h"
#include "Elevator.h"
#include "Barillet.h"
#include "Comm.h"
enum actionCouranteE {Idle,Chaos,Distrib};
enum etapeChaosE {PrepChaos,DescentSouffletSol,RemontePalet,DeposeOneFloor,DeposeRemonte,TourneBarillet};

class Mega
{
public:
    Barillet barillet;
    Pompe pompeG, pompeD;
    Elevator elevator;
    MegaServo brasGauche,brasDroit,doigtGauche,doigtDroit;
    Pinces pinces;
    Sharp sharpAVG,sharpAVD,sharpARG,sharpARD,sharpPaletG,sharpPaletD,AmperemetrePompeGauche,AmperemetrePompeDroit;
    Contacteur tirette;
    Comm comm;
    actionCouranteE actionCourante;
    etapeChaosE etapeChaos;
    uint32_t millisInit,millisActu;

    void actuate();
    void init();

    bool coteviolet = true ; 

private:
    bool evitting;


};

#endif // !MEGA_INCLUDED
