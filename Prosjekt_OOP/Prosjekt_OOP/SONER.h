#if !defined(__SONER_h)
#define __SONER_h

// Include filer 
#include <iostream>
#include <fstream>
#include "SONE.h"
#include "GLOBALE_CONST.h"

using namespace std;

// Soner class
class Soner {
  private:
	int nrSE;					// Nr til siste innlagte eiendom
	Sone* soner[MAX_ANT_SON];	// Max antall soner

  public:
	Soner();
	void hent_sone(int nr, ifstream & inn);
	void Sone :: vise_sone();



};


#endif