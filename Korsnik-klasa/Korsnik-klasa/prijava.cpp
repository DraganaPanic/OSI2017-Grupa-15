#include "Header.h"


void Korisnik::prijava(Korisnik *p)noexcept (false)
{
	if (p != 0) {
		fstream dat("registrovani.txt", ios::app);

		if (dat)
		{
			string ime, prezime, pin, korgr;

			while (dat >> ime >> prezime >> pin >> korgr)
			{
				if (p->Ime == ime && p->Prezime == prezime && p->Pin == pin && p->korisnickaGrupa == korgr)
					cout << "Account founded!\n" << endl;
				dat.close();
				break;
			}

			cout << "Account not found! You will be registered now!" << endl;

			dat << p->Ime << " " << p->Prezime << " " << p->Pin << " " << p->korisnickaGrupa << endl;
			cout << "Registration succeed!\n" << endl;
			dat.close();
		}
	}
}