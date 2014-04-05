#include "LISTTOOL2.h"
#if !defined(__SONE_h)
#define __SONE_h

class Sone {
private:
	char* info;			// Kort beskrivelse for en aktuel sone
	List* eiendomsliste;
	int sonenummer;

public:
	void display();
	


};

#endif