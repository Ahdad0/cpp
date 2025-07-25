#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
    : AForm(name, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj)
{
    *this = obj;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->get_CheckGrade() == true && executor.getGrade() <= this->get_executeGrade())
        {
            std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n";
        }
        else if (executor.getGrade() > 150 || executor.getGrade() > this->get_executeGrade())
            throw Bureaucrat::GradeTooLowException();
        else if (executor.getGrade() < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            throw std::exception();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << "\n";
        throw std::exception();
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << "\n";
        throw std::exception();
    }
}

