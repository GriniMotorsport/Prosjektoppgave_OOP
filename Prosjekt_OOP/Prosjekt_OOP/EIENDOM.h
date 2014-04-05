#if !defined(__EIENDOM_h)
#define  __EIENDOM_h
#include "ENUMER.h"
#include "LISTTOOL2.h"

class Eiendom : public Num_element {
  private:
    int dato;				// Dato for opprettelse av tomten/eiendom
	int bruksNr;			// Bruks-nummer (4-sifret)
	int saksB;				// Saksbehandlers nr
	int pris;				// Pris for tomten/eiendomen
	int areal;				// Areal på tomten/eiendomen
	char* gateadresse;		// Gateadresse (gate + nr)
	char* postAdresse;		// Postadresse (nr + sted)
	char* eiersN;			// Eiers navn
	char* kommune;			// Kommune navn
	char* info;				// Beskrivelse av eiendomen
	Eiendomstype type;		// Enum
	Boliginfo info;			// Enum

  public:
	  bool tomt();
	  void display();

};

#endif