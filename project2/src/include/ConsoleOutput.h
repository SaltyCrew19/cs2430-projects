//consoleOutput.h
#pragma once
#include <iostream>
#include <sstream>

class ConsoleOutput
{
    private:
        std::string projectName;
    public:
        ConsoleOutput(/* args */);
        ConsoleOutput(std::string name);
        void intro();
        void print(std::stringstream);
        void print(std::string);
        ~ConsoleOutput();
};

