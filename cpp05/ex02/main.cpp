#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {

        Bureaucrat b0("MPSY", 1);
        AForm *f0 = new ShrubberyCreationForm("tree");
        b0.signForm(*f0);
        b0.increment_grade();
        b0.signForm(*f0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "throw an exception : " << e.what() << '\n';
    }
}
