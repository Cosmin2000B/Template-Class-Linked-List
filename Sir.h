#pragma once

#include <iostream>
#include <string.h>

class Sir
{
    char* head;

    friend std::ostream& operator << (std::ostream& out, const Sir& sir);
    friend std::istream& operator >> (std::istream& in, Sir& sir);

public:
    Sir();
    Sir(const char* val);
    Sir(const Sir& sir);

    Sir& operator = (const Sir& sir);
    bool operator != (const Sir& sir);
    bool operator == (const Sir& sir);

    ~Sir();

};
