#include <iostream>
#include <map>
#include "MapProcessor.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::map<std::string, int> words = ReadWords(std::cin);
    PrintWords(std::cout, words);

    return 0;
}
