#if !defined(__SONER_h)	// Start på fil
#define __SONER_h

// Include fra biblotek
#include <iostream>
#include <fstream>
// Include .h filer
#include "SONE.h"
#include "GLOBALE_CONST.h"

using namespace std;

class Soner { // Soner-Class
  private:
	int nrSE;					// Nr til siste innlagte eiendom
	Sone* sonene[MAX_ANT_SON];	// Max antall soner

  public:
	Soner();								// Soner constructor
	void hent_sone(int nr, ifstream & inn);	// Constructor som henter fra fil
	void vis_sone(int nr);					// Viser eksakt sone fra input
	void hent_eiendom(int nr);				// Henter eksakt eiendom
	void Eiendom_Ny(int sonenr);



};

#endif	// Slutt på fil