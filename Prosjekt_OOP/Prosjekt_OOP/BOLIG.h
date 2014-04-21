#if !defined (__BOLIG_h)	// Start p� fil
#define __BOLIG_h

// Include .h filer
#include "EIENDOM.h"
#include "ENUMER.h"

using namespace std;

class Bolig : public Eiendom { // Bolig klassen.  En subclasse av Eiendom
  private:
	int byggeaar;					// Bygge�r (AAAA)
	int bruttoareal;				// Bruttoareal
	int boareal;					// Boareal
	int antSoverom;					// Ant soverom
	int onsket;						// Om til salgs / leie eller begge deler

  public:
	Bolig(char t, int nr);
	Bolig(int nr, ifstream & inn);	// Constructor som henter fra fil
	void display();					// Skriver ut sine variable
};

#endif	// Slutt p� fil	