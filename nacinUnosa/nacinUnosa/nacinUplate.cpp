#include "Korisnik.h"
#include "administrator.h"
#include <string>
#include <iostream>

void Korisnik::nacinUplate()
{
	administrator pom;
	int opcija;
	double valuta, iznos;
	std::string stranavaluta;
	std::cout << "Izaberite nacin uplate : Gotovinom[1] Karticom[2]" << std::endl;
	std::cin >> opcija;
	if (opcija == 2)
		std::cout << "Provjera stanja na racunu..." << std::endl;
	else if (opcija == 1)
	{
		std::cout << " Izaberite jednu od dvije ponudjene opcije : Uplata u osnovnoj valuti[1] Uplata u stranoj valuti[2]" << std::endl;
		std::cin >> valuta;
		if (valuta == 1)
		{
			std::cout << "Unesite iznos u osnovnoj valuti:" << std::endl;
			std::cin >> iznos;
			std::cout << "Izvrsena uplata : " << iznos;  pom.izaberiValutu();
		}
		else if (valuta == 2)
		{
			std::cout << "Unesite valutu u kojoj uplacujete:" << std::endl;
			std::cin >> stranavaluta;
			std::cout << "Unesite iznos"; std::cin >> iznos;
			pom.uplataStranaValuta(stranavaluta, iznos);
		}
	}
	else if (opcija != 1 && opcija != 2)
		std::cout << "Greska!";
}