#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <cstdlib>

void    add_func(contact &New)
{
    std::string name;

    while (1)
    {
        std::cout << "Enter your first name: ";
        std::getline(std::cin, name);
        New.set_first_name(name);
        if (!name.empty())
            break;
    }
    while (1)
    {
        std::cout << "Enter your last name: ";
        std::getline(std::cin, name);
        New.set_last_name(name);
        if (!name.empty())
            break;
    }
    while (1)
    {
        std::cout << "Enter your nickname: ";
        std::getline(std::cin, name);
        New.set_nickname_name(name);
        if (!name.empty())
            break;
    }
    while (1)
    {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, name);
        New.set_phone_number(name);
        if (!name.empty())
            break;
    }
    while (1)
    {
        std::cout << "Enter your darkest secret: ";
        std::getline(std::cin, name);
        New.set_darkest_secret(name);
        if (!name.empty())
            break;
    }
}

void    search_func(Phonebook book)
{
    std::string input;
    int num;

    std::cout << "     Index|first name| last name|  nickname|" << std::endl;
    book.display_contacts();
    std::cout << "Enter an index: ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    ss >> num;
    if (ss.fail() || num > book.last || num < 0)
        std::cout << "Wrong amigos!" << std::endl;
    else
        book.display_contact(num);
}

int main()
{
    contact New;
    Phonebook book;
    std::string Str;
    std::string name;

    std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
    while (1)
    {
        std::cout << "Enter ADD, SEARCH, EXIT: ";
        std::getline(std::cin, Str);
        system("clear");
        if (std::string(Str) == "ADD")
        {
            add_func(New);
            book.add_contact(New);
        }
        else if (std::string(Str) == "SEARCH")
            search_func(book);
        else if (std::string(Str) == "EXIT")
        {
            std::cout << "Bye!" << std::endl;
            exit(0);
        }
    }
    return 0;
}
