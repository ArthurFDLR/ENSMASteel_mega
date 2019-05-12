#ifndef COMM_INCLUDED
#define COMM_INCLUDED
#include "Arduino.h"

//Cette classe s'occupe de la communication avec la teensy

#define NB_MESSAGES 11
enum MessageE
{
	Default, Impossible, Tirette, Pince_Ouverte, Pince_Mi_Fermee, Pince_Fermee, Evitemment, Ok, Done, New_Action, Sync, Evitemment_Clear
};

class Comm
{
public:
	Comm();
	~Comm();

	void sendMessage(MessageE newMsg);

private:

};


#endif // !COMM_INCLUDED