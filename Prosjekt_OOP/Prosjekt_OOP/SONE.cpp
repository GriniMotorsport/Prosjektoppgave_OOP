#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "SONE.h"
#include "EIENDOM.h"
#include "BOLIG.h"

using namespace std;

// Extern variable
extern char dta[];
extern char e[];

// Funksjoner for Sone
Sone :: Sone(ifstream & inn) {
	int ant;
	char a [MAX_TEGN_TEKST];
	char* nvn;

	Eiendomer = new List(Sorted);
	Eiendom* eiendom;
	inn.getline(a, MAX_TEGN_TEKST);	  
	info = a;
	
	inn >> ant;

	for (int i = 1; i <= ant; i++) {
	  int nr;
	  inn >> nr;
	  nvn = new char[(strlen(e) + strlen(dta) + 7 + 1)];
	  lagNavn(nvn, e, dta, nr, 7);

	  ifstream eiendomHent (nvn);
	  
	  eiendom = new Eiendom(nr, eiendomHent);
	}
	
	cout << "\n\n" << info << '\n' << ant;
	
};
/*
void Sone::display()	{
	int antElementer;
	Eiendom* eiendommen;
	cout << "\nSonenummer:	" << sonenummer;
	cout << "\nBeskrivelse:	" << info;
	antElementer = Eiendomer -> no_of_elements();
	for (int i = 1; i <= antElementer; i++)	{
		eiendommen = (Eiendom*) Eiendomer -> remove_no(i);
		if (eiendommen->tomt()) 
			eiendommen->display();
		else eiendommen->display();
		

		Eiendomer -> add(eiendommen);
	}
}
*/