#include "Car.h"

bool Car::IsTurnedOn() const {
    return m_engineStatus;
}

int Car::GetSpeed() const {
    return m_speed;
}

int Car::GetGear() const {
    return m_gear;
}

Direction Car::GetDirection() {
    if (m_direction == 0)
    {
        return StandingStill;
    }
    else if (m_direction > 0)
    {
        return Forward;
    }

    return Backward;
}
