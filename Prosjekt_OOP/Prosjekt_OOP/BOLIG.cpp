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
// Bolig-constructor som henter data fra fil
Bolig :: Bolig(int nr, ifstream & inn) : Eiendom(nr, inn) {
   inn >> type;					

   if (type == 'b') {        // Hvis b (boligtype og ikke en bare en tomt)
     inn >> byggeaar;		 // Legger data til variable
	 inn >> bruttoareal;	 // -----------------------------------------
	 inn >> boareal;		 // -----------------------------------------
	 inn >> antSoverom;		 // -----------------------------------------
	 inn >> onsket;			 // ------------------------------------------
	 
	 /*
	 cout << byggeaar << '\n'
		  << bruttoareal << '\n'
		  << boareal << '\n'
		  << antSoverom << '\n'
		  << onsket << '\n';
	*/
   }
}

// Bolig sin display funksjon som skriver ut sine data
void Bolig::Display()	{
	Eiendom::Display();			// Skriver først sine data ut
								// Så skriver den sine data
	cout << "\nByggeaar:	    " << byggeaar;
	cout << "\nBrutto areal:	" << bruttoareal;
	cout << "\nBo areal:	    " << boareal;
	cout << "\nAntall soverom:	" << antSoverom;
	cout << "\nOnske:	        " << onsket;	
}

// ************************************************************************* //