#include <iostream>
#include <cstring>
#include "GLOBALE.h"

//#include "GLOBALE_VARIABLE.h"
using namespace std;

// Globale variable


int main()	{
	
  char kommando;
  skriv_fra_fil();

  skriv_meny();
  kommando = meny_valg();

  while (kommando != 'Q')  {
    switch(kommando)  {
	  case 'E' : eiendom();      break;    
      case 'K' : kunde();        break;
	  case 'S' : sone();        break; 
	  case 'U' : status();       break;   
      default:				     break;
	}
   skriv_meny();
   kommando = meny_valg();
  }
  return 0;
}
// ******************************** E N D *********************************** //