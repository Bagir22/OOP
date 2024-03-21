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
