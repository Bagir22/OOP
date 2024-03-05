#include "StringProcessor.h"
#include <algorithm>
#include <string>

std::string ReadString(std::istream& input)
{
    std::string readedString;
    std::getline(input, readedString);
    return readedString;
}

std::string TrimBlanks(std::string const& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
    {
        return "";
    }
    size_t last = str.find_last_not_of(' ');

    return str.substr(first, (last - first + 1));
}

void PrintString(std::ostream& output, std::string str)
{
    output << str << std::endl;
}
