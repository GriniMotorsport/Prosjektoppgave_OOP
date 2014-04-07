#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "EIENDOM.h"


using namespace std;

Eiendom :: Eiendom(int nr, ifstream & inn) : Num_element(nr) {
	char txt[MAX_TEGN_TEKST2];
	inn >> dato;
	inn >> bruksNr;
	inn >> saksB;
	inn >> pris;
	inn >> areal;					    inn.ignore();
	inn.getline(txt, MAX_TEGN_TEKST2);  gateadresse = txt;
	inn.getline(txt, MAX_TEGN_TEKST2);  postAdresse = txt;
	/*inn.getline(txt, MAX_TEGN_TEKST2);  eiersN = txt;
	inn.getline(txt, MAX_TEGN_TEKST2);  kommune = txt;
	inn.getline(txt, MAX_TEGN_TEKST2);  info = txt;*/

	cout << "\nDato for opprettelse av tomten/eiendom:	" << dato;
	cout << "\nBruks-nummer:	" << bruksNr;
	cout << "\nSaksbehandlers nr:	" << saksB;
	cout << "\nPris for tomten/eiendomen:	" << pris;
	cout << "\nAreal på tomten/eiendomen:	" << areal;
	cout << "\nGateadresse:	" << gateadresse;
	cout << "\nPostadresse:	" << postAdresse;
	/*cout << "\nEiers navn:	" << eiersN;
	cout << "\nKommune navn:	" << kommune;
	cout << "\nBeskrivelse:	"	<< info << endl;*/
	
};


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


