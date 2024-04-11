#include "CarHandler.h"
#include "iostream"
#include <string>
#include <sstream>
#include "vector"

std::vector<std::string> CarHandler::Split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool CarHandler::IsInt(const std::string& byteArg)
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

void CarHandler::Introduce()
{
    std::cout << introduceEnter;
    std::cout << introduceInfo;
    std::cout << introduceEngineOn;
    std::cout << introduceEngineOff;
    std::cout << introduceSetGear;
    std::cout << introduceSetSpeed;
    std::cout << "\n";
}

void CarHandler::Info(Car& c)
{
    std::cout << infoFirst;
    std::cout << infoGear << static_cast<int>(c.GetGear()) << std::endl;
    std::cout << infoSpeed << c.GetSpeed() << std::endl;

    bool engineStatus = c.IsTurnedOn();

    if (engineStatus)
    {
        std::cout << infoEngineOn;
    }
    else
    {
        std::cout << infoEngineOff;
    }

    int direction = static_cast<int>(c.GetDirection());
    if (direction == -1)
    {
        std::cout << infoDirectionBackward;
    }
    else if (direction == 1)
    {
        std::cout << infoDirectionForward;
    }
    else
    {
        std::cout << infoDirectionStanding;
    }
}

void CarHandler::EngineOn(Car& c)
{
    c.TurnOnEngine();
}

void CarHandler::EngineOff(Car& c)
{
    c.TurnOffEngine();
}

void CarHandler::SetGear(Car& c, int gear)
{
    c.SetGear(gear);
}

void CarHandler::SetSpeed(Car& c, int speed)
{
    c.SetSpeed(speed);
}

void CarHandler::CarOperate(Car& c)
{
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::vector<std::string> splittedLine = Split(line, " ");
        int command = 0;
        int subCommand = 0;
        if (IsInt(splittedLine[0]))
        {
            command = stoi(splittedLine[0]);
        }

        if (splittedLine.size() == 2 && IsInt(splittedLine[1]))
        {
            subCommand = stoi(splittedLine[1]);
        }
        else if (splittedLine.size() == 2)
        {
            command = 0;
        }

        switch (command)
        {
        case 1:
        {
            Info(c);
            break;
        }
        case 2:
        {
            EngineOn(c);
            break;
        }
        case 3:
        {
            EngineOff(c);
            break;
        }
        case 4:
        {
            SetGear(c, subCommand);
            break;
        }
        case 5:
        {
            SetSpeed(c, subCommand);
            break;
        }
        default:
            std::cout << unknownCommand;
            break;
        }

    }
}
