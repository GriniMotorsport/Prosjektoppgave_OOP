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
#include "GLOBALE_VARIABLE.h"

using namespace std;

// Constructor Soner
Soner :: Soner() {}

// Soner_Hent_Sone - Henter data om sone og legger på riktig plass i Array
void Soner :: hent_sone(int nr, ifstream & inn) {
  sonene[nr] = new Sone(inn);
}

// Soner_Vis_Sone - Viser en angitt sone som bruker har skrevet inn
void Soner :: vis_sone(int nr) {
  sonene[nr] -> display(nr);
}

// Soner_Hent_Eiendom - Henter eiendom for soner
void Soner :: hent_eiendom(int nr) {
  for (int i = 1; i <= MAX_ANT_SON; i++) {
	sonene[i] -> hent_eiendom(nr);	
  }
}

// Ny eiendom
void Soner :: Eiendom_Ny(int sonenr)	{
	sisteE++;
	if (sonene[sonenr])	{
		sonene[sonenr]->eiendom_ny(sisteE);
	}
}

void Soner :: Eiendom_Slett(int sonenr)	{
	bool 
	int i = 1;

}

// ************************************************************************* //