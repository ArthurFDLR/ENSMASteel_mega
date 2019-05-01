#ifndef ELEVATOR_INCLUDED
#define ELEVATOR_INCLUDED

enum state_elev {UP,DOWN};

class elevator
{
  public:
  
  elevator();
  
  void up(); // faire monter les ventouses
  void down(); // faire descendre les ventouses
  
  
  private:
  state_elev state;
};

#endif
