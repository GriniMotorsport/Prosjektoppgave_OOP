#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"
#include "SONE.h"
#include "EIENDOM.h"
#include "BOLIG.h"

using namespace std;

void Sone::display()	{
	int antElementer;
	Eiendom* eiendommen;
	cout << "\nSonenummer:	" << sonenummer;
	cout << "\nBeskrivelse:	" << info;
	antElementer = eiendomsliste->no_of_elements();
	for (int i = 1; i <= antElementer; i++)	{
		eiendommen = (Eiendom*) eiendomsliste-> remove_no(i);
		if (eiendommen->tomt()) 
			eiendommen->display();
		else eiendommen->bDisplay();
		
		eiendomsliste->add(eiendommen);
	}











}