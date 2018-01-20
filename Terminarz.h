#ifndef TERMINARZ_H
#define TERMINARZ_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

template <typename T>
class Terminarz{
private:
    std::vector<T> terminarz_;
public:
    Terminarz();
    Terminarz& operator+=(const T& referencjaDoObiektuTypuT);
    Terminarz& operator-=(unsigned int numerElementuDoUsuniecia);
    int pobierzLiczbeElementowWektora() const;
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Terminarz<U>& refTerminarz);
    template<typename U>
    friend std::ofstream& operator<<(std::ofstream& ofs, const Terminarz<U>& refTerminarz);
    template<typename U>
    friend std::ifstream& operator>>(std::ifstream& ifs, Terminarz<U>& refTerminarz);
};

template <typename T>
Terminarz<T>::Terminarz():terminarz_(){}

template <typename T>
Terminarz<T>& Terminarz<T>::operator+=(const T& referencjaDoObiektuTypuT)
{

    if(terminarz_.size()==0 || find(terminarz_.begin(),terminarz_.end(),referencjaDoObiektuTypuT)==terminarz_.end())
    {
        terminarz_.push_back(referencjaDoObiektuTypuT);
        std::sort(terminarz_.begin(),terminarz_.end());
    }
    return *this;
}

template <typename T>
Terminarz<T>& Terminarz<T>::operator-=(unsigned int numerElementuDoUsuniecia)
{
    if(!terminarz_.empty())
    {
        terminarz_.erase(terminarz_.begin()+(numerElementuDoUsuniecia-1));
    }
    return *this;
}

template <typename T>
int Terminarz<T>::pobierzLiczbeElementowWektora() const
{
    return terminarz_.size();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Terminarz<T>& refTerminarz)
{
    if(!refTerminarz.terminarz_.empty())
    {
        os<<"Terminarz posiada nastepujace wydarzenia: "<<std::endl;
        for(int i=0; i<(int)refTerminarz.terminarz_.size(); ++i)
        {
            os<<"Wydarzenie " << i+1<<": "<<std::endl;
            os<<refTerminarz.terminarz_[i]<<std::endl;
        }
    } else os<<"Brak wydarzen w terminarzu."<<std::endl;
    return os;
}

template <typename T>
std::ofstream& operator<<(std::ofstream& ofs, const Terminarz<T>& refTerminarz)
{
    if(refTerminarz.pobierzLiczbeElementowWektora()>0)
    {
        ofs<<refTerminarz.pobierzLiczbeElementowWektora()<<std::endl;
        for(int i=0; i<refTerminarz.pobierzLiczbeElementowWektora(); ++i)
        {
            ofs<<refTerminarz.terminarz_[i]<<std::endl;
        }
    } else std::cout<<"Brak wydarzen w terminarzu."<<std::endl;
    return ofs;
}

template <typename T>
std::ifstream& operator>>(std::ifstream& ifs, Terminarz<T>& refTerminarz)
{
    unsigned int tempLicznik;
    ifs>>tempLicznik;
    ifs.get();
    T tempObiektTypuT;
    for(int i=0; i<(int)tempLicznik; ++i)
    {
        ifs>>tempObiektTypuT;
        refTerminarz+=tempObiektTypuT;
    }
    return ifs;
}

#endif
