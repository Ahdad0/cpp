#include "Weapon.hpp"

Weapon::Weapon(std::string we)
{
    setType(we);
}

const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string input)
{
    type = input;
}
