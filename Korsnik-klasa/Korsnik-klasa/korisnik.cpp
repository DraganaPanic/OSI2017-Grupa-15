#include "korisnik.h"


Korisnik::Korisnik(std::string ime, std::string prezime, std::string pin, string korisnickagrupa) : Ime(ime), Prezime(prezime), Pin(pin), korisnickaGrupa(korisnickagrupa)
{
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

ostream& operator <<(ostream& out, const Korisnik& korisnik)
{
	out << korisnik.Ime << endl;
	out << korisnik.Prezime << endl;
	out << korisnik.Pin << endl;
	out << korisnik.korisnickaGrupa << endl;
	return out;
}

std::istream& operator >> (istream& in, Korisnik& korisnik)
{
	in >> korisnik.Ime;
	in >> korisnik.Prezime;
	in >> korisnik.Pin;
	in >> korisnik.korisnickaGrupa;
	return in;
}


void Korisnik::registracija(std::fstream os, Korisnik& other)
{
	if (does_person_exist(std::ifstream("registrovani.txt"), other) == 1)
	{
		std::cout << "This person already exists!"; std::ifstream("registrovani.txt").close();
	}
	else
	{
		os << other.getIme() << " " << other.getPrezime() << " " << other.getPin() << " " << other.getKorisnickaGrupa() << std::endl;
		os.flush();
		std::cout << "Registration succeeded!";
	}

}

Korisnik Korisnik::dodaj()
{
	Korisnik p;
	cout << "Ime: "; cin >> p.Ime;
	cout << "Prezime: "; cin >> p.Prezime;
	cout << "PIN: "; cin >> p.Pin;


	if ((p.is_number(p.Pin) != 1) || (p.Pin.length() != 4))
	{
		do { cout << "PIN1 "; cin >> p.Pin; } while ((p.is_number(p.Pin) != 1) || (p.Pin.length() != 4));

	}
	cout << "Korisnicka grupa: "; cin >> p.korisnickaGrupa;

	if ((p.korisnickaGrupa != "administrator") && (p.korisnickaGrupa != "analiticar"))
	{
		do { cout << "Korisnicka grupa "; cin >> p.korisnickaGrupa; } while ((p.korisnickaGrupa != "administrator") && (p.korisnickaGrupa != "analiticar"));
	}

	return p;
}

bool Korisnik::is_number(string& src)
{
	const char *start = src.c_str();
	errno = 0;
	char *end;
	long string_value = strtol(start, &end, 10);

	if (
		errno == ERANGE ||                                 // Did we set off errno?
		string_value > numeric_limits<int>::max() ||       // Is it too big?
		string_value < numeric_limits<int>::min() ||       // Too small?
		static_cast<unsigned>(end - start) != src.length() // Non-numerics?
		)
	{
		return false;
	}

	return true;
}

int Korisnik::does_person_exist(std::ifstream os, Korisnik& other)
{
	if (os)
	{
		string name, surname, pin, usergroup;
		while (os >> name >> surname >> pin >> usergroup)
		{
			if (other.Ime == name && other.Prezime == surname)
				return 1;
		}os.close();
		return 0;
	}

}