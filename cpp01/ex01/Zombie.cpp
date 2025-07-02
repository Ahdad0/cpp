#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << ": is destroyed!" << std::endl;
}

Zombie::Zombie()
{
    name = "unamed";
}

void    Zombie::SetName(std::string namee)
{
    name = namee;
}
