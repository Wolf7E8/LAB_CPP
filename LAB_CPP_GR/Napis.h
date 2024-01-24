#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"

class Napis
{
private:
	char* m_pszNapis;
	int m_nDl;

public:
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;
	Napis(const char* nap = "");
	~Napis();
	Napis(const Napis& wzor);
	Napis& operator=(const Napis& wzor);
	bool operator==(const Napis& wzor) const;

	friend ostream& operator<<(ostream& wy, const Napis& p);
	friend istream& operator>>(istream& we, Napis& p);
};

ostream& operator<<(ostream& wy, const Napis& p);
istream& operator>>(istream& we, Napis& p);