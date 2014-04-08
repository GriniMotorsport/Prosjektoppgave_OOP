				////////// KUNDER.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "KUNDER.h"
#include "KUNDE.h"


using namespace std;

// Extern int variable
extern int fNaaK;			// Forste Nåvarende kunde	
extern int sInnlK;			// Siste innlagte kunde

// Constructor Kunder
Kunder :: Kunder() {}

// Constructor Kunder - Henter data fra fil
Kunder :: Kunder(int nr, ifstream & inn) : Num_element(nr) {
  forsteNK = fNaaK;
  sistIK = sInnlK;
  
  KundeListe = new List(Sorted);		// Lager en ny List
  Kunde* kunde;							// Hjelpe objekt
  kunde = new Kunde(nr, inn);			// Legger til hjelpe objekt 
  KundeListe -> add(kunde);				// inn i list med data
}
// ************************************************************************* //