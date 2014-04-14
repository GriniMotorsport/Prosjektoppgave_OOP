				////////// KUNDE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "KUNDE.h"
#include "INTRSONE.h"
#include "KUNDER.h"

using namespace std;

// Constructor Kunde - Henter data fra fil
Kunde :: Kunde (int nr, ifstream & inn) : Num_element(nr) {
  int soneNr;								// Sone-Nr
  navn     = new char[MAX_TEGN_TEKST2+1];	// New char med nok plass
  adr      = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  post_adr = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  mail     = new char[MAX_TEGN_TEKST2+1];	// ----------------------

  inn.getline(navn, MAX_TEGN_TEKST2);		// Getline data til variable
  inn.getline(adr, MAX_TEGN_TEKST2);		// -------------------------
  inn.getline(post_adr, MAX_TEGN_TEKST2);	// -------------------------
  inn >> tlf;  inn.ignore();	// Henter tlf og hopper over en linje på fil
  inn.getline(mail, MAX_TEGN_TEKST2);		// Getline data til variable

  inn.ignore();				// Hopper over linje

  IntrsonerListe = new List(Sorted);	// Lager en ny List Intersoner
  Intrsone* intrsone;					// Hjelpe objekt
  
  inn >> soneNr;						// Leser Sone-Nr
  
  while (!inn.eof()) {					    // Så lenge det er data på fil
    intrsone = new Intrsone(soneNr, inn);	// Legger til nytt objekt i List
    IntrsonerListe -> add(intrsone);		// -----------------------------
	inn >> soneNr;							// Spørr etter neste object
  }
}

void Kunde :: sjekkInfo(char* navn_nr)	{
	Intrsone* intrsonen;
	int nummer = atoi(navn_nr);
	int antIntrsoner = IntrsonerListe-> no_of_elements();

	if(strcmp(navn_nr, navn) == 0 || nummer == kundenummer)	{
		kunde_display();
		for(int i = 1; i <= antIntrsoner; i++)	{
			intrsonen = (Intrsone*) IntrsonerListe->remove_no(i);
			intrsonen->display();
			IntrsonerListe->add(intrsonen);
		}


	}

}


// ************************************************************************* //