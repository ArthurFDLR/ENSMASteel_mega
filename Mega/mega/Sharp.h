#ifndef SHARP_INCLUDED
#define SHARP_INCLUDED
#include "Arduino.h"
enum SharpState {Normal,Proximity,Alerte};
class Sharp
{
    public:
        Sharp();
        Sharp(uint8_t pin,uint16_t seuil_alerte,uint16_t seuil_classique);
        SharpState getState();
        uint16_t debug();
    private:
        SharpState lastState;
        uint8_t pin;
        uint16_t seuil_alerte,seuil_proximity;
};

#endif // SHARP_INCLUDED
