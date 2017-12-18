#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdio>
#include <list>

using namespace std;

class Korisnik
{
	friend ostream &operator<<(ostream&, const Korisnik&) noexcept;
	friend istream &operator>>(istream&, Korisnik&) noexcept;
public:
	Korisnik(std::string, std::string, std::string, string)noexcept(false);
	/*std::string getIme() const noexcept;
	std::string getPrezime() const noexcept;
	std::string getPin() const noexcept;
	string getKorisnickaGrupa() const noexcept;*/
	void registracija(Korisnik*)noexcept(false);
	~Korisnik() = default;

protected:
	std::string Ime, Prezime, Pin, korisnickaGrupa;
private:
	const char* poruka1 = "Invalid PIN!\n";
	const char* poruka2 = "This person already exist!\n";
};
