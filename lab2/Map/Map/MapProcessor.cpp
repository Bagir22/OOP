#include "MapProcessor.h"

std::map<std::string, int> ReadWords(std::istream& input)
{
    std::map<std::string, int> words;
    std::string readedWord;
    while (input >> readedWord)
    {
        words[readedWord] += 1;
    }

    return words;
}

void PrintWords(std::ostream& output, std::map<std::string, int> words)
{
    for (const auto& wordPair : words)
       output << wordPair.first << "->" << wordPair.second << std::endl;
}
