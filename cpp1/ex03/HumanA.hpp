#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string user_name, Weapon &weapon_type);
        void    attack(void);
        Weapon& weapon;

    private:
        std::string type;
        std::string name;
};
