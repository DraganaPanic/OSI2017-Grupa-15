#include "korisnik.h"


void Korisnik::prijava()noexcept (false)
{
	fstream dat("registrovani.txt",ios::app);
	
	Korisnik p;
	cout << "Ime: "; cin >> p.Ime; cout << endl;
	cout << "Prezime: "; cin >> p.Prezime; cout << endl;
	cout << "PIN: "; cin >> p.Pin; cout << endl;
	cout << "Korisnicka grupa: "; cin >> p.korisnickaGrupa; cout << endl;

	if (dat)
	{
		string ime, prezime, pin, korgr;

		while (dat >> ime >> prezime >> pin >> korgr)
		{
			if (p.Ime == ime && p.Prezime == prezime && p.Pin == pin && p.korisnickaGrupa == korgr)
				cout << "Account founded!\n" << endl;
			dat.close();
			break;
		}

		cout << "Account not found! You will be registered now!" << endl;

		dat << p.Ime << " " << p.Prezime << " " << p.Pin << " " << p.korisnickaGrupa << endl;
		cout << "Registration succeed!\n" << endl;
		dat.close();
	}
}