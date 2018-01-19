#pragma once
#include <iostream>
#define BrojProizvoda 100


class ObradaRacuna
{

	friend std::ostream& operator<<(std::ostream&, const ObradaRacuna&) noexcept;
	friend std::istream& operator>>(std::istream&, ObradaRacuna&) noexcept;

protected:
	std::string kupac, *proizvod;
	unsigned int inicBrojProizvoda;
	unsigned int dan, mjesec, godina;
	double ukupno, PDV, ukupnoZaPlacanje;
	double *kolicina, *cijena;
	const char* poruka = "Pogresan format !\n";
	const char* poruka2 = "Pogresan naziv datoteke!\n";

public:
	ObradaRacuna() = default;
	void obradaRacuna(std::string,int ) noexcept(false);
	~ObradaRacuna();
};

