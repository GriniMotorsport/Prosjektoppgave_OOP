#if !defined(__ENUMER_h)	// Start p� fil
#define  __ENUMER_h
					// Enum for de forskjellige typene for eiendomer
enum Eiendomstype { Tomt, Enebolig, Rekkehus, Leilighet, Hytte };
					// Enum for hva slags marked som eiendomen ligger under
enum Onske { Salg, Leie, Begge };
					// Enum for n�r kunde hvil f� tildelt svar p� IntrSoner
enum Boliginfo { Ukentlig, Snarest };

#endif	// Slutt p� fil