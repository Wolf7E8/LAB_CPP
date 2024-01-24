#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"

const char* Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis)
{
	delete[] m_pszNapis;
	m_nDl = strlen(nowy_napis) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	cout << m_pszNapis;
}

void Napis::Wpisz()
{
	delete[] m_pszNapis;
	char zmienna[100];
	cin >> zmienna;
	m_nDl = strlen(zmienna)+1;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, zmienna);
}

int Napis::SprawdzNapis(const char* por_napis) const
{
	return strcmp(m_pszNapis, por_napis);
}

Napis::Napis(const char* nap)
{
	m_nDl = strlen(nap) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, nap);
}

Napis::~Napis()
{
	delete[] m_pszNapis;
	m_nDl = 0;
}

Napis::Napis(const Napis& wzor)
{
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}

Napis& Napis::operator=(const Napis& wzor)
{
	if (this == &wzor)
		return *this;
	delete[] m_pszNapis;
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, wzor.m_pszNapis);
	return *this;
}

bool Napis::operator==(const Napis& wzor) const
{
	return !SprawdzNapis(wzor.m_pszNapis);
}

ostream& operator<<(ostream& wy, const Napis& p)
{
	wy << p.m_pszNapis;
	return wy;
}

//istream& operator>>(istream& we, Napis& n)
//{
//    char pom[20];
//    we >> ws;
//    we.get(pom, 20);
//    n.Nowy(pom);
//
//    while (we && we.peek() != '\n')
//    {
//        we.get(pom, 20);
//        n += pom;
//    }
//    we.get(); //'\n'
//
//    return we;
//}

istream& operator>>(istream& we, Napis& p)
{
	char pom[11];
	char pom_wy[11];
	we >> ws;
	we.get(pom, 11);

	for (int i = 0; i < 11; i++)
	{
		if (pom[i] != ' ')
		{
			pom_wy[i] = pom[i];
		}
		else
		{
			pom_wy[i] = '\0';
			break;
		}
	}
	p.Ustaw(pom_wy);
	we.clear();
	return we;
}
