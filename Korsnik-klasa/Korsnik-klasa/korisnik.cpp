#include "Header.h"


Korisnik::Korisnik(std::string ime, std::string prezime, std::string pin, string korisnickagrupa) noexcept : Ime(ime), Prezime(prezime), Pin(pin), korisnickaGrupa(korisnickagrupa)
{
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

void Korisnik::registracija(Korisnik* p) noexcept(false)
{
	if (p != 0) {
		fstream dat("registrovani.txt", ios::app);


		if (dat)
		{
			cout << "otvorena je tebra";
			string ime, prezime, pin, korgr;

			while (dat >> ime >> prezime >> pin >> korgr)
			{
				if (p->Ime == ime && p->Prezime == prezime)
					throw poruka2;
			}


			dat << p->Ime << " " << p->Prezime << " " << p->Pin << " " << p->korisnickaGrupa << endl;
			cout << "Registration succeed!\n" << endl;
			dat.close();
		}
	}
}

Korisnik Korisnik::dodaj() noexcept (false)
{
	Korisnik p;
	cout << "Ime: "; cin >> p.Ime; cout << endl;
	cout << "Prezime: "; cin >> p.Prezime; cout << endl;
	cout << "PIN: "; cin >> p.Pin; cout << endl;
	cout << "Korisnicka grupa: "; cin >> p.korisnickaGrupa; cout << endl;

	if (size(p.Pin) < 4 || size(p.Pin) > 4)
	{
		throw poruka1;
	}
	else
		return p;
}