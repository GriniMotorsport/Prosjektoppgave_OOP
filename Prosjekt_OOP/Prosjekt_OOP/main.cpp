#include <iostream>
#include <cstring>

using namespace std;

#include "GLOBALE.h"
#include "KUNDE.h"
#include "EIENDOM.h"

int main()	{
	
char kommando;

skriv_meny1();
kommando = meny_valg();

  while (kommando != 'Q')  {
    switch(kommando)  {
	  case 'E' : eiendom();      break;    
      case 'K' : kunde();        break;
	  case 'S' : sone ();        break; 
	  case 'U' : status();       break;   
      default:  skriv_meny1();   break;
    
	kommando = meny_valg();
	}
  }
  return 0;
}