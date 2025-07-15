#pragma once

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int EnergyPoint;
        int AttackDamage;
        int HitPoint;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& obj);
        ClapTrap& operator=(const ClapTrap& obj);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        virtual ~ClapTrap();
};