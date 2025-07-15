#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("NoOne_clap_name")
{
    HitPoint = FragTrap::HitPoint;
    EnergyPoint = ScavTrap::EnergyPoint;
    AttackDamage = FragTrap::get_Vattack();
    name = "NoOne";
    std::cout << "DiamondTrap " << name << " enter the fight\n";
}

DiamondTrap::DiamondTrap(std::string namee)
    : ClapTrap(namee + "_clap_name")
{
    HitPoint = FragTrap::HitPoint;
    EnergyPoint = ScavTrap::EnergyPoint;
    AttackDamage = FragTrap::get_Vattack();
    name = namee;
    std::cout << "DiamondTrap " << name << " enter the fight\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj)
{
    std::cout << "DiamondTrap " << name << " enter the fight\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "name is " << this->name << " and ClapTrap name is "
    << ClapTrap::name << "\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has exit the fight\n";
}
