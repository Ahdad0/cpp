#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        else
        {
            PmergeMe a;
            a.deque(av);
            a.list(av);
            a.print_before_after();
            a.print_time();
        }
    }
    catch(const std::exception& e){}
}