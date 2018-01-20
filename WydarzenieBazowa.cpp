#include <iostream>
#include "WydarzenieBazowa.h"

WydarzenieBazowa::WydarzenieBazowa():opisWydarzenia_("Brak opisu"){}

WydarzenieBazowa::WydarzenieBazowa(const WydarzenieBazowa& refWydarzenieBazowa)
{
    opisWydarzenia_=refWydarzenieBazowa.opisWydarzenia_;
    dataCzasRozpoczecia_=refWydarzenieBazowa.dataCzasRozpoczecia_;
}

WydarzenieBazowa::~WydarzenieBazowa(){}

WydarzenieBazowa& WydarzenieBazowa::operator=(const WydarzenieBazowa& refWydarzenieBazowa)
{
    opisWydarzenia_=refWydarzenieBazowa.opisWydarzenia_;
    dataCzasRozpoczecia_=refWydarzenieBazowa.dataCzasRozpoczecia_;
    return *this;
}

bool WydarzenieBazowa::operator>(const WydarzenieBazowa& refWydarzenieBazowa) const
{
    return dataCzasRozpoczecia_>refWydarzenieBazowa.dataCzasRozpoczecia_;
}

bool WydarzenieBazowa::operator<(const WydarzenieBazowa& refWydarzenieBazowa) const
{
    return dataCzasRozpoczecia_<refWydarzenieBazowa.dataCzasRozpoczecia_;
}

bool WydarzenieBazowa::operator==(const WydarzenieBazowa& refWydarzenieBazowa) const
{
    return dataCzasRozpoczecia_==refWydarzenieBazowa.dataCzasRozpoczecia_ && opisWydarzenia_==refWydarzenieBazowa.opisWydarzenia_;
}

void WydarzenieBazowa::dodajOpisWydarzenia(std::string opisWydarzenia)
{
    opisWydarzenia_=opisWydarzenia;
}

void WydarzenieBazowa::dodajDateICzasRozpoczecia(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta)
{
    dataCzasRozpoczecia_.ustawDateICzas(rok, miesiac, dzien, godzina, minuta);
}

void WydarzenieBazowa::MetodaWirtualna() const
{
    std::cout<<"Metoda wirtualna klasy bazowej."<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const WydarzenieBazowa& refWydarzenieBazowa)
{
    os<< "Opis wydarzenia: \t" << refWydarzenieBazowa.opisWydarzenia_ << std::endl;
    os<< "Poczatek: " <<std::endl;
    os<< refWydarzenieBazowa.dataCzasRozpoczecia_;
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const WydarzenieBazowa& refWydarzenieBazowa)
{
    ofs<<refWydarzenieBazowa.opisWydarzenia_;
    ofs<<refWydarzenieBazowa.dataCzasRozpoczecia_;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, WydarzenieBazowa& refWydarzenieBazowa)
{
    std::string tempOpisWydarzenia;
    getline(ifs,tempOpisWydarzenia);
    refWydarzenieBazowa.dodajOpisWydarzenia(tempOpisWydarzenia);
    ifs>>refWydarzenieBazowa.dataCzasRozpoczecia_;
    ifs.get();
    return ifs;
}
