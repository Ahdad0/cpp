#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    public:
        void announce( void );
        Zombie(std::string UserName);
        ~Zombie();

    private:
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif