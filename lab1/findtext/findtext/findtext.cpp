#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <optional>

const std::string errInvalidArgsCount = "Invalid arguments count\n"
                                        "Usage: copyfile.exe <input file> <searched text>\n";
const std::string errFailedOpenFile = "Failed open file for reading: ";
const std::string resultNotFound = "No string found\n";

struct Args
{
    std::string inputFileName;
    std::string searchText;
};

bool FindStringInText(std::istream& text, const std::string& needle, bool& found)
{
    std::string line;
    for (int lineIndex = 1; getline(text, line); ++lineIndex)
    {
        auto pos = line.find(needle);

        if (pos != std::string::npos)
        {
            found = true;
            std::cout << lineIndex << std::endl;
        }
    }

    return found;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << errInvalidArgsCount;

        return std::nullopt;
    }

    Args args;
    args.inputFileName = argv[1];
    args.searchText = argv[2];

    return args;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");

    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 2;
    }

    std::ifstream input(args->inputFileName);

    if (!input.is_open())
    {
        std::cout << errFailedOpenFile << args->inputFileName << std::endl;

        return 2;
    }

    bool found = false;

    FindStringInText(input, args->searchText, found);
    if (!found)
    {
        std::cout << resultNotFound;
        return 1;
    }

    return 0;
}
