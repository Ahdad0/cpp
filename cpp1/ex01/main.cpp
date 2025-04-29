#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(4, "abdo");
    int i = 0;
    while (i < 4)
    {
        zombies[i].announce();
        i++;
    }
    delete[] zombies;
}
