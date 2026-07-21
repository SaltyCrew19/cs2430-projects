#include <iostream>
#include "Console.h"
#include "Simulation.h"

int main(int, char**)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    Console sys = Console("MonopolySimulation");
    sys.intro();

    Simulation sim = Simulation();

}
