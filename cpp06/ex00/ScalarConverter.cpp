#include "ScalarConverter.hpp"

int  ScalarConverter::string_lenght(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

std::string ScalarConverter::to_string(char *str)
{
    std::string tmp = str;
    return tmp;
}

int ScalarConverter::check_type(std::string str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return 1;
    else if (std::isdigit(str[0]))
    {
        int i = 0;
        while (str[i])
        {
            if (!std::isdigit(str[i]))
                return -1;
            i++;
        }
        return 2;
    }
    return -1;
}
