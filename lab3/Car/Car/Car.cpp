#include "Car.h"

bool Car::IsTurnedOn() const {
    return m_engineStatus;
}

int Car::GetSpeed() const {
    return m_speed;
}

Gear Car::GetGear() const {
    return m_gear;
}

Direction Car::GetDirection() {
    return m_direction;
}

bool Car::TurnOnEngine()
{
    m_engineStatus = engineStatusOn;
    return m_engineStatus;
}


bool Car::TurnOffEngine() {
    if (!m_engineStatus)
    {
        return true;
    }

    if (m_gear == Gear::GearN && m_speed == gearNMinSpeed)
    {
        m_engineStatus = engineStatusOff;
        return true;
    }

    return false;
}

bool Car::SetGear(int gear) {
    if (!IsTurnedOn() && gear != Gear::GearN) 
    {
        std::cout << "Can't set new gear because engine turned off" << std::endl;
        return false;
    }

    if (gear < static_cast<int>(Gear::GearR) || gear > static_cast<int>(Gear::Gear5))
    {
        std::cout << "Can't set gear because new gear not in gear diapason" << std::endl;
        return false;
    }

    if (gear == static_cast<int>(Gear::GearN)) 
    {
        m_gear = Gear::GearN;
        return true;
    }

    if (m_gear == Gear::GearR && gear != Gear::GearN && gear != Gear::GearR)
    {
        std::cout << "Can't set gear because you can't change rear gear to forward" << std::endl;
        return false;
    }

    int minSpeed = speedRanges.at(static_cast<Gear>(gear)).first;
    int maxSpeed = speedRanges.at(static_cast<Gear>(gear)).second;

    if (m_speed >= minSpeed && m_speed <= maxSpeed) {
        m_gear = static_cast<Gear>(gear);
        
        if (m_gear == Gear::GearR)
        {
            m_direction = Direction::Backward;
        }
        else if (m_gear == Gear::GearN && m_speed == gearNMinSpeed)
        {
            m_direction = Direction::StandingStill;
        }
        else
        {
            m_direction = Direction::Forward;
        }

        return true;
    }
    else 
    {
        std::cout << "Can't set new gear because current speed not int new gear speed diapason" << std::endl;
        return false;
    }

}

bool Car::SetSpeed(int speed) {
    if (speed < 0)
    {
        std::cout << "Can't set speed because new speed lower 0" << std::endl;
        return false;
    }

    if (!IsTurnedOn())
    {
        std::cout << "Can't set speed because engine is off" << std::endl;
        return false;
    }

    if (m_gear == Gear::GearN)
    {
        if (m_speed <= speed)
        {
            std::cout << "Can't set speed because current gear is neutral and new speed is bigger than current speed" << std::endl;
            return false;
        }

        m_speed = speed;
        return true;
    }

    int currentGearMinSpead = speedRanges.at(m_gear).first;
    int currentGearMaxSpead = speedRanges.at(m_gear).second;

    if (currentGearMinSpead <= speed && speed <= currentGearMaxSpead)
    {
        m_speed = speed;
        return true;
    }

    std::cout << "Can't set speed because new speed isn't in current gear speed range" << std::endl;
    return false;
}
