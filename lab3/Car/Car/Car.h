#pragma once

#include "iostream"
#include "map"

enum class Direction : int
{
    Backward = -1,
    StandingStill,
    Forward
};

enum Gear : int
{
    GearR = -1,
    GearN,
    Gear1,
    Gear2,
    Gear3,
    Gear4,
    Gear5,
};

const bool engineStatusOff = false;
const bool engineStatusOn = true;

const int gearRMinSpeed = 0;
const int gearRMaxSpeed = 20;
const int gearNMinSpeed = 0;
const int gearNMaxSpeed = 150;
const int gear1MinSpeed = 0;
const int gear1MaxSpeed = 30;
const int gear2MinSpeed = 20;
const int gear2MaxSpeed = 50;
const int gear3MinSpeed = 30;
const int gear3MaxSpeed = 60;
const int gear4MinSpeed = 40;
const int gear4MaxSpeed = 90;
const int gear5MinSpeed = 50;
const int gear5MaxSpeed = 150;

typedef std::map<Gear, std::pair<int, int>> speedRangesType;

const speedRangesType speedRanges =
{
    { Gear::GearR, {gearRMinSpeed, gearRMaxSpeed} },
    { Gear::GearN, {gearNMinSpeed, gearNMaxSpeed} },
    { Gear::Gear1, {gear1MinSpeed, gear1MaxSpeed} },
    { Gear::Gear2, {gear2MinSpeed, gear2MaxSpeed} },
    { Gear::Gear3, {gear3MinSpeed, gear3MaxSpeed} },
    { Gear::Gear4, {gear4MinSpeed, gear4MaxSpeed} },
    { Gear::Gear5, {gear5MinSpeed, gear5MaxSpeed} }
};

const std::string errGearEngineTurnOff = "Can't set new gear because engine turned off\n";
const std::string errGearNotInGearRange = "Can't set gear because new gear not in gear range\n";
const std::string errGearRearToForward = "Can't set gear because: can't change rear gear to forward\n";
const std::string errGearSpeedNotInGearRange = "Can't set new gear because current speed not in new gear speed range\n";
const std::string errSpeedLower0 = "Can't set speed because new speed lower 0\n";
const std::string errSpeedEngineTurnOff = "Can't set speed because engine is off\n";
const std::string errSpeedGearNeutral = "Can't set speed because current gear is neutral and new speed is bigger than current speed\n";
const std::string errSpeedNotInGearRange = "Can't set speed because new speed isn't in current gear speed range\n";

class Car
{
public:
    bool TurnOnEngine();
    bool TurnOffEngine();
    bool SetGear(int gear);
    bool SetSpeed(int speed);
    bool IsTurnedOn() const;
    int GetSpeed() const;
    Gear GetGear() const;
    Direction GetDirection();

private:
    bool m_engineStatus = engineStatusOff;
    int m_speed = gearNMinSpeed;
    Gear m_gear = Gear::GearN;
    Direction m_direction = Direction::StandingStill;
};
