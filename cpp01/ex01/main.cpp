#include "Zombie.hpp"

int main()
{
    int i = 0;
    Zombie *zombies = zombieHorde(4, "abdo");

    while (i < 4)
    {
        zombies[i].announce();
        i++;
    }
    delete[] zombies;
}
