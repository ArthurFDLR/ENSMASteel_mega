#include "MegaServo.h"
#include "1_CONSTANTS.h"
#include "Barillet.h"
#include "Mega.h"


Mega mega;
void setup() 
{
  mega=Mega(4.0);
  delay(1000);
  Serial.begin(115200);
}

void loop() {
  mega.actuate(0.1);
//  if (Serial.available()>0)
//  {
//    int x=Serial.parseInt();
//    mega.pinceGauche.debug(x);
//    while (Serial.available()>0)
//    {
//      Serial.read();
//    }
//  }
}
