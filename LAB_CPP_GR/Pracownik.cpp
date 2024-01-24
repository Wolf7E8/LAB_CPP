#include "Pracownik.h"
#include "Kierownik.h"
#include <iomanip>

int Pracownik::ID{};

const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << "	";
	m_Nazwisko.Wypisz();
	cout << "	";
	m_DataUrodzenia.Wypisz();
	cout << endl;
}

void Pracownik::Wpisz()
{
	cout << "Podaj Imie: ";
	m_Imie.Wpisz();
	cout << "Podaj Nazwisko: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzenia" << endl;
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	int wynik;
	wynik = SprawdzImie(wzorzec.m_Imie.Zwroc());

	if (wynik == 0)
	{
		wynik = SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc());
	}
	else return wynik;

	if (wynik == 0)
	{
		wynik = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
	}
	else return wynik;

	return wynik;
}

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) : m_nIDZatrudnienia(ID+1), m_DataUrodzenia(Data(dzien, miesiac, rok))
{
	m_Imie = im;
	m_Nazwisko = naz;
	ID++;
	m_pNastepny = nullptr;
}

Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia(wzor.m_nIDZatrudnienia), m_DataUrodzenia(wzor.m_DataUrodzenia)
{
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	//m_pNastepny = wzor.m_pNastepny;
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if (this != &wzor)
	{
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		//m_Imie = wzor.Imie();
		//m_Nazwisko = wzor.Nazwisko();
		//m_Imie.Ustaw(wzor.Imie());
		//m_Nazwisko.Ustaw(wzor.Nazwisko());
		//m_pNastepny = wzor.m_pNastepny;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
	}
	return *this;
}

bool Pracownik::operator==(const Pracownik& wzor) const
{
	return !Porownaj(wzor);
}

void Pracownik::WypiszDane()
{
	cout << std::setw(10) << std::left << m_Imie << "\t" << std::setw(15) << std::left
		<< m_Nazwisko << "\t" << m_DataUrodzenia
		<< "\t" << std::setw(3) << std::right << m_nIDZatrudnienia << "\t";
	Kierownik* kto = dynamic_cast<Kierownik*>(this);
	if (kto == nullptr)
	{
		cout << endl;
	}
	/*cout << "Imie: " << m_Imie << endl;
	cout << "Nazwisko: " << m_Nazwisko << endl;
	cout << "Data urodzenia: " << m_DataUrodzenia << endl;
	cout << "ID: " << m_nIDZatrudnienia << endl;*/
}

Pracownik* Pracownik::KopiaObiektu() const
{
	Pracownik* nowy = new Pracownik(*this);
	return nowy;
}

Pracownik::~Pracownik()
{
	m_pNastepny = nullptr;
}

ostream& operator<<(ostream& wy, Pracownik& p)
{
	//wy << p.m_Imie << ' ' << p.m_Nazwisko << ' ' << p.m_DataUrodzenia << ' ' << p.m_nIDZatrudnienia;
	wy << std::setw(10) << std::left << p.m_Imie << "\t" << std::setw(10) << std::left
		<< p.m_Nazwisko << "\t" << p.m_DataUrodzenia
		<< "\t" << std::setw(3) << std::right << p.m_nIDZatrudnienia << "\t";
	Kierownik* kto = dynamic_cast<Kierownik*>(&p);
	if (kto == nullptr)
	{
		wy << endl;
	}
	return wy;
}

istream& operator>>(istream& we, Pracownik& p)
{
	if (&we == &cin)
	{
		cout << "Podaj imie: " << std::endl;
	}
	we >> p.m_Imie;
	if (&we == &cin)
	{
		cout << "Podaj nazwisko: " << std::endl;
	}
	we >> p.m_Nazwisko;
	if (&we == &cin)
	{
		cout << "Podaj date urodzenia: " << std::endl;
	}
	we >> p.m_DataUrodzenia;

	if (&we != &cin)
	{
		int niepotrzebna;
		we >> niepotrzebna;
	}
	return we;
}
