#ifndef POMPE_INCLUDED
#define POMPE_INCLUDED

class pompe
{
  public:
  
  pompe();
  
  void take(); // prendre un pallet
  void release(); // lacher le pallet
  
  
  private:
  
  bool taken;
};


#endif
