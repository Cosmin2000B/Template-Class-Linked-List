#pragma once

#include <iostream>
#include "Sir.h"

template <class T>
class Nod
{
    // automat private

    T val;
    Nod* prev;
    Nod* next;

public:

    Nod<T>(const T &val);

    // setters & getters

    // pentru T val

    T getVal();
    void setVal(const T val);

    // pentru Nod* prev

    Nod<T>* getPrev();
    void setPrev(Nod<T>* prev);

    // pentru Nod* next

    Nod<T>* getNext();
    void setNext(Nod<T>* next);
};

template class Nod <int>;
template class Nod <double>;
template class Nod <Sir>;
