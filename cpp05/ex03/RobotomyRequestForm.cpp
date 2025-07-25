#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
    : AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
    *this = obj;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->get_CheckGrade() == true && executor.getGrade() <= this->get_executeGrade())
        {
            srand(time(NULL));
            std::cout << "Bzzzzzzzzzzzzz...\n";
            int random_number = (rand() % 2) + 1;
            if (random_number == 1)
            {
                std::cout << executor.getName() << " has been robotomized successfully\n";
            }
            else
                std::cout << executor.getName() << " robotomy failed\n";
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

