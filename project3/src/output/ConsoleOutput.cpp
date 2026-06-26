#include "consoleOutput.h"
#include <iostream>

ConsoleOutput::ConsoleOutput(){this->projectName = "[c++System] ";}
ConsoleOutput::ConsoleOutput(std::string name){this -> projectName = "[" + name + "] ";}

void ConsoleOutput::print(std::stringstream msg){std::cout << projectName << msg.str() << std::endl;}
void ConsoleOutput::print(std::string msg){std::cout << projectName << msg << std::endl;}
void ConsoleOutput::intro()
{
    std::string intro;
    intro.append("-----------------------------------------------------------------------------------------\n");
    intro.append("Welcome to the " + projectName + "project\n");
    intro.append("-----------------------------------------------------------------------------------------\n");
    std::cout << intro;
}

ConsoleOutput::~ConsoleOutput(){}
