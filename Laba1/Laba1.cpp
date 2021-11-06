#include <iostream>
#include <conio.h>
#include <string>
#include "Set.h"

bool InputControl()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Enter the element of right type!" << "\n";
        system("pause");
        return false;
    }
    return true;
}

int main()
{
    Set<std::string> AS;
    Set<std::string> BS;
    Set<std::string> CS;
    Set<int> AI;
    Set<int> BI;
    Set<int> CI;
    Set<float> AF;
    Set<float> BF;
    Set<float> CF;
    int Choice=0;
    int Menu=0;
    int NumberI=0;
    float NumberF=0;
   std::string Sequence;
    int Index;
    for (;;)
    {
        std::cout << "Laboratory work 2. Choose the type of sets to work with:" << "\n";
        std::cout << "1. std::string" << "\n";
        std::cout << "2. Integer" << "\n";
        std::cout << "3. Float" << "\n";
        std::cout << "Your choice:";
        std::cin >> Choice;
        if ((Choice == 1) || (Choice == 2) || (Choice == 3))break;
        system("cls");
    }
    for(;;)
    {
        system("cls");
        std::cout << "1.Get an element by index"<<"\n";
        std::cout << "2.Combining sets" << "\n";
        std::cout << "3.Difference of sets" << "\n";
        std::cout << "4.Add a number" << "\n";
        std::cout << "5.Delete a number" << "\n";
        std::cout << "6.Intersection of sets" << "\n";
        std::cout << "Esc.Exit" << "\n";
        switch (Choice)
        {
        case 1:std::cout << "First set:" << AS << "\n";
            std::cout << "Second set:" << BS << "\n";
            break;
        case 2:std::cout << "First set:" << AI << "\n";
            std::cout << "Second set:" << BI << "\n";
            break;
        case 3:std::cout << "First set:" << AF << "\n";
            std::cout << "Second set:" << BF << "\n";
            break;
        }
        Menu = _getch();
        if (Menu == 27) break;
        switch (Menu)
        {
        case 49:for (;;) //Взятие числа по индексу
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            switch (Choice)
            {
            case 1:std::cout << "1:" << AS << "\n";
                std::cout << "2:" << BS << "\n";
                break;
            case 2:std::cout << "1:" << AI << "\n";
                std::cout << "2:" << BI << "\n";
                break;
            case 3:std::cout << "1:" << AF << "\n";
                std::cout << "2:" << BF << "\n";
                break;
            }
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49:
                std::cout << "Enter the index:";
                std::cin >> Index;
                if (InputControl() == false) break;
                try
                {
                    switch (Choice)
                    {
                    case 1: std::cout << "This is your number:" << AS[Index - 1] << "\n";
                        break;
                    case 2: std::cout << "This is your number:" << AI[Index - 1] << "\n";
                        break;
                    case 3: std::cout << "This is your number:" << AF[Index - 1] << "\n";
                        break;
                    }
                }
                catch (const char* err)
                {
                    std::cerr<<err<<"\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            case 50:std::cout << "Enter the index:";
                std::cin >> Index;
                if (InputControl() == false) break;
                try {
                    switch (Choice)
                    {
                    case 1: std::cout << "This is your number:" << BS[Index - 1] << "\n";
                        break;
                    case 2: std::cout << "This is your number:" << BI[Index - 1] << "\n";
                        break;
                    case 3: std::cout << "This is your number:" << BF[Index - 1] << "\n";
                        break;
                    }
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
            switch (Choice)
            {
            case 1:CS = AS + BS;
                std::cout << CS << "\n";
                system("pause");
                break;
            case 2:CI = AI + BI;
                std::cout << CI << "\n";
                system("pause");
                break;
            case 3:CF = AF + BF;
                std::cout << CF << "\n";
                system("pause");
                break;
            }
            break;
        case 51:std::cout << "From which set to subtract?" << "\n";//Разность множеств
            switch (Choice)
            {
            case 1:std::cout << "1:" << AS << "\n";
                std::cout << "2:" << BS << "\n";
                break;
            case 2:std::cout << "1:" << AI << "\n";
                std::cout << "2:" << BI << "\n";
                break;
            case 3:std::cout << "1:" << AF << "\n";
                std::cout << "2:" << BF << "\n";
                break;
            }
            Menu = _getch();
            switch(Menu)
            {
            case 49:
                std::cout << "Result of subtract:";
                switch (Choice)
                {
                case 1:CS = AS - BS;
                    std::cout << CS << "\n";
                    system("pause");
                    break;
                case 2:CI = AI - BI;
                    std::cout << CI << "\n";
                    system("pause");
                    break;
                case 3:CF = AF - BF;
                    std::cout << CF << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:std::cout << "Result of subtract:";
                switch (Choice)
                {
                case 1:CS = BS - AS;
                    std::cout << CS << "\n";
                    system("pause");
                    break;
                case 2:CI = BI - AI;
                    std::cout << CI << "\n";
                    system("pause");
                    break;
                case 3:CF = BF - AF;
                    std::cout << CF << "\n";
                    system("pause");
                    break;
                }
            }
            break;
        case 52:for (;;) //добавить элемент
        {
            system("cls");
            std::cout << "Select a set:" << "\n";
            switch (Choice)
            {
            case 1:std::cout << "1:" << AS << "\n";
                std::cout << "2:" << BS << "\n";
                break;
            case 2:std::cout << "1:" << AI << "\n";
                std::cout << "2:" << BI << "\n";
                break;
            case 3:std::cout << "1:" << AF << "\n";
                std::cout << "2:" << BF << "\n";
                break;
            }
            std::cout << "Esc.Back to main menu" << "\n";
            Menu = _getch();
            if (Menu == 27) break;
            switch (Menu)
            {
            case 49: 
                switch (Choice)
                {
                case 1:std::cout << "Enter the sequence:";
                    std::cin >> Sequence;
                    break;
                case 2:std::cout << "Enter the number:";
                    std::cin >> NumberI;
                    break;
                case 3:std::cout << "Enter the number:";
                    std::cin >> NumberF;
                    break;
                }
                try 
                {
                    switch (Choice)
                    {
                    case 1:AS + Sequence;
                        break;
                    case 2:AI + NumberI;
                        break;
                    case 3:AF + NumberF;
                        break;
                    }
                }
                catch (const char* err)
                {
                    std::cout << err << "\n";
                    system("pause");
                    break;
                }
                break;
            case 50:switch (Choice)
            {
            case 1:std::cout << "Enter the sequence:";
                std::cin >> Sequence;
                break;
            case 2:std::cout << "Enter the number:";
                std::cin >> NumberI;
                break;
            case 3:std::cout << "Enter the number:";
                std::cin >> NumberF;
                break;
            }
                   try
                   {
                       switch (Choice)
                       {
                       case 1:BS + Sequence;
                           break;
                       case 2:BI + NumberI;
                           break;
                       case 3:BF + NumberF;
                           break;
                       }
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
            case 53: 
                for (;;) //Убрать элемент
                {
                    system("cls");
                    std::cout << "Select a set:" << "\n";
                    switch (Choice)
                    {
                    case 1:std::cout << "1:" << AS << "\n";
                        std::cout << "2:" << BS << "\n";
                        break;
                    case 2:std::cout << "1:" << AI << "\n";
                        std::cout << "2:" << BI << "\n";
                        break;
                    case 3:std::cout << "1:" << AF << "\n";
                        std::cout << "2:" << BF << "\n";
                        break;
                    }
                    std::cout << "Esc.Back to main menu" << "\n";
                    Menu = _getch();
                    if (Menu == 27) break;
                    switch (Menu)
                    {
                    case 49:
                        switch (Choice)
                        {
                        case 1:std::cout << "Enter the sequence:";
                            std::cin >> Sequence;
                            break;
                        case 2:std::cout << "Enter the number:";
                            std::cin >> NumberI;
                            break;
                        case 3:std::cout << "Enter the number:";
                            std::cin >> NumberF;
                            break;
                        }
                        try
                        {
                            switch (Choice)
                            {
                            case 1:AS - Sequence;
                                break;
                            case 2:AI - NumberI;
                                break;
                            case 3:AF - NumberF;
                                break;
                            }
                        }
                        catch (const char* err)
                        {
                            std::cout << err << "\n";
                            system("pause");
                            break;
                        }
                        break;
                    case 50:switch (Choice)
                    {
                    case 1:std::cout << "Enter the sequence:";
                        std::cin >> Sequence;
                        break;
                    case 2:std::cout << "Enter the number:";
                        std::cin >> NumberI;
                        break;
                    case 3:std::cout << "Enter the number:";
                        std::cin >> NumberF;
                        break;
                    }
                           try
                           {
                               switch (Choice)
                               {
                               case 1:BS - Sequence;
                                   break;
                               case 2:BI - NumberI;
                                   break;
                               case 3:BF - NumberF;
                                   break;
                               }
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
            switch (Choice)
            {
            case 1:CS = AS.Intersection(BS);
                break;
            case 2:CI = AI.Intersection(BI);
                break;
            case 3:CF = AF.Intersection(BF);
                break;
            }
            switch (Choice)
            {
            case 1:std::cout << CS << "\n";;
                break;
            case 2:std::cout << CI << "\n";;
                break;
            case 3:std::cout << CF << "\n";;
                break;
            }
            system("pause");
            break;
        case 27: //Esc
            break;
        }
    }
    return 0;
}
