#if !defined(__KUNDE_h)
#define  __KUNDE_h

class Kunde  {
  private:
	int tlf; //telephone numere
	char* navn; //navn av kunde
	char* adr; // gata adress
	char* post_adr; //post adress
	char* mail; //mail
	//List* Intrsoner; //Intrsone

public:
  void kunde_display();
  void kunde_ny();
  void kunde_slett();
  void kunde_endre();
};




#endif