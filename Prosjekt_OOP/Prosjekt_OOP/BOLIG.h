#if !defined (__BOLIG_h)
#define __BOLIG_h
#include "EIENDOM.h"
#include "ENUMER.h"

class Bolig : public Eiendom {
private:
	int byggeaar;
	int bruttoareal;
	int boareal;
	int antSoverom;
	Onske onsket;
public:
	bool tomt();
	void bDisplay();


};


#endif