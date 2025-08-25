#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    AForm* form;
    try
    {
        Intern someIntern;
        Bureaucrat bob("Bob", 150);
        form = someIntern.makeForm("shrubbery request", "Bender");
        if (form)
        {
            bob.signForm(*form);
            form->execute(bob);
            delete form;
        }
        else
            std::cerr << "Unknown name form!\n";
    }
    catch(const std::exception& e)
    {
        delete form;
        std::cerr << "throw an exception : " << e.what() << '\n';
    }
}