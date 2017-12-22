#include "biranjeValute.h"
#include <iostream>
#include <string>


void izaberiValutu()

{
	std::string glavnaValuta;
	std::ifstream dat("valute.txt");
	if (dat.is_open())

	{
		std::getline(dat, glavnaValuta);
		std::cout << "Glavna valuta je " << glavnaValuta<< std::endl;
		dat.close();
	}
	else
		std::cout << "Greska u otvaranju datoteke sa valutama!";
}