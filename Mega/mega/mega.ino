#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Mega.h"
#include "Arduino.h"

Mega mega;

void setup() 
{
//    mega.pompeG.suck();
//  mega.pompeD.suck();
  Serial.println("REBOOT");
  Serial.begin(250000);
  //test

  mega.init();
 // mega.pompeG.suck();
  //mega.pompeD.suck();

  while (mega.tirette.isPressed())
  {
    ;
  }
  Serial.println("fin du setup");
  
}

void loop() {
  mega.pompeG.suck();
  mega.pompeD.suck();
  mega.actuate();
  delay(1);
}
