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

void Intrsone :: display()	{
	char* Eiendomstype[] = {"Tomt", "Enebolig", "Rekkehus", "Leilighet", "Hytte"};
	char* Onske[] = {"Salg", "Leie", "Begge"};
	char* Boliginfo[] = {"Ukentlig", "Snarest"};
	cout << "\n\n Interessesone:	";
	cout << "\nSonenummer:	" << sonenummer;
	cout << "\nMakspris:	" << max_pris;
	cout << "\nMinimum areal:	" << min_areal;
	cout << "\nMinimum soverom:	" << minA_rom;
	cout << "\nEiendomtype:	" << Eiendomstype[eien_t];
	cout << "\nInteressert i: " << Onske[interessert];
	cout << "\nTilsending:	" << Boliginfo[tilsen_Bolig];
		
}

// ************************************************************************* //