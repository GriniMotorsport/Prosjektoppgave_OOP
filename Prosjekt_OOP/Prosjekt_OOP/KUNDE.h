#if !defined(__KUNDE_h)	// Start på fil
#define  __KUNDE_h

// Include fra biblotek
#include <iostream>
// Include .h filer
#include "LISTTOOL2.h"

using namespace std;

class Kunde : public Num_element  { // Kunde classen
  private:
	char* navn;				// Navn på kunde
	char* adr;			    // Gate-Adresse
	char* post_adr;			// Post-Adresse
	int tlf;				// Telefon-Nr
	char* mail;				// Mail / Epost
	List* IntrsonerListe;	// Ønsker fra kunde

  public:
    Kunde (int nr, ifstream & inn);	// Constructor som henter fra fil
    void kunde_display();			// Skriver ut sine variable
    void kunde_ny();				// Registrerer en ny kunde
    void kunde_slett();				// Sletter / Fjerner en kunde fra programme
    void kunde_endre();				// Endring på kunde
};

#endif