#ifndef MEGA_INCLUDED
#define MEGA_INCLUDED
#include "Barillet.h"
#include "Pompe.h"
#include "Elevator.h"
#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Pinces.h"
#include "Sharp.h"

class Mega
{
public:
    Barillet barillet;
    Pompe pompeG, pompeD;
    Elevator elevator;
    MegaServo brasGauche,brasDroit,doigtGauche,doigtDroit;
    Pinces pinces;
    Sharp sharpAVG,sharpAVD,sharpARG,sharpARD,sharpPaletG,sharpPaletD;
    uint32_t millisInit,millisActu;

    void actuate();
    void init();


};

#endif // !MEGA_INCLUDED
