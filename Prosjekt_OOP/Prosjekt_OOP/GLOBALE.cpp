#include <iostream>
#include <iomanip>
#include "GLOBALE.h"


using namespace std;

char meny_valg() {
	char ch;
	cout << "Komando: ";  cin  >> ch;  cin.ignore();  return toupper(ch);
}

void skriv_meny1()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n Hva vil du gj�re?\n"
          "\tE - Eiendom\n"
          "\tS - Skriv ut data om alle eiendommene/oppdragene i en sone.\n"
		  "\tK - Kunde\n"
		  "\tU - Utskrift\n"
		  "\tQ - Quit / avslutt\n";
}

void eiendom() { // ------------------ eiendom() ------------------------------
  char kommando;
	skriv_meny2();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "ED"; break; 
		case 'N' : cout << "EN"; break; 
		case 'S' : cout << "ES"; break; 
		case 'E' : cout << "EE"; break; 
		default:   cout << "DEFAULT-E"; break;
		}
	}
} // -------------------------------------------------------------------------

void kunde() { // ---------------- kunde() ------------------------------------
  char kommando;
	skriv_meny3();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "KD"; break; 
		case 'N' : cout << "KN"; break; 
		case 'S' : cout << "KS"; break; 
		case 'E' : cout << "KE"; break; 
		default:   cout << "DEFAULT-K"; break;
		}
	}
} // ------------------------------------------------------------------------

void sone() { // ---------------- sone() ------------------------------------
  char kommando;
	skriv_meny3();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "SD"; break; 
		default:   cout << "DEFAULT-S"; break;
		}
	}
} // ------------------------------------------------------------------------

void status() { // ---------------- sone() ------------------------------------
  char kommando;
	skriv_meny3();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "US"; break; 
		default:   cout << "DEFAULT-S"; break;
		}
	}
} // ------------------------------------------------------------------------

void skriv_meny2()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n\t----------- Eiendom -----------\n"
		  "\tD - Display eiendom\n"
	      "\tN - Opprett en ny eiendom/bolig\n"
		  "\tS - Slett en eiendom\n"
		  "\tE - Endre en eiendom\n"
		  "\tQ - Quit / avslutt\n";
}


void skriv_meny3()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\nHva vil du gj�re?\n";
  cout << "\tD - Display en kunde\n";
  cout << "\tN - Opprett en ny kunde\n";
  cout << "\tS - Slett en kunde\n";
  cout << "\tE - Endre en kunde\n";
  cout << "\tQ - Quit / avslutt\n";
}
