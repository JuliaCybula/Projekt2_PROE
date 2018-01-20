#ifndef DATACZAS_H
#define DATACZAS_H

#include <iostream>
#include <fstream>

class DataCzas
{
private:
    static const unsigned int mies_w_roku=12;
    static const unsigned int min_w_h=60;
    static const unsigned int h_w_dniu=24;
    unsigned int rok_;
    enum Miesiac{Styczen=1, Luty, Marzec, Kwiecien, Maj, Czerwiec, Lipiec, Sierpien, Wrzesien, Pazdziernik, Listopad, Grudzien} miesiac_;
    const static std::string nazwyMiesiecy_[mies_w_roku];
    unsigned int dzien_;
    unsigned int godzina_;
    unsigned int minuta_;
public:
    DataCzas();
    DataCzas(unsigned int rok, Miesiac miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta);
    bool operator==(const DataCzas& refDataCzas) const;
    bool operator>(const DataCzas& refDataCzas) const;
    bool operator<(const DataCzas& refDataCzas) const;
    DataCzas operator+(const DataCzas& refDataCzas) const;
    DataCzas operator+(unsigned int minuty) const;
    void ustawDateICzas(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta);
    friend DataCzas operator+(unsigned int minuty, const DataCzas& refDataCzas);
    friend std::ostream& operator<<(std::ostream& os, const DataCzas& refDataCzas);
    friend std::ofstream& operator<<(std::ofstream& ofs, const DataCzas& refDataCzas);
    friend std::ifstream& operator>>(std::ifstream& ifs, DataCzas& refDataCzas);
};

#endif
