#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << ": is destroyed!" << std::endl;
}

Zombie::Zombie(std::string UserName)
{
    name = UserName;
}
