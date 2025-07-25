#pragma once

#include <iostream>

class ScalarConverter
{
    public:
        static int  string_lenght(char *str);
        static  std::string to_string(char *str);
        static int check_type(std::string str);
};
