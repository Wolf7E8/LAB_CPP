#include <iostream>
#include "ListaPracownikow.h"

using namespace std;

int main()
{
	int wybor;
	do
	{
		cout << "=======Menu=======\n"
			<< "1) Data \n2) Napis\n"
			<< "3) Pracownik\n4) ListaPracownikow\n"
			<< "0) Koniec" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			cout << "Testowanie Klasy Data:" << endl;
			cout << "Pierwszy obiekt:" << endl;
			Data jeden(1, 1, 1);
			cout << "Metoda Wypisz():" << endl;
			jeden.Wypisz();
			cout << "Metoda Ustaw():" << endl;
			jeden.Ustaw(10, 10, 2000);
			jeden.Wypisz();
			cout << "Drugi obiekt:" << endl;
			Data drugi(1, 1, 1);
			cout << "Metoda Wpisz():" << endl;
			drugi.Wpisz();
			cout << "Gettery:" << endl;
			cout << drugi.Dzien() << endl
				<< drugi.Miesiac() << endl
				<< drugi.Rok() << endl;
			cout << "Operator>>: " << endl;
			cin >> jeden;
			cout << "Wczytano do obiektu 'jeden'" << endl;
			cout << "Operator<<: " << jeden << endl;
			cout << "Metoda Porownaj():" << endl;
			cin >> drugi;
			cout << "Wczytano do obiektu 'drugi'" << endl;
			cout << "Wynik porownania 'jeden' z 'drugi': "
				<< jeden.Porownaj(drugi) << endl;
		}
		break;
		case 2:
		{
			cout << "Testowanie klasy Napis:" << endl;
			cout << "Pierwszy obiekt:" << endl;
			Napis jeden("pierwszy\n");
			cout << "Metoda Wypisz():" << endl;
			jeden.Wypisz();
			cout << "Drugi obiekt: " << endl;
			Napis drugi;
			cout << "Metoda Wpisz():" << endl;
			drugi.Wpisz();
			cout << "Metoda Zwroc(): " << drugi.Zwroc() << endl;
			cout << "Konstruktor kopiujacy:" << endl;
			Napis trzeci(drugi);
			cout << "Operator= : " << endl;
			jeden = drugi;
			cout << "Operator>>" << endl;
			cin >> drugi >> jeden;
			cout << "Operator<< : " << drugi << jeden << endl;
			cout << "Metoda jeden.SprawdzNapis(drugi.Zwroc()): " << jeden.SprawdzNapis(drugi.Zwroc()) << endl;
			cout << "Operator== : " << (jeden == drugi) << endl;
			break;
		}
		case 3:
		{
			cout << "Testowanie klasy Pracownik: " << endl;
			cout << "Pierwszy obiekt: " << endl;
			Pracownik jeden("Bogdan", "Staszczak", 11, 1, 1820);
			jeden.Wypisz();
			cout << "Konstrukto kopiujacy: " << endl;
			Pracownik drugi(jeden);
			drugi.Wypisz();
			cout << "Metoda Imie():" << endl;
			jeden.Imie("Jan");
			cout << "Metoda Nazwisko():" << endl;
			jeden.Nazwisko("Kowalski");
			cout << "Metoda DataUrodzenia():" << endl;
			jeden.DataUrodzenia(1, 1, 2000);
			jeden.Wypisz();
			cout << "Metoda Wpisz(): " << endl;
			jeden.Wpisz();
			cout << "Metoda Wypisz():" << endl;
			jeden.Wypisz();
			cout << "Metoda SprawdzImie(): "
				<< jeden.SprawdzImie("Jan") << endl;
			cout << "Metoda SprawdzNazwisko(): "
				<< jeden.SprawdzNazwisko("Kowalski") << endl;
			cout << "Metoda Porownaj(): " << jeden.Porownaj(drugi) << endl;
			cout << "Operator== : " << (jeden == drugi) << endl;
			cout << "Operator>> : " << endl;
			cin >> jeden;
			cout << "Operator<< : " << jeden << endl;
			cout << "Operator= : " << endl;
			drugi = jeden;
			cout << drugi << endl;
			cout << "Metoda KopiaObiektu():" << endl;
			Pracownik* trzeci = jeden.KopiaObiektu();
			cout << *trzeci << endl;
			cout << "Metoda WypiszDane():" << endl;
			trzeci->WypiszDane();
			break;
		}
		case 4:
		{
			cout << "Testowanie klasy ListaPracownikow:" << endl;
			ListaPracownikow lista;
			int wybor_4;
			do
			{
				cout << "Lista Pracownikow:\n"
					<< "1) Dodaj pracownika/kierownika\n"
					<< "2) Usun pracownika/kierownika\n"
					<< "3) Wypisz liste\n"
					<< "4) Szukaj pracownika/kierownika\n"
					<< "5) Usuniecie wszystkich z listy\n"
					<< "6) Zapis listy do pliku\n"
					<< "7) Odczyt listy z pliku\n"
					<< "0) Zakoncz\n";


				cin >> wybor_4;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (wybor_4)
				{
				case 1:
				{
					cout << "Dodawanie pracownika/kierownika-podaj dane:\n";
					cout << "Podaj P jesli to pracownik, albo K jesli to Kierownik: ";
					char znak;
					cin >> znak;
					if (znak == 'p' || znak == 'P')
					{
						Pracownik dododania;
						cin >> dododania;
						lista.Dodaj(dododania);
					}
					else if (znak == 'k' || znak == 'K')
					{
						Kierownik dododania;
						cin >> dododania;
						lista.Dodaj(dododania);
					}
					break;
				}
				case 2:
				{
					Pracownik dousuniecia;
					cout << "Usuwanie pracownika-podaj dane:\n";
					cin >> dousuniecia;
					dousuniecia.WypiszDane();
					lista.Usun(dousuniecia);
					break;
				}
				case 3:
				{
					lista.WypiszPracownikow();
					cout << endl;
					break;
				}
				case 4:
				{
					Napis imie;
					Napis nazwisko;
					cout << "Podaj imie:\n";
					cin >> imie;
					cout << "Podaj nazwisko:\n";
					cin >> nazwisko;
					const Pracownik* prac = lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
					cout << "Szukany pracownik:\n";
					if (prac != nullptr)
						prac->KopiaObiektu()->WypiszDane();
					else
						cout << "Nie znaleziono!\n"
						<< endl;
					break;
				}
				case 5:
				{
					cout << "Wyczyszczenie listy" << endl;
					lista.~ListaPracownikow();
					break;
				}
				case 6:
				{
					cout << "Zapis do pliku" << endl;
					lista.zapisDoPliku();
					break;
				}
				case 7:
				{
					cout << "Odczyt z pliku" << endl;
					lista.odczytZPliku();
					break;
				}
				default :
				{
					break;
				}
				}
			} while (wybor_4 != 0);
			break;
		}
		}
	} while (wybor != 0);
	return 0;
}