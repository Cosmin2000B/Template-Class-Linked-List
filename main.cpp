#include <iostream>

#include "Sir.h"
#include "ListaDL.h"

/*
   Metode ale liste dublu inlanuite:

    void addFront(const T val);  -inserare la inceputyl listei a valorii val

    void addLast(const T val);   -inserare la sfarsitul listei a valorii val

    void addAfterValue(const T caut, const T val); -inserare dupa un nod cu o
    anumita valoare 'caut' a valorii 'val' data de utilizator

    void removeNodVal(const T val); -stergerea din lista a primei aparitii a valorii
    val (data de utilizator)

    void removeNodPoz(int poz); -stergerea nodului aflat pe pozitia cu numarul poz

    void modifyPoz(int poz, const T val); -modificam nodul de pe pozitia poz, punandu-i
    valoarea val (data de utilizator)

    void modifyVal(const T caut, const T val); -modificam primul nod cu valoarea caut
    (ii punem valoarea val data de utilizator)

    void modifyAllVal(const T caut, const T val); -modificam  toate nodurile cu valoarea
     caut (le punem valoarea val)

    void afisare(); -afisarea listei in consola

    void afisareInversat(); -afisarea listei inversate (parcurgere inversa) in consola

    int getSize(); -returneaza nr de elemente aflate in lista

    void save(char* nume); -salveaza lista curenta intr-un fisier dat prin nume

    void read(char* name); -citeste o lista dintr-un fisier dat prin nume

    Tipuri de date suportate: int,float,Sir.
*/

int main()
{
  ListaDL<Sir> text;
  text.read("text.in");
  text.modifyAllVal("si","and");
  text.modifyVal("Humulesti,","Tenerife,");
  text.removeNodPoz(5);
  text.removeNodVal("bucurie!");
  text.addLast("frica");
  text.addFront("Cred");
  text.addAfterValue("Cred","ca");
  text.modifyAllVal("sfara", "sfoara");
  text.save("text.out");
  text.afisareInversat();

  std::cout << std::endl;

  ListaDL<int>x;
  x.read("informatie");
  x.addFront(20);
  x.addLast(4);
  x.addLast(1);
  x.modifyAllVal(1, 99);
  x.modifyPoz(2,999);
  x.removeNodPoz(5);
  x.afisare();
  x.afisareInversat();
}
