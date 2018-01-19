#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <tuple>

using namespace std;

class Korisnik
{
	friend ostream &operator<<(ostream&, const Korisnik&);
	friend istream &operator >> (istream&, Korisnik&);
public:
	Korisnik() = default;
	Korisnik(std::string, std::string, std::string, std::string);
	std::string getIme() const noexcept;
	std::string getPrezime() const noexcept;
	std::string getPin() const noexcept;
	string getKorisnickaGrupa() const noexcept;
	Korisnik dodaj();
	void nacinUplate();
	void registracija(std::fstream , Korisnik& );
	void prijava(Korisnik*);
	virtual ~Korisnik() = default;
	bool is_number(string& src);
	int does_person_exist(std::ifstream, Korisnik&);
	
protected:
	std::string Ime, Prezime, Pin, korisnickaGrupa;
private:
	const char* poruka1 = "Invalid PIN!\n";
	const char* poruka2 = "This person already exist!\n";
};


