#pragma once
#include "korisnik.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class administrator : public Korisnik
{
public:
	administrator() = default;
	administrator(std::string a, std::string b, std::string c, std::string d) : Korisnik(a, b, c, d) {}
	void izaberiValutu();
	void uplataStranaValuta(std::string, double);
};



