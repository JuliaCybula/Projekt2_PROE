#include "DataCzas.h"

const std::string DataCzas::nazwyMiesiecy_[] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};

DataCzas::DataCzas() : rok_(0), miesiac_(Styczen), dzien_(0), godzina_(0), minuta_(0) {}

DataCzas::DataCzas(unsigned int rok, Miesiac miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta) : rok_(rok), miesiac_(miesiac), dzien_(dzien), godzina_(godzina), minuta_(minuta) {}

DataCzas DataCzas::operator+(const DataCzas& refDataCzas) const
{
    DataCzas suma;
    suma.minuta_=(minuta_+refDataCzas.minuta_)%min_w_h;
    suma.godzina_=(godzina_+refDataCzas.godzina_+(minuta_+refDataCzas.minuta_)/min_w_h)%h_w_dniu;
    return suma;
}

DataCzas DataCzas::operator+(unsigned int minuty) const
{
    DataCzas suma;
    suma.minuta_=(minuta_+minuty)%min_w_h;
    suma.godzina_=(godzina_+(minuta_+minuty)/min_w_h)%h_w_dniu;
    return suma;
}

DataCzas operator+(unsigned int minuty, const DataCzas& refDataCzas)
{
    return refDataCzas+minuty;
}

bool DataCzas::operator==(const DataCzas& refDataCzas) const
{
    return (rok_==refDataCzas.rok_)&& (miesiac_==refDataCzas.miesiac_) && (dzien_==refDataCzas.dzien_) && (godzina_==refDataCzas.godzina_)&&(minuta_==refDataCzas.minuta_);
}

bool DataCzas::operator>(const DataCzas& refDataCzas) const
{
    if(*this==refDataCzas)
    {
        return false;
    }
    if(rok_>refDataCzas.rok_)
    {
        return true;
    }
    else if(rok_<refDataCzas.rok_)
    {
        return false;
    }
    else
    {
        if((int)miesiac_>(int)refDataCzas.miesiac_)
        {
            return true;
        }
        else if((int)miesiac_<(int)refDataCzas.miesiac_)
        {
            return false;
        }
        else
        {
            if(dzien_>refDataCzas.dzien_)
            {
                return true;
            }
            else if(dzien_<refDataCzas.dzien_)
            {
                return false;
            }
            else
            {
                if(godzina_>refDataCzas.godzina_)
                {
                    return true;
                }
                else if(godzina_<refDataCzas.godzina_)
                {
                    return false;
                }
                else
                {
                    if(minuta_>refDataCzas.minuta_)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
}

bool DataCzas::operator<(const DataCzas& refDataCzas) const
{
    if(!(*this==refDataCzas || *this>refDataCzas))
    {
        return true;
    }
    else
        return false;
}

void DataCzas::ustawDateICzas(unsigned int rok, unsigned int miesiac, unsigned int dzien, unsigned int godzina, unsigned int minuta)
{
    minuta_= minuta%min_w_h;
    godzina_=(godzina+minuta/min_w_h)%h_w_dniu;
    dzien_=dzien+(godzina+minuta/min_w_h)/h_w_dniu;
    miesiac_=(Miesiac)miesiac;
    rok_=rok;
}

std::ostream& operator<<(std::ostream& os, const DataCzas& refDataCzas)
{
    os<<"Data:\t\t\t"<<refDataCzas.dzien_<<" "<<refDataCzas.nazwyMiesiecy_[refDataCzas.miesiac_-1]<<" "<<refDataCzas.rok_<<std::endl;
    os<<"Czas:\t\t\t"<<refDataCzas.godzina_<<":";
    if(refDataCzas.minuta_>=0 && refDataCzas.minuta_<=9)
    {
        std::cout<<0<<refDataCzas.minuta_<<std::endl;
    }
    else
    {
        std::cout<<refDataCzas.minuta_<<std::endl;
    }

    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const DataCzas& refDataCzas)
{
    ofs<<refDataCzas.dzien_<<std::endl;
    ofs<<refDataCzas.miesiac_<<std::endl;
    ofs<<refDataCzas.rok_<<std::endl;
    ofs<<refDataCzas.godzina_<<std::endl;
    ofs<<refDataCzas.minuta_<<std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, DataCzas& refDataCzas)
{
    unsigned int tempDzien;
    unsigned int tempMiesiac;
    unsigned int tempRok;
    unsigned int tempGodzina;
    unsigned int tempMinuta;
    ifs>>tempDzien;
    ifs>>tempMiesiac;
    ifs>>tempRok;
    ifs>>tempGodzina;
    ifs>>tempMinuta;
    refDataCzas.ustawDateICzas(tempRok,tempMiesiac,tempDzien,tempGodzina,tempMinuta);
    return ifs;
}
