#include "barillet.h"
#include "Arduino.h"

barillet::barillet()
{
  pidBarillet=*(new PID(true,500,20,50,20,0));
}
