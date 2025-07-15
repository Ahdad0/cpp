#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap& obj)
    : name(obj.name), EnergyPoint(obj.EnergyPoint),
    AttackDamage(obj.AttackDamage), HitPoint(obj.HitPoint)
{
    std::cout << "ClapTrap " << name << " enter the fight\n";
}

ClapTrap::ClapTrap()
    : name(""), EnergyPoint(10),
    AttackDamage(0), HitPoint(10)
{
    std::cout << "ClapTrap " << name << " enter the fight\n";
}

ClapTrap::ClapTrap(std::string namee)
    : name(namee), EnergyPoint(10),
    AttackDamage(0), HitPoint(10)
{
    std::cout << "ClapTrap " << name << " enter the fight\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " exit the fight\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        this->AttackDamage = obj.AttackDamage;
        this->HitPoint = obj.HitPoint;
        this->EnergyPoint = obj.EnergyPoint;
    }
    return *this;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoint <= 0)
        std::cout << "ClapTrap " << this->name << " is dead!\n";
    else if (this->EnergyPoint <= 0)
        std::cout << "ClapTrap " << this->name
        << " can't be repaired because it has no energy points left!\n";
    else
    {
        this->EnergyPoint -= 1;
        this->HitPoint += amount;
        std::cout << "ClapTrap " << name << " adding "
        << amount << " to the health. now health is " << this->HitPoint << "!\n";
    }
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HitPoint <= 0)
        std::cout << "ClapTrap " << this->name
        << " can't attack because it dead!\n";
    else if (this->EnergyPoint <= 0)
        std::cout << "ClapTrap " << this->name
        << " can't attack because it has no energy points left!\n";
    else
    {
        this->EnergyPoint -= 1;
        std::cout << "ClapTrap " << name << " attacks " << target
        << ", causing " <<  AttackDamage << " points of damage!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoint <= 0)
        std::cout << "ClapTrap " << this->name << " is dead!\n";
    else
    {
        this->HitPoint -= amount;
        std::cout << "ClapTrap " << name << " has taken "
        <<  amount << " points of damage";
        if (this->HitPoint <= 0)
            std::cout << ", it has 0 of health and is now defeated!\n";
        else
            std::cout << ", now it has " << HitPoint << " health point!\n";
    }
}