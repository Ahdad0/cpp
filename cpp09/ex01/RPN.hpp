#pragma once

#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

class RPN
{
    private:
        std::stack<std::string> stak;
        std::stack<std::string> calculate_stak;
        std::string first_num;
        std::string seconde_num;
    public:
        RPN();  
        void check_add(std::string str);
        std::string remove_spaces(std::string str);
        int calculate_operator(int first, int seconde, std::string op);
        void calculate();
        int check_type(std::string &str);

        void error();
};
