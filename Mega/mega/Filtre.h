#ifndef FILTRE_INCLUDED
#define FILTRE_INCLUDED
#include "Arduino.h"

enum typeFiltreE{PAS_DE_FILTRE,LOWPASS1,LOWPASS2,DELAY};

class Filtre
{
  float lastValue,lastLastValue,raw,lastRaw;
  typeFiltreE typeFiltre;                     //Ordre du filtre
  float Wc;                                     //Frequence de coupure

  public:
  void in(float newRaw,float dt);               //Entrée d'une donnée brute
  float out();                                  //Sortie d'une donnée filtrée
  Filtre(float initValue,float frequency,typeFiltreE typeFiltre);
  Filtre();
};

#endif
