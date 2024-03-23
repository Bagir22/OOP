#include <iostream>
#include "../Car/Car.h"
#include <string>
#include <sstream>
#include <vector>

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


void Info(Car &c)
{
    std::cout << "Car info:" << std::endl;
    std::cout << "Current gear: "  << static_cast<int>(c.GetGear()) << std::endl;
    std::cout << "Current speed: " << c.GetSpeed() << std::endl;

    bool engineStatus = c.IsTurnedOn();

    if (engineStatus)
    {
        std::cout << "Engine: on" << std::endl;
    }
    else
    {
        std::cout << "Engine: off" << std::endl;
    }

    int direction = static_cast<int>(c.GetDirection());
    if (direction == -1)
    {
        std::cout << "Current direction: backward" << std::endl;
    }
    else if (direction == 1)
    {
        std::cout << "Current direction: forward" << std::endl;
    }
    else
    {
        std::cout << "Current direction: standing still" << std::endl;
    }
}

void EngineOn(Car& c)
{
    c.TurnOnEngine();
}

void EngineOff(Car& c)
{
    c.TurnOffEngine();
}

void SetGear(Car& c, int gear)
{
    c.SetGear(gear);
}

void SetSpeed(Car& c, int speed)
{
    c.SetSpeed(speed);
}

int main()
{
    Car car;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::vector<std::string> splittedLine = Split(line, " ");
        bool validCommand = true;

        if (splittedLine[0] != "")
        {
            if (splittedLine[0] == "Info")
            {
                Info(car);
            } 
            else if (splittedLine[0] == "EngineOn")
            {
                EngineOn(car);
            }
            else if (splittedLine[0] == "EngineOff")
            {
                EngineOff(car);
            }
            else if (splittedLine.size() == 2 && IsInt(splittedLine[1]))
            {
                if (splittedLine[0] == "SetGear")
                {
                    SetGear(car, std::stoi(splittedLine[1]));
                } 
                else if (splittedLine[0] == "SetSpeed")
                {
                    SetSpeed(car, std::stoi(splittedLine[1]));
                }
                else
                {
                    validCommand = false;
                }
            }           
            else
            {
                validCommand = false;
            }

            if (!validCommand)
            {
                std::cout << "Invalid command" << std::endl;
            }
        }
    }

    return 0;
}
