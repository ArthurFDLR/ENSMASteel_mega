#ifndef COMM_INCLUDED
#define COMM_INCLUDED
#include "Arduino.h"
#include "1_CONSTANTS.h"

//Cette classe s'occupe de la communication avec la teensy

class Comm
{
public:
	Comm();
	~Comm();

	void sendMessage(MessageE newMsg);

private:

};


#endif // !COMM_INCLUDED
