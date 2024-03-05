#include "VectorProcessor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iterator> 

std::vector<double> ParseVector(std::istream& input)
{
    std::vector<double> readedVector;
    double num;

    while (input >> num)
    {
        readedVector.push_back(num);
    }

    return readedVector;
}

void MultiplyVector(std::vector<double>& vector)
{
    if (vector.empty())
    {
        return;
    }

    double minElement = *std::min_element(vector.begin(), vector.end());

    std::transform(vector.begin(), vector.end(), vector.begin(), [&minElement](auto& c) {return c * minElement; });
}

void PrintVector(std::ostream& output, std::vector<double>& vector)
{
    for (auto& i : vector)
    {
        output << std::fixed << std::setprecision(2) << i << " ";
    }
    output << std::endl;
}