#include <iostream>
#include "WydarzeniePochodna.h"

WydarzeniePochodna::WydarzeniePochodna(): lokalizacjaWydarzenia_("Brak lokalizacji"){}

WydarzeniePochodna::WydarzeniePochodna(const WydarzeniePochodna& refWydarzeniePochodna) : WydarzenieBazowa(refWydarzeniePochodna)
{
    lokalizacjaWydarzenia_=refWydarzeniePochodna.lokalizacjaWydarzenia_;
    dataCzasZakonczenia_=refWydarzeniePochodna.dataCzasZakonczenia_;
}

WydarzeniePochodna::~WydarzeniePochodna(){}

WydarzeniePochodna& WydarzeniePochodna::operator=(const WydarzeniePochodna& refWydarzeniePochodna)
{
    static_cast<WydarzenieBazowa&>(*this)=refWydarzeniePochodna;
    lokalizacjaWydarzenia_=refWydarzeniePochodna.lokalizacjaWydarzenia_;
    dataCzasZakonczenia_=refWydarzeniePochodna.dataCzasZakonczenia_;
    return *this;
}

void WydarzeniePochodna::dodajLokalizacjeWydarzenia(std::string lokalizacjaWydarzenia)
{
    lokalizacjaWydarzenia_=lokalizacjaWydarzenia;
}

void WydarzeniePochodna::dodajDateICzasZakonczenia(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta)
{
    dataCzasZakonczenia_.ustawDateICzas(rok, miesiac, dzien, godzina, minuta);
}

bool WydarzeniePochodna::operator==(const WydarzeniePochodna& refWydarzeniePochodna) const
{
    return dataCzasRozpoczecia_==refWydarzeniePochodna.dataCzasRozpoczecia_ && opisWydarzenia_==refWydarzeniePochodna.opisWydarzenia_ && dataCzasZakonczenia_==refWydarzeniePochodna.dataCzasZakonczenia_ && lokalizacjaWydarzenia_==refWydarzeniePochodna.lokalizacjaWydarzenia_;
}

void WydarzeniePochodna::MetodaWirtualna() const
{
    std::cout<<"Metoda klasy pochodnej."<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const WydarzeniePochodna& refWydarzeniePochodna)
{
    os<< static_cast<const WydarzenieBazowa&> (refWydarzeniePochodna);
    os<< "Koniec: " <<std::endl;
    os<< refWydarzeniePochodna.dataCzasZakonczenia_;
    os<< "Lokalizacja: \t\t" << refWydarzeniePochodna.lokalizacjaWydarzenia_ << std::endl;
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const WydarzeniePochodna& refWydarzeniePochodna)
{
    ofs<<static_cast<const WydarzenieBazowa&> (refWydarzeniePochodna);
    ofs<<refWydarzeniePochodna.dataCzasZakonczenia_;
    ofs<<refWydarzeniePochodna.lokalizacjaWydarzenia_<<std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, WydarzeniePochodna& refWydarzeniePochodna)
{
    ifs>>static_cast<WydarzenieBazowa&> (refWydarzeniePochodna);
    ifs>>refWydarzeniePochodna.dataCzasZakonczenia_;
    ifs.get();
    std::string tempLokalizacjaWydarzenia;
    getline(ifs,tempLokalizacjaWydarzenia);
    refWydarzeniePochodna.dodajLokalizacjeWydarzenia(tempLokalizacjaWydarzenia);
    ifs.get();
    return ifs;
}
