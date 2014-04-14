				////////// SONE.cpp //////////
// Include fra biblotek
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "SONE.h"
#include "EIENDOM.h"
#include "BOLIG.h"


using namespace std;

// Extern variable
extern char dta[];
extern char e[];

// Constructor Sone - Henter data fra fil 
Sone :: Sone(ifstream & inn) {
  int ant;
  char* nvn;
  info = new char [MAX_TEGN_TEKST+1];

  Eiendomer = new List(Sorted);			// Oppretter ny Eiendomer List
  Bolig* bolig;							// Hjelpe object
  inn.getline(info, MAX_TEGN_TEKST);	  
	
  inn >> ant;		// Henter ant

  for (int i = 1; i <= ant; i++) {		// Går fra 1 -> ant ganger
    int nr;
    inn >> nr;							// Setter av plass til filnavn
    nvn = new char[(strlen(e) + strlen(dta) + 7 + 1)];
    lagNavn(nvn, e, dta, nr, 7);		// Setter sammen filnavn
	 
	ifstream eiendomHent (nvn);			// Setter fstream til filnavn
	  
    while (!eiendomHent.eof()) {			// Kjør så lenge det er data på fil
	  bolig = new Bolig(nr, eiendomHent);	// Danner et nytt Bolig object
	  Eiendomer -> add(bolig);				// Legger objecte til Eiendomer L
      inn >> nr;					
	} 
  }
};

// Sone_Display - Skriver ut en git sone
void Sone::display(int nr)	{
  Bolig* bolig;		// Hjelpe object
	
  cout << "\n\tSonenummer - " << nr << " -"
       << "\nBeskrivelse for sonen: " << info;  // Loop'er ant ganger = ant 
  for (int i = 1; i <= (Eiendomer -> no_of_elements()); i++) { // element list
    bolig = (Bolig*) Eiendomer -> remove_no(i);		// Fjerner element fra list
    bolig -> Display();				// Skriver ut elemente og sine data
    Eiendomer -> add(bolig);		// Legger elementet tilbake til List
  }
}

// Sone_Hent_Eiendom - Skriver eiendommer
void Sone :: hent_eiendom(int nr) {
  Eiendom* eiendom;		// Hjelpe object
						// Loop'er = ant element i list
  for (int i = 1; i <= (Eiendomer -> no_of_elements()); i++) {
    eiendom = (Eiendom*) Eiendomer -> remove_no(i); 
							// Fjernen et element
	if (eiendom -> finnes_nr(nr)) { // Hvis nr er likt
	  eiendom -> display();			// Skriv ut eiendommen
	}								
	Eiendomer -> add(eiendom);		// Legger den tilbake uansett
  }
}

// Lager ny eiendom inne i sonen
void Sone :: eiendom_ny(int onr)	{
	Eiendom* eiendommen;
	char valg;

	cout << "\n\n[B]olig eller [E]iendom?"; valg = meny_valg();
	if (valg == 'E')
		eiendommen = new Eiendom(onr);
	else if ( valg == 'B')
		eiendommen = new Bolig(onr);

	Eiendomer->add(eiendommen);
	

}




// ************************************************************************* //