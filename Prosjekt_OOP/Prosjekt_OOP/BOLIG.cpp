				////////// BOLIG.cpp //////////
// Include fra biblotek
#include <iomanip>
#include <fstream>
#include <cstdlib>
// Include .h filer
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "BOLIG.h"

using namespace std;

Bolig :: Bolig(char t, int nr) : Eiendom(t, nr) {
  char ch;
  byggeaar = les("\tBygge-Aar (", TIDL_B_AA, SEN_B_AA);
  bruttoareal = les("\tBrutto-Areal (", BRUTT_AREAL_MIN, BRUTT_AREAL_MAX);
  boareal = les("\tBoareal (", BOAREAL_MIN, BOAREAL_MAX);
  antSoverom = les("\tAntall soverom (",1 ,SOVANT_MAX);

  cout << "\tHva er statusen for dette oppdraget?\n"
	   << "\tTil (S)alg"
	   << "\t(L)eie"
	   << "\t(B)egge deler\n\n\t";  ch = meny_valg();

  while (ch != 'Q'){
    switch (ch) {
	  case 'S': { onsket = 0; } break;
	  case 'L': { onsket = 1; } break;
	  case 'B': { onsket = 2; } break;
	  default: cout << "Ugyldig verdi"; break;
	}  
	break;
  }
}

// Bolig-constructor som henter data fra fil
Bolig :: Bolig(int nr, ifstream & inn) : Eiendom(nr, inn) {
   
     inn >> byggeaar;		 // Legger data til variable
	 inn >> bruttoareal;	 // -----------------------------------------
	 inn >> boareal;		 // -----------------------------------------
	 inn >> antSoverom;		 // -----------------------------------------
	 inn >> onsket;			 // ------------------------------------------
}

// Bolig sin display funksjon som skriver ut sine data
void Bolig::display()	{
  Eiendom::display();			// Skriver først sine data ut
								// Så skriver den sine data
 
  cout << "\n\tByggeaar:	    " << byggeaar
       << "\n\tBrutto areal:	" << bruttoareal
       << "\n\tBo areal:	    " << boareal
       << "\n\tAntall soverom:	" << antSoverom
       << "\n\tOnske:	        ";	

  switch (onsket) {
    case 0: cout << "Salg";		break;		// 0 for Salg
 	case 1: cout << "Leie";		break;		// 1 for Leie
	case 2: cout << "Begge";	break;		// 2 for Begge
  }
  
}

// ************************************************************************* //