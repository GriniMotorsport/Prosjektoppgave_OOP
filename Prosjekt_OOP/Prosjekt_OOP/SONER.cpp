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

// Constructor Soner
Soner :: Soner() {}

// Soner_Hent_Sone - Henter data om sone og legger på riktig plass i Array
void Soner :: hent_sone(int nr, ifstream & inn) {
  soner[nr] = new Sone(inn);
}

// Soner_Vis_Sone - Viser en angitt sone som bruker har skrevet inn
void Soner :: vis_sone(int nr) {
  soner[nr] -> display(nr);
}

// Soner_Hent_Eiendom - Henter eiendom for soner
void Soner :: hent_eiendom(int nr) {
  for (int i = 1; i <= MAX_ANT_SON; i++) {
	soner[i] -> hent_eiendom(nr);	
  }
}
// ************************************************************************* //