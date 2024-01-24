#include "Kierownik.h"
#include <iomanip>

Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok, Napis nazwaDzialu, int lPracownikow)
	: Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(nazwaDzialu), m_nliczbaPracownikow(lPracownikow)
{
}

Kierownik::Kierownik(const Kierownik& wzor) : Pracownik(wzor), m_NazwaDzialu(wzor.m_NazwaDzialu), m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
{
}

Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	if (this != &wzor)
	{
		Pracownik::operator=(wzor);
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	bool pochodna;
	bool bazowa = Pracownik::operator==(wzor);
	if (m_NazwaDzialu == wzor.m_NazwaDzialu && m_nliczbaPracownikow == wzor.m_nliczbaPracownikow)
	{
		pochodna = true;
	}
	else pochodna = false;
	return bazowa && pochodna;
}

void Kierownik::WypiszDane()
{
	Pracownik::WypiszDane();
	cout << std::setw(15) << std::left << m_NazwaDzialu << "\t" << std::setw(3) << std::left << m_nliczbaPracownikow << endl;
	//cout << "Nazwa dzia³u: " << m_NazwaDzialu << endl;
	//cout << "Liczba pracownikow: " << m_nliczbaPracownikow << endl;
}

Pracownik* Kierownik::KopiaObiektu() const
{
	Pracownik* nowy = new Kierownik(*this);
	return nowy;
}

ostream& operator<<(ostream& wy, Kierownik& s)
{
	//return wy << (const Pracownik&)s << ' ' << s.m_NazwaDzialu << ' ' << s.m_nliczbaPracownikow;
	wy << (Pracownik&)s;
	wy << std::setw(10) << std::left << s.m_NazwaDzialu << "\t" << std::setw(3) << std::right << s.m_nliczbaPracownikow << endl;
	return wy;
}

istream& operator>>(istream& we, Kierownik& s)
{
	if (&we == &cin)
	{
		cout << "Operator>>KierowniK\n";
	}
	we >> (Pracownik &)s;
	if (&we == &cin)
	{
		cout << "Podaj nazwe dzialu: ";
	}
	we >> s.m_NazwaDzialu;
	if (&we == &cin)
	{
		cout << "Podaj liczbe pracownikow: ";
	}
	we >> s.m_nliczbaPracownikow;
	return we;
}
