#include "Zombie.hpp"

int main()
{
    Zombie *zo = newZombie("abdo ahdad");
    zo->announce();
    randomChump("Mpsy");
    delete zo;
}
