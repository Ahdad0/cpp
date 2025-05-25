#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string username)
{
    weapon = NULL;
    name = username;
}

void    HumanB::setWeapon(Weapon &weaponn)
{
    weapon = &weaponn;
    type = weapon->getType();
}

void HumanB::attack(void)
{
    if (!weapon)
    {
        std::cout << name << " Have not a weopen" << std::endl;
        return ;
    }
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
