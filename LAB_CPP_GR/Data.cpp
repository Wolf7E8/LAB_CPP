#include "Data.h"
#include <iomanip>


void Data::Ustaw(int d, int m, int r)
{
    m_nDzien = d;
    m_nMiesiac = m;
    m_nRok = r;
    Koryguj();
}

int Data::Dzien() const
{
    return m_nDzien;
}

int Data::Miesiac() const
{
    return m_nMiesiac;
}

int Data::Rok() const
{
    return m_nRok;
}

void Data::Wypisz() const
{
    cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;
}

void Data::Wpisz()
{
    cout << "Podaj dzien: ";
    cin >> m_nDzien;
    cout << "Podaj miesiac: ";
    cin >> m_nMiesiac;
    cout << "Podaj rok: ";
    cin >> m_nRok;

    Koryguj();
}

void Data::Koryguj()
{
    if (m_nDzien <= 0)
    {
        m_nDzien = 1;
    }

    if (m_nMiesiac == 1 || m_nDzien == 3 || m_nDzien == 5 || m_nDzien == 7 || m_nDzien == 8 || m_nDzien == 12)
    {
        if (m_nDzien > 31)
        {
            m_nDzien = 31;
        }
    }
    else if (m_nMiesiac == 2)
    {
        if ((m_nRok % 4) == 0)
        {
            if (m_nDzien > 29) { m_nDzien = 29; }
        }
        else
        {
            if (m_nDzien > 28) { m_nDzien = 28; }
        }

    }
    else
    {
        if (m_nDzien > 30)
        {
            m_nDzien = 30;
        }
    }

}

int Data::Porownaj(const Data& wzor) const
{
    if ((m_nDzien == wzor.m_nDzien) && (m_nMiesiac == wzor.m_nMiesiac) && (m_nRok == wzor.m_nRok))
    {
        return 0;
    }

    if (m_nRok < wzor.m_nRok) {
        return 1;
    }
    else if (m_nRok > wzor.m_nRok) {
        return -1;
    }
    else if (m_nMiesiac < wzor.m_nMiesiac) {
        return 1;
    }
    else if (m_nMiesiac > wzor.m_nMiesiac) {
        return -1;
    }
    else if (m_nDzien < wzor.m_nDzien) {
        return 1;
    }
    else if (m_nDzien > wzor.m_nDzien) {
        return -1;
    }
    else return -1;
}

Data::Data(int d, int m, int r)
{
    m_nDzien = d;
    m_nMiesiac = m;
    m_nRok = r;
    Koryguj();
}

ostream& operator<<(ostream& wy, const Data& d)
{
    return wy << std::setw(2) << std::right << d.Dzien() << "-" << d.Miesiac() << "-" << d.Rok();
}

istream& operator>>(istream& we, Data& d)
{
    char pauza;
    if (&we == &cin)
    {
        cout << "Podaj dzien: ";
    }
    we >> d.m_nDzien;
    if (&we != &cin)
    {
        we >> pauza;
    }
    if (&we == &cin)
    {
        cout << "Podaj miesiac: ";
    }
    we >> d.m_nMiesiac;
    if (&we != &cin)
    {
        we >> pauza;
    }
    if (&we == &cin)
    {
        cout << "Podaj rok: ";
    }
    we >> d.m_nRok;
    d.Koryguj();
    return we;
}
