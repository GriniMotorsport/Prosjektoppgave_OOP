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
extern int sisteE;			// Siste registrerte eiendom

// Sone constructor
Sone :: Sone() {

    info = new char[MAX_TEGN_TEKST+1];
    Eiendomer = new List(Sorted);
	cin.ignore();
    les("\n\tSone beskrivelse: ", info, MAX_TEGN_TEKST); 
 
}

// Constructor Sone - Henter data fra fil 
Sone :: Sone(ifstream & inn) {
  int ant;
  char* nvn;
  info = new char [MAX_TEGN_TEKST+1];

  Eiendomer = new List(Sorted);			// Oppretter ny Eiendomer List
  Bolig* bolig;							// Hjelpe object
  Eiendom* eiendom;
  inn.getline(info, MAX_TEGN_TEKST);	  
	
  inn >> ant;		// Henter ant

  for (int i = 1; i <= ant; i++) {		// Går fra 1 -> ant ganger
    int nr;
	char type;
    inn >> nr;							// Setter av plass til filnavn
    nvn = new char[(strlen(e) + strlen(dta) + 7 + 1)];
    lagNavn(nvn, e, dta, nr, 7);		// Setter sammen filnavn
	 
	ifstream eiendomHent (nvn);			// Setter fstream til filnavn
	  
	eiendomHent >> type;
	cout << type;

	while (!eiendomHent.eof()) {			    // Kjør så lenge det er data på fil
	  if (type == 'b') {
	    bolig = new Bolig(nr, eiendomHent); 	// Danner et nytt Bolig object
	    Eiendomer -> add(bolig);
	  }
	  else {
	    eiendom = new Eiendom(nr, eiendomHent); 
		Eiendomer -> add(eiendom);		
	  }
      eiendomHent >> type;
	  inn >> nr;
	} 
  }
};

// 
void Sone :: skriv_til_fil(ofstream & ut) {
  ut << info  << '\n'
	 << '1'   << '\n'
	 << sisteE;
}

//
void Sone :: ny_oppdrag(int nr, bool f) {
  char type;
  Eiendom* eiendom;
  Bolig* bolig;
    
  cout << "\n\tHva slags type er det?\n"
	   << "\t(T)omt\n"
	   << "\t(E)nebolig\n"
	   << "\t(R)ekkehus\n"
	   << "\t(L)eilighet\n"
	   << "\t(H)ytte\n\n\t";
  
  type = meny_valg();
  
  while (type != 'Q') {
    switch (type) {
	  case 'T': { 
	    cout << "\n\t---- Ny Eiendom ----";
	    eiendom = new Eiendom('t', ++sisteE);
		//eiendom -> 
		Eiendomer -> add(eiendom); } break; 

	  case 'E': case 'R': case 'L': case 'H': {
	    cout << "\n\t---- Ny Bolig ----";
	    bolig = new Bolig('b', ++sisteE);
		Eiendomer -> add(bolig);
	  } break;
	    
	  default:  break;
    }
	break;
  }
}

// Sone_Display - Skriver ut en git sone
void Sone :: display(int nr) {
	
  cout << "\n\tSonenummer - " << nr << " -"
       << "\nBeskrivelse for sonen: " << info;  // Loop'er ant ganger = ant 
  Eiendomer -> display_list();
}

// Sone_Hent_Eiendom - Skriv eiendom
void Sone :: vis_eiendom(int nr) {
  if (Eiendomer -> in_list(nr)) {
    cout << "\n\t\t\tEiendom - " << nr << " -";
    Eiendomer -> display_element(nr);
  }					
}

// Sone_Hent_Eiendommer - Skriver eiendommer
void Sone :: vis_eiendommer(int postNr) {
  Eiendom* eiendommer;
  int ant = Eiendomer -> no_of_elements();

  for (int i = 1; i <= ant; i++) {
    eiendommer = (Eiendom*) Eiendomer -> remove_no(i);

	if (eiendommer -> harPost(postNr)) { eiendommer -> display(); }
	
	Eiendomer -> add(eiendommer);
  }
}


// ************************************************************************* //