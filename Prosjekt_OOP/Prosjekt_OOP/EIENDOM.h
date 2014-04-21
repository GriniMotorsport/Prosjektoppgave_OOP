#if !defined(__EIENDOM_h)	// Start p� fil
#define  __EIENDOM_h

// Include fra biblotek
#include <iostream>
#include <fstream>
// Include .h filer
#include "ENUMER.h"
#include "LISTTOOL2.h"

using namespace std;

class Eiendom : public Num_element { // Eiendom-classen
  private:
    int dato;				// Dato for opprettelse av tomten/eiendom
	int bruksNr;			// Bruks-nummer (4-sifret)
	int saksB;				// Saksbehandlers nr
	int pris;				// Pris for tomten/eiendomen
	int areal;				// Areal p� tomten/eiendomen
	char* gateadresse;		// Gateadresse (gate + nr)
	char* postAdresse;		// Postadresse (nr + sted)
	char* eiersN;			// Eiers navn
	char* kommune;			// Kommune navn
	char* info;				// Beskrivelse av eiendomen
	int eiendomType;		// Enum verdi

  public:
    Eiendom(char t, int nr);
	Eiendom(int nr, ifstream & inn);	// Constructor som henter fra fil
    void display();					// Skriver ut sine variable
    bool harPost(int postNr);
};

#endif	// Slutt p� fil