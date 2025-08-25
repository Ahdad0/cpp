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

void ScalarConverter::isInt(std::string str)
{
    char *end;
    double d = std::strtod(str.c_str(), &end);
    if (*end != '\0')
    {
        std::cerr << "Error\n";
        return;
    }
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    float f = static_cast<float>(d);

    if (std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: Impossible\n";
    else if (!std::isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f < -FLT_MAX || f > FLT_MAX)
        std::cout << "float: Impossible\n";
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::isinf(d))
        std::cout << "double: Impossible" << std::endl;
    else    
       std::cout << "double: " << d << std::endl;
}

void ScalarConverter::isChar(std::string str)
{
    char c = str[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (!isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (i > INT_MAX || i < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalarConverter::isFloat(std::string str)
{
    char *end;
    double d =  std::strtod(str.c_str(), &end);
    if (*end != '\0' && *end != 'f')
    {
        std::cerr << "Error\n";
        return;
    }
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    float f = static_cast<float>(d);

    if (std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: Impossible\n";
    else if (!std::isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f < -FLT_MAX || f > FLT_MAX)
        std::cout << "float: Impossible\n";
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

    if (std::isinf(d))
        std::cout << "double: Impossible" << std::endl;
    else    
       std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalarConverter::isDouble(std::string str)
{
    char *end;
    double d = std::strtod(str.c_str(), &end);
    if (*end != '\0')
    {
        std::cerr << "Error\n";
        return;
    }
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    float f = static_cast<float>(d);
    
    if (std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: Impossible\n";
    else if (!std::isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f < -FLT_MAX || f > FLT_MAX)
        std::cout << "float: Impossible\n";
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

    if (std::isinf(d))
        std::cout << "double: Impossible" << std::endl;
    else    
       std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalarConverter::print_info(std::string str, int type)
{
    if (type == 2)
        isInt(str);
    else if (type == 0)
        isChar(str);
    else if (type == 1)
        isFloat(str);
    else if (type == 3)
        isDouble(str);
}

int ScalarConverter::check_type(std::string str)
{
    int i = 0;
    int dot = 0;

    if (std::isalpha(str[0]) && !str[1])
        return 0;
    while (str[i])
    {
        if (str[i] == '.')
            dot++;
        i++;
    }
    if (str[i - 1] == 'f' && dot == 1)
        return 1;
    if (dot != 0)
        return 3;
    return 2;
}

void ScalarConverter::scien_c_e(std::string str)
{
    char *end;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << std::strtod(str.c_str(), &end) << "f" << std::endl;
    std::cout << "double: " << std::strtod(str.c_str(), &end) << std::endl;
}

void ScalarConverter::convert(char *str)
{
    std::string n = to_string(str);
    if (n == "-inff" || n == "+inff" || n == "-inf"
        || n == "+inf" || n == "nan" || n == "inff"
        || n == "inf")
        scien_c_e(n);
    else
    {
        if (str[1])
        {
            char *end;
            double check = std::strtod(str, &end);
            if ((*end != '\0' && *end != 'f') || (n.length() == 0 && !*end))
            {
                std::cerr << "Error: " << end << std::endl;
                return;
            }
            (void)check;
        }
        int type = check_type(n);
        if (type == -1)
        {
            std::cerr << "Invalid input!\n";
            return;
        }
        print_info(n, type);
    }
}
