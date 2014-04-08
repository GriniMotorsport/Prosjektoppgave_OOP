#if !defined (__BOLIG_h)	// Start på fil
#define __BOLIG_h

// Include .h filer
#include "EIENDOM.h"
#include "ENUMER.h"

using namespace std;

class Bolig : public Eiendom { // Bolig klassen.  En subclasse av Eiendom
private:
	int byggeaar;					// Byggeår (AAAA)
	int bruttoareal;				// Bruttoareal
	int boareal;					// Boareal
	int antSoverom;					// Ant soverom
	int onsket;						// Om til salgs / leie eller begge deler
	char type;						// Hjelpe char for og si om Bolig eller ei

public:
	Bolig(int nr, ifstream & inn);	// Constructor som henter fra fil
	void Display();					// Skriver ut sine variable
};

#endif	// Slutt på fil	