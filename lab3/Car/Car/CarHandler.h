#pragma once
#include "Car.h"

const std::string introduceEnter = "Enter command:\n";
const std::string introduceInfo = "1 - Info(Car info about engine, gear, speed and direction)\n";
const std::string introduceEngineOn = "2 - EngineOn\n";
const std::string introduceEngineOff = "3 - EngineOff\n";
const std::string introduceSetGear = "4 (some int value) - SetGear\n";
const std::string introduceSetSpeed = "5 (some int value) - SetSpeed\n";

const std::string infoFirst = "Car info:\n";
const std::string infoGear = "Current gear: ";
const std::string infoSpeed = "Current speed: ";
const std::string infoEngineOn = "Engine: on\n";
const std::string infoEngineOff = "Engine: off\n";
const std::string infoSetSpeed = "5 (some int value) - SetSpeed\n";
const std::string infoDirectionStanding = "Current direction: standing still\n";
const std::string infoDirectionForward = "Current direction: forward\n";
const std::string infoDirectionBackward = "Current direction: backward\n";

const std::string unknownCommand = "Unknown command\n";

class CarHandler {
public:
    void Introduce();
    void Info(Car& c);
    void EngineOn(Car& c);
    void EngineOff(Car& c);
    void SetGear(Car& c, int gear);
    void SetSpeed(Car& c, int speed);
private:
    Car c;
};

