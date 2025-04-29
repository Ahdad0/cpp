#include "phonebook.hpp"

void Phonebook::display_contact(int num)
{
    std::cout << "First name: ";
    contacts[num].get_first_name();
    std::cout << std::endl;
    std::cout << "Last name: ";
    contacts[num].get_last_name();
    std::cout << std::endl;
    std::cout << "Nickname: ";
    contacts[num].get_nickname_name();
    std::cout << std::endl;
    std::cout << "Phone number: ";
    contacts[num].get_phone_number();
    std::cout << std::endl;
    std::cout << "Darkest secret: ";
    contacts[num].get_darkest_secret();
    std::cout << std::endl;
}

void Phonebook::add_contact(const contact &obj)
{
    if (index == 8)
        index = 0;
    contacts[index] = obj;
    if (index > last)
        last = index;
    index++;
}

void Phonebook::display_contacts()
{
    while (track <= last)
    {
        contacts[track].display_all_info(track);
        track++;
    }
    track = 0;
}
