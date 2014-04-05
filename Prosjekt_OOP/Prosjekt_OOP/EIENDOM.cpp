

void eiendom() { 
  char kommando;
  skriv_meny_eiendom();
  kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "ED"; break; 
		case 'N' : cout << "EN"; break; 
		case 'S' : cout << "ES"; break; 
		case 'E' : cout << "EE"; break; 
		default:   cout << "DEFAULT-E"; break;
		}
	  break;
	}