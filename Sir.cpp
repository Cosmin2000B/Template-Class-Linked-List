#include "Sir.h"


Sir::Sir()
{
    this->head = NULL;
}

Sir::Sir(const char* val)
{
   this->head = new char[strlen(val) + 1];
   strcpy(this->head, val);
}

Sir::Sir(const Sir& sir)
{
   this->head = new char[strlen(sir.head) + 1];
   strcpy(this->head, sir.head);
}

Sir& Sir::operator = (const Sir& sir)
{
    if(this->head != NULL)
        delete []this->head;

    this->head = new char[strlen(sir.head) + 1];
    strcpy(this->head, sir.head);

    return *this;
}

bool Sir::operator != (const Sir& sir)
{
    if(strcmp(this->head, sir.head) != 0)
        return true;
    return false;
}

bool Sir::operator == (const Sir& sir)
{
    if(!strcmp(this->head, sir.head))
        return true;
    return false;
}

Sir::~Sir()
{
  delete []this->head;
}

std::ostream& operator << (std::ostream& out, const Sir& sir)
{
    out << sir.head;
    return out;
}

std::istream& operator >> (std::istream& in, Sir& sir)
{
    char buffer[50];
    in >> buffer;

    sir.head = new char[strlen(buffer) + 1];
    strcpy(sir.head, buffer);

    return in;
}
