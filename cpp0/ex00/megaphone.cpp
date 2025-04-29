#include <iostream>

int main(int ac, char **av)
{
    std::string store;
    int         i;

    (void)av;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        i = 1;
        while (av[i])
        {
            store += av[i];
            i++;
        }
        i = 0;
        while (store[i])
        {
            if (store[i] >= 97 && store[i] <= 122)
                store[i] = store[i] - 32;
            else
                store[i] = store[i];
            i++;
        }
        std::cout << store << std::endl;
    }
}