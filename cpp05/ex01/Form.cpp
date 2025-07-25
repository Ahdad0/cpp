#include "Form.hpp"

Form::Form()
    : name(""), sign_grade(0), execute_grade(0), check_grade(false)
{
    check_grades(sign_grade);
    check_grades(execute_grade);
}

Form::Form(std::string const name, int sign_grade, int execute_grade)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade), check_grade(false)
{
    check_grades(sign_grade);
    check_grades(execute_grade);
}

Form::Form(const Form& obj)
    : name(obj.name), sign_grade(obj.sign_grade), execute_grade(obj.execute_grade)
{
    *this = obj;
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->check_grade = obj.check_grade;
    }
    return *this;
}

Form::~Form()
{
}

void Form::beSigned(Bureaucrat &obj)
{
    try
    {
        std::cout << "grade of buca is " << obj.getGrade()
        << " the sign grade is " << sign_grade << "\n";
        if (obj.getGrade() > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (obj.getGrade() <= sign_grade)
            check_grade = true;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
        throw std::exception();
    }
}

const std::string& Form::getName() const
{
    return name;
}

bool    Form::get_CheckGrade() const
{
    return check_grade;
}

int     Form::get_sigGrade() const
{
    return sign_grade;
}

int     Form::get_executeGrade() const
{
    return execute_grade;
}


void Form::check_grades(int grade)
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

std::ostream& operator<<(std::ostream& os, const Form& b)
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
