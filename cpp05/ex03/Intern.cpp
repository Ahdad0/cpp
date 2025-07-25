#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& obj)
{
    *this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
    if (this != &obj)
    {
    }
    return *this;
}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    AForm *ret = NULL;
    int i = 0;

    storeCon tmp[3] = {
        {"robotomy request", new RobotomyRequestForm(target)},
        {"shrubbery request", new ShrubberyCreationForm(target)},
        {"presidential request", new PresidentialPardonForm(target)}
    };

    while (i < 3)
    {
        if (tmp[i].form_name == form_name)
            ret = tmp[i].concrete;
        else
            delete tmp[i].concrete;
        i++;
    }
    
    return ret;
}