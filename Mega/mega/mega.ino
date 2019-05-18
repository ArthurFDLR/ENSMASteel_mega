#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Barillet.h"


MegaServo brasGauche,brasDroit,doigtGauche,doigtDroit,pinceGauche,pinceDroite;

void setup() 
{
  brasGauche=MegaServo(BRAS_GAUCHE_PIN,BRAS_GAUCHE_RETRACTED,BRAS_GAUCHE_HALF_RETRACTED,BRAS_GAUCHE_HALF_EXTENDED,BRAS_GAUCHE_EXTENDED);
  brasDroit=MegaServo(BRAS_DROIT_PIN,BRAS_DROIT_RETRACTED,BRAS_DROIT_HALF_RETRACTED,BRAS_DROIT_HALF_EXTENDED,BRAS_DROIT_EXTENDED);
  doigtGauche=MegaServo(DOIGT_GAUCHE_PIN,DOIGT_GAUCHE_RETRACTED,DOIGT_GAUCHE_HALF_RETRACTED,DOIGT_GAUCHE_HALF_EXTENDED,DOIGT_GAUCHE_EXTENDED);
  doigtDroit=MegaServo(DOIGT_DROIT_PIN,DOIGT_DROIT_RETRACTED,DOIGT_DROIT_HALF_RETRACTED,DOIGT_DROIT_HALF_EXTENDED,DOIGT_DROIT_EXTENDED);
  pinceGauche=MegaServo(PINCE_GAUCHE_PIN,PINCE_GAUCHE_RETRACTED,PINCE_GAUCHE_HALF_RETRACTED,PINCE_GAUCHE_HALF_EXTENDED,PINCE_GAUCHE_EXTENDED);
  pinceDroite=MegaServo(PINCE_DROITE_PIN,PINCE_DROITE_RETRACTED,PINCE_DROITE_HALF_RETRACTED,PINCE_DROITE_HALF_EXTENDED,PINCE_DROITE_EXTENDED);
  brasGauche.set(ServoPosition::Extended);
  brasDroit.set(ServoPosition::Extended);
  pinceGauche.set(ServoPosition::Extended);
  pinceDroite.set(ServoPosition::Extended);
  doigtDroit.set(ServoPosition::Extended);
  doigtGauche.set(ServoPosition::Extended);
  delay(1000);
  pinceGauche.set(ServoPosition::Retracted);
  delay(1000);
  pinceDroite.set(ServoPosition::Retracted);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()>0)
  {
    int x=Serial.parseInt();
    brasDroit.debug(x);
    while (Serial.available()>0)
    {
      Serial.read();
    }
  }
}
