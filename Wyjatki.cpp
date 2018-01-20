#include "Wyjatki.h"

Wyjatki::Wyjatki(std::string komunikat_bledu) : komunikat_(komunikat_bledu) {}

std::ostream& operator<<(std::ostream& os, const Wyjatki& wyjatek)
{
    os<< wyjatek.komunikat_;
    return os;
}
