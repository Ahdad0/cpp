#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!\n";
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << "FragTrap " << name << " enter the fight\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj) 
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

FragTrap::FragTrap() : ClapTrap()
{
    this->HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " enter the fight\n";
}

FragTrap::FragTrap(std::string namee) : ClapTrap(namee)
{
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " enter the fight\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " exit the fight\n";
}

void FragTrap::attack(const std::string& target)
{
    if (this->HitPoint <= 0)
        std::cout << "FragTrap " << this->name
        << " can't attack because it dead!\n";
    else if (this->EnergyPoint <= 0)
        std::cout << "FragTrap " << this->name
        << " can't attack because it has no energy points left!\n";
    else
    {
        this->EnergyPoint -= 1;
        std::cout << "FragTrap " << name << " attacks " << target
        << ", causing " <<  AttackDamage << " points of damage!\n";
    }
}