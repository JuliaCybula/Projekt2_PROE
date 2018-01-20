#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "Terminarz.h"
#include "WydarzeniePochodna.h"
#include "Wyjatki.h"
#define DOBRY_WYBOR 10
#define L_IGNOROWANYCH_ZNAKOW 1000

void wyswietlMenu();
void wczytajLiczbe(unsigned int& liczba);
void wczytajWyborUzytkownika(unsigned int& wybor);
bool menu(bool& koniec,Terminarz<WydarzeniePochodna>& pt);
void wypiszWydarzeniaZTerminarza(const Terminarz<WydarzeniePochodna>& rt);
void dodajNoweWydarzenieDoTerminarza(Terminarz<WydarzeniePochodna>& rt);
void usunWydarzenieZTerminarza(Terminarz<WydarzeniePochodna>& rt);
void zapiszTerminarzDoPliku(Terminarz<WydarzeniePochodna>& rt);
void wczytajTerminarzZPliku(Terminarz<WydarzeniePochodna>& rt);
void wczytajDateICzas(unsigned int& tempRok, unsigned int& tempMiesiac, unsigned int& tempDzien, unsigned int& tempGodzina, unsigned int& tempMinuta);
void testKlasySzablonowejZTypemInt();
void testMetodyWirtualnej();

#endif
