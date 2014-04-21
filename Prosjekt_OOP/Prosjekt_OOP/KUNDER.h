#if !defined(__KUNDER_h)	// Start p� fil
#define  __KUNDER_h

// Include fra biblotek
#include <iostream>
#include <fstream>
// Include .h filer
#include "KUNDE.h"
#include "LISTTOOL2.h"

using namespace std;

class Kunder { // Kunder classen
  private:
    int forsteNK;		// F�rste registrert n�v�rende kunde
	int sistIK;			// Siste innlagt kunde
	List* KundeListe;	// En liste med kunder 

  public:
	Kunder();						// Kunder constructor		
	void ny_kunde();
	void display(int nr);
	void vis_kunde(int kNr);
	bool vis_kunder(char* nvn);
	
};

#endif	// Slutt p� fil