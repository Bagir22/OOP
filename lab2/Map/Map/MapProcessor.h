#pragma once
#include <map>
#include <iostream>

std::map<std::string, int> ReadWords(std::istream& input);
void PrintWords(std::ostream& output, std::map<std::string, int> words);

