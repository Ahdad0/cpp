#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        const int sign_grade;
        const int execute_grade;
        bool check_grade;
    public:
        AForm();
        AForm(std::string const name, int sign_grade, int execute_grade);
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);
        ~AForm();

        void    increment_grade();
        void    decrement_grade();
        const std::string& getName() const;
        int getGrade() const;
        void    setGrade(bool b);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        void    beSigned(Bureaucrat &obj);
        bool    get_CheckGrade() const;
        int     get_sigGrade() const;
        int     get_executeGrade() const;
        void    check_grades(int grade);

        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);