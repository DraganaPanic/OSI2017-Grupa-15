#include "stdafx.h"
#include "Unos.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>



Unos::Unos()
{
}



std::ostream& operator<<(std::ostream& out, const Unos& racun) noexcept
{
	out << racun.kupac << std::endl;
	out << racun.dan << std::endl;
	out << racun.mjesec << std::endl;
	out << racun.godina << std::endl;
	out << racun.brojProizvoda << std::endl;
	for (int i = 0; i < racun.brojProizvoda; i++)
	{
		out << racun.proizvod[i] << std::endl;
		out << racun.kolicina[i] << std::endl;
		out << racun.cijena[i] << std::endl;
	}
	out << racun.ukupno;
	out << racun.PDV;
	return out;
}

std::istream& operator>>(std::istream& in, Unos& racun) noexcept
{
	in >> racun.kupac;
	in >> racun.dan;
	in >> racun.mjesec;
	in >> racun.godina;
	in >> racun.brojProizvoda;
	for (int i = 0; i < racun.brojProizvoda; i++)
	{
		in >> racun.proizvod[i];
		in >> racun.kolicina[i];
		in >> racun.cijena[i];
	}
	return in;
} /* na cplusplus sajtu procitati o operator>> string */


void Unos::unos(std::string filename) noexcept(false)
{
	int i;

	int x = filename.length();

	if (filename[x - 1] != 't' && filename[x - 2] != 'x' && filename[x - 3] != 't' && filename[x - 4] != '\.')
	{
		throw poruka2;
	}
	std::cout << "Odaberite format: [1] [2] [3] ";
	std::cin >> i;
	if (i < 0 || i > 3)
		throw poruka;

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

	else if (i == 1)
	{
		Unos racun;
		std::cout << "Kupac: "; std::cin >> racun.kupac;
		std::cout << "Datum: "; std::cin >> racun.dan >> racun.mjesec >> racun.godina;
		std::cout << "Broj proizvoda: "; std::cin >> racun.brojProizvoda;

		racun.proizvod = new std::string[racun.brojProizvoda];
		racun.kolicina = new double[racun.brojProizvoda];
		racun.cijena = new double[racun.brojProizvoda];
		for (int i = 1; i <= racun.brojProizvoda; i++)
		{
			std::cout << "Unesite " << i << " proizvod: ";
			std::cin >> racun.proizvod[i];
			std::cout << "Unesite kolicinu " << i << ". proizvoda:";
			std::cin >> racun.kolicina[i];
			std::cout << "Unesite cijenu " << i << ". proizvoda: ";
			std::cin >> racun.cijena[i];
			racun.ukupno += racun.kolicina[i] * racun.cijena[i];
		}
		racun.PDV = (racun.ukupno - (racun.ukupno / 1.17));
		std::cout << "RACUN PDV :" << racun.PDV << std::endl;

		std::ofstream dat;
		dat.open(filename, std::ios::app);

		dat << "Kupac: " << racun.kupac;
		dat << "\n";
		dat << "Datum:" << racun.dan << "/" << racun.mjesec << "/" << racun.godina;
		dat << "\n";
		dat << "	       Racun" << "	       ";
		dat << "\n";
		dat << "Proizvod - kolicina - cijena - ukupno";
		dat << "\n";
		for (int i = 1; i <= racun.brojProizvoda; i++)
		{
			std::cout << racun.proizvod[i] << std::endl;
			dat << racun.proizvod[i] << "  -    " << racun.kolicina[i] << "  -    " << racun.cijena[i] << "  -    " << racun.kolicina[i] * racun.cijena[i];;
			dat << "\n";
		}
		dat << "---------------------------------------";
		dat << "\n";
		dat << "Ukupno: " << racun.ukupno;
		dat << "\n";
		dat << "PDV: " << racun.PDV;
		dat << "\n";
		dat << "Ukupno za placanje: " << (racun.ukupno + racun.PDV);
		dat << "\n";

		dat.close();
	}

	/*
	OSI Market Banja Luka
	Poslovnica: ETF

	Maloprodajni racun

	Kupac: ABC

	Proizvod - kolicina - cijena - ukupno
	---------------------------------------
	abc 123  -    10    -    5   -   50
	abb 456  -    20    -   10   -   200
	---------------------------------------

	Ukupno: 250
	PDV: 42.5
	Ukupno za placanje: 292.5
	Datum: 24/10/2017*/

	else if (i == 2)
	{
		Unos racun;
		std::cout << "Kupac: "; std::cin >> racun.kupac;
		std::cout << "Datum: "; std::cin >> racun.dan >> racun.mjesec >> racun.godina;
		std::cout << "Broj proizvoda: "; std::cin >> racun.brojProizvoda;
		racun.proizvod = new std::string[racun.brojProizvoda];
		racun.kolicina = new double[racun.brojProizvoda];
		racun.cijena = new double[racun.brojProizvoda];
		for (int i = 0; i < racun.brojProizvoda; i++)
		{
			std::cout << "Unesite" << i + 1 << " proizvod: ";
			std::cin >> racun.proizvod[i];
			std::cout << "Unesite kolicinu" << i + 1 << " og prozivoda:";
			std::cin >> racun.kolicina[i];
			std::cout << "Unesite cijenu" << i + 1 << " og prozivoda: ";
			std::cin >> racun.cijena[i];
			racun.ukupno += racun.kolicina[i] * racun.cijena[i];
		}
		racun.PDV = (racun.ukupno - (racun.ukupno / 1.17));



		std::ofstream dat;
		dat.open(filename, std::ios::app);
		dat << "OSI Market Banja Luka";
		dat << "\n";
		dat << "Poslovnica: ETF";
		dat << "\n";
		dat << "	Maloprodajni racun" << "	";
		dat << "\n";
		dat << "Kupac: " << racun.kupac;
		dat << "\n";
		dat << "Proizvod - kolicina - cijena - ukupno";
		dat << "\n";
		dat << "---------------------------------------";
		dat << "\n";
		for (int i = 0; i < racun.brojProizvoda; i++)
		{
			dat << racun.proizvod[i] << "  -    " << racun.kolicina[i] << "  -    " << racun.cijena[i] << "  -    " << racun.kolicina[i] * racun.cijena[i];
			dat << "\n";
		}
		dat << "---------------------------------------";
		dat << "\n";
		dat << "Ukupno: " << racun.ukupno;
		dat << "\n";
		dat << "PDV: " << racun.PDV;
		dat << "\n";
		dat << "Ukupno za placanje: " << (racun.ukupno + racun.PDV);
		dat << "\n";
		dat << "Datum:" << racun.dan << "/" << racun.mjesec << "/" << racun.godina;
		dat.close();

	}

	/*Kupac: ABC
	Datum: 24/10/2017

	OSI Market

	Proizvod - kolicina - cijena - ukupno
	---------------------------------------
	abc 123  -    10    -    5   -   50
	abb 456  -    20    -   10   -   200
	---------------------------------------
	Ukupno: 250
	PDV: 42.5
	=======================================
	Ukupno za placanje: 292.5

	=======================================*/

	else if (i == 3)
	{
		Unos racun;
		std::cout << "Kupac: "; std::cin >> racun.kupac;
		std::cout << "Datum: "; std::cin >> racun.dan >> racun.mjesec >> racun.godina;
		std::cout << "Broj proizvoda: "; std::cin >> racun.brojProizvoda;

		racun.proizvod = new std::string[racun.brojProizvoda];
		racun.kolicina = new double[racun.brojProizvoda];
		racun.cijena = new double[racun.brojProizvoda];
		for (int i = 1; i < racun.brojProizvoda; i++)
		{
			std::cout << "Unesite " << i << " proizvod: ";
			std::cin >> racun.proizvod[i];
			std::cout << "Unesite kolicinu " << i << " proizvoda:";
			std::cin >> racun.kolicina[i];
			std::cout << "Unesite cijenu " << i << " tog proizvoda: ";
			std::cin >> racun.cijena[i];
			racun.ukupno += racun.kolicina[i] * racun.cijena[i];
		}
		racun.PDV = (racun.ukupno - (racun.ukupno / 1.17));


		std::ofstream dat;
		dat.open(filename, std::ios::app);// promijeniti naziv fajla za razlicite datoteke
		dat << "Kupac: " << racun.kupac;
		dat << "\n";
		dat << "Datum:" << racun.dan << "/" << racun.mjesec << "/" << racun.godina;
		dat << "\n";
		dat << "\n";
		dat << "	       OSI MARKET" << "	       ";
		dat << "\n";
		dat << "\n";
		dat << "Proizvod - kolicina - cijena - ukupno";
		dat << "\n";
		for (int i = 0; i < racun.brojProizvoda; i++)
		{
			dat << racun.proizvod[i] << "  -    " << racun.kolicina[i] << "  -    " << racun.cijena[i] << "  -    " << racun.kolicina[i] * racun.cijena[i];
			dat << "\n";
		}
		dat << "---------------------------------------";
		dat << "\n";
		dat << "Ukupno: " << racun.ukupno;
		dat << "\n";
		dat << "PDV: " << racun.PDV;
		;
		dat << "\n";
		dat << "=======================================";
		dat << "\n";
		dat << "Ukupno za placanje: " << (racun.ukupno + racun.PDV);
		dat << "\n";
		dat << "=======================================";
		dat.close();

	}
}

Unos::~Unos()
{
}
