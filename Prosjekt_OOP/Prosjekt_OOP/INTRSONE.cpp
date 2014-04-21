				////////// INTRSONE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "INTRSONE.h"

using namespace std;

// Constructor
Intrsone :: Intrsone(int nr) : Num_element(nr) {
  max_pris  = les("\tMax-Pris: ", MIN_PRIS, MAX_PRIS);
  min_areal = les("\tMin-Areal: ", MIN_E_AREAL, MAX_E_AREAL);
  
}

// Constructor Intersone - Henter data fra fil 
Intrsone :: Intrsone(int nr, ifstream & inn) : Num_element(nr) {
	inn >> max_pris;		// Henter data og legger til i variable
	inn >> min_areal;		// ------------------------------------
	inn >> minA_rom;		// ------------------------------------
	inn >> eien_t;			// ------------------------------------
	inn >> interessert;		// ------------------------------------
	inn >> tilsen_Bolig;	// ------------------------------------
	
	/*
	cout << max_pris	 << '\n'
		 << min_areal	 << '\n'
		 << minA_rom	 << '\n'
		 << eien_t	     << '\n'
		 << interessert  << '\n'
		 << tilsen_Bolig << '\n';
	*/
}

void Intrsone :: display() {
  cout << "\n\n\tMax-Pris:    " << max_pris
	   <<   "\n\tMin-Areal:   " << min_areal
	   <<   "\n\tMin-Ant-Rom: " << minA_rom
	   <<   "\n\tEiendomtype: ";

  switch (eien_t) {		/* Forskjellig output avhengi av hva 
								   eiendomType sin vardi er          */	
	    case 0: cout << "Tomt";			break;		// 0 for Tomt
		case 1: cout << "Enebolig";		break;		// 1 for Enebolig
		case 2: cout << "Rekkehus";		break;		// 2 for Rekkehus
		case 3: cout << "Leilighet";	break;		// 3 for Leilighet
		case 4: cout << "Hytte";		break;		// 4 for Hytte
  }

  cout <<   "\n\tInteresse:   ";

  switch (interessert) {		/* Forskjellig output avhengi av hva 
								   eiendomType sin vardi er          */	
	    case 0: cout << "Salg";		break;		// 0 for Tomt
		case 1: cout << "Leie";		break;		// 1 for Enebolig
		case 2: cout << "Begge";	break;		// 2 for Rekkehus
  }

  cout <<   "\n\tTilsending:  ";
  if (tilsen_Bolig == 0) cout << "Ukentlig";
  else					 cout << "Snarest";	
}
// ************************************************************************* //