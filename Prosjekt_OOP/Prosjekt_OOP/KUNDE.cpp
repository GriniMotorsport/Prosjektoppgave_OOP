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
#include "SONER.H"

using namespace std;

extern Soner* soner;

// Externe char variable
extern char dta[];
extern int sInnlK;			// Siste innlagte kunde
extern char SONE[];

// Constructor Kunde - Legger til ny kunde
Kunde :: Kunde() : Num_element(sInnlK) {
  char* nvn;
  char ch;
  int soneNr;
  Intrsone* intrsone;
  navn     = new char[MAX_TEGN_TEKST2+1];	// New char med nok plass
  adr      = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  post_adr = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  mail     = new char[MAX_TEGN_TEKST2+1];	// ----------------------

  les("Navn: ", navn, MAX_TEGN_TEKST2);
  les("Gate-Adressse: ", adr, MAX_TEGN_TEKST2);
  les("Post-Adresse:", post_adr, MAX_TEGN_TEKST2);
  les("Mail:", mail, MAX_TEGN_TEKST2);
  tlf = les("Telefon: ", 8);

  soneNr = les("Hvilke sone har du en interesse for (", 1, MAX_ANT_SON);
  nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Legger av plass 
 
  for (int i = 1; i <= MAX_ANT_SON; i++) {	// Fra 1 - 100 plasser i sone[]
	lagNavn(nvn, SONE, dta, i, 3);					// Kaller på funksjonen med
													// tilsente parametre
	ofstream soneFinnes (nvn);

	if (soneFinnes) {
	  intrsone = new Intrsone(soneNr);
	  IntrsonerListe -> add(intrsone);
	} 
  }
 
  
}

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

Kunde :: Kunde(ofstream & ut) {
	ut << navn      << '\n'
	   << adr       << '\n'
	   << post_adr  << '\n'
	   << tlf       << '\n'
	   << mail      << '\n';
}

void Kunde :: display() {
  cout << "\n\n\tNavn:         " << navn
	   << "\n\tAdresse:      " << adr
	   << "\n\tPost-Adresse: " << post_adr
	   << "\n\tTelefon:      " << tlf
	   << "\n\tEpost:        " << mail;
  IntrsonerListe -> display_list();
  cout << "\n\t---------------------------------";
}

bool Kunde :: finnes_navn(char* nvn) {
  if (strcmp(nvn, navn)) { return true;  }
  else                   { return false; }
}
// ************************************************************************* //