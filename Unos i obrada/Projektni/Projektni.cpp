// Projektni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ObradaRacuna.h"
#include "Unos.h"


int main()
{
	Unos racun;
	try {
		racun.unos("racuni5.txt");
	}
	catch (const char* p) {
		std::cout << p << std::endl;
	}
	
    return 0;
}
