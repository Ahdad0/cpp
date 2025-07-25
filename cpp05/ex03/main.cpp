#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someIntern;
    Bureaucrat bob("Bob", 1);
    AForm* form = someIntern.makeForm("shrubbery request", "Bender");
    if (form)
    {
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
}