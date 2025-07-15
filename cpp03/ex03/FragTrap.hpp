#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        int copy_attack;
    public:
        FragTrap();
        FragTrap(std::string namee);
        FragTrap(const FragTrap& obj);
        FragTrap& operator=(const FragTrap& obj);
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys(void);
        int get_Vattack();
};