#include <System.hpp>

// Metoda za provjeru oib-a
// Kontrolna znamenka prema me�unarodnoj normi ISO 7064 (MOD 11, 10). dobiva se slijede�im postupkom :
// 1. prva znamenka zbroji se s brojem 10
// 2. dobiveni zbroj cjelobrojno (s ostatkom) podijeli se brojem 10;
// ako je dobiveni ostatak 0 zamijeni se brojem 10 (ovaj broj je tzv. me�uostatak)
// 3. dobiveni me�uostatak pomno�i se brojem 2
// 4. dobiveni umno�ak cjelobrojno (s ostatkom) podijeli se brojem 11;
// ovaj ostatak matemati�ki nikako ne mo�e biti 0 jer je rezultat
// prethodnog koraka uvijek paran broj
// 5. slijede�a znamenka zbroji se s ostatkom u prethodnom koraku
// 6. ponavljaju se koraci 2, 3, 4 i 5 dok se ne potro�e sve znamenke
// 7. razlika izme�u broja 11 i ostatka u zadnjem koraku je kontrolna znamenka; ako je
// ostatak 1 kontrolna znamenka je 0 (11-1=10, a 10 ima dvije znamenke)

bool duzinaOIB(const AnsiString& oibStr) {
	if (oibStr.Length() != 11) {
		return false; // duzina nije ispravna
	} else {
		return true; // duzina je ispravna
	}
}

bool provjeriOIB(const int oib[]) {
    int meduostatak = 10;
    for (int i = 0; i < 10; ++i) {
        int znamenka = oib[i];
        meduostatak += znamenka;
        meduostatak %= 10;
        if (meduostatak == 0)
            meduostatak = 10;
        meduostatak *= 2;
        meduostatak %= 11;
    }
    int izracunataKontrolnaZnamenka = 11 - meduostatak;
    if (izracunataKontrolnaZnamenka == 10)
        izracunataKontrolnaZnamenka = 0;
    return oib[10] == izracunataKontrolnaZnamenka;
}
