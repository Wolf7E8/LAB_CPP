#include "ListaPracownikow.h"

ListaPracownikow::ListaPracownikow()
{
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}

//void ListaPracownikow::Dodaj(const Pracownik & p)
//{
//	//Pracownik* nowy_pracownik;
//	//nowy_pracownik = new Pracownik(p);
//	Pracownik* nowy_pracownik = new Pracownik();
//	nowy_pracownik = p.KopiaObiektu();
//
//	if (m_pPoczatek == nullptr)
//	{
//		m_pPoczatek = nowy_pracownik;
//		m_nLiczbaPracownikow = 1;
//		nowy_pracownik->m_pNastepny = nullptr;
//		return;
//	}
//
//	Pracownik* aktualny = m_pPoczatek;
//	Pracownik* nastepny = m_pPoczatek->m_pNastepny;
//	int wynik;
//	do		//pêtla ktora sprawdza czy na liœcie nie ma takiego samego elementu
//	{
//		wynik =  aktualny->Porownaj(*nowy_pracownik);
//		aktualny = nastepny;
//		if (aktualny != nullptr)
//		{
//			nastepny = aktualny->m_pNastepny;
//		}
//		if (wynik == 0)
//		{
//			cout << "Taka osoba jest juz na liscie" << endl;
//			return;
//		}
//	} while (nastepny != nullptr);
//
//	aktualny = m_pPoczatek;
//	nastepny = m_pPoczatek->m_pNastepny;
//	Pracownik* poprzedni = nullptr;	//wskaŸnik który przechowuje adres poprzedniego elementu
//	while (aktualny != nullptr)
//	{
//		wynik = aktualny->Porownaj(*nowy_pracownik);
//
//		if (wynik < 0 && aktualny == m_pPoczatek)
//		{
//			m_pPoczatek = nowy_pracownik;
//			nowy_pracownik->m_pNastepny = aktualny;
//			return;
//		}
//
//		if (wynik < 0)
//		{
//			nowy_pracownik->m_pNastepny = aktualny;
//			poprzedni->m_pNastepny = nowy_pracownik;
//			return;
//		}
//
//		if (nastepny == nullptr)
//		{
//			aktualny->m_pNastepny = nowy_pracownik;
//			nowy_pracownik->m_pNastepny = nullptr;
//			return;
//		}
//
//		poprzedni = aktualny;
//		aktualny = nastepny;
//		nastepny = aktualny->m_pNastepny;
//	}
//}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
	//Pracownik* nowy_pracownik;
	//nowy_pracownik = new Pracownik(p);
	Pracownik* nowy_pracownik = new Pracownik();
	nowy_pracownik = p.KopiaObiektu();

	if (m_pPoczatek == nullptr)
	{
		m_pPoczatek = nowy_pracownik;
		m_nLiczbaPracownikow = 1;
		nowy_pracownik->m_pNastepny = nullptr;
		return;
	}

	Pracownik* aktualny = m_pPoczatek;
	Pracownik* nastepny = m_pPoczatek->m_pNastepny;
	int wynik;
	do		//pêtla ktora sprawdza czy na liœcie nie ma takiego samego elementu
	{
		wynik = aktualny->Porownaj(*nowy_pracownik);
		aktualny = nastepny;
		if (aktualny != nullptr)
		{
			nastepny = aktualny->m_pNastepny;
		}
		if (wynik == 0)
		{
			cout << "Taka osoba jest juz na liscie" << endl;
			return;
		}
	} while (nastepny != nullptr);

	aktualny = m_pPoczatek;
	nastepny = m_pPoczatek->m_pNastepny;
	Pracownik* poprzedni = nullptr;	//wskaŸnik który przechowuje adres poprzedniego elementu
	while (aktualny != nullptr)
	{
		wynik = aktualny->Porownaj(*nowy_pracownik);

		 if (wynik > 0 && aktualny == m_pPoczatek)
		{
			m_pPoczatek = nowy_pracownik;
			nowy_pracownik->m_pNastepny = aktualny;
			return;
		}

		if (wynik > 0)
		{
			nowy_pracownik->m_pNastepny = aktualny;
			poprzedni->m_pNastepny = nowy_pracownik;
			return;
		}

		if (nastepny == nullptr)
		{
			aktualny->m_pNastepny = nowy_pracownik;
			nowy_pracownik->m_pNastepny = nullptr;
			return;
		}

		poprzedni = aktualny;
		aktualny = nastepny;
		nastepny = aktualny->m_pNastepny;
	}
}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	int wynik;
	Pracownik* aktualny = m_pPoczatek;
	Pracownik* poprzedni = nullptr;
	while (aktualny != nullptr)
	{
		wynik = aktualny->Porownaj(wzorzec);
		int nic = 0;
		if (wynik == 0 && aktualny == m_pPoczatek)
		{
			m_pPoczatek = aktualny->m_pNastepny;
			delete aktualny;
			return;
		}

		if (wynik == 0)
		{
			poprzedni->m_pNastepny = aktualny->m_pNastepny;
			delete aktualny;
			return;
		}

		if (aktualny->m_pNastepny == nullptr)
		{
			cout << "Nie ma takiego pracownika na liscie" << endl;
			return;
		}
		poprzedni = aktualny;
		aktualny = aktualny->m_pNastepny;
	}
}

ListaPracownikow::~ListaPracownikow()
{
	if (m_pPoczatek != nullptr)
	{
		Pracownik* aktualny = m_pPoczatek;
		Pracownik* nastepny = aktualny->m_pNastepny;
		while (aktualny != nullptr)
		{
			delete aktualny;
			aktualny = nastepny;
			if (aktualny != nullptr)
			{
				nastepny = aktualny->m_pNastepny;
			}
		}
	}
	m_pPoczatek = nullptr;
}

void ListaPracownikow::WypiszPracownikow() const
{
	cout << "LISTA PRACOWNIKOW" << endl;

	Pracownik* aktualny = m_pPoczatek; 

	if (m_pPoczatek != nullptr)
	{

		while (aktualny != nullptr)
		{
			aktualny->WypiszDane();
			aktualny = aktualny->m_pNastepny;
		}
	}
	else cout << "Lista pracownikow jest pusta!" << endl;
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	Pracownik* aktualny = m_pPoczatek;
	int wynik_1, wynik_2;

	while (aktualny != nullptr)
	{
		wynik_1 = aktualny->SprawdzImie(imie);
		wynik_2 = aktualny->SprawdzNazwisko(nazwisko);
		if (wynik_1 == 0 && wynik_2 == 0)
		{
			return aktualny;
		}
		aktualny = aktualny->m_pNastepny;
	}
	return nullptr;
}

void ListaPracownikow::zapisDoPliku() const
{
	ofstream plik("lista.txt", ios::out);
	if (!plik)
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
		return;
	}
	Pracownik* obecny = m_pPoczatek;
	while (obecny != nullptr)
	{
		Kierownik* kto = dynamic_cast<Kierownik*>(obecny);
		if (kto != nullptr)
		{
			plik << "K " << *kto;
		}
		else
		{
			plik << "P " << *obecny;
		}
		obecny = obecny->m_pNastepny;
	}
	plik.close();
}

void ListaPracownikow::odczytZPliku()
{
	ifstream plik("lista.txt", ios::in);
	if (!plik)
	{
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
		return;
	}
	char znak;
	while (!plik.eof())
	{
		znak = plik.get();
		if (znak == 'P')
		{
			Pracownik prac;
			plik >> prac >> std::ws;
			this->Dodaj(prac);
		}
		else if (znak == 'K')
		{
			Kierownik kto;
			plik >> kto >> std::ws;
			this->Dodaj(kto);
		}
	}
	plik.close();
}
