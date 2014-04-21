
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
	Sone();
	Sone(ifstream & inn);		  // Constructor som henter fra fil	
	void skriv_til_fil(ofstream & ut);
	void ny_oppdrag(int nr, bool f);
	void display(int nr);		  // Skriver ut sine variable
	void vis_eiendom(int nr);	  // Henter eksakt eiendom etter sortert nummer
	void vis_eiendommer(int postNr);
};

#endif	// Slutt på fil