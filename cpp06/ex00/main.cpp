#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cerr << "Must be 1 argument!\n";
    else
        ScalarConverter::convert(av[1]);
}