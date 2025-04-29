#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *zo = new Zombie(name);
    return zo;
}
