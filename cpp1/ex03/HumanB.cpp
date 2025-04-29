#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string username)
{
    name = username;
}

void    HumanB::setWeapon(Weapon &weaponn)
{
    weapon = &weaponn;
    type = weapon->getType();
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
