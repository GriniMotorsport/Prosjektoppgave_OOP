
#if !defined(__SONE_h)	// Start på fil
#define __SONE_h

// Include fra biblotek
#include <iostream>
// Include .h filer
#include "LISTTOOL2.h"

using namespace std;

class Sone { // Sone-Classen
private:
	char* info;			// Kort beskrivelse for en aktuel sone
	List* Eiendomer;	// En liste med eiendommer
	

public:
	Sone(ifstream & inn);		// Constructor som henter fra fil	
	void display(int nr);		// Skriver ut sine variable
	void hent_eiendom(int nr);	// Henter eksakt eiendom etter sortert nummer

};

#endif	// Slutt på fil