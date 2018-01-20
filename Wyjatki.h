#ifndef WYJATKI_H
#define WYJATKI_H
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

class Wyjatki : public std::exception
{
private:
    std::string komunikat_;
public:
    Wyjatki(std::string komunikat_bledu);
    friend std::ostream& operator<<(std::ostream& os, const Wyjatki& wyjatek);
};



#endif
