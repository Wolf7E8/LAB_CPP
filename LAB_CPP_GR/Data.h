#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>

using namespace std;

class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
public:
	void Ustaw(int d, int m, int r);

	int Dzien() const;
	int Miesiac() const;
	int Rok() const;

	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data& wzor) const;
	Data(int d, int m, int r);

	friend ostream& operator<<(ostream& wy, const Data& d);
	friend istream& operator>>(istream& we, Data& d);

	
};

ostream& operator<<(ostream& wy, const Data& d);
istream& operator>>(istream& we, Data& d);
