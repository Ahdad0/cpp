#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap " << name << " enter the fight\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << name << " enter the fight\n";
}

ScavTrap::ScavTrap(std::string namee) : ClapTrap(namee)
{
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << name << " enter the fight\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " exit the fight\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (this->HitPoint <= 0)
        std::cout << "ScavTrap " << this->name
        << " can't attack because it dead!\n";
    else if (this->EnergyPoint <= 0)
        std::cout << "ScavTrap " << this->name
        << " can't attack because it has no energy points left!\n";
    else
    {
        this->EnergyPoint -= 1;
        std::cout << "ScavTrap " << name << " attacks " << target
        << ", causing " <<  AttackDamage << " points of damage!\n";
    }
}