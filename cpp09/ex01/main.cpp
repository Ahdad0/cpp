#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        else
        {
            RPN a;
            a.check_add(av[1]);
            a.calculate();
        }
    }
    catch(const std::exception& e)
    {
    }
    
}