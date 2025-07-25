#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);
        ~Intern();

        AForm* makeForm(std::string form_name, std::string target);
};

struct storeCon
{
    std::string form_name;
    AForm* concrete;
};
