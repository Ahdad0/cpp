#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <vector>

class Zombie
{
    public:
        void announce( void );
        Zombie();
        ~Zombie();
        void    SetName(std::string namee);

    private:
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif
