#include "contact.hpp"

void    contact::set_first_name(std::string name)
{
    first_name = name;
}

void    contact::get_first_name()
{
    std::cout << first_name << std::endl;
}

void    contact::set_last_name(std::string name)
{
    last_name = name;
}

void    contact::get_last_name()
{
    std::cout << last_name << std::endl;
}

void    contact::set_nickname_name(std::string name)
{
    nickname = name;
}

void    contact::get_nickname_name()
{
    std::cout << nickname << std::endl;
}

void    contact::set_darkest_secret(std::string name)
{
    darkest_secret = name;
}

void    contact::get_darkest_secret()
{
    std::cout << darkest_secret << std::endl;
}

void    contact::set_phone_number(std::string name)
{
    phone_number = name;
}

void    contact::get_phone_number()
{
    std::cout << phone_number << std::endl;
}

void    contact::display_all_info(int track)
{
    std::cout << "         " << track << "|";
    display_info(first_name);
    display_info(last_name);
    display_info(nickname);
    std::cout << std::endl;
}

void    contact::display_info(std::string string)
{
    unsigned long i = 0;
    if (string.length() > 10)
    {
        while (i < 9)
        {
            std::cout << string[i];
            i++;
        }
        std::cout << ".|";
    }
    else
    {
        std::cout << std::setw(11 - string.length());
        i = 0;
        while (i < string.length())
        {
            std::cout << string[i];
            i++;
        }
        std::cout << "|";
    }
}
