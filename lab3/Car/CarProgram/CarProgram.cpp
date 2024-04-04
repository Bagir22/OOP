#include <iostream>
#include "../Car/Car.h"
#include <string>

int main()
{
    Car car;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }
}
