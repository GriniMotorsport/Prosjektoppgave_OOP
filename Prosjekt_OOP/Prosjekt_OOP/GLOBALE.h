//  Deklarasjon av prosedyre-headinger for skriv_meny.CPP:
#if !defined(__GLOBALE_h)
#define  __GLOBALE_h

//#include "GLOBALE_VARIABLE.h"

void skriv_meny();				// Skriver ut hoved-menyen
void skriv_meny_eiendom();		// Skriver ut eiendom-menyen
void skriv_meny_kunde();		// Skriver ut kunde-menyen
void skriv_meny_sone();			// Skriver ut sone-menyen
void skriv_meny_status();		// Skriver ut status-menyen
void eiendom();					// Går til kommando-valg for eiendom
void kunde();					// Går til kommando-valg for kunde
void sone();					// Går til kommando-valg for sone
void status();					// Går til kommando-valg for status
void utskrift();				// Går til kommando-valg for utskrift
void skriv_fra_fil();			// Leser informasjon fra filer

void lagNavn(char* t, char* s1, char* s2, int n, const int LEN);

char meny_valg();				// Funksjon som henter kommandovalg fra bruker

#endif
