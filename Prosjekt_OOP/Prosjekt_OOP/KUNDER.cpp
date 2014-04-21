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
Kunder :: Kunder() {
  forsteNK = fNaaK;
  sistIK = sInnlK;
  int ant = sInnlK - forsteNK;
  char* nvn;
  
  extern char dta[];
  extern char k[];

  Kunde* kunde;	
  KundeListe = new List(Sorted);

  cout << ant;
  int nr = fNaaK;	    // Går fra forste nåværende kunde til siste registrerte
  
  for (int i = 0; i <= ant; i++) {	
    nvn = new char[(strlen(k) + strlen(dta) + 7 + 1)];	// Legger av plass
	lagNavn(nvn, k, dta, nr, 7);// Kaller på funksjonen med tilsent parametre

	ifstream kundeHent (nvn);		// Setter ifstream lik filnavn

	if (kundeHent) { // Hvis filen finnes. Hent data for kunder
	  kunde = new Kunde(nr++, kundeHent);			// Legger til hjelpe objekt 
      KundeListe -> add(kunde);				// inn i list med data	
	}
  }
}

void Kunder :: ny_kunde() {
  Kunde* kunde;
  forsteNK = fNaaK;
  sistIK = sInnlK;
  kunde = new Kunde();
  KundeListe -> add(kunde);

}

// Void vis_kunde - viser kunde med nr
void Kunder :: vis_kunde(int kNr) {
  cout << "\n\t\t--- Kunde-Nr - " << kNr << " ---";
  if (KundeListe -> in_list(kNr)) {
	  KundeListe -> display_element(kNr);	
  }
}

// Void vis_kunder - viser kunder med navn
bool Kunder :: vis_kunder(char* nvn) {
  Kunde* kunde;
  bool finnes = false;
  int ant = (KundeListe -> no_of_elements());
 cout << ant;
  for (int i = 1; i <= ant; i++) {
    kunde = (Kunde*) KundeListe -> remove_no(i);

	if (!kunde -> finnes_navn(nvn)) { kunde -> display();  finnes = true; }

	KundeListe -> add(kunde);
  }
  return finnes;
}

// ************************************************************************* //