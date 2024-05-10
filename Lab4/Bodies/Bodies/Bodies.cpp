#include <iostream>
#include "CBodyHandler.h"

int main()
{
    std::vector<std::shared_ptr<CBody>> bodies;
    CBodyHandler handler(std::cin, std::cout, bodies);
    
    handler.Introduce();
    handler.Operate();

    return 0;
}
