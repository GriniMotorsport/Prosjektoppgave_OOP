int main()	{

char kommando;

skriv_meny();
kommando = menyValg();

  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'E': eiendom();		break;    
      case 'K': sonenr_display();		break;    
      case 'S': kunde();   		break;    
      case 'U': utskrift();			break;   
      default:  skriv_meny();		break;
    }
	kommando = menyValg();
  





skriv_meny();
kommando = menyValg();

  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'D': eiendom_display();		break;    
      case 'N': eiendom_ny();		break;    
      case 'S': eiendom_slett();   		break;    
      case 'E': eiendom_endre();
      default:  skriv_meny();		break;
    }
	kommando = menyValg();





skriv_meny();
kommando = menyValg();

  while (kommando != 'Q')  {
    switch(kommando)  {
      case 'D': kunde_display();		break;    
      case 'N': kunde_ny();		break;    
      case 'S': kunde_slett();   		break;    
      case 'E': kunde_endre();
      default:  skriv_meny();		break;
    }
	kommando = menyValg();