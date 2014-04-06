#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "SONER.h"

using namespace std;

Soner :: Soner() {}

void Soner :: hent_sone(int nr, ifstream & inn) {
	
	soner[nr] = new Sone(inn);
	
}

void Sone :: vise_sone(){
	int nr;
	nr = funksjon som return int;
	cout << "Skriv";  cin >> nr;
	
	sone[nr].display;
 






}