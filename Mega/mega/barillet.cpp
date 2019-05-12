#include "barillet.h"
#include "Arduino.h"

barillet::barillet()
{
  pidBarillet=new PID(true,500,20,50,20,0);
  codeuseBarillet=new Codeuse(11,12,PI*0.4/11500.0);
}

int barillet::get_pos()
{
	return 0;
}

void barillet::set_pos(int pos)
{
}

void barillet::turn(int nb)
{
}
