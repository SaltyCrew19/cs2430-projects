#include "Console.h"
#include <iostream>

Console::Console(){this->projectName = "[c++System] ";}
Console::Console(std::string name){this -> projectName = "[" + name + "] ";}

void Console::print(std::stringstream &msg){std::cout << projectName << msg.str() << "\n";}
void Console::print(const std::string &msg){std::cout << projectName << msg << "\n";}
void Console::error(std::stringstream &msg){std::cout << "-[ERROR]-" <<projectName << msg.str() << "\n";}
void Console::error(const std::string &msg){std::cout << "-[ERROR]-" <<projectName << msg << "\n";}
void Console::intro()
{
    std::string intro;
    intro.append("-----------------------------------------------------------------------------------------\n");
    intro.append("Welcome to the " + projectName + "project\n");
    intro.append("-----------------------------------------------------------------------------------------\n");
    std::cout << intro;
}

Console::~Console(){}

