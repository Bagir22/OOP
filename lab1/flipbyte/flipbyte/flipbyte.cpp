#include <iostream>
#include <string>

const std::string errInvalidArgsCount = "Invalid arguments count\n"
                                        "Usage: flipbyte.exe <num to flip>\n";
const std::string errValueIsNotInt = "Entered value is not in\n";
const std::string errValueIsLowerOrBigger = "Entered number is lower 0 or bigger 255\n";

int FlipByte(int byte)
{
    byte = (byte & 0b11110000) >> 4 | (byte & 0b00001111) << 4;
    byte = (byte & 0b11001100) >> 2 | (byte & 0b00110011) << 2;
    byte = (byte & 0b10101010) >> 1 | (byte & 0b01010101) << 1;

    return byte;
}

bool IsInt(const std::string& byteArg)
{
    if (byteArg.empty())
    {
        return false;
    }

    for (int i = 0; i < byteArg.size(); i++)
    {
        if (i == 0 && (byteArg[i] != '-' && !isdigit(byteArg[i])))
        {
            return false;
        }
        else if (i != 0 && !isdigit(byteArg[i]))
        {
            return false;
        }
    }

    return true;
}

bool IsValidNumber(int num)
{
    return (0 <= num and num <= 255);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << errInvalidArgsCount;

        return 1;
    }

    std::string byteArg = argv[1];

    if (!IsInt(byteArg))
    {
        std::cout << errValueIsNotInt;

        return 1;
    }

    int byte = stoi(byteArg);

    if (!IsValidNumber(byte))
    {
        std::cout << errValueIsLowerOrBigger;

        return 1;
    }

    int flippedByte = FlipByte(byte);
    std::cout << flippedByte << std::endl;

    return 0;
}