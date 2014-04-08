#if !defined(__ENUMER_h)	// Start på fil
#define  __ENUMER_h
					// Enum for de forskjellige typene for eiendomer
enum Eiendomstype { Tomt, Enebolig, Rekkehus, Leilighet, Hytte };
					// Enum for hva slags marked som eiendomen ligger under
enum Onske { Salg, Leie, Begge };
					// Enum for når kunde hvil få tildelt svar på IntrSoner
enum Boliginfo { Ukentlig, Snarest };

#endif	// Slutt på fil