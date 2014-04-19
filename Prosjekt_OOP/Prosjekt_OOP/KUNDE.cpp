				////////// KUNDE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "KUNDE.h"
#include "INTRSONE.h"
#include "KUNDER.h"

using namespace std;

// Constructor Kunde - Henter data fra fil
Kunde :: Kunde (int nr, ifstream & inn) : Num_element(nr) {
  int soneNr;								// Sone-Nr
  navn     = new char[MAX_TEGN_TEKST2+1];	// New char med nok plass
  adr      = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  post_adr = new char[MAX_TEGN_TEKST2+1];	// ----------------------
  mail     = new char[MAX_TEGN_TEKST2+1];	// ----------------------

  inn.getline(navn, MAX_TEGN_TEKST2);		// Getline data til variable
  inn.getline(adr, MAX_TEGN_TEKST2);		// -------------------------
  inn.getline(post_adr, MAX_TEGN_TEKST2);	// -------------------------
  inn >> tlf;  inn.ignore();	// Henter tlf og hopper over en linje på fil
  inn.getline(mail, MAX_TEGN_TEKST2);		// Getline data til variable

  inn.ignore();				// Hopper over linje

  IntrsonerListe = new List(Sorted);	// Lager en ny List Intersoner
  Intrsone* intrsone;					// Hjelpe objekt
  
  inn >> soneNr;						// Leser Sone-Nr
  
  while (!inn.eof()) {					    // Så lenge det er data på fil
    intrsone = new Intrsone(soneNr, inn);	// Legger til nytt objekt i List
    IntrsonerListe -> add(intrsone);		// -----------------------------
	inn >> soneNr;							// Spørr etter neste object
  }
}

// Kunde ny konstruktor
Kunde :: Kunde(int kundenr) : Num_element(kundenr)	{
	char valg;
	char buffer[STRLEN];

	Intrsone* intrsonepointer;
	Intrsone* intrsonepointerkopi;

	kundenummer = kundenr;
	cout << endl << kundenr;

	les("Navn", buffer, STRLEN);			// Leser navn
	strcpy(navn, buffer);

	les("Adresse", buffer, STRLEN);			// Leser adresse
	strcpy(adr, buffer);

	les("Postadresse", buffer, STRLEN);		// Leser postadresse
	strcpy(post_adr, buffer);

	tlf = les("Telefon", 10000000, 99999999);	// Leser telefonnummer
	
	les("Mail", buffer, STRLEN);			// Leser mailadresse
	strcpy(mail, buffer);

	IntrsonerListe = new List(Sorted);		// Lager ny liste
	
	int sonenummer = les("Sonenummer", 1, 100);
	intrsonepointer = new Intrsone(sonenummer);
	IntrsonerListe->add(intrsonepointer);

	cout << "\n Vil du legge til enda en ny sone(kopi)? J eller N";
	valg = meny_valg();

	while (valg == 'J')	{
		intrsonepointerkopi = new Intrsone(*intrsonepointer);		//Copy constructor
		sonenummer = les("Sonenummer", 1, 100);			// Leser inn sonenummer
		intrsonepointerkopi->byttsonenr(sonenummer);
		IntrsonerListe->add(intrsonepointerkopi);
		cout << "\n Vil du legge til enda en ny sone(kopi)? J eller N";
		valg = meny_valg();
	}
}

void Kunde :: sjekkInfo(char* navn_nr)	{
	Intrsone* intrsonen;
	int nummer = atoi(navn_nr);
	int antIntrsoner = IntrsonerListe-> no_of_elements();

	if(strcmp(navn_nr, navn) == 0 || nummer == kundenummer)	{
		kunde_display();
		for(int i = 1; i <= antIntrsoner; i++)	{
			intrsonen = (Intrsone*) IntrsonerListe->remove_no(i);
			intrsonen->display();
			IntrsonerListe->add(intrsonen);
		}
	}
}



// ************************************************************************* //