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
//  mega.barillet.moteurBarillet->order=100;
//  mega.barillet.moteurBarillet->actuate();
    mega.barillet.codeuseBarillet->actuate(1);



//  mega.elevator.moteurElevator->order=150;
//  mega.elevator.moteurElevator->actuate();
//  delay(500);
//  mega.elevator.init();
//  Serial.println(mega.elevator.codeuseElevator->pos);
//
//      while (!mega.barillet.contacteurBarillet->isPressed())
//  {
//  mega.elevator.moteurElevator->order=40;
//  mega.elevator.moteurElevator->actuate();
//  mega.elevator.codeuseElevator->actuate(1);
//  mega.barillet.codeuseBarillet->actuate(1);
//  Serial.println(mega.elevator.codeuseElevator->pos);
//  }

  
//  Serial.println(mega.elevator.codeuseElevator->pos);
////  Serial.println(pos);
//  delay(1000);
//  mega.elevator.moteurElevator->order=-50;
//  delay(1000);
//
//  mega.pompeG.suck();
//  mega.pompeD.suck();
  Serial.println("fin du setup");
  
}

void loop() {
  mega.actuate();
//  Serial.println(mega.elevator.codeuseElevator->pos);
//  delay(1);
}
