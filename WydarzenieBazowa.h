#ifndef WYDARZENIEBAZOWA_H
#define WYDARZENIEBAZOWA_H
#include <string>
#include "DataCzas.h"

class WydarzenieBazowa
{
protected:
    std::string opisWydarzenia_;
    DataCzas dataCzasRozpoczecia_;
public:
    WydarzenieBazowa();
    virtual ~WydarzenieBazowa();
    WydarzenieBazowa(const WydarzenieBazowa& refWydarzenieBazowa);
    WydarzenieBazowa& operator=(const WydarzenieBazowa& refWydarzenieBazowa);
    bool operator>(const WydarzenieBazowa& refWydarzenieBazowa) const;
    bool operator<(const WydarzenieBazowa& refWydarzenieBazowa) const;
    bool operator==(const WydarzenieBazowa& refWydarzenieBazowa) const;
    void dodajOpisWydarzenia(std::string opisWydarzenia);
    void dodajDateICzasRozpoczecia(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta);
    virtual void MetodaWirtualna() const;
    friend std::ostream& operator<<(std::ostream& os, const WydarzenieBazowa& refWydarzenieBazowa);
    friend std::ofstream& operator<<(std::ofstream& ofs, const WydarzenieBazowa& refWydarzenieBazowa);
    friend std::ifstream& operator>>(std::ifstream& ifs, WydarzenieBazowa& refWydarzenieBazowa);
};

#endif
