#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    *this = obj;
    std::cout << "ClapTrap " << name << " enter the fight\n";
}

ClapTrap::ClapTrap()
{
    HitPoint = 10;
    EnergyPoint = 10;
    AttackDamage = 0;
    name = "";
    std::cout << "ClapTrap " << name << " enter the fight\n";
}

ClapTrap::ClapTrap(std::string namee)
{
    HitPoint = 10;
    EnergyPoint = 10;
    AttackDamage = 0;
    name = namee;
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
    if (this->EnergyPoint == 0)
        std::cout << "ClapTrap " << this->name << " can't repaire because of the 0 energy point!\n";
    else
    {
        this->EnergyPoint -= 1;
        this->HitPoint += amount;
        std::cout << "ClapTrap " << name << " adding "
        << amount << " hit points back. now Energy point is " << this->HitPoint << std::endl;
    }
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EnergyPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack because of the 0 energy point!\n";
    }
    else
    {
        this->EnergyPoint -= 1;
        std::cout << "ClapTrap " << name << " attacks " << target;
        std::cout << ", causing " <<  AttackDamage << " points of damage!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!\n";
    }
    else
    {
        this->HitPoint -= amount;
        std::cout << "ClapTrap " << name << " has taken "
        <<  amount << " points of damage";
        if (this->HitPoint <= 0)
            std::cout << ", he has " << HitPoint << " of health. so he is dead!" << std::endl;
        else
            std::cout << ", now he has " << HitPoint << std::endl;
    }
}