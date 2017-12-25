#pragma once
#include "korisnik.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class administrator : public Korisnik
{
public:
	administrator(std::string, std::string, std::string, std::string) : Korisnik(std::string, std::string, std::string, std::string) {};
	virtual ~administrator();
	void izaberiValutu();
	void uplataStranaValuta(std::string, double);
};

