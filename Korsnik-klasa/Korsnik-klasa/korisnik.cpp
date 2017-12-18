#include "Korisnik.h"



Korisnik::Korisnik(std::string ime, std::string prezime, std::string pin, string korisnickagrupa) noexcept(false) : Ime(ime), Prezime(prezime), Pin(pin), korisnickaGrupa(korisnickagrupa)
{
	if (size(pin) < 4 || size(pin) > 4)
	throw poruka1;
}

std::string Korisnik::getIme() const noexcept
{
	return Ime;
}

std::string Korisnik::getPrezime() const noexcept
{
	return Prezime;
}

std::string Korisnik::getPin() const noexcept
{
	return Pin;
}
 string Korisnik::getKorisnickaGrupa() const noexcept
{
	return korisnickaGrupa;
}

ostream& operator <<(ostream& out, const Korisnik& korisnik) noexcept
{
	out << korisnik.Ime << endl;
	out << korisnik.Prezime << endl;
	out << korisnik.Pin << endl;
	out << korisnik.korisnickaGrupa << endl;
	return out;
}
/*
istream& operator >>(istream& in, Korisnik& korisnik) noexcept
{
	in >> korisnik.Ime >> endl;
	in >> korisnik.Prezime >>endl;
	in >> korisnik.Pin >> endl;
	in >> korisnik.korisnickaGrupa >> endl;
	return in;
}*/

void Korisnik::registracija(Korisnik* korisnik) noexcept(false)
{
	fstream dat;
	dat.open("registrovani.txt");

	if (dat) cout << "Greska pri otvaranju datoteke\n" << endl;
	else
	{

	}
}