#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pacijent {
	char ime[21], prezime[21], JMBG[14], ime_oca[21];
	double visina, tezina;
	int godine;
} PACIJENT;

typedef struct cvor {
	PACIJENT info;
	struct cvor* lijevi, *desni;
}CVOR;

void insertFront(CVOR**, CVOR**, PACIJENT*);
void insertBack(CVOR**, CVOR**, PACIJENT*);
int removeFront(CVOR**);
int removeBack(CVOR**, CVOR**);
void insertAt(CVOR*, CVOR*, PACIJENT*, int);
void removeAt(CVOR*, CVOR*, int);
PACIJENT front(CVOR*);
PACIJENT back(CVOR*, CVOR*);
int prebrojavanje(CVOR*, CVOR*);
void pisi(CVOR*);
void brisi_listu(CVOR**,CVOR**);
void citaj(PACIJENT*);
void sortByWeigth(CVOR*,CVOR*);
void olderThan20(CVOR*);

int main()
{
	CVOR *glava = 0, *rep = 0; char c; PACIJENT p;

	do {
		printf("======================================================================\n");
		printf("Dodaj element na pocetak liste [A]\n");
		printf("Dodaj element na kraj liste [B]\n");
		printf("Brisi element sa pocetka liste [C]\n");
		printf("Brisi element sa kraja liste [D]\n");
		printf("Dodaj element na poziciju [E]\n");
		printf("Izbrisi element sa pozicije [F]\n");
		printf("Vrati element sa pocetka liste [G]\n");
		printf("Vrati element sa kraja liste [H]\n");
		printf("Sortiraj [S]\n");
		printf("Pretrazi [P]\n");
		printf("Kraj [O]\n");
		scanf("\n%c", &c);
		if (c == 'A') {
			printf("Unesite podatke:\n"); citaj(&p);
			insertFront(&glava, &rep, &p);
			pisi(glava);
		}
		else if (c == 'B') {
			printf("Unesite podatke:\n"); citaj(&p);
			insertBack(&glava, &rep, &p);
			pisi(glava);
		}
		else if (c == 'C') {
			if (removeFront(&glava) == 1)
				printf("Element je pravilno obrisan sa pocetka liste\n");
			else
				printf("Element nije pravilno obrisan sa pocetka liste\n");
			pisi(glava);
		}
		else if (c == 'D') {
			if (removeBack(&glava, &rep) == 1)
				printf("Element je pravilno obrisan sa kraja liste\n");
			else
				printf("Element nije pravilno obrisan sa kraja liste\n");
			pisi(glava);
		}
		else if (c != 'E')
		{
			int i;
			printf("Unesite poziciju za dodavanje elementa\n"); scanf("%d", &i); citaj(&p);
			insertAt(glava, rep, &p, i);
			pisi(glava);
		}
		else if (c != 'F')
		{
			int i;
			printf("Unesite poziciju za brisanje elementa\n"); scanf("%d", &i);
			removeAt(glava, rep, i);
			pisi(glava);
		}
		else if (c != 'G')
		{
			p = front(glava);
			printf("Pacijent %s %s je bio na pocetku liste\n", p.ime, p.prezime);
		}
		else if (c != 'H')
		{
			p = back(glava, rep);
			printf("Pacijent %s %s je bio na kraju liste\n", p.ime, p.prezime);

		}
		else if (c != 'S')
		{
			sortByWeigth(glava, rep);
			pisi(glava);
		}
		else if (c != 'T')
		{
			olderThan20(glava);
		}
		else
			if (c != '0') printf("  Nepoznata opcija\n");
	} while (c != '0');
	brisi_listu(&glava, &rep);
	printf("KRAJ!\n"); return 0;
}

void sortByWeight(CVOR*glava,CVOR*rep)
{
	if (glava != 0)
	{
		int broj = prebrojavanje(glava, rep);
		PACIJENT*niz = (PACIJENT*)malloc(broj * sizeof(PACIJENT));
		int i, j;
		for (i = 0; i < broj; i++)
		{
			niz[i] = glava->info;
			glava = glava->desni;
		}
		i = 0; j = 0;

		for (i = 0; i < broj - 1; i++)
		{
			for (j = i + 1; j < broj; j++)
			{
				if (niz[j].tezina > niz[i].tezina)
				{
					PACIJENT pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
		}
	}
}

void olderThan20(CVOR* glava)
{
	if (glava != 0)
	{
		while (glava)
		{
			if (glava->info.godine > 20)
			{
				printf("%-21s	%-21s	%-21s	%-14s	%d	%5.2lf	%5.2lf\n", glava->info.prezime, glava->info.ime_oca, glava->info.ime, glava->info.JMBG, glava->info.godine, glava->info.visina, glava->info.tezina);
				glava = glava->desni;
			}
		}
	}
}

void citaj(PACIJENT* p)
{
	printf("\nIme:"); scanf("%s", p->ime);
	printf("\nPrezime:"); scanf("%s", p->prezime);
	printf("\nIme oca:"); scanf("%s", p->ime_oca);
	printf("\nJMBG"); scanf("%s", p->JMBG);
	printf("\nGodine:"); scanf("%d", &p->godine);
	printf("\nVisina:"); scanf("%lf", &p->visina);
	printf("\nTezina:"); scanf("%lf", &p->tezina);
}

void insertFront(CVOR** glava, CVOR** rep, PACIJENT* p)
{
	CVOR* novi = (CVOR*)malloc(sizeof(CVOR));
	novi->info=*p;
	novi->lijevi = novi->desni = 0;

	if (*glava == 0) *glava = *rep = novi;
	else
	{
		novi->desni = *glava;
		*glava = novi;
		novi->desni->lijevi = novi;
	}
}

void insertBack(CVOR** glava, CVOR** rep, PACIJENT* p)
{
	CVOR* novi = (CVOR*)malloc(sizeof(CVOR));
	novi->info=*p;
	novi->lijevi = novi->desni = 0;

	if (*glava == 0) *glava = *rep = novi;
	else
	{
		novi->lijevi = *rep;
		*rep = novi;
		novi->lijevi->desni = novi;
	}
}

int removeFront(CVOR** glava)
{
	if (*glava == 0) return 0;
	else
	{
		CVOR* p = *glava;
		*glava = p->desni;
		p->desni->lijevi = p->desni = 0;
		free(p);
		return 1;
	}
}

int removeBack(CVOR** glava, CVOR** rep)
{
	if (*glava == 0) return 0;
	else
	{
		CVOR* p = *rep;
		*rep = p->lijevi;
		p->lijevi->desni = p->lijevi = 0;
		free(p);
		return 1;
	}
}


void insertAt(CVOR* glava, CVOR* rep, PACIJENT* p, int n)
{
	if (glava== 0) return;
	else
	{
		int broj = prebrojavanje(glava, rep);
		if (n == 1)
			insertFront(&glava, &rep, p);
		else if (n == (broj + 1))
		{
			insertBack(&glava, &rep, p);
		}
		else if (n > (broj + 1) || n<1) return;
		else
		{
			int i = 1;
			CVOR* novi = (CVOR*)malloc(sizeof(CVOR));
			novi->info = *p;
			novi->desni = novi->lijevi = 0;
			while (i < n - 1)
			{
				glava = glava->desni;
				i++;
			}
			novi->desni = glava->desni;
			glava->desni->lijevi = novi;
			novi->lijevi = glava;
			glava->desni = novi;
		}
	}
}

void removeAt(CVOR* glava, CVOR* rep, int n)
{
	if (glava == 0) return;
	else
	{
		int broj = prebrojavanje(glava, rep);
		if (n == 1)
			removeFront(&glava);
		else if (n == broj)
		{
			removeBack(&glava, &rep);
		}
		else if (n > broj || n<1) return;
		else
		{
			int i = 1;
			CVOR*p = glava->desni;
			while (i < n - 1)
			{
				glava = glava->desni;
				p = glava->desni;
				i++;
			}
			glava->desni = p->desni;
			p->desni->lijevi = p->lijevi;
			p->desni = p->lijevi = 0;
			free(p);
		}
	}
}


int prebrojavanje(CVOR* glava, CVOR* rep)
{
	if (glava == 0) return 0;
	else
	{
		int i = 0;
		while (glava != rep)
		{
			glava = glava->desni;
			i++;
		}
		i++;
		return i;
	}
}

PACIJENT front(CVOR* glava)
{
	if (glava != 0) {
		PACIJENT p = glava->info;
		return p;
	}
}

PACIJENT back(CVOR* glava,CVOR* rep)
{ 
	if (glava != 0) {
		PACIJENT p = rep->info;
		return p;
	}
}

void brisi_listu(CVOR **glava, CVOR **rep) {
	while (*glava)
	{
		CVOR *p = (*glava)->desni; free(*glava); *glava = p;
	}
	*rep = 0;
}

void pisi(CVOR* glava)
{
	if (glava != 0)
	{
		printf("================================================================\n");
		printf("PREZIME	(IME OCA)	IME	JMBG	GODINE	VISINA	TEZINA\n");
		printf("================================================================\n");
		while (glava)
		{
			printf("%-21s	%-21s	%-21s	%-14s	%d	%5.2lf	%5.2lf\n", glava->info.prezime, glava->info.ime_oca, glava->info.ime, glava->info.JMBG, glava->info.godine, glava->info.visina, glava->info.tezina);
			glava = glava->desni;
		}
	}
}
