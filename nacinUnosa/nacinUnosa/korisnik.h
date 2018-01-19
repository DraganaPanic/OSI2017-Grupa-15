#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdio>
#include <tuple>

using namespace std;

class Korisnik
{
	friend ostream &operator<<(ostream&, const Korisnik&) noexcept;
	friend istream &operator>>(istream&, Korisnik&) noexcept;
public:
	Korisnik() = default;
	Korisnik(std::string, std::string, std::string, string)noexcept;
	/*std::string getIme() const noexcept;
	std::string getPrezime() const noexcept;
	std::string getPin() const noexcept;
	string getKorisnickaGrupa() const noexcept;*/
	Korisnik dodaj() noexcept(false);
	void registracija(Korisnik*)noexcept(false);
	void prijava(Korisnik*) noexcept(false);
	void nacinUplate();
	~Korisnik() = default;

protected:
	std::string Ime, Prezime, Pin, korisnickaGrupa;
private:
	const char* poruka1 = "Invalid PIN!\n";
	const char* poruka2 = "This person already exist!\n";
};
