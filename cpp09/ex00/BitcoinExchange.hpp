#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
    public:
        void store_data(const char *file);
        void print_data(const char *file);
        int check_line(std::string str, int i);
        void remove_whitespaces(std::string& str);
        std::vector<std::string> parse_string(std::string str, char del);

        int error_bad_input(std::string& str);

        int check_numbers(std::string& str);
};
