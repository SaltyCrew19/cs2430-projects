#include <iostream>
#include "Console.h"
#include "Simulation.h"

int main(int, char**)
{
    Console sys = Console("MonopolySimulation");
    sys.intro();

    Simulation sim = Simulation();
}
