#pragma once
#include <vector>
#include <iostream>

std::vector<double> ParseVector(std::istream& input);
void MultiplyVector(std::vector<double>& vector);
void PrintVector(std::ostream& output, std::vector<double>& vector);