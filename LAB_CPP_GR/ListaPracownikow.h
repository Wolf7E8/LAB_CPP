#pragma once
#include "Pracownik.h"
#include "Kierownik.h"
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

class ListaPracownikow
{
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	ListaPracownikow();
	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	~ListaPracownikow();
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	void zapisDoPliku() const;
	void odczytZPliku();
};

