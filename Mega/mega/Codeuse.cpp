#include "Codeuse.h"

int32_t ticksTab[2]={0,0};
uint8_t pins[2][2]={{0,0},{0,0}};
uint8_t Codeuse::nextIdToGive=0;

void Codeuse::actuate(float dt)
{
//  ticks= ticksTab[ID] + ticks;
//  pos = ticks/tickToPos;

  ticks= ticksTab[ID] ;//ID
  dPos=(ticks-oldTicks)/(tickToPos*dt);
  pos+=dPos*dt;
  oldTicks= ticks;
  Serial.println(ticks);
//  Serial.println(pos);
}

void handler0() 
 {

  if (digitalRead(pins[0][0]) == HIGH) 
  {
    if (digitalRead(pins[0][1]) == HIGH)
      ticksTab[0] = ticksTab[0] + 1;
    else
      ticksTab[0] = ticksTab[0] - 1;
  }
  else 
  {
    if (digitalRead(pins[0][1]) == LOW)
      ticksTab[0] = ticksTab[0] + 1;
    else
      ticksTab[0] = ticksTab[0] - 1;
  }
}

void handler1() 
 {
  Serial.println("In handler1");
  if (digitalRead(pins[1][0]) == HIGH) 
  {
    if (digitalRead(pins[1][1]) == HIGH)
      ticksTab[1] = ticksTab[1] + 1;
    else
      ticksTab[1] = ticksTab[1] - 1;
  }
  else 
  {
    if (digitalRead(pins[1][1]) == LOW)
      ticksTab[1] = ticksTab[1] + 1;
    else
      ticksTab[1] = ticksTab[1] - 1;
  }
  Serial.println(ticksTab[1]);
}

Codeuse::Codeuse(uint8_t pin1,uint8_t pin2,float tickToPos)
{ 
  this->pin1=pin1;
  this->pin2=pin2;
  this->ID=nextIdToGive;
  nextIdToGive++;
  pins[ID][0]=pin1;
  pins[ID][1]=pin2;
  if (ID==0)
  {
    
    attachInterrupt(digitalPinToInterrupt(pin1),handler0,CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin2),handler0,CHANGE);
  }
  else
  {
    
    attachInterrupt(digitalPinToInterrupt(pin1),handler1,CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin2),handler1,CHANGE);
  }
////  ticks=0;
//  oldTicks=0;
//  pos=0.0;
//  dPos=0.0;
  this->tickToPos=tickToPos;
}

//------------------------------------Partie tomy, on n'est plus en quadrature dans on divise la précision par 4 mais c'est deja suffisant------
//
//long Ticks;
//const int pin1;
//const int pin2;
//void Reagir();
//void Codeuse::actuate(float dt)
//{
//  Serial.println(Ticks);
//  dPos=(Ticks-oldTicks)/(tickToPos*dt);
//  pos+=dPos*dt;
//  oldTicks= ticks;
//}
//
//Codeuse::Codeuse(uint8_t pin1,uint8_t pin2,float tickToPos)
//{ 
//  Ticks=0;
//  oldTicks=0;
//  pos=0.0;
//  dPos=0.0;
//  this->tickToPos=tickToPos;
//  this->pin1=pin1;
//  this->pin2=pin2;
//  pinMode(pin2, INPUT);  
//  attachInterrupt(digitalPinToInterrupt(pin1), Reagir, RISING);
//}
//void Reagir()
//{  
//  if(digitalRead(pin2) == HIGH)
//  {
//    Ticks--;        
//  }
//  else
//  {
//    Ticks++;      
//  }      
//}
//// Fin fonction d'intéruption pour le codeur gauche
//
//Codeuse::Codeuse()
//{  
//}
