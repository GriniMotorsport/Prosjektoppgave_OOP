				////////// SONER.cpp //////////
// Include fra biblotek
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "SONER.h"
#include "SONE.h"

using namespace std;

// Externe char variable
extern char dta[];
extern char SONE[]; 
extern char k[];			
extern int sisteE;			// Siste registrerte eiendom
extern int fNaaK;			// Forste Nåvarende kunde
extern int sInnlK;			// Siste innlagte kunde

// Constructor Soner
Soner :: Soner() {}

// Soner_Hent_Sone - Henter data om sone og legger på riktig plass i Array
void Soner :: hent_sone(int nr, ifstream & inn) {
  soner[nr] = new Sone(inn);
}

// Soner_Ny_Oppdrag - oppretter nytt oppdrag i eksisterende sone
void Soner :: ny_oppdrag(int nr, bool f) {
  char* nvn;
  if (!f) { 
    soner[nr] = new Sone(); 
    soner[nr] -> ny_oppdrag(nr, f);
    nvn = new char[(strlen(SONE) + strlen(dta) + 3 + 1)];
	lagNavn(nvn, SONE, dta, nr, 3);
	ofstream soneSkriv (nvn);
	soner[nr] -> skriv_til_fil(soneSkriv);
  }
 
  else { soner[nr] -> ny_oppdrag(nr, f); }	

  opp_SISTE();  nrSE = sisteE;
  nvn = new char[(strlen(k) + strlen(dta) + 7 + 1)];
  
  
  
  
}

// Soner_Vis_Sone - Viser en angitt sone som bruker har skrevet inn
void Soner :: vis_sone(int nr) {
  soner[nr] -> display(nr);
}

// Soner_Hent_Eiendom - Henter eiendom for soner
void Soner :: hent_eiendom(int nr, int eiendomNr) {
  soner[nr] -> vis_eiendom(eiendomNr);
}

// Soner_Hent_Eiendommer - Viser eiendommer på et spessielt postnr
void Soner :: hent_eiendommer(int nr, int postNr) {
  soner[nr] -> vis_eiendommer(postNr);	
}


// ************************************************************************* //