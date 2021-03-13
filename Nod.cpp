#include "Nod.h"


template<class T> Nod<T>::Nod(const T &val)
{
    this->val = val;
    this->prev = NULL;
    this->next = NULL;
}

template<class T> T Nod<T>::getVal()
{
    return this->val;
}

template<class T> void Nod<T>::setVal(const T val)
{
    this->val = val;
}

template<class T> Nod<T>* Nod<T>::getPrev()
{
    return this->prev;
}

template<class T> void Nod<T>::setPrev(Nod<T>* prev)
{
    this->prev = prev;
}

template<class T> Nod<T>* Nod<T>::getNext()
{
    return this->next;
}

template<class T> void Nod<T>::setNext(Nod<T>* next)
{
    this->next = next;
}
