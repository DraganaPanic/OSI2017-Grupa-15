#pragma once
#include <iostream>

class Unos
{
	friend std::ostream& operator<<(std::ostream&, const Unos&) noexcept;
	friend std::istream& operator>>(std::istream&, Unos&) noexcept;
protected:
	std::string kupac, *proizvod, sifra;
	unsigned int brojProizvoda;
	unsigned int dan, mjesec, godina;
	double ukupno, PDV;
	double *kolicina, *cijena;
	const char* poruka = "Pogresan format !\n";
	const char* poruka2 = "Pogresan naziv datoteke!\n";

public:
	Unos();
	void unos(std::string) noexcept(false);

	~Unos();
};

