#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"
#include "EIENDOM.h"


using namespace std;

void Eiendom::display()	{
	cout << "\nDato for opprettelse av tomten/eiendom:	" << dato;
	cout << "\nBruks-nummer:	" << bruksNr;
	cout << "\nSaksbehandlers nr:	" << saksB;
	cout << "\nPris for tomten/eiendomen:	" << pris;
	cout << "\nAreal på tomten/eiendomen:	" << areal;
	cout << "\nGateadresse:	" << gateadresse;
	cout << "\nPostadresse:	" << postAdresse;
	cout << "\nEiers navn:	" << eiersN;
	cout << "\nKommune navn:	" << kommune;
	cout << "\nBeskrivelse:	"	<< info << endl;


}





	int areal;				// Areal på tomten/eiendomen
	char* gateadresse;		// Gateadresse (gate + nr)
	char* postAdresse;		// Postadresse (nr + sted)
	char* eiersN;			// Eiers navn
	char* kommune;			// Kommune navn
	char* info;				// Beskrivelse av eiendomen
	Eiendomstype type;		// Enum
	Boliginfo info;			// Enum