#include <iostream>
#include <fstream>

#include "Nod.h"
#include "Sir.h"

template <class T>
class ListaDL
{
    // primul nod din lista
    Nod<T>* first;
    // ultimul nod din lista
    Nod<T>* last;

    // marimea listei
    int sizeList = 0;

public:
    // constructor fara argumente
    ListaDL();

    // destructor
    ~ListaDL();

    // inserare la inceput
    void addFront(const T val);
    //inserare la sfarsit
    void addLast(const T val);
    // inserare dupa un nod cu o anumita valoare 'caut'
    // a valorii 'val' data de utilizator
    void addAfterValue(const T caut, const T val);

    // stergere dupa valoare
    void removeNodVal(const T val);
    // stergere dupa pozitie
    void removeNodPoz(int poz);

    // modificam nodul de pe pozitia poz
    // (ii punem valoare val)
    void modifyPoz(int poz, const T val);

    // modificam nodul cu valoarea caut
    // (ii punem valoarea val) (doar prima aparitie
    // a valorii caut)
    void modifyVal(const T caut, const T val);

    // modificam  toate nodurile cu valoarea caut
    // (le punem valoarea val)
    void modifyAllVal(const T caut, const T val);

    // afisarea listei
    void afisare();

    // afisarea listei inversate
    // (parcurgere inversa)
    void afisareInversat();

    // returneaza nr de elemente aflate in lista
    int getSize();

    // salveaza lista curenta intr-un fisier dat
    void save(char* nume);

    // citeste o lista dintr-un fisier dat
    void read(char* name);

};

template class ListaDL <int>;
template class ListaDL <double>;
template class ListaDL <Sir>;
