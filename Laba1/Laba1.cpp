#include <iostream>
#include <conio.h>
#include "Set.h"

bool InputControl()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Enter the integer number!" << "\n";
        system("pause");
        return false;
    }
    return true;
}

int main()
{
    Set A;
    Set B;
    Set C;
    int Menu;
    int Number;
    std::cout << "Test of new branch"<<"\n";
    system("pause");
    for(;;)
    {
        system("cls");
        std::cout << "1.Get a number by index"<<"\n";
        std::cout << "2.Combining sets" << "\n";
        std::cout << "3.Difference of sets" << "\n";
        std::cout << "4.Add a number" << "\n";
        std::cout << "5.Delete a number" << "\n";
        std::cout << "6.Intersection of sets" << "\n";
        std::cout << "Esc.Exit" << "\n";
        std::cout << "First set:" << A << "\n";
        std::cout << "Second set:" << B << "\n";
        Menu = _getch();
        if (Menu == 27) break;
        switch (Menu)
        {
        case 49:for (;;) //Взятие числа по индексу
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            std::cout << "1:" << A << "\n";
            std::cout << "2:" << B << "\n";
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49:
                std::cout << "Enter the index:";
                std::cin >> Number;
                if (InputControl() == false) break;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    std::cout << "Enter the integer number!"<<"\n";
                    system("pause");
                    break;
                }
                try {
                    std::cout << "This is your number:" << A[Number - 1] << "\n";
                }catch (const char* err)
                {
                    std::cerr<<err<<"\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            case 50:std::cout << "Enter the index:";
                std::cin >> Number;
                if (InputControl() == false) break;
                try {
                    std::cout << "This is your number:" << B[Number - 1] << "\n";
                }
                catch (const char* err)
                {
                    std::cerr << err << "\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            }
        }
            break;
        case 50:std::cout << "Result of combining:";//Объединение множеств
            C = A + B;
            std::cout << C<<"\n";
            system("pause");
            break;
        case 51:std::cout << "From which set to subtract?" << "\n";//Разность множеств
            std::cout << "1." << A << "\n";
            std::cout << "2." << B << "\n";
            Menu = _getch();
            switch(Menu)
            {
            case 49:C = A - B;
                std::cout << "Result of subtract:" << C << "\n";
                system("pause");
                break;
            case 50:C = B - A;
                std::cout << "Result of subtract:" << C << "\n";
                system("pause");
                break;
            }
            break;
        case 52: for (;;) //добавить элемент
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            std::cout << "1:" << A << "\n";
            std::cout << "2:" << B << "\n";
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49:std::cout << "Enter the number:";
                std::cin >> Number;
                if (InputControl() == false) break;
                try
                {
                    A + Number;
                }
                catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:std::cout << "Enter the number:";
                std::cin >> Number;
                if (InputControl() == false) break;
                try
                {
                    B + Number;
                }
                catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            }
        }
            break;
        case 53: for (;;) //убрать элемент
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            std::cout << "1:" << A << "\n";
            std::cout << "2:" << B << "\n";
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49:std::cout << "Enter the number:";
                std::cin >> Number;
                if (InputControl() == false) break;
                try 
                {
                    A - Number;
                }catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:std::cout << "Enter the number:";
                std::cin >> Number;
                if (InputControl() == false) break;
                try
                {
                   B - Number;
                }
                catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            }
        }
            break;
        case 54:std::cout << "Result of intersection:";//Пересечение множеств
            C = A.Intersection(B);
            std::cout << C<<"\n";
            system("pause");
            break;
        case 27: //Esc
            break;
        }
    }
    return 0;
}
