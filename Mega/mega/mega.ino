#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Barillet.h"
#include "Mega.h"
#include "Arduino.h"

Mega mega;

void setup() 
{
  Serial.println("REBOOT");
  mega.init();
  Serial.begin(9600);
  //mega.pompeG.suck();
  //mega.pompeD.suck();
  Serial.println("fin du setup"); 
}

void loop() {
  mega.actuate();
  if (Serial.available()>0)
  {
      int x=Serial.parseInt();
      if (x>=0 && x<=3)
      {
        switch (x)
        {
          case 0:
          mega.pinces.bothPincesSet(ServoPosition::Retracted);
          break;
          case 1:
          mega.pinces.bothPincesSet(ServoPosition::HalfRetracted);
          break;
          case 2:
          mega.pinces.bothPincesSet(ServoPosition::HalfExtended);
          break;
          case 3:
          mega.pinces.bothPincesSet(ServoPosition::Extended);
          break;
        }
      }
      else 
      {
        mega.pinces.pinceDroite.debug(x);
      }
      while (Serial.available()>0){Serial.read();}
  }
  Serial.print("sharp AVG ");Serial.print(mega.sharpAVG.debug());Serial.print("\t");
    Serial.print("sharp AVD ");Serial.print(mega.sharpAVD.debug());Serial.print("\t");
    Serial.print("sharp ARG ");Serial.print(mega.sharpARG.debug());Serial.print("\t");
    Serial.print("sharp ARD ");Serial.print(mega.sharpARD.debug());Serial.print("\t");
    Serial.print("sharp Palet Gauche ");Serial.print(mega.sharpPaletG.debug());Serial.print("\t");
    Serial.print("sharp Palet Droite ");Serial.print(mega.sharpPaletD.debug());Serial.println("\t");
    if (mega.sharpARD.getState()==SharpState::Proximity || mega.sharpARG.getState()==SharpState::Proximity)
    {
      mega.pinces.pinceGaucheSet(ServoPosition::HalfExtended,false);
    }
    else if(mega.sharpARD.getState()==SharpState::Normal && mega.sharpARG.getState()==SharpState::Normal)
    {
      mega.pinces.pinceGaucheSet(ServoPosition::Extended,false);
    }
  delay(100);
}
