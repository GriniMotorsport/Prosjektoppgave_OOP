#if !defined(__EIENDOM_h)
#define  __EIENDOM_h

class Kunder {
private:
	
	int forstN_K;					//forste haavverende kunde
	int sisti_K;					//sist innlagte kunde
	List Kunde;						//datastrukture med alle kunde

public:

}


class Intersone{
private:
	int max_pris;
	int min_areal;
	int minA_rom;
	int tilsen_over;
	int interessert;
	int eien_t;
public:

}	;

class Soner{
private:
	int sist_eindom; //sist innlagte eiendom
	char sone[];//namber av brukers

public:

}
class sone{
private:
char* info; //beskrivelse av sonen
List Eiendomer; //Eiendom til salg leie i sonen
public:

}

class Eiendom{
private:
	int datoInn;  //dato innlagt i systemet
	int bruk_num; //number av brukers
	int pris; //pris
	int areal;  // tomtens areal i kvardratmeter
	char* adr_num; //gata adresse
	char* post_adr; // post adress
	char* nam;//næværende eier navn
	int eiendomstype; //eiendomstype
public:

}

class Bolig public :: Eiendom {
private:
	int byg_aar; // byggeår
	int bruttoareal; //bruttoareal
	int boareal;//boareal
	int ant_sovrom;//antal soverom
	int interesert;//
public:

}

class Bolig {
private:
public:
}



void eiendom_display();
void eiendom_ny();
void eiendom_slett();
void eiendom_endre();


#endif