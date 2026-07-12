#include "Console.h"
#include <iostream>

Console::Console(){this->projectName = "[c++System] ";}
Console::Console(std::string name){this -> projectName = "[" + name + "] ";}

void Console::print(std::stringstream &msg){std::cout << projectName << msg.str() << std::endl;}
void Console::print(const std::string &msg){std::cout << projectName << msg << std::endl;}
void Console::error(std::stringstream &msg){std::cout << "-[ERROR]-" <<projectName << msg.str() << std::endl;}
void Console::error(const std::string &msg){std::cout << "-[ERROR]-" <<projectName << msg << std::endl;}
void Console::intro()
{
    std::string intro;
    intro.append("-----------------------------------------------------------------------------------------\n");
    intro.append("Welcome to the " + projectName + "project\n");
    intro.append("-----------------------------------------------------------------------------------------\n");
    std::cout << intro;
}

Console::~Console(){}

