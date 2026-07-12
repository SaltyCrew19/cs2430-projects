//Console.h
#pragma once
#include <iostream>
#include <sstream>

class Console
{
    private:
        std::string projectName;
    public:
        Console(/* args */);
        Console(std::string name);
        void intro();
        void print(std::stringstream &msg);
        void print(const std::string &msg);
        void error(std::stringstream &msg);
        void error(const std::string &msg);
        ~Console();
};

