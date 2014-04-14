#if !defined(__KUNDER_h)	// Start p� fil
#define  __KUNDER_h

// Include fra biblotek
#include <iostream>
#include <fstream>
// Include .h filer
#include "KUNDE.h"
#include "LISTTOOL2.h"

using namespace std;

class Kunder : public Num_element { // Kunder classen
  private:
    int forsteNK;		// F�rste registrert n�v�rende kunde
	int sistIK;			// Siste innlagt kunde
	List* KundeListe;	// En liste med kunder 

  public:
	Kunder();						// Kunder constructor			
	Kunder(int nr, ifstream & inn);	// Constructor som henter fra fil
	void Kunde_Display(char* navn_nr);
	

};

#endif	// Slutt p� fil