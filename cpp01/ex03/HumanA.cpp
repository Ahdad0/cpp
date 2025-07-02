#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string username, Weapon& weapon_type) : weapon(weapon_type)
{
    name = username;
    type = weapon.getType();
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " <<  weapon.getType() << std::endl;
}
