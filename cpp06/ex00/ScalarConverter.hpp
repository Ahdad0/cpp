#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter() {};
    public:
        static  void convert(char *str);
        static void scien_c_e(std::string str);
        static  int string_lenght(char *str);
        static  std::string to_string(char *str);
        static  int check_type(std::string str);
        static  void print_info(std::string str, int type);
        static  void isInt(std::string str);
        static  void isChar(std::string str);
        static  void isFloat(std::string str);
        static  void isDouble(std::string str);
};
