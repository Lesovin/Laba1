#include <iostream>
#include "Set.h"

int main()
{
    Set A;
    Set B;
    Set C;
    try
    {
        A + 1;
        A + 2;
        std::cout << A;
        B + 1;
        C = A - B;
        std::cout << C;
    }
    catch (const char* err)
    {
        std::cerr << err;
    }
    return 0;
}
