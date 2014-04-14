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
// Displayer en kunde
void Kunder :: Kunde_Display(char* navn_nr)	{
	Kunde* kunden;
	int antallkunder = KundeListe-> no_of_elements();	//Finner antall kunder
	
	for(int i = 1; i <= antallkunder; i++)	{
		kunden = (Kunde*) KundeListe->remove_no(i);
		kunden-> sjekkInfo(navn_nr);
		KundeListe->add(kunden);
	}


}


// ************************************************************************* //