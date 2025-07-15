#include "FragTrap.hpp"

int main()
{
    FragTrap b("abdo");
    FragTrap a;

    a = b;
    a.attack("ahdad");
    a.beRepaired(10);
    a.takeDamage(10);

}