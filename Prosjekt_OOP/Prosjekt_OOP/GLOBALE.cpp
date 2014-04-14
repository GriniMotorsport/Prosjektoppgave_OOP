				////////// GLOBALE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
// Include .h filer
#include <stdlib.h>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"
#include "SONER.h"
#include "KUNDER.h"
#include "main.cpp"

using namespace std;


// Externe char variable
extern char dta[];
extern char SONE[];
extern char e[];

// Variable for siste-brukt
int sisteE;			// Siste registrerte eiendom
int fNaaK;			// Forste Nåvarende kunde
int sInnlK;			// Siste innlagte kunde

// Meny_valg-funksjonene tar en char input fra bruker den som kommando
char meny_valg() {
	char ch;
	cout << "Komando: ";  cin  >> ch;  cin.ignore();  return toupper(ch);
}

// Skriv_meny-funksjonen
void skriv_meny()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n Hva vil du gj�re?\n"
          "\tE - Eiendom\n"
          "\tS - Skriv ut data om alle eiendommene/oppdragene i en sone.\n"
		  "\tK - Kunde\n"
		  "\tU - Utskrift\n"
		  "\tQ - Quit / avslutt\n";
}

// Eiendom - funksjonen som har en switch til og kunne velge mellom funksjoner
void eiendom() {								// under kategorien eiendom
  char kommando;
  int sonenr;
  skriv_meny_eiendom();							// Skriver meny
  kommando = meny_valg();						// Henter komando

  while (kommando != 'Q') {		// Kjører så lenge ikke Q skrives inn
    switch (kommando){
      case 'D' : Eiendom_Display();  break;			// Eiendom_Display
	  case 'N' : sonenr = les("Skriv inn sonenummer",1 ,100);
		  soner.Eiendom_Ny(sonenr); break;			// Eiendom_Ny
	  case 'S' : cout << "ES"; break;				// Eiendom_Slett
	  case 'E' : cout << "EE"; break;				// Eiendom_Endre
	  default:   cout << "DEFAULT-E"; break;		// Deafulte
	}
   break;
  }
}

// Kunde - funksjonen som har en switch til og kunne velge mellom funksjoner
void kunde() {									// under kategorien Kunde
  char kommando;
  skriv_meny_kunde();							// Skriver meny
  kommando = meny_valg();						// Henter komando

  while (kommando != 'Q') {	       // Kjører så lenge ikke Q skrives inn
    switch (kommando){
   	  case 'D' : cout << "KD"; break;				// Kunde_Display
	  case 'N' : cout << "KN"; break;				// Kunde_Ny
	  case 'S' : cout << "KS"; break;				// Kunde_Slett
	  case 'E' : cout << "KE"; break;				// Kunde_Endre
	  default:   cout << "DEFAULT-K"; break;		// Deafult
	}
   break;
  }
}

// Sone - funksjonen som har en switch til og kunne velge mellom funksjoner
void sone() {									// under kategorien Sone
  char kommando;	
  skriv_meny_sone();							// Skriver meny
  kommando = meny_valg();						// Henter komando

  while (kommando != 'Q') {				// Kjører så lenge ikke Q skrives inn
	switch (kommando) {
   	  case 'D' : Sone_Display(); break;				// Sone_Display
	  default:   cout << "DEFAULT-S"; break;		// Deafult
	}
   break;
  }
} 

// Status - funksjonen som har en switch til og kunne velge mellom funksjoner
void status() {									// under kategorien Status
  char kommando;
  skriv_meny_status();							// Skriver meny
  kommando = meny_valg();						// Henter komando

  while (kommando != 'Q') {			// Kjører så lenge ikke Q skrives inn
	switch (kommando){
	  case 'S' : cout << "US";        break;		// Utskrift_Status 
	  default:   cout << "DEFAULT-S"; break;		// Default
	}
   break;
  }
}

//  Eiendom - Skriver meny/lovlige kommandoer til bruker
void skriv_meny_eiendom()  {         
  cout << "\n\n\n\t----------- Eiendom -----------\n"
		  "\tD - Display eiendom\n"
	      "\tN - Opprett en ny eiendom/bolig\n"
		  "\tS - Slett en eiendom\n"
		  "\tE - Endre en eiendom\n"
		  "\tQ - Quit / avslutt\n";
}

// Kunde - Skriver meny/lovlige kommandoer til bruker
void skriv_meny_kunde()  {         
  cout << "\n\n\n\t----------- Kunde -----------\n"
		  "\tD - Display en kunde\n"
		  "\tN - Opprett en ny kunde\n"
		  "\tS - Slett en kunde\n"
		  "\tE - Endre en kunde\n"
		  "\tQ - Quit / avslutt\n";
}

// Sone - Skriver meny/lovlige kommandoer til bruker
void skriv_meny_sone() {
	cout << "\n\n\n\t----------- Sone -----------\n"
		  "\tD - Display en sone\n";
}

// Utskrift - Skriver meny/lovlige kommandoer til bruker
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

// Les - funksjon med retun int
int les (char txt[STRLEN], int min, int max) {
  int t;								// Hjelpe variable
  cout << txt << '(' << min << '-' << max << "): ";  cin >> t;	// Skriver ut tekst og lar bruke skrive inn
	
  while (t < min || t > max) {        // Hvis verdi er i intervalet fra min 
    cout << "\n\tUlovelig verdi!\n"	// til max så returnere funskjonen t
   	     << txt;  cin >> t;			// Looper til riktig interval
  } 
  return t;
}

// Les tekst
void les(char t[], char s[], const int LEN)	{
	do {
		cout << '\t' << t << ":	";
		cin.getline(s, LEN);
	} while (strlen(s) == 0);
	}

// Sone_Display - Skriver ut data om ønsket sone
void Sone_Display() {
  char* nvn;
  int nr =				// Henter sone-nr fra bruker
		les("\nHvilken sone hvil du skrive ut data om? (1 - 100):\t", 1, 100);
  
  nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Setter av plass
  lagNavn(nvn, SONE, dta, nr, 3);	 // Kaller på funksjonen med tilsente parametre
	
  ifstream finnesSone (nvn);	// Setter ifstream til generert fil-navn
  if (finnesSone) { soner -> vis_sone(nr); }	// Hvis filen finnes. Hent data
  else { cout << "\n\t- Denne sonen eksisterer desverre ikke -"; }
}

// Eiendom_Display - Skriver ut ønsket eiendom / eiendommer for bruker
void Eiendom_Display() {
  char ch;
  int nr;			// Spørr om en eller flere eiendommer skal søkes etter
  cout << "\nHvil du soke etter (E)n eller (F)lere eiendommer?:\t ";  
  cin >> ch;  cin.ignore();
								      // Kjører til endte E eller F skrives
  while (toupper(ch) != 'E' || toupper(ch) != 'F') {	
    switch (toupper(ch)) {
      case 'E': {	// Hvis - E -
  	    cout << "Skriv inn Eiendomsnr / oppdragsnr (Fra 100000):\t ";  cin >> nr;
	    soner -> hent_eiendom(nr);		// Hent eiendom
		  
	  } break;
	    
	  case 'F': {   // Hvis - F -
	  		
       } break;
	  
	  default:   break;
	}
  }  
}


// Kunde_Display - Skriver ut data om ønsket kunde
void Kunde_Display() {


// Hent_fra_fil - henter all data fra filer til programmet og legger de inn
void hent_fra_fil() { 
  char* nvn;
  ifstream sisteHent	("SISTE.DTA");			// Skriver siste variable fra fil
  
  if (sisteHent) { // hvis filen finnes
	 
	sisteHent >> sisteE;    // Siste registrerte eiendom
    sisteHent >> fNaaK;     // Forste Nåvarende kunde
    sisteHent >> sInnlK;	// Siste innlagte kunde
  }
  
  for (int i = 1; i <= MAX_ANT_SON; i++) {	// Fra 1 - 100 plasser i sone[]
	nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Legger av plass 
	lagNavn(nvn, SONE, dta, i, 3);					// Kaller på funksjonen med
													// tilsente parametre
	ifstream soneHent (nvn);		// Setter ifstream lik filnavn

	if (soneHent) {						 // Hvis filen finnes
	  soner -> hent_sone(i, soneHent);	// Hent data for soner
	}
  }

  // Kunne les_fra_fil 
  int ant = sInnlK - fNaaK;
  int nr = fNaaK;	    // Går fra forste nåværende kunde til siste registrerte
  for (int i = 1; i <= ant; i++) {	
    nvn = new char[(strlen(k) + strlen(dta) + 7 + 1)];	// Legger av plass
	lagNavn(nvn, k, dta, nr++, 7);// Kaller på funksjonen med tilsent parametre

	ifstream kundeHent (nvn);		// Setter ifstream lik filnavn

	if (kundeHent) { // Hvis filen finnes. Hent data for kunder
	  kunder = new Kunder(nr, kundeHent);
	}
  }
}

// ************************************************************************* //