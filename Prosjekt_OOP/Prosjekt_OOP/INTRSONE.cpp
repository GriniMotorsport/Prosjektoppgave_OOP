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

Intrsone :: Intrsone(int snr) : Num_element(snr){
	char valg;
	sonenummer = snr;

	max_pris = les("Maxpris", 1, 99999999);	
	min_areal = les("Minimum areal", 1, 99999);	
	minA_rom = les("Minimum antall soverom", 1, 30);

	cout << "\nHvilken eiendomstype onsker du? [T]omt, [E]nebolig, [R]ekkehus, [L]eilighet, [H]ytte";
	valg = meny_valg();

	switch(valg)	{
		case 'T' : eien_t = Tomt; break;
		case 'E' : eien_t = Enebolig; break;
		case 'R' : eien_t = Rekkehus; break;
		case 'L' : eien_t = Leilighet; break;
		case 'H' : eien_t = Hytte; break;
		default: cout << "\n\nUgyldig kommando"; break;
	}

	cout << "\nHva onsker du å gjore? [S]alg, [L]eie";
	valg = meny_valg();

	switch(valg)	{
		case 'S' : interessert = Salg; break;
		case 'L' : interessert = Leie; break;
		default: cout << "\n\nUgyldig kommando"; break;
	}

	cout << "Hvor ofte vil du faa tilsendt info om boliger? [U]kentlig eller [S]narest";
	valg = meny_valg();

	switch(valg)	{
		case 'U' : tilsen_Bolig = Ukentlig; break;
		case 'S' : tilsen_Bolig = Snarest; break;
		default: cout << "\n\nUgyldig kommando"; break;
	}


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