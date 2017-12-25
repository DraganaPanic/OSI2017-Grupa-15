#include "administrator.h"

void administrator::izaberiValutu()

{
	std::string glavnaValuta;
	std::ifstream dat("valute.txt");
	if (dat.is_open())

	{
		std::getline(dat, glavnaValuta);
		std::cout << "Glavna valuta je " << glavnaValuta << std::endl;
		dat.close();
	}
	else
		std::cout << "Greska u otvaranju datoteke sa valutama!";
}


void administrator::uplataStranaValuta(std::string stranaValuta, double iznos)
{
	std::ifstream dat("valute.txt");
	std::string glavnaValuta;
	std::string pom;
	int znak = 0;
	double konverzija;
	double noviIznos;
	if (dat.is_open())
	{
		std::getline(dat, glavnaValuta);
		while (dat >> pom >> konverzija)
		{
			if (stranaValuta == pom)
			{
				dat >> konverzija;
				noviIznos = iznos / konverzija;
				std::cout << "Izvrsena je konverzija u osnovnu valutu, novi iznos je: " << noviIznos << std::endl;
				znak = 1;
			}

		}
		if (znak == 0) std::cout << "Konverzija ne moze biti izvrsena, strana valuta se ne nalazi u datoteci!" << std::endl;

	}
}