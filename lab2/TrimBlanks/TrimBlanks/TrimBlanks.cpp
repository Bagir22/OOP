#include <iostream>
#include "StringProcessor.h"
#include <Windows.h>

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (std::cin) 
    {
        std::string inputString = ReadString(std::cin);

        std::string trimedString = TrimBlanks(inputString);
        PrintString(std::cout, trimedString);
    }
    
    return 0;
}
