#include "ListaDL.h"

template<class T> ListaDL<T>::ListaDL()
{
   this->first = NULL;
   this->last = NULL;
}

template<class T> ListaDL<T>::~ListaDL()
{
  Nod<T>* iter = first;
  Nod<T>* aux;

  while(iter != NULL)
  {
      aux = iter;
      iter = iter->getNext();

      delete aux;
  }
}

template<class T> void ListaDL<T>::addFront(const T val)
{
  Nod<T>* novaNod = new Nod<T>(val);

  if(novaNod == NULL)
  {
      std::cout << "Overflow inserare la inceput! \n";
      return;
  }

  // testam daca s-a inserat cu succes
  bool isInserat = false;

  // lista este goala
  if (this->first == NULL && this->last == NULL)
  {
      // actualizam pointerii listei pt primul, ultimul elem.
      this->first = novaNod;
      this->last = novaNod;

      isInserat = true;
  }
  else // lista nu este goala
  {
      // legam nodul de primul nod din lista si actualizam
      // pointer-ul first
      novaNod->setNext(first);
      first->setPrev(novaNod);
      first = novaNod;

      isInserat = true;
  }

  // nu s-a inserat cu succes
  if(!isInserat)
  {
      std::cout << "Nu s-a inserat cu succes la inceputul listei! \n";
      return;
  }

  sizeList ++;
}

template<class T> void ListaDL<T>::addLast(const T val)
{
  Nod<T>* novaNod = new Nod<T>(val);

  if(novaNod == NULL)
  {
      std::cout << "Overflow inserare la inceput! \n";
      return;
  }

  // testam daca s-a inserat cu succes
  bool isInserat = false;

  // lista este goala
  if (this->first == NULL && this->last == NULL)
  {
      // actualizam pointerii listei pt primul, ultimul elem.
      this->first = novaNod;
      this->last = novaNod;

      isInserat = true;
  }
  else // lista nu este goala <=> actualizam last
  {
      this->last->setNext(novaNod);
      novaNod->setPrev(this->last);

      this->last = novaNod;

      isInserat = true;
  }

  // nu s-a inserat cu succes
  if(!isInserat)
  {
      std::cout << "Nu s-a inserat cu succes la inceputul listei! \n";
      return;
  }

  sizeList ++;
}

template<class T> void ListaDL<T>::addAfterValue(const T caut, const T val)
{
   Nod<T>* iter = this->first;

  // caut nodul cu informatia cautata in lista
  while(iter != NULL && iter->getVal() != caut)
    iter = iter->getNext();

  // nodul cu aceasta valoare nu s-a gasit in lista
  if(iter == NULL)
  {
      std::cout << "In lista nu exista nod cu aceasta valoare! \n";
      return;
  }

  // a fost gasit nodul cautat dupa valoare
  // alocam memorie pt un nou nod

  Nod<T> *novaNod = new Nod<T>(val);

  if(novaNod == NULL)
  {
      std::cout << "Overflow inserare dupa valoare data! \n";
      return;
  }

  // testam daca s-a inserat cu succes
  bool isInserat = false;

  // nodul cautat era pe ultima pozitie
  if(iter->getNext() == NULL)
  {
      this->last->setNext(novaNod);
      novaNod->setPrev(this->last);

      // acutalizez last
      this->last = novaNod;

      // inserat cu succes
      isInserat = true;
  }
  else // nodul cautat nu este pe ultima pozitie
  {
      // legam nodul de vecini

      // la stanga
      (iter->getNext())->setPrev(novaNod);
      novaNod->setNext(iter->getNext());

      // la dreapta
      iter->setNext(novaNod);
      novaNod->setPrev(iter);

      // inserat cu succes
      isInserat = true;
  }

  // nu s-a inserat cu succes
  if(!isInserat)
  {
      std::cout << "Nu s-a inserat cu succes la inceputul listei! \n";
      return;
  }

  sizeList ++;
}

template<class T> void ListaDL<T>::removeNodVal(const T val)
{
  if(this->first == NULL)
  {
      std::cout << "Underflow la stergere nod dupa valoare! \n";
      return;
  }

  // parcurgere lista
  Nod<T>* iter = first;

  while(iter != NULL && iter->getVal() != val)
    iter = iter->getNext();

  // nodul cu aceasta valoare nu s-a gasit in lista
  if(iter == NULL)
  {
      std::cout << "In lista nu exista nod cu aceasta valoare! \n";
      return;
  }

  // nodul s-a gasit si il eliminam
  // prin copierea informatiei din nodul urmator pe pozitia celui
  // sters si eliminand succesorul

  if (iter == first)
  {
      this->first->setPrev(iter);
      iter->setNext(this->first);

      this->first = iter;
      sizeList --;
      return;
  }

  if (iter == last)
  {
      Nod<T>* aux = this->last;
      this->last = this->last->getPrev();
      this->last->setNext(NULL);

      delete aux;
      sizeList --;
      return;
  }

  // nodul nu este nici primul, nici ultimul
  Nod<T>* aux = iter->getNext();

  iter->setVal(iter->getNext()->getVal());
  iter->setNext(iter->getNext()->getNext());

  delete aux;

  sizeList --;
}

template<class T> void ListaDL<T>::removeNodPoz(int poz)
{
  if(this->first == NULL)
  {
      std::cout << "Underflow la stergere nod dupa valoare! \n";
      return;
  }

  if(poz == 1)
  {
      Nod<T>* aux = first;
      first = first->getNext();
      delete aux;
      sizeList --;

      return;
  }

  // numarare pozitie
  int nr = 1;

  Nod<T>* iter = this->first;

  while(iter != NULL && nr < poz-1)
  {
        iter = iter->getNext();
        nr++;
  }

  if(iter == NULL)
  {
      std::cout << "In lista nu exista nod cu aceasta pozitie! \n";
      return;
  }

  Nod<T>* aux = iter->getNext();;

  iter->getNext()->getNext()->setPrev(iter);
  iter->setNext(iter->getNext()->getNext());

  delete aux;

  sizeList --;
}

template<class T> void ListaDL<T>::modifyPoz(int poz, const T val)
{
    int pozCurr = 1;
    Nod<T>* iter = this->first;

    while(iter != NULL && pozCurr < poz)
    {
        iter = iter->getNext();
        pozCurr ++;
    }

    if(iter == NULL)
    {
        std::cout << "Aceasta pozitie nu exista in lista!" << std::endl;
        return;
    }

    iter->setVal(val);
}

template<class T> void ListaDL<T>::modifyVal(const T caut, const T val)
{
    Nod<T>* iter = this->first;

    while(iter != NULL && iter->getVal() != caut)
        iter = iter->getNext();

    if(iter == NULL)
    {
        std::cout << "Aceasta valoare nu exista in lista!" << std::endl;
        return;
    }

    iter->setVal(val);
}

template<class T> void ListaDL<T>::modifyAllVal(const T caut, const T val)
{
    // verific daca s-a modificat macar un element
    bool modificare = false;

    Nod<T>* iter = this->first;

    while(iter != NULL)
    {
        if(iter->getVal() == caut)
        {
            iter->setVal(val);
            modificare = true;
        }

        iter = iter->getNext();
    }

    if(!modificare)
        std::cout << "Lista nu a fost modificata prin schimbarea elementelor cu informatia "
        << caut << " !" << std::endl;
}

template<class T> void ListaDL<T>::afisare()
{
    Nod<T>* iter = first;

    while(iter != NULL)
    {
      std::cout << iter->getVal() << " ";
      iter = iter->getNext();
    }

    std::cout << std::endl;
}

template<> void ListaDL<Sir>::afisare()
{
   Nod<Sir>* iter = first;
   int contorCuv = 1;

    while(iter != NULL)
    {
      std::cout << iter->getVal() << " ";
      iter = iter->getNext();

      if(contorCuv++ > 11)
      {
          std::cout << std::endl;
          contorCuv = 1;
      }
    }

    std::cout << std::endl;
}

template<class T> void ListaDL<T>::afisareInversat()
{
    Nod<T>* iter = this->last;

    while(iter != NULL)
    {
      std::cout << iter->getVal() << " ";
      iter = iter->getPrev();
    }

    std::cout << std::endl;
}

template<> void ListaDL<Sir>::afisareInversat()
{
    Nod<Sir>* iter = this->last;
    int contorCuv = 1;

    while(iter != NULL)
    {
      std::cout << iter->getVal() << " ";
      iter = iter->getPrev();

      if(contorCuv++ > 11)
      {
          std::cout << std::endl;
          contorCuv = 1;
      }
    }

    std::cout << std::endl;
}

template <class T> int ListaDL<T>::getSize()
{
    return sizeList;
}

template <class T> void ListaDL<T>::save(char* nume)
{
    int contorCuv = 1;
    std::fstream out (nume);

    Nod<T>* iter = this->first;

    while(iter != NULL)
    {
        out << iter->getVal() << " ";
        iter = iter->getNext();

        // limitarea numarului de elemente de pe un rand
        // la 11
        contorCuv ++;
        if(contorCuv > 11)
        {
            out << std::endl;
            contorCuv = 1;
        }
    }

    out.close();
}

template <class T> void ListaDL<T>::read(char* nume)
{
    std::fstream in (nume);
    T val;

    while(in.peek() != EOF)
    {
        in >> val;
        this->addLast(val);
        this->sizeList ++;
    }

    in.close();
}

// specializare pentru Sir - mai aparea un caracter special
// in lista
template<> void ListaDL<Sir>::read(char* nume)
{
    std::fstream in (nume);
    Sir val;

    while(in.peek() != EOF)
    {
        in >> val;
        this->addLast(val);
        this->sizeList ++;
    }

    in.close();
    this->removeNodVal(val);
}
