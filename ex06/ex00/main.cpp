#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    (void)ac;
    if (ac != 2)
        std::cerr << "Must be 1 argument!\n";
    else
    {
        std::string n = ScalarConverter::to_string(av[1]);
        if (ScalarConverter::check_type(n) == 1)
        {
            std::cout << "is char\n";
        }
        else if (ScalarConverter::check_type(n) == 2)
            std::cout << "an int\n";
        else if (ScalarConverter::check_type(n) == -1)
            std::cout << "it must be char or int or float or double!\n";
        std::cout << n << "\n";
    }
}