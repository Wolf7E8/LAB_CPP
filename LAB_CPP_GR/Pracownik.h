#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"

class Pracownik
{
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int ID;
	
public:
	Pracownik* m_pNastepny;
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const; 
	Pracownik(const char* im = "", const char* naz = "",
		int dzien = 1, int miesi¹c = 1, int rok = 2000);
	Pracownik(const Pracownik& wzor);
	Pracownik& operator=(const Pracownik& wzor);
	bool operator==(const Pracownik& wzor) const;
	friend ostream& operator<<(ostream& wy, Pracownik& p);
	friend istream& operator>>(istream& we, Pracownik& p);

	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu() const;

	virtual ~Pracownik();
};

ostream& operator<<(ostream& wy, Pracownik& p);
istream& operator>>(istream& we, Pracownik& p);


