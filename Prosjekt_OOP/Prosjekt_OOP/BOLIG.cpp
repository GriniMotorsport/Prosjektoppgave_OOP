#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "GLOBALE.h"
#include "GLOBALE_CONST.h"
#include "GLOBALE_VARIABLE.h"
#include "BOLIG.h"

using namespace std;

void Bolig::bDisplay()	{
	cout << "\nByggeaar:	" << byggeaar;
	cout << "\nBrutto areal:	" << bruttoareal;
	cout << "\nBo areal:	" << boareal;
	cout << "\nAntall soverom:	" << antSoverom;
	cout << "\nOnske:	" << onsket;
	


}
