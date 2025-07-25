#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : AForm(name, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{
    *this = obj;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->get_CheckGrade() == true && executor.getGrade() <= this->get_executeGrade())
        {
            std::ofstream file((executor.getName() + "_shrubbery").c_str());
            if (!file)
                throw std::exception();
            file << "       ^\n";
            file << "      ^^^\n";
            file << "     ^^^^^\n";
            file << "    ^^^^^^^\n";
            file << "   ^^^^^^^^^\n";
            file << "      |||\n";
            file << "      |||\n";
            file.close();
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

