#include "Zombie.hpp"

int main()
{
    {
        Zombie zo("abdo");
        zo.announce();
    }
    {
        std::cout << std::endl;
        Zombie *zo = newZombie("mpsy");
        zo->announce();
        delete zo;
    }
    {
        std::cout << std::endl;
        randomChump("ahdad");
    }
}
