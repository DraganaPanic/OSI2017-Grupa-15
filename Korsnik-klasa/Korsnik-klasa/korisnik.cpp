#include "Korisnik.h"


Korisnik::Korisnik(std::string ime, std::string prezime, std::string pin, string korisnickagrupa) noexcept(false) : Ime(ime), Prezime(prezime), Pin(pin), korisnickaGrupa(korisnickagrupa)
{

	if (size(pin) < 4 || size(pin) > 4)
	throw poruka1;
}
/*
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
}*/

ostream& operator <<(ostream& out, const Korisnik& korisnik) noexcept
{
	out << korisnik.Ime << endl;
	out << korisnik.Prezime << endl;
	out << korisnik.Pin << endl;
	out << korisnik.korisnickaGrupa << endl;
	return out;
}

std::istream& operator >>(istream& in, Korisnik& korisnik) noexcept
{
	in >> korisnik.Ime;
	in >> korisnik.Prezime;
	in >> korisnik.Pin;
	in >> korisnik.korisnickaGrupa;
	return in;
}

void Korisnik::registracija() noexcept(false)
{
	fstream dat("registrovani.txt",ios::app);

	Korisnik p;
	cout << "Ime: "; cin >> p.Ime; cout << endl;
	cout << "Prezime: "; cin >> p.Prezime; cout << endl;
	cout << "PIN: "; cin >> p.Pin; cout << endl;
	cout << "Korisnicka grupa: "; cin >> p.korisnickaGrupa; cout << endl;

	if (dat)
	{
		string ime, prezime, pin, korgr;

		while (dat >> ime >> prezime >> pin >> korgr)
		{
			if (p.Ime == ime && p.Prezime == prezime)
				throw poruka2;
		}

		dat << p.Ime << " " << p.Prezime << " " << p.Pin << " " << p.korisnickaGrupa << endl;
		cout << "Registration succeed!\n" << endl;
		dat.close();
	}
}