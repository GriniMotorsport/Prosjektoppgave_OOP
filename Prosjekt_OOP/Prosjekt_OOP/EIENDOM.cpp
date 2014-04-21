				////////// EIENDOM.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include <stdlib.h>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "EIENDOM.h"
#include "ENUMER.h"
#include "timer3.h"

using namespace std;

// Externe char variable
extern char dta[];
extern char e[];

Eiendom :: Eiendom(char t, int nr) : Num_element(nr) {
  Timer* timer;
  timer = new Timer();
  gateadresse = new char [MAX_TEGN_TEKST2+1];		// Sier new for char* + \0
  postAdresse = new char [MAX_TEGN_TEKST2+1];		// ----------------------
  eiersN      = new char [MAX_TEGN_TEKST2+1];		// ----------------------	
  kommune     = new char [MAX_TEGN_TEKST2+1];		// ----------------------

  eiendomType = t;
  dato = (timer -> hentDato());

  bruksNr = les("\n\tBruks-Nummer (4-siffre) : ", 4);
  saksB = les("\tSakbehandlers-Nummer (2-siffre) : ", 2);
  pris = les("\tPris for eiendomen (", MIN_PRIS ,MAX_PRIS);
  areal = les("\tAreal på eiendom (", MIN_E_AREAL, MAX_E_AREAL);  cin.ignore();
  les("\tGate-Adresse: ", gateadresse, MAX_TEGN_TEKST2);	      
  les("\tPost-Adresse: ", postAdresse, MAX_TEGN_TEKST2);		  
  les("\tEiers-Navn: ",   eiersN,      MAX_TEGN_TEKST2);		  
  les("\tKomune: ",       kommune,     MAX_TEGN_TEKST2);		  
  les("\n\tInfo om eiendommen:\n\t", gateadresse, MAX_TEGN_TEKST3); 
}

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
void Eiendom::display()	{
  cout << "\n\n\tDato for opprettelse av tomten/eiendom:  " << dato
       << "\n\tBruks-nummer:	    "						<< bruksNr
       << "\n\tSaksbehandlers nr:	"					    << saksB
	   << "\n\tPris for tomten/eiendomen:	"			    << pris
	   << "\n\tAreal på tomten/eiendomen:	"				<< areal
	   << "\n\tGateadresse:	"							    << gateadresse
	   << "\n\tPostadresse:	"							    << postAdresse
	   << "\n\tEiers navn:	"							    << eiersN
	   << "\n\tKommune navn:	"							<< kommune
	   << "\n\tBeskrivelse:	"							    << info
	   << "\n\tType eiendom:  ";
	
  switch (eiendomType) {		/* Forskjellig output avhengi av hva 
								   eiendomType sin vardi er          */	
	    case 0: cout << "Tomt";			break;		// 0 for Tomt
		case 1: cout << "Enebolig";		break;		// 1 for Enebolig
		case 2: cout << "Rekkehus";		break;		// 2 for Rekkehus
		case 3: cout << "Leilighet";	break;		// 3 for Leilighet
		case 4: cout << "Hytte";		break;		// 4 for Hytte
  }
}

bool Eiendom :: harPost(int postNr) {
  char t1 = postAdresse[0];
  char t2 = postAdresse[1];
  char t3 = postAdresse[2];
  char t4 = postAdresse[3];
  
  int tall1 = atoi(&t1);
  int tall2 = atoi(&t2);
  int tall3 = atoi(&t3);
  int tall4 = atoi(&t4);

  int tall = (tall1 * 1000) + (tall2 * 100) + (tall3 * 10) + tall4;

  if (tall == postNr) { return true; }

  return false;
}

// ************************************************************************* //