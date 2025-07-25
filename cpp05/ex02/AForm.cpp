#include "AForm.hpp"

AForm::AForm()
    : name(""), sign_grade(0), execute_grade(0), check_grade(false)
{
    throw std::exception();
}

AForm::AForm(std::string const name, int sign_grade, int execute_grade)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), check_grade(false)
{
    check_grades(sign_grade);
    check_grades(execute_grade);
}

AForm::AForm(const AForm& obj)
    : name(obj.name), sign_grade(obj.sign_grade), execute_grade(obj.execute_grade)
{
    *this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
    {
        this->check_grade = obj.check_grade;
    }
    return *this;
}

AForm::~AForm()
{
}

void    AForm::setGrade(bool b)
{
    check_grade = b;
}

void AForm::beSigned(Bureaucrat &obj)
{
    try
    {
        std::cout << obj.getGrade() << "\n";
        if (obj.getGrade() > 150)
        {
            check_grade = false;
            throw Bureaucrat::GradeTooLowException();
        }
        else if (obj.getGrade() < 1)
        {
            check_grade = false;
            throw Bureaucrat::GradeTooHighException();
        }
        else if (obj.getGrade() <= sign_grade && obj.getGrade() <= execute_grade)
            check_grade = true;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
        throw std::exception();
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
        throw std::exception();
    }
}

const std::string& AForm::getName() const
{
    return name;
}

bool    AForm::get_CheckGrade() const
{
    return check_grade;
}

int     AForm::get_sigGrade() const
{
    return sign_grade;
}

int     AForm::get_executeGrade() const
{
    return execute_grade;
}


void AForm::check_grades(int grade)
{
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

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os << b.getName() << " , required grade to sign is " << b.get_sigGrade()
    << " , required grade to execute is " << b.get_executeGrade()
    << " , bool of signed is ";
    if (b.get_CheckGrade() == true)
        os << "true";
    else
        os << "false";
    return os;
}
