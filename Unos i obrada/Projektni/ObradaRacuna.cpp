#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "ObradaRacuna.h"
#define BrojProizvoda 100

/*Napraviti sistem za analizu troškova proizvoljne kompanije. 
Sistem treba da podrži automatsku obradu i analizu troškova na osnovu unesenih podataka. 
Svi podaci se trajno čuvaju u sistemu.
Unos podataka u sistem obavlja se automatski, tako što se računi sačuvaju u folder koji 
aplikacija čita prilikom pokretanja.
Jedan račun se može samo jednom obraditi nakon čega se arhivira u poseban folder.
Računi mogu imati različite sadržaje i formate, a svi mogući formati su dati na 
Moodle stranici projekta. 
Sistemu su važne informacije koje se čuvaju na računu: naziv kupca, datum kupovine,
šifra proizvoda, 
prodana količina, pojedinačna cijena svakog proizvoda, ukupna cijena za plaćanje 
i PDV vrijednost.
Jedan račun se nalazi u jednom tekstualnom fajlu. 
Na jednom računu može biti više proizvoda.
Nakon što se jedan račun učita počinje njegova obrada. 
U ovoj fazi sistem skladišti podatke sa računa 
na odgovarajuća mjesta koja su definisana od strane projektanta sistema
(strukture podataka).  Osim toga, izvršava se validacija svakog računa, 
koja podrazumijeva provjeru izračunatih vrijednosti sa računa 
(npr. da li je iznos*količina=ukupno…). 
Ukoliko se vrijednosti razlikuju sistem prijavljuje grešku i 
detalje upisuje u fajl sa imenom: naziv_racuna_error.txt. 
Obrada računa se u tom slučaju završava.
Ukoliko je račun uspješno obrađen, podaci se skladište u sistem, 
a potrebno je implementirati mehanizam ignorisanja tog računa pri sljedećem pokretanju.

Sistem ima i sljed*/

/*friend std::ostream& operator<<(std::ostream& out, const ObradaRacuna& racun) noexcept
{
	out << racun.kupac << std::endl;
	out << racun.brojProizvoda << std::endl;
	for (int i = 0; i < racun.brojProizvoda; i++)
		out << racun.proizvod << std::endl;
	out << racun. << endl;
	out << korisnik.Pin << endl;
	out << korisnik.korisnickaGrupa << endl;
	return out;
}*/


/* na cplusplus sajtu procitati o operator>> string */

std::ostream& operator<<(std::ostream& out, const ObradaRacuna& sistem) noexcept
{
	out << sistem.kupac << std::endl;
	out << sistem.dan << std::endl;
	out << sistem.mjesec << std::endl;
	out << sistem.godina << std::endl;
	out << sistem.inicBrojProizvoda << std::endl;
	for (int i = 0; i < sistem.inicBrojProizvoda; i++)
	{
		out << sistem.proizvod[i] << std::endl;
		out << sistem.kolicina[i] << std::endl;
		out << sistem.cijena[i] << std::endl;
	}
	out << sistem.ukupno;
	out << sistem.PDV;
	out << sistem.ukupnoZaPlacanje;
	return out;
}

std::istream& operator>>(std::istream& in, ObradaRacuna& sistem) noexcept
{
	in >> sistem.kupac;
	in >> sistem.dan;
	in >> sistem.mjesec;
	in >> sistem.godina;
	in >> sistem.inicBrojProizvoda;
	for (int i = 0; i < sistem.inicBrojProizvoda; i++)
	{
		in >> sistem.proizvod[i];
		in >> sistem.kolicina[i];
		in >> sistem.cijena[i];
	}
	in >> sistem.ukupno;
	in >> sistem.PDV;
	in >> sistem.ukupnoZaPlacanje;
	return in;
}

void ObradaRacuna::obradaRacuna(std::string filename, int i) noexcept(false)
{
	

int x = filename.length();

	if (filename[x-1] != 't' && filename[x - 2] != 'x' && filename[x - 3] != 't' && filename[x - 4] != '\.')
		throw poruka2;
	

	if (i < 0 || i > 3)
		throw poruka;
	

	else if (i == 1)
	{
	ObradaRacuna sistem;
	std::ifstream dat;
	sistem.inicBrojProizvoda = BrojProizvoda;
	sistem.proizvod = new std::string[inicBrojProizvoda];
	sistem.kolicina = new double[inicBrojProizvoda];
	sistem.cijena = new double[inicBrojProizvoda];

	dat.open(filename, std::ios::out);

/*Kupac: ABC
Datum: 24/10/2017

	       Racun

Proizvod - kolicina - cijena - ukupno
abc 123  -    10    -    5   -   50
abb 456  -    20    -   10   -   200
---------------------------------------
Ukupno: 250
PDV: 42.5
Ukupno za placanje: 292.5 */

	

	}
}

ObradaRacuna::~ObradaRacuna()
{
}
