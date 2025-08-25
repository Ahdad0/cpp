#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        AForm *f0;
        try
        {
            Bureaucrat b0("fri", 30);
            f0 = new ShrubberyCreationForm("tree");
            
            b0.signForm(*f0);
            b0.executeForm(*f0);
            
            delete f0;
        }
        catch(const std::exception& e)
        {
            delete f0;
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
    {
        AForm *f0;
        try
        {
            Bureaucrat b0("mpsy", 140);
            f0 = new RobotomyRequestForm("robbot");
            b0.signForm(*f0);
            f0->execute(b0);
            delete f0;
        }
        catch(const std::exception& e)
        {
            delete f0;
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
}
