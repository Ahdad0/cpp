#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    int i;

    i = 0;
    while (i < N)
    {
        zombies[i].SetName(name);
        i++;
    }
    return zombies;
}
