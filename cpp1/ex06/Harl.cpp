#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
    int index = 0;

    std::string arg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (index < 4)
    {
        if (level == arg[index])
            break;
        index++;
    }
    // if (index == 4)
    //     exit(1);
    void    (Harl::*func[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    switch (index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*func[0])();
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            (this->*func[1])();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*func[2])();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*func[3])();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
