#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Barillet.h"
#include "Mega.h"
#include "Arduino.h"

Mega mega;

void setup() 
{
  mega.init();
  delay(2000);
  //pompe->stop();
  Serial.begin(9600);
  Serial.println("REBOOT");
  //mega=Mega(true);
  Serial.println("mega=...");
  delay(1500);
  Serial.println("suck");
  mega.pinces.bothPincesSet(ServoPosition::HalfExtended);
  mega.pompeG.suck();
  delay(1500);
  Serial.println("fin du setup");
  
}

void loop() {
  Serial.println("in the loop");
  mega.actuate(0.1);
}
