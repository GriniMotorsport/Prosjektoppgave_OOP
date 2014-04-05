#include "LISTTOOL2.h"
#if !defined(__SONE_h)
#define __SONE_h

#include <iostream>

using namespace std;

class Sone {
private:
	char* info;			// Kort beskrivelse for en aktuel sone
	List* Eiendomer;
	int sonenummer;

public:
	Sone(ifstream & inn);
	void display();
	


};

#endif