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
	case 'E' : ;
		  skriv_meny2();
kommando = meny_valg();
	
  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'D': eiendom_display();		break;    
      case 'N': eiendom_ny();			break;    
      case 'S': eiendom_slett();   		break;    
      case 'E': eiendom_endre();		break;
      default:  skriv_meny2();			break;
    }
	kommando = meny_valg();
  }
		break;   

      case 'K': sonenr_display();	break;
	  case 'S': ;			
		  		  skriv_meny3();
kommando = meny_valg();
  
  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'D': kunde_display();		break;    
      case 'N': kunde_ny();		break;    
      case 'S': kunde_slett();   		break;    
      case 'E': kunde_endre();
      default:  skriv_meny3();		break;
    }
	kommando = meny_valg();
  }	  
		  break; 
      case 'U': utskrift();			break;   
      default:  skriv_meny1();		break;
    
	kommando = meny_valg();
	}

  }

}