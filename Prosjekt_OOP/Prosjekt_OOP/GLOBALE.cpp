#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"

using namespace std;

// Variable for siste-brukt
int sisteE;			// Siste registrerte eiendom
int fNaaK;			// Forste Nåvarende kunde
int sInnlK;			// Siste innlagte kunde

char meny_valg() {
	char ch;
	cout << "Komando: ";  cin  >> ch;  cin.ignore();  return toupper(ch);
}

void skriv_meny()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n Hva vil du gj�re?\n"
          "\tE - Eiendom\n"
          "\tS - Skriv ut data om alle eiendommene/oppdragene i en sone.\n"
		  "\tK - Kunde\n"
		  "\tU - Utskrift\n"
		  "\tQ - Quit / avslutt\n";
}

void eiendom() { // ------------------ eiendom() ------------------------------
  char kommando;
  skriv_meny_eiendom();
  kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "ED"; break; 
		case 'N' : cout << "EN"; break; 
		case 'S' : cout << "ES"; break; 
		case 'E' : cout << "EE"; break; 
		default:   cout << "DEFAULT-E"; break;
		}
	  break;
	}
} // -------------------------------------------------------------------------

void kunde() { // ---------------- kunde() ------------------------------------
  char kommando;
  skriv_meny_kunde();
  kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "KD"; break; 
		case 'N' : cout << "KN"; break; 
		case 'S' : cout << "KS"; break; 
		case 'E' : cout << "KE"; break; 
		default:   cout << "DEFAULT-K"; break;
		}
	  break;
	}
} // ------------------------------------------------------------------------

void sone() { // ---------------- sone() ------------------------------------
  char kommando;
  skriv_meny_sone();
  kommando = meny_valg();

  while (kommando != 'Q') {
	switch (kommando){
   	  case 'D' : cout << "SD"; break; 
	  default:   cout << "DEFAULT-S"; break;
	}
   break;
  }
} // ------------------------------------------------------------------------

void status() { // ---------------- sone() ------------------------------------
  char kommando;
	skriv_meny_status();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'S' : cout << "US"; break; 
		default:   cout << "DEFAULT-S"; break;
		}
	  break;
	}
} // ------------------------------------------------------------------------

void skriv_meny_eiendom()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n\t----------- Eiendom -----------\n"
		  "\tD - Display eiendom\n"
	      "\tN - Opprett en ny eiendom/bolig\n"
		  "\tS - Slett en eiendom\n"
		  "\tE - Endre en eiendom\n"
		  "\tQ - Quit / avslutt\n";
}

void skriv_meny_kunde()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n\t----------- Kunde -----------\n"
		  "\tD - Display en kunde\n"
		  "\tN - Opprett en ny kunde\n"
		  "\tS - Slett en kunde\n"
		  "\tE - Endre en kunde\n"
		  "\tQ - Quit / avslutt\n";
}

void skriv_meny_sone() {
	cout << "\n\n\n\t----------- Sone -----------\n"
		  "\tD - Display en sone\n";
}

void skriv_meny_status() {
	cout << "\n\n\n\t----------- Utskrifter -----------\n"
		  "\tS - Skriv utskrifter til kunde \n";
}

// Kode for lagNavn
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN) {  
  char num[10];					// Hjelpe charArray.
  itoa(n, num, 10);				// Gjør n om til char og legger i num.
  int ant = LEN - strlen(num);	/* Får tak i antall ganger char "0" skal
								   legges til i filnavn før n. */
  strcpy(t, s1);				    // Legger s1 til filnavn.
  for (int i = 1; i <= ant; i++) {  // Skriver 0 til filnavn hvis plass.
	  strcat(t, "0"); }				// ________________________________
  strcat(t, num);				    // Legger num til filnavn.
  strcat(t, s2);					// Legger filtype til filnavn.
}


void les_fra_fil() { // Les fra fil ------------------------------------------
  char* nvn;
  ifstream sisteHent	("SISTE.DTA");			// Skriver siste variable fra fil
  


  if (sisteHent) { // hvis filen finnes
	 
	sisteHent >> sisteE;    // Siste registrerte eiendom
    sisteHent >> fNaaK;     // Forste Nåvarende kunde
    sisteHent >> sInnlK;	// Siste innlagte kunde
  }
  
  for (int i = 1; i <= MAX_ANT_SON; i++) {
	nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];
	lagNavn(nvn, SONE, dta, i, 3);	 // Kaller på funksjonen med tilsente parametre
	
	ifstream soneHent (nvn);

	if (soneHent) {
	  cout << "Finnes";
	}
  }
}