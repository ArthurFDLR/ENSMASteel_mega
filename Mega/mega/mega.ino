#include "MegaServo.h"
#include "1_CONSTANTS.h"
//#include "Barillet.h"
#include "Mega.h"
#include "Arduino.h"
//lol
Mega mega;

void setup() 
{
  Serial.println("REBOOT");
  Serial.begin(250000);
  mega.init();
  
  while (mega.tirette.isPressed())
  {
    ;
  }
  Serial.println("coucou");
//  mega.barillet.moteurBarillet->order=100;
//  mega.barillet.moteurBarillet->actuate();
//  mega.elevator.moteurElevator->order=75;
//  mega.elevator.moteurElevator->actuate();
//  delay(500);
//mega.elevator.init();
//
//  mega.pompeG.suck();
//  mega.pompeD.suck();
  Serial.println("fin du setup");
  
}

void loop() {
  mega.actuate();
  //Serial.println(mega.elevator.codeuseElevator->pos);
  delay(1);
}
