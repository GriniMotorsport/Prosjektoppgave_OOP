#include <iostream>
#include <cstring>

using namespace std;

#include "GLOBALE.h"
//#include "KUNDE.h"
//#include "EIENDOM.h"

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
      case 'D': 		break;    
      case 'N': 		break;    
      case 'S': 		break;    
      case 'E': 		break;
      default:  	    break;
    }
	kommando = meny_valg();
  }
		break;   

      case 'K': 	break;
	  case 'S': ;			
		  		  skriv_meny3();
kommando = meny_valg();
  
  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'D':		break;    
      case 'N': 		break;    
      case 'S':    		break;    
      case 'E': 
      default:  		break;
    }
	kommando = meny_valg();
  }	  
		  break; 
      case 'U': 			break;   
      default:  skriv_meny1();		break;
    
	kommando = meny_valg();
	}

  }

}