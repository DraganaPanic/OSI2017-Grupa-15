#include "korisnik.h"

void Korisnik::prijava(Korisnik *p)
{
	if (p != 0) {
		int flag = 0;
		fstream dat("registrovani.txt", ios::app);

		if (dat)
		{
			string ime, prezime, pin, korgr;

			while (dat >> ime >> prezime >> pin >> korgr)
			{
				if (p->Ime == ime && p->Prezime == prezime && p->Pin == pin && p->korisnickaGrupa == korgr)
				{
					cout << "Account founded!\n" << endl; flag = 1;
				}
			}
			if (flag == 1)
			{
				dat.close();
			}
			else
			{
				p->registracija(p);
				dat.close();
			}
			/*cout << "Account not found! You will be registered now!" << endl;

			dat << p->Ime << " " << p->Prezime << " " << p->Pin << " " << p->korisnickaGrupa << endl;
			cout << "Registration succeed!\n" << endl;
			dat.close();*/
		}
	}
}