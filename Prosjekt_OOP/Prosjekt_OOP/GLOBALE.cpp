#include <iostream>
#include <iomanip>
#include "GLOBALE.h"


using namespace std;

char meny_valg() {
	char ch;
	cout << "Komando: ";  cin  >> ch;  cin.ignore();  return toupper(ch);
}

void skriv_meny1()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n Hva vil du gjøre?\n"
          "\tE - Eiendom\n"
          "\tS - Skriv ut data om alle eiendommene/oppdragene i en sone.\n"
		  "\tK - Kunde\n"
		  "\tU - Utskrift\n"
		  "\tQ - Quit / avslutt\n";
}

void eiendom() {
  char kommando;
	skriv_meny2();

	kommando = meny_valg();

	while (kommando != 'Q') {
		switch (switch_on)
		{
		default:
			break;
		}
	}
	{

	}
}


void skriv_meny2()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\n\t----------- Eiendom -----------\n"
		  "\tD - Display eiendom\n"
	      "\tN - Opprett en ny eiendom/bolig\n"
		  "\tS - Slett en eiendom\n"
		  "\tE - Endre en eiendom\n"
		  "\tQ - Quit / avslutt\n";
}


void skriv_meny3()  {         //  Skriver meny/lovlige kommandoer til bruker:
  cout << "\n\n\nHva vil du gjøre?\n";
  cout << "\tD - Display en kunde\n";
  cout << "\tN - Opprett en ny kunde\n";
  cout << "\tS - Slett en kunde\n";
  cout << "\tE - Endre en kunde\n";
  cout << "\tQ - Quit / avslutt\n";
}