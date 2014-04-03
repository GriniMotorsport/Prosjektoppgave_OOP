//
//  main.cpp
//  testing_kode_gudbrand
//
//  Created by Gudbrand Grini on 24.03.14.
//  Copyright (c) 2014 Gudbrand Grini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// Variable deklarasjon
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN);

// GLOBALEVARIABLE
char dta[]   = ".DTA";			// _____________________________________
char inf[]   = ".INF";			// 
char sone[]  = "SONE";			// Globale tekster til bruk for fil-navn.
char k[]     = "K";				//
char e[]     = "E";				// _____________________________________

// Hovedprogram
int main() {
	
  char* nvn;		// Danner pekere	

/* Lager en charArray med en lengde lik filnavnet.
	<(del 1) + (del 2) + (del 3) + (del 4)>
		
		(del 1): Henter lengden på første del som filnavnet skal inneholdet.
		(del 2): Henter lengden til filtype navnet.
		(del 3): Dette er tallet med antall tall filnavnet max kan inneholde.
		(del 4): Pluss 1 er for og legge til \o på slutten av navnet.
*/
  nvn = new char[(strlen(sone) + strlen(dta) + 3 + 1)];	
 
  lagNavn(nvn, k, dta, 1012, 7);	 // Kaller på funksjonen med tilsente parametre
  ofstream ut (nvn);			 // Opretter en fil med nvn som filvan. 


return 0;
}

// Kode for lagNavn
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN) {  
  char num[10];					// Hjelpe charArray.
  itoa(n, num, 10);				// Gjør n om til char og legger i num.
  int ant = LEN - strlen(num);	/* Får tak i antall ganger char "0" skal
								   legges til i filnavn før n. */
  strcpy(t, s1);				    // Legger s1 til filnavn.
  for (int i = 1; i <= ant; i++) {  // Skriver 0 til filnavn hvis plass.
	  strcat(t, "0"); }				// ________________________________
  strcat(t, num);				    // Legger num til filnavn.
  strcat(t, s2);					// Legger filtype til filnavn.
}


