#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    this->grade = grade;
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        this->grade = obj.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void    Bureaucrat::increment_grade()
{
    try
    {
        if (grade <= 1)
            throw Bureaucrat::GradeTooHighException();
        grade--;
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
}

void    Bureaucrat::decrement_grade()
{
    try
    {
        if (grade >= 150)
            throw Bureaucrat::GradeTooLowException();
        grade++; 
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
        throw std::exception();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too hight!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}