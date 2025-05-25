#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string namee )
{
    int     i = 0;
    Zombie *zombies = new Zombie[N];

    while (i < N)
    {
        zombies[i].SetName(namee);
        i++;
    }
    return zombies;
}
