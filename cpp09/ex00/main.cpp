#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        (void)av;
        if (ac != 2)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        BitcoinExchange obj;
        obj.store_data("data.csv");
        obj.print_data(av[1]);
    }
    catch(const std::exception& e) {}
}