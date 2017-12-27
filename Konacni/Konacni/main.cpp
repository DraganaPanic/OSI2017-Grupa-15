#include <iostream>
#include "korisnik.h"
#include <string>
#include <fstream>
#include "administrator.h"
using namespace std;

int main()
{
	Korisnik korisnik;
	korisnik = korisnik.dodaj();

	cout << endl;
	char c;
	
	do {
		cout << "Zelite li se prijaviti[1] ili registrovati[2]?" << endl;
		cin >> c;
	} while (c != '1' &&  c != '2');

	if (c == '1') korisnik.prijava(&korisnik);
	else
		korisnik.registracija(&korisnik);
	
	

	getchar();
	getchar();
	return 0;
}