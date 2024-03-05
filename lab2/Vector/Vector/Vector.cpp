#include <iostream>
#include <vector>
#include "VectorProcessor.h"

int main()
{
    std::vector<double> readedVector = ParseVector(std::cin);

    MultiplyVector(readedVector);
    PrintVector(std::cout, readedVector);

    return 0;
}
