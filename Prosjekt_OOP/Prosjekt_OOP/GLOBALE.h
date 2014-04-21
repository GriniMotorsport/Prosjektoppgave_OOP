//  Deklarasjon av prosedyre-headinger for skriv_meny.CPP:
#if !defined(__GLOBALE_h)	// Start på fil
#define  __GLOBALE_h

// Skriv_meny funkjoner
void skriv_meny();				// Skriver ut hoved-menyen
void skriv_meny_eiendom();		// Skriver ut eiendom-menyen
void skriv_meny_kunde();		// Skriver ut kunde-menyen
void skriv_meny_sone();			// Skriver ut sone-menyen
void skriv_meny_status();		// Skriver ut status-menyen

// Kategorifunksjoner
void eiendom();					// Går til kommando-valg for eiendom
void kunde();					// Går til kommando-valg for kunde
void sone();					// Går til kommando-valg for sone
void status();					// Går til kommando-valg for status
void utskrift();				// Går til kommando-valg for utskrift

// Globale funksjoner sammen med filbehandling
void hent_fra_fil();			// Leser informasjon fra filer

// Globale Display-f´Funksjoner
void Sone_Display();
void Eiendom_Display();
void Kunde_Display();

// Globale Opprett-Funksjoner
void Eiendom_Ny();
void Kunde_Ny();

// Globale Slett-Funksjoner
void Eiendom_Slett();
void Kunde_Slett();

// Globale Endre-Funksjoner
void Eiendom_Endre();
void Kunde_Endre();

// Les-funksjoner
int les (char txt[], int min, int max);		// Returnerer int verdi
int les (char txt[], const int LEN);
void les (char txt[], char* n, const int LEN);

// LagNavn funksjoner som lager et filnavn sammensatt av parametre
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN);

// Komando Funksjon
char meny_valg();				// Funksjon som henter kommandovalg fra bruker

// 
void opp_SISTE();

#endif	// Slutt på fil
