				////////// EIENDOM.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "EIENDOM.h"
#include "ENUMER.h"
#include "timer3.h"

using namespace std;

// Eiendom-constructor som henter data fra fil
Eiendom :: Eiendom(int nr, ifstream & inn) : Num_element(nr) {
  gateadresse = new char [MAX_TEGN_TEKST2+1];		// Sier new for char* + \0
  postAdresse = new char [MAX_TEGN_TEKST2+1];		// ----------------------
  eiersN      = new char [MAX_TEGN_TEKST2+1];		// ----------------------	
  kommune     = new char [MAX_TEGN_TEKST2+1];		// ----------------------
  info        = new char [MAX_TEGN_TEKST3+1];		// ----------------------

  inn >> dato;		// Legger data til variable	
  inn >> bruksNr;	// -----------------------
  inn >> saksB;		// -----------------------		
  inn >> pris;		// -----------------------   // Hopper til neste linje
  inn >> areal;		/* ----------------------- */  inn.ignore(); 
 
  inn.getline(gateadresse, MAX_TEGN_TEKST2);	// Sier getline for hent
  inn.getline(postAdresse, MAX_TEGN_TEKST2);    // ---------------------
  inn.getline(eiersN, MAX_TEGN_TEKST2);		    // ---------------------
  inn.getline(kommune, MAX_TEGN_TEKST2);		// ---------------------
  inn.getline(info, MAX_TEGN_TEKST3);			// ---------------------	
  inn >> eiendomType;			// Cin for eiendomstype
};

// Eiendom-Display for visning av data
void Eiendom::Display()	{
  Eiendomstype type;				// Skriver ut data om Eiendom
  cout << "\nDato for opprettelse av tomten/eiendom:  " << dato
       << "\nBruks-nummer:	"							<< bruksNr
       << "\nSaksbehandlers nr:	"					    << saksB
	   << "\nPris for tomten/eiendomen:	"			    << pris
	   << "\nAreal på tomten/eiendomen:	"				<< areal
	   << "\nGateadresse:	"							<< gateadresse
	   << "\nPostadresse:	"							<< postAdresse
	   << "\nEiers navn:	"							<< eiersN
	   << "\nKommune navn:	"							<< kommune
	   << "\nBeskrivelse:	"							<< info
	   << "\nType eiendom: ";
	
  switch (eiendomType) {		/* Forskjellig output avhengi av hva 
								   eiendomType sin vardi er          */	
	    case 0: cout << "Tomt";			break;		// 0 for Tomt
		case 1: cout << "Enebolig";		break;		// 1 for Enebolig
		case 2: cout << "Rekkehus";		break;		// 2 for Rekkehus
		case 3: cout << "Leilighet";	break;		// 3 for Leilighet
		case 4: cout << "Hytte";		break;		// 4 for Hytte
  }
}

/* Eiendom-finnes brukes for og se om number som er sortert etter i listen med
   er lik nr som brukeren skriver i input*/
bool Eiendom :: finnes_nr(int nr) {
	if (number == nr) return true;			// Hvis like.		Return true
	return false;							// Hvis ikke-like.	Return false
}

Eiendom :: Eiendom(int oppdrnr)	: Num_element(oppdrnr)	{
	char temp[STRLEN];
	Timer* timer3 = new Timer;
	dato = timer3->hentDato();
	delete timer3;

	bruksNr = les("Bruksnummer", 1000, 9999);
	saksB = les("Saksbehandlernummer", 0, 1000); 
	pris = les ("Pris", 1, 100000000);
	areal = les ("Areal", 1, 1000);

	les("Gateadresse:", temp, STRLEN)
}

// ************************************************************************* //