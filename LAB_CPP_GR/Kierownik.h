#pragma once
#include "Pracownik.h"
class Kierownik :
    public Pracownik
{
private:
    Napis m_NazwaDzialu;
    int m_nliczbaPracownikow;
public:
    Kierownik(const char* im = "", const char* naz = "",
        int dzien = 1, int miesi¹c = 1, int rok = 2000,
        Napis nazwaDzialu = "nie podano", int lPracownikow = 0);
    Kierownik(const Kierownik& wzor);
    Kierownik& operator=(const Kierownik& wzor);
    bool operator==(const Kierownik& wzor) const;
    virtual void WypiszDane();
    virtual Pracownik* KopiaObiektu() const;
    friend ostream& operator<<(ostream& wy, Kierownik& s);
    friend istream& operator>>(istream& we, Kierownik& s);
};

ostream& operator<<(ostream& wy, Kierownik& s);
istream& operator>>(istream& we, Kierownik& s);

