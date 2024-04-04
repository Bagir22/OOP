#include "CarHandler.h"

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
