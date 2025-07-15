#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("abdo");
    ClapTrap b("mpsy");

    a.takeDamage(200);
    b.attack("abdo");
    a.beRepaired(10);
}