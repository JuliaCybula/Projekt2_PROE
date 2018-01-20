#ifndef WYDARZENIEPOCHODNA_H
#define WYDARZENIEPOCHODNA_H
#include "WydarzenieBazowa.h"

class WydarzeniePochodna : public WydarzenieBazowa
{
private:
    std::string lokalizacjaWydarzenia_;
    DataCzas dataCzasZakonczenia_;
public:
    WydarzeniePochodna();
    ~WydarzeniePochodna();
    WydarzeniePochodna(const WydarzeniePochodna& refWydarzeniePochodna);
    WydarzeniePochodna& operator=(const WydarzeniePochodna& refWydarzeniePochodna);
    void dodajLokalizacjeWydarzenia(std::string lokalizacjaWydarzenia);
    void dodajDateICzasZakonczenia(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta);
    bool operator==(const WydarzeniePochodna& refWydarzeniePochodna) const;
    void MetodaWirtualna() const override;
    friend std::ostream& operator<<(std::ostream& os, const WydarzeniePochodna& refWydarzeniePochodna);
    friend std::ofstream& operator<<(std::ofstream& ofs, const WydarzeniePochodna& refWydarzeniePochodna);
    friend std::ifstream& operator>>(std::ifstream& ifs, WydarzeniePochodna& refWydarzeniePochodna);
};

#endif
