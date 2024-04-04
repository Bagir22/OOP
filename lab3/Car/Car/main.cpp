#include <iostream>
#include "../Car/Car.h"
#include "../Car/CarHandler.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> Split(std::string s, std::string delimiter) {
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

int main()
{
    Car car;
    CarHandler handler;

    handler.Introduce();

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

        switch(command)
        {
            case 1:
            {
                handler.Info(car);
                break;
            }
            case 2:
            {
                handler.EngineOn(car);
                break;
            }
            case 3:
            {
                handler.EngineOff(car);
                break;
            }
            case 4:
            {
                handler.SetGear(car, subCommand);
                break;
            }
            case 5:
            {
                handler.SetSpeed(car, subCommand);
                break;
            }
            default:
                std::cout << unknownCommand;
                break;
        }

    }

    return 0;
}
