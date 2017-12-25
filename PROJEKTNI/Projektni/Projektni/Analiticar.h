#pragma once
#include "korisnik.h"
#include <string>

class Analiticar : public Korisnik
{
	public:
		Analiticar(std::string, std::string, std::string, std::string) : Korisnik(std::string, std::string, std::string, std::string) {}

};
