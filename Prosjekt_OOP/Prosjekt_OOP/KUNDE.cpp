
void kunde() { 
  char kommando;
  skriv_meny_kunde();
  kommando = meny_valg();

	while (kommando != 'Q') {
		switch (kommando){
		case 'D' : cout << "KD"; break; 
		case 'N' : cout << "KN"; break; 
		case 'S' : cout << "KS"; break; 
		case 'E' : cout << "KE"; break; 
		default:   cout << "DEFAULT-K"; break;
		}
	  break;
	}
}