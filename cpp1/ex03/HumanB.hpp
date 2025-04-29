#pragma once
#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string user_name);
        void    attack(void);
        void    setWeapon(Weapon &weaponn);
        Weapon* weapon;

    private:
        std::string type;
        std::string name;
};

#endif