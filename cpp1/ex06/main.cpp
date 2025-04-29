#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl obj;

    if (ac == 2)
        obj.complain(av[1]);
}
