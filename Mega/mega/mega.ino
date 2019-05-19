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
  Serial.println("fin du setup"); 
}

void loop() {
  Serial.println("in the loop");
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
  delay(100);
}
