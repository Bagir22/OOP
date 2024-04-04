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
        m_direction = Direction::StandingStill;
        return true;
    }

    return false;
}

bool Car::SetGear(int gear) {
    if (!IsTurnedOn() && gear != Gear::GearN) 
    {
        std::cout << errGearEngineTurnOff;
        return false;
    }

    if (gear < static_cast<int>(Gear::GearR) || gear > static_cast<int>(Gear::Gear5))
    {
        std::cout << errGearNotInGearRange;
        return false;
    }

    if (gear == static_cast<int>(Gear::GearN)) 
    {
        m_gear = Gear::GearN;
        return true;
    }

    if (m_gear == Gear::GearR && gear != Gear::GearN && gear != Gear::GearR)
    {
        std::cout << errGearRearToForward;
        return false;
    }

    int minSpeed = speedRanges.at(static_cast<Gear>(gear)).first;
    int maxSpeed = speedRanges.at(static_cast<Gear>(gear)).second;

    if (m_speed >= minSpeed && m_speed <= maxSpeed) 
    {
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
        std::cout << errGearSpeedNotInGearRange;
        return false;
    }

}

bool Car::SetSpeed(int speed) {
    if (speed < 0)
    {
        std::cout << errSpeedLower0;
        return false;
    }

    if (!IsTurnedOn())
    {
        std::cout << errSpeedEngineTurnOff;
        return false;
    }

    if (m_gear == Gear::GearN)
    {
        if (m_speed <= speed)
        {
            std::cout << errSpeedGearNeutral;
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

    std::cout << errSpeedNotInGearRange;
    return false;
}
