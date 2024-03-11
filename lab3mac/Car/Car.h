#ifndef CAR_CAR_H
#define CAR_CAR_H

enum Direction
{
    Backward = -1,
    StandingStill,
    Forward
};

enum Gear
{
    GearR = -1,
    GearN,
    Gear1,
    Gear2,
    Gear3,
    Gear4,
    Gear5,
};

const bool engineStatus = false;

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

class Car
{
public:
    bool TurnOnEngine();
    bool TurnOffEngine();
    bool SetGear(int gear);
    bool SetSpeed(int speed);
    bool IsTurnedOn() const;
    int GetSpeed() const;
    int GetGear() const;
    Direction GetDirection();

private:
    bool m_engineStatus = engineStatus;
    int m_direction = Direction::StandingStill;
    int m_speed = gearNMinSpeed;
    int m_gear = Gear::GearN;
};

#endif //CAR_CAR_H
