#if !defined(__INTRSONE_h)	// Start på fil
#define  __INTRSONE_h

// Include fra biblotek
#include <iostream>
#include <fstream>
// Include .h filer
#include "ENUMER.h"
#include "LISTTOOL2.h"

using namespace std;

class Intrsone : public Num_element { // Intrsone classen
  private:
	int max_pris;			// Max pris 
	int min_areal;			// Min areal
	int minA_rom;			// Min ant soverom
	int eien_t;				// Eiendomtype
	int interessert;		// Interesert i til: salg, leie eller begge-deler
	int tilsen_Bolig;		// Når info om boliger skal bli sendt til kunden
	

public:
	Intrsone(int nr, ifstream & inn);	// Constructor som henter fra fil
};
#endif	// Slutt på fil