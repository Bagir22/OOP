#include <iostream>
#include "../Car/Car.h"
#include "../Car/CarHandler.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
    Car car;
    CarHandler handler;

    handler.Introduce();

    handler.CarOperate(car);

    return 0;
}
