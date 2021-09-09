#include <iostream>
#include "Set.h"

int main()
{
    std::cout << "Hello World\n";
    Set A;
    A + 1;
    std::cout<<A[0];
    try
    {
        A + 2;
        A + 3;
        A + 4;
        std::cout << A;
        A - 2;
        A - 3;
       std::cout<<A;
    }
    catch (const char* err)
    {
        std::cerr << err;
    }
    return 0;
}
