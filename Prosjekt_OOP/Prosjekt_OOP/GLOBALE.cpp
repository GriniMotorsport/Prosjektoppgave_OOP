				////////// GLOBALE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
// Include .h filer
#include <stdlib.h>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"
#include "SONER.h"
#include "KUNDER.h"


using namespace std;

// Externe objekter
extern Soner* soner;
extern Kunder* kunder;

// Externe char variable
extern char dta[];
extern char SONE[];
extern char e[];

// Variable for siste-brukt
extern int sisteE;			// Siste registrerte eiendom
extern int fNaaK;			// Forste Nåvarende kunde
extern int sInnlK;			// Siste innlagte kunde

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
  skriv_meny_eiendom();							// Skriver meny
  kommando = meny_valg();						// Henter komando

  while (kommando != 'Q') {		// Kjører så lenge ikke Q skrives inn
    switch (kommando){
      case 'D' : Eiendom_Display();  break;		// Eiendom_Display
   	  case 'N' : Eiendom_Ny();       break;		// Eiendom_Ny
	  case 'S' : Eiendom_Slett;      break;	    // Eiendom_Slett
	  case 'E' : Eiendom_Endre; break;				// Eiendom_Endre
	  default:   cout << "Dette er en ugyldig komando!"; break;		// Deafulte
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
   	  case 'D' : Kunde_Display();     break;	    // Kunde_Display
	  case 'N' : Kunde_Ny();          break;		// Kunde_Ny
	  case 'S' : Kunde_Slett();       break;  		// Kunde_Slett
	  case 'E' : Kunde_Endre();       break;    	// Kunde_Endre
	  default:   cout << "Dette er en ugyldig komando!"; break;  // Deafult
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
int les (char txt[], int min, int max) {
  int t;								// Hjelpe variable
  // Skriver ut tekst og lar bruke skrive inn
  cout << txt << min << " - " << max << "):\t";  cin >> t;				
	
  while (t < min || t > max) {            // Hvis verdi er i intervalet fra min 
    cout << "\n\t - Ulovelig verdi! -\n"  // til max så returnere funskjonen t
									      // Looper til riktig interval
   	     << txt << min << " - " << max << "):\t";  cin >> t;			
  }										
  return t;
}

// Les - Funksjon som henter inputt
void les(char txt[], char* n, const int LEN) { 
  do  {
    cout << txt;                  // skriver ut txt
    cin.getline(n, LEN);          // Leser inn tekst.
  } while (strlen(n) == 0);      
}

// Les - 
int les (char txt[], const int LEN) {
  int tall;
  cout << txt;  cin >> tall;

  switch (LEN) {
    case 2: {
	  while (tall > 99 || tall == 0) {
        cout << "\n\t\tUgyldig Verdi!\n";
	    cout << txt;  cin >> tall;
      } 
    } break;

    case 4: {
	  while (tall > 9999 || tall == 0) {
        cout << "\n\t\tUgyldig Verdi!\n";
	    cout << txt;  cin >> tall;
      }
	} break;

	case 8: {
	  while (tall > 99999999 || tall == 0) {
        cout << "\n\t\tUgyldig Verdi!\n";
	    cout << txt;  cin >> tall;
      }
	} break;
	
  }
  return tall;
}

// Sone_Display - Skriver ut data om ønsket sone
void Sone_Display() {
  char* nvn;
  int nr =				// Henter sone-nr fra bruker
		les("\nHvilken sone hvil du skrive ut data om (", 1, MAX_ANT_SON);
  
  nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Setter av plass
  lagNavn(nvn, SONE, dta, nr, 3);	 // Kaller på funksjonen med tilsente parametre
	
  ifstream finnesSone (nvn);	// Setter ifstream til generert fil-navn
  if (finnesSone) { soner -> vis_sone(nr); }	// Hvis filen finnes. Hent data
  else { cout << "\n\t- Denne sonen eksisterer desverre ikke -"; }
}

// Eiendom_Display - Skriver ut ønsket eiendom / eiendommer for bruker
void Eiendom_Display() {
  char ch;
  char* nvn;
  int nr;			// Spørr om en eller flere eiendommer skal søkes etter
  nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Setter av plass
  cout << "\nHvil du soke etter (E)n eller (F)lere eiendommer?:\t ";  
  cin >> ch;  cin.ignore();
								      // Kjører til endte E eller F skrives
  while (toupper(ch) != 'E' || toupper(ch) != 'F') {	
    switch (toupper(ch)) {
      case 'E': {	// Hvis - E -
  	    nr = les("Skriv inn Eiendomsnr / oppdragsnr (", 10000, sisteE);
		for (int i = 1; i <= MAX_ANT_SON; i++) {
		  lagNavn(nvn, SONE, dta, i, 3);	
		  ifstream finnesSone (nvn);

		  if (finnesSone) {soner -> hent_eiendom(i, nr);  }	// Hent eiendom
		}
	  } break;
	    
	  case 'F': {   // Hvis - F -
	  	nr = les("Skriv inn et postnr (", MIN_POST, MAX_POST);
		for (int i = 1; i <= MAX_ANT_SON; i++) {
		  lagNavn(nvn, SONE, dta, i, 3);	
		  ifstream finnesSone (nvn);

		  if (finnesSone) {soner -> hent_eiendommer(i, nr);  }	// Hent eiendom
		}
		
       } break;
	  
	  default:   break;
	}
	break;
  }  
}

// Kunde_Display Skriver ut data om gitt kunde eller alle kunder med gitt navn
void Kunde_Display() {
  char ch;
  char* nvn;
  char* navn;
  int nr;
  cout << "\nDette er en funksjon som skriver ut forskjellige kunde-data:\n"
	   << "(A) Skriver ut data om en kunde (Kunde-Nr)\n"
	   << "(B) Skriver ut data om kunder ved et gitt navn (Kunde-Navn)\n\n";
  ch = meny_valg();

  switch (toupper(ch)) {
    case 'A' : {
	  nr = les("SKriv inn et Kunde-Nr som du vil soke paa (", fNaaK, sInnlK);
	  nvn = new char[(strlen(k) + strlen(dta) + 7 + 1)];	// Setter av plass
      lagNavn(nvn, k, dta, nr, 7);	 // Kaller på funksjonen med tilsente parametre
	  ifstream finnKunde (nvn);

	  if (finnKunde) { kunder -> vis_kunde(nr); }
	  else { cout << "Kunden finnes ikke"; }

	} break;

    case 'B' : {
	  navn = new char[]; 
	  
	  les("Skriv inn et navn for kunde: ", navn, MAX_TEGN_TEKST2);
	  if (!kunder -> vis_kunder(navn)) {
	    cout << "Kunden eksisterer ikke";
	  }
    
	} break;
    
	default: break;
  }
}

// Oppretter en ny eiendom i en angitt sone
void Eiendom_Ny() {
  char* nvn;
  bool finnes = false;

  int soneNr = les("\n\tHvilken sone ligger det nye oppdraget (", 1, MAX_ANT_SON);
  
  nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];	// Legger av plass 
  lagNavn(nvn, SONE, dta, soneNr, 3);					// Kaller på funksjonen med
													// tilsente parametre
  ifstream soneHent (nvn);		// Setter ifstream lik filnavn
  
  if (soneHent) { finnes = true; }
  
  soner -> ny_oppdrag(soneNr, finnes); 
}

// Oppretter en ny kunde
void Kunde_Ny() {
  cout << "\n\tGratulerer som en ny kunde her hos oss.\n\n\tDitt kunde-nummer er: "
	   << "---" << (++sInnlK) << "---\n";
 
  kunder -> ny_kunde();
	  
}

// Sletter en utvalgt eiendom etter eiendom-nummer
void Eiendom_Slett() {

}

void Kunde_Slett() {

}

// Endrer på verdier som objekter har og lagrer endringene
void Eiendom_Endre() {

}

void Kunde_Endre() {

}

// Hent_fra_fil - henter all data fra filer til programmet og legger de inn
void hent_fra_fil() { 
  char* nvn;
  ifstream sisteHent	("SISTE.DTA");		// Skriver siste variable fra fil
  
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

  // Kunnde les_fra_fil 
 
  if (!fNaaK == 0) { kunder = new Kunder(); }
}

void opp_SISTE() {
  ofstream siste ("SISTE.DTA");
  siste << sisteE   << '\n'
        << fNaaK    << '\n'
        << sInnlK   << '\n';
}

// ************************************************************************* //