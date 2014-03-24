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
#include <stdio.h>
using namespace std;

//Deklarasjon
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN);

// GLOBALEVARIABLE
char dta[]   = ".DTA";
char inf[]   = ".INF";
char sone[]  = "SONE";



int main() {
	
	char* nvn, * p1, * p2;
	int tall = 5, MAX_LEN = 3;
	p1 = sone; 
  p2 = dta;

  nvn = new char[(strlen(p1) + strlen(p2) + MAX_LEN + 1)];
  lagNavn(nvn, p1, p2, tall, MAX_LEN); 
	ofstream ut (nvn);


return 0;
}

// Kode for lagNavn
void lagNavn(char* t, char* s1, char* s2, int n, const int LEN) {
	int ant = 0;
  char num[10];

  itoa(n, num, 10);
  strcpy(t, s1);
  for .....  strcat(t, "0");
  strcat(t, num);
  strcat(t, s2);
  
  while ( *s1 != '\0') {
    *t++ = *s1++;
  }
  for (int i = 1; ; <#increment#>) {
    <#statements#>
}
  
  *t++ = '0';
}


