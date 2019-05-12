#ifndef POMPE_INCLUDED
#define POMPE_INCLUDED

class Pompe
{
  public:
	  Pompe();
	  void Take(); // prendre un pallet
	  void Release(); // lacher le pallet
  
  private:
  
  bool taken;
};


#endif
