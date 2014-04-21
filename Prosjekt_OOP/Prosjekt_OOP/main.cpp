				////////// MAIN.cpp //////////
// Include fra biblotek
#include <iostream>
#include <cstring>
// Include .h filer
#include "GLOBALE.h"
#include "SONER.h"
#include "KUNDER.h"

using namespace std;

// Globale objekter
Soner* soner;
Kunder* kunder;


int sisteE;			// Siste registrerte eiendom
int fNaaK;			// Forste N�varende kunde
int sInnlK;			// Siste innlagte kunde


// Int Main - Hovedprogram
int main() {
	
  soner = new Soner;		// Lager nytt objekt soner
  kunder = new Kunder;		// Lager nytt objekt kunder

  char kommando;
  hent_fra_fil();			// Hent fra fil - funksjonen

  skriv_meny();				// Skriver meny / kommandoforslag
  kommando = meny_valg();	// Henter kommando fra bruker

  while (kommando != 'Q') {		// Kj�rer s� lenge ikke Q
    switch(kommando)  {
	  case 'E' : eiendom();   break;    // Eiendom
      case 'K' : kunde();     break;	// Kunde
	  case 'S' : sone();      break;	// Sone
	  case 'U' : status();    break;	// Utskrift
      default:	              break;	// Default
	}
   skriv_meny();			// Skriver meny / kommandoforslag
   kommando = meny_valg();	// Henter kommando fra bruker
  }
 return 0;
}
// ******************************** E N D *********************************** //