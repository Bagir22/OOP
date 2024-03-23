#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include "../Car/Car.h"
#include "../Car/Car.cpp"

SCENARIO("Test default values")
{
	
	WHEN("Car is jsut created")
	{
		std::cout << "Test 1: car default values" << std::endl;
		Car car;
		THEN("Engine is switched off, gear is Neutral, speed = 0 adn direction is standing still")
		{
			REQUIRE(car.IsTurnedOn() == engineStatusOff);
			REQUIRE(car.GetGear() == Gear::GearN);
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			REQUIRE(car.GetDirection() == Direction::StandingStill);
			std::cout << "Test 1 passed" << std::endl;
		}
	}
	
}

SCENARIO("Engine switch on")
{
	WHEN("Engine is off, and we turned it on")
	{
		std::cout << "Test 2: switch on engine" << std::endl;
		Car car;
		car.TurnOnEngine();
		THEN("Engine is switching on")
		{
			REQUIRE(car.IsTurnedOn() == engineStatusOn);
			REQUIRE(car.GetGear() == Gear::GearN);
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			REQUIRE(car.GetDirection() == Direction::StandingStill);
			std::cout << "Test 2 passed" << std::endl;
		}
	}
}

SCENARIO("Engine switch off")
{
	Car car;
	car.TurnOnEngine();

	WHEN("Switch off engine at neutral gear and speed = 0")
	{
		std::cout << "Test 3: switch off engine at neutral gear and speed = 0" << std::endl;
		REQUIRE(car.GetGear() == Gear::GearN);
		REQUIRE(car.GetSpeed() == gearNMinSpeed);
		REQUIRE(car.GetDirection() == Direction::StandingStill);
		car.TurnOffEngine();
		THEN("Engine is switched off")
		{
			REQUIRE(car.IsTurnedOn() == engineStatusOff);
			std::cout << "Test 3 passed" << std::endl;
		}		
	}

	WHEN("Switch off engine not at neutral gear and speed != 0")
	{
		std::cout << "Test 4: switch off engine at neutral gear and speed != 0" << std::endl;
		car.SetGear(Gear::Gear1);
		car.SetSpeed(10);
		REQUIRE(car.GetGear() == Gear::Gear1);
		REQUIRE(car.GetSpeed() == 10);
		car.TurnOffEngine();
		THEN("Engine isn't switched off")
		{
			REQUIRE(car.IsTurnedOn() != engineStatusOff);
			std::cout << "Test 4 passed" << std::endl;
		}
	}

	WHEN("Switch off engine at neutral gear and speed != 0")
	{
		std::cout << "Test 5: switch off engine at neutral gear and speed != 0" << std::endl;
		car.SetGear(Gear::Gear1);
		car.SetSpeed(10);
		REQUIRE(car.GetGear() == Gear::Gear1);
		REQUIRE(car.GetSpeed() == 10);
		car.SetGear(Gear::GearN);
		REQUIRE(car.GetGear() == Gear::GearN);
		REQUIRE(car.GetSpeed() == 10);
		car.TurnOffEngine();
		THEN("Engine isn't switched off")
		{
			REQUIRE(car.IsTurnedOn() != engineStatusOff);
			std::cout << "Test 5 passed" << std::endl;
		}
	}
}

SCENARIO("Gear setting")
{
	Car car;
	WHEN("Change gear while engine off")
	{
		std::cout << "Test 6: change gear while engine off" << std::endl;
		REQUIRE(car.IsTurnedOn() == engineStatusOff);
		REQUIRE(car.GetGear() == Gear::GearN);
		REQUIRE(car.GetSpeed() == gearNMinSpeed);
		REQUIRE(car.GetDirection() == Direction::StandingStill);
		car.SetGear(Gear::Gear1);
		THEN("Gear doesn't change")
		{
			REQUIRE(car.GetGear() == Gear::GearN);
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			REQUIRE(car.GetDirection() == Direction::StandingStill);
			std::cout << "Test 6 passed" << std::endl;
		}
	}

	WHEN("Change to gear 1 while engine on and gear is neutral")
	{
		std::cout << "Test 6: change to gear 1 while engine on and gear is neutral" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		REQUIRE(car.GetGear() == Gear::GearN);
		car.SetGear(Gear::Gear1);
		THEN("Gear set to 1")
		{
			REQUIRE(car.GetGear() == Gear::Gear1);
			REQUIRE(car.GetSpeed() == gear1MinSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 7 passed" << std::endl;
		}
	}

	WHEN("Change to gear R while engine on and gear is neutral")
	{
		std::cout << "Test 7: change to gear R while engine on and gear is neutral" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		REQUIRE(car.GetGear() == Gear::GearN);
		car.SetGear(Gear::GearR);
		THEN("Gear set to R")
		{
			REQUIRE(car.GetGear() == Gear::GearR);
			REQUIRE(car.GetSpeed() == gearRMinSpeed);
			REQUIRE(car.GetDirection() == Direction::Backward);
			std::cout << "Test 7 passed" << std::endl;
		}
	}

	WHEN("Try to change to invalid gear for current speed")
	{
		std::cout << "Test 8: try to change to invalid gear for current speed" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		REQUIRE(car.GetGear() == Gear::GearN);
		car.SetGear(Gear::Gear1);
		REQUIRE(car.GetGear() == Gear::Gear1);
		car.SetSpeed(10);
		REQUIRE(car.GetSpeed() == 10);
		car.SetGear(Gear::Gear2);
		THEN("Can't set next gear for current speed")
		{
			REQUIRE(car.GetGear() == Gear::Gear1);
			REQUIRE(car.GetSpeed() == 10);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 8 passed" << std::endl;
		}
	}
	
	WHEN("Change to neutral gear while speed = 0 and gear not neutral")
	{
		std::cout << "Test 9: try to change to invalid gear for current speed" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		REQUIRE(car.GetGear() == Gear::GearN);
		REQUIRE(car.GetSpeed() == gearNMinSpeed);
		car.SetGear(Gear::GearN);
		THEN("Gear are the same")
		{
			REQUIRE(car.GetGear() == Gear::GearN);
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			REQUIRE(car.GetDirection() == Direction::StandingStill);
			std::cout << "Test 9 passed" << std::endl;
		}
	}

	WHEN("Change to neutral gear while speed != 0 and gear not neutral")
	{
		std::cout << "Test 10: try to change to neutral gear while speed != 0 and gear not neutral" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		REQUIRE(car.GetGear() == Gear::GearN);
		REQUIRE(car.GetSpeed() == gearNMinSpeed);
		car.SetGear(Gear::Gear1);
		car.SetSpeed(gear1MaxSpeed);
		REQUIRE(car.GetSpeed() == gear1MaxSpeed);
		THEN("Gear change to neutral, speed and direction are same")
		{
			car.SetGear(Gear::GearN);
			REQUIRE(car.GetGear() == Gear::GearN);
			REQUIRE(car.GetSpeed() == gear1MaxSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 10 passed" << std::endl;
		}
	}

	WHEN("Change from rear gear to forward gear when speed = 0")
	{
		std::cout << "Test 11: try to change from rear gear to forward gear when speed = 0" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		car.SetGear(Gear::GearR);
		REQUIRE(car.GetSpeed() == gearRMinSpeed);
		THEN("Gear doesn't change")
		{
			car.SetGear(Gear::Gear1);
			REQUIRE(car.GetGear() == Gear::GearR);
			REQUIRE(car.GetSpeed() == gearRMinSpeed);
			REQUIRE(car.GetDirection() == Direction::Backward);
			std::cout << "Test 11 passed" << std::endl;
		}
	}


	WHEN("Change from rear gear to forward gear when speed != 0")
	{
		std::cout << "Test 12: try to change from rear gear to forward gear when speed != 0" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == engineStatusOn);
		car.SetGear(Gear::GearR);
		car.SetSpeed(gearRMaxSpeed);
		REQUIRE(car.GetSpeed() == gearRMaxSpeed);
		THEN("Gear doesn't change")
		{
			car.SetGear(Gear::Gear1);
			REQUIRE(car.GetGear() == Gear::GearR);
			REQUIRE(car.GetSpeed() == gearRMaxSpeed);
			REQUIRE(car.GetDirection() == Direction::Backward);
			std::cout << "Test 12 passed" << std::endl;
		}
	}
}

SCENARIO("Speed setting")
{
	Car car;
	WHEN("Change speed while engine off")
	{
		std::cout << "Test 13: try to change speed while engine off" << std::endl;
		REQUIRE(!car.IsTurnedOn());
		car.SetSpeed(20);
		THEN("Speed has default value")
		{
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			std::cout << "Test 13 passed" << std::endl;
		}
	}

	WHEN("Set speed while engine on and gear is neutral")
	{
		std::cout << "Test 14: set speed while engine on and gear is neutral" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.GetGear() == Gear::GearN);
		car.SetSpeed(10);
		THEN("Speed has default value")
		{
			REQUIRE(car.GetSpeed() == gearNMinSpeed);
			REQUIRE(car.GetDirection() == Direction::StandingStill);
			std::cout << "Test 14 passed" << std::endl;
		}
	}


	WHEN("Set valid speed for current gear while engine on")
	{
		std::cout << "Test 15: set valid speed for current gear while engine on" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn());
		car.SetGear(Gear::Gear1);
		REQUIRE(car.GetGear() == Gear::Gear1);
		car.SetSpeed(gear1MaxSpeed);
		THEN("Speed is updated")
		{
			REQUIRE(car.GetSpeed() == gear1MaxSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 15 passed" << std::endl;
		}
	}

	WHEN("Set invalid speed for current gear while engine on")
	{
		std::cout << "Test 16: set invalid speed for current gear while engine on" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn());
		car.SetGear(Gear::Gear1);
		REQUIRE(car.GetGear() == Gear::Gear1);
		car.SetSpeed(gear2MaxSpeed);
		THEN("Speed is not setted")
		{
			REQUIRE(car.GetSpeed() == gear1MinSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 16 passed" << std::endl;
		}
	}

	WHEN("Decrease to valid speed for current gear")
	{
		std::cout << "Test 17: decrease to valid speed for current gear" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn());
		car.SetGear(Gear::Gear1);
		REQUIRE(car.GetGear() == Gear::Gear1);
		car.SetSpeed(gear1MaxSpeed);
		car.SetGear(Gear::Gear2);
		REQUIRE(car.GetGear() == Gear::Gear2);
		car.SetSpeed(gear2MaxSpeed);
		REQUIRE(car.GetSpeed() == gear2MaxSpeed);
		car.SetSpeed(gear2MinSpeed);
		THEN("Speed is not setted")
		{
			REQUIRE(car.GetSpeed() == gear2MinSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 17 passed" << std::endl;
		}
	}

	WHEN("Decrease to invalid speed for current gear")
	{
		std::cout << "Test 18: decrease to invalid speed for current gear" << std::endl;
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn());
		car.SetGear(Gear::Gear1);
		REQUIRE(car.GetGear() == Gear::Gear1);
		car.SetSpeed(gear1MaxSpeed);
		car.SetGear(Gear::Gear2);
		REQUIRE(car.GetGear() == Gear::Gear2);
		car.SetSpeed(gear2MaxSpeed);
		REQUIRE(car.GetSpeed() == gear2MaxSpeed);
		car.SetSpeed(gear1MinSpeed);
		THEN("Speed is not setted")
		{
			REQUIRE(car.GetSpeed() == gear2MaxSpeed);
			REQUIRE(car.GetDirection() == Direction::Forward);
			std::cout << "Test 18 passed" << std::endl;
		}
	}
}