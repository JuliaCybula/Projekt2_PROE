#include "Menu.h"

void wyswietlMenu()
{
    std::cout<<"\t \t \t *** TERMINARZ ***"<<std::endl<<std::endl;
    std::cout<<"Wybierz dzialanie podajac liczbe od 0 do 6:"<<std::endl<<std::endl;
    std::cout<<"1.  Dodaj nowe wydarzenie do terminarza."<<std::endl;
    std::cout<<"2.  Wypisz wszystkie wydarzenia w terminarzu."<<std::endl;
    std::cout<<"3.  Usun wybrane wydarzenie z terminarza."<<std::endl;
    std::cout<<"4.  Wczytaj istniejacy terminarz."<<std::endl;
    std::cout<<"5.  Zapisz terminarz do pliku."<<std::endl;
    std::cout<<"6.  Test klasy szablonowej z typem int."<<std::endl;
    std::cout<<"7.  Test metody wirtualnej."<<std::endl;
    std::cout<<"0.  Zamknij program."<<std::endl<<std::endl;
}

void wczytajLiczbe(unsigned int& liczba)
{
    std::cin>>liczba;
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(L_IGNOROWANYCH_ZNAKOW,'\n');
        throw Wyjatki("Wprowadzona wartosc nie jest liczba!");
    }
}

void wczytajWyborUzytkownika(unsigned int& wybor)
{
    std::cout<<"Wybrane dzialanie to: ";
    wczytajLiczbe(wybor);
    if(wybor<0 || wybor>7)
    {
        std::cin.ignore(L_IGNOROWANYCH_ZNAKOW,'\n');
        throw Wyjatki("Wprowadzono wartosc spoza podanego zakresu!");
    }
}

bool menu(bool& koniec,Terminarz<WydarzeniePochodna>& pt)
{
    unsigned int wybor;
    try
    {
        wczytajWyborUzytkownika(wybor);
    }
    catch(const Wyjatki& wyjatek)
    {
        std::cout<<wyjatek;
        std::cin.get();
        wybor=DOBRY_WYBOR;
    }
    catch(std::exception& e)
    {
        std::cout<<"Wystapil wyjatek z biblioteki standardowej: "<< e.what();
        std::cin.get();
    }
    catch(...)
    {
        std::cout<<"Wystapil nieznany wyjatek! Program zakonczyl dzialanie.";
        std::cin.get();
    }
    switch(wybor)
    {
        case 1:
            std::cin.ignore();
            dodajNoweWydarzenieDoTerminarza(pt);
            break;
        case 2:
            std::cin.ignore();
            wypiszWydarzeniaZTerminarza(pt);
            std::cin.get();
            break;
        case 3:
            std::cin.ignore();
            usunWydarzenieZTerminarza(pt);
            std::cin.get();
            break;
        case 4:
            std::cin.ignore();
            wczytajTerminarzZPliku(pt);
            std::cin.get();
            break;
        case 5:
            std::cin.ignore();
            zapiszTerminarzDoPliku(pt);
            std::cin.get();
            break;
        case 6:
            std::cin.ignore();
            testKlasySzablonowejZTypemInt();
            std::cin.get();
            break;
        case 7:
            std::cin.ignore();
            testMetodyWirtualnej();
            std::cin.get();
            break;
        case 0:
            koniec=true;
            break;
        default:
            break;
    }
    return koniec;
}

void wypiszWydarzeniaZTerminarza(const Terminarz<WydarzeniePochodna>& rt)
{
    std::cout<<rt;
}

void dodajNoweWydarzenieDoTerminarza(Terminarz<WydarzeniePochodna>& rt)
{
	try
    {
        WydarzeniePochodna w1;
        std::string tempOpis;
        std::cout<<"Podaj opis wydarzenia: ";
        getline(std::cin, tempOpis);
        w1.dodajOpisWydarzenia(tempOpis);
        unsigned int tempRok;
        unsigned int tempMiesiac;
        unsigned int tempDzien;
        unsigned int tempGodzina;
        unsigned int tempMinuta;
        std::cout<<"Podaj date rozpoczecia: "<<std::endl;
        wczytajDateICzas(tempRok, tempMiesiac, tempDzien, tempGodzina, tempMinuta);
        w1.dodajDateICzasRozpoczecia(tempRok, tempMiesiac, tempDzien, tempGodzina, tempMinuta);
        std::cout<<"Podaj date zakonczenia: "<<std::endl;
        wczytajDateICzas(tempRok, tempMiesiac, tempDzien, tempGodzina, tempMinuta);
        w1.dodajDateICzasZakonczenia(tempRok, tempMiesiac, tempDzien, tempGodzina, tempMinuta);
        std::string tempLokalizacja;
        std::cout<<"Podaj lokalizacje wydarzenia: ";
        std::cin.ignore( 1000, '\n' );
        getline(std::cin, tempLokalizacja);
        w1.dodajLokalizacjeWydarzenia(tempLokalizacja);
        rt+=w1;
    }
    catch(const Wyjatki& wyjatek)
    {
        std::cout<<wyjatek<<" Wydarzenie nie zostalo utworzone. Sprobuj ponownie.";
        std::cin.get();
    }
    catch(std::exception& e)
    {
        std::cout<<"Wystapil wyjatek z biblioteki standardowej: "<< e.what();
        std::cin.get();
    }
    catch(...)
    {
        std::cout<<"Wystapil nieznany wyjatek! Program zakonczyl dzialanie.";
        std::cin.get();
    }
}

void wczytajDateICzas(unsigned int& tempRok, unsigned int& tempMiesiac, unsigned int& tempDzien, unsigned int& tempGodzina, unsigned int& tempMinuta)
{
    std::cout<<"Podaj rok: ";
    wczytajLiczbe(tempRok);
    std::cout<<"Podaj miesiac: ";
    wczytajLiczbe(tempMiesiac);
    while(tempMiesiac==0 || tempMiesiac>12)
    {
        std::cout<<"Podano bledna wartosc! \n";
        std::cout<<"Podaj miesiac: ";
        std::cin>>tempMiesiac;
    }
    std::cout<<"Podaj dzien: ";
    wczytajLiczbe(tempDzien);
    std::cout<<"Podaj godzine: ";
    wczytajLiczbe(tempGodzina);
    std::cout<<"Podaj minuty: ";
    wczytajLiczbe(tempMinuta);
}

void usunWydarzenieZTerminarza(Terminarz<WydarzeniePochodna>& rt)
{
    if(rt.pobierzLiczbeElementowWektora()==0)
    {
        std::cout<<rt;
    }
    else
    {
        unsigned int numerWydarzenia;
        std::cout<<rt;
        std::cout<<"Podaj numer wydarzenia, ktore chcesz usunac: ";
        try
        {
            wczytajLiczbe(numerWydarzenia);
            if(numerWydarzenia>0 && (int)numerWydarzenia<=rt.pobierzLiczbeElementowWektora())
            {
                rt-=numerWydarzenia;
                std::cout<<"Wydarzenie zostalo usuniete!"<<std::endl;
                std::cout<<rt;
            }
            else
            {
                std::cin.ignore(L_IGNOROWANYCH_ZNAKOW,'\n');
                throw Wyjatki("Terminarz nie posiada wydarzenia o podanym numerze!");
            }
        }
        catch(const Wyjatki& wyjatek)
        {
            std::cout<<wyjatek;
        }
        catch(std::exception& e)
        {
            std::cout<<"Wystapil wyjatek z biblioteki standardowej: "<< e.what();
            std::cin.get();
        }
        catch(...)
        {
            std::cout<<"Wystapil nieznany wyjatek! Program zakonczyl dzialanie.";
            std::cin.get();
        }
    }
}

void zapiszTerminarzDoPliku(Terminarz<WydarzeniePochodna>& rt)
{
    std::string nazwaPliku;
    std::cout<<"Podaj nazwe pliku: ";
    getline(std::cin, nazwaPliku);
    std::ofstream ofile;
    try
    {
        ofile.open(nazwaPliku+".txt");
        if(ofile.is_open())
        {
            ofile<<rt;
            std::cout<<std::endl<<"Zakonczono zapis terminarza do pliku o nazwie: "<<nazwaPliku<<".txt"<<std::endl;
            ofile.close();
        }
        if(!ofile.good())
        {
            ofile.clear();
            throw Wyjatki("Nieudany zapis do pliku!");
        }
    }
    catch(const Wyjatki& wyjatek)
    {
        std::cout<<wyjatek;
    }
    catch(std::exception& e)
    {
        std::cout<<"Wystapil wyjatek z biblioteki standardowej: "<< e.what();
        std::cin.get();
    }
    catch(...)
    {
        std::cout<<"Wystapil nieznany wyjatek! Program zakonczyl dzialanie.";
        std::cin.get();
    }
}

void wczytajTerminarzZPliku(Terminarz<WydarzeniePochodna>& rt)
{
    std::string nazwaPliku;
    std::cout<<"Podaj nazwe pliku: ";
    getline(std::cin, nazwaPliku);
    std::ifstream ifile(nazwaPliku+".txt");
    try
    {
        if(ifile.is_open())
        {
            ifile>>rt;
            std::cout<<std::endl<<"Zakonczono odczyt terminarza z pliku o nazwie: "<<nazwaPliku<<".txt"<<std::endl;
            ifile.close();
        }
        else
        {
            ifile.clear();
            throw Wyjatki("Blad odczytu z pliku o podanej nazwie!");
        }
    }
    catch(const Wyjatki& wyjatek)
    {
        std::cout<<wyjatek;
    }
    catch(std::exception& e)
    {
        std::cout<<"Wystapil wyjatek z biblioteki standardowej: "<< e.what();
        std::cin.get();
    }
    catch(...)
    {
        std::cout<<"Wystapil nieznany wyjatek! Program zakonczyl dzialanie.";
        std::cin.get();
    }
}

void testKlasySzablonowejZTypemInt()
{
    Terminarz<int> ti;
    for(int i=5; i>=-5; --i)
    {
        ti+=i;
    }
    std::cout<<std::endl;
    std::cout<<ti;
    std::cout<<"\n \t \t \t Zapis do pliku"<<std::endl;
    std::ofstream ofile;
    ofile.open("Klasa_szablonowa_z_typem_int.txt");
    ofile<<ti;
    std::cout<<std::endl<<"Zakonczono zapis do pliku o nazwie: Klasa_szablonowa_z_typem_int.txt"<<std::endl;
    ofile.close();
    std::cout<<"\n \t \t Usuwanie elementow z terminarza"<<std::endl;
    for(int i=1; i<=ti.pobierzLiczbeElementowWektora();)
    {
        ti-=i;
    }
    std::cout<<std::endl<<ti;
    std::cout<<"\n \t \t \t Odczyt z pliku"<<std::endl;
    std::ifstream ifile("Klasa_szablonowa_z_typem_int.txt");
    if(!ifile.is_open())
    {
        std::cout<<"Blad odczytu z pliku o podanej nazwie.";
    }
    else
    {
        ifile>>ti;
        std::cout<<std::endl<<"Zakonczono odczyt z pliku o nazwie: Klasa_szablonowa_z_typem_int.txt"<<std::endl;
        ifile.close();
    }
    std::cout<<std::endl<<ti;
}

void testMetodyWirtualnej()
{
    std::cout<<"\t \t \t Test metody wirtualnej\n "<<std::endl;
    WydarzeniePochodna wp;
    WydarzenieBazowa wb;
    WydarzenieBazowa* pwb=&wp;
    std::cout<<"Dla klasy pochodnej: ";
    wp.MetodaWirtualna();
    std::cout<<"Dla klasy bazowej: ";
    wb.MetodaWirtualna();
    std::cout<<"Dla wskaznika na obiekt klasy bazowej: ";
    pwb->MetodaWirtualna();
}
