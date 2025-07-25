#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        const int sign_grade;
        const int execute_grade;
        bool check_grade;
    public:
        Form();
        Form(std::string const name, int sign_grade, int execute_grade);
        Form(const Form& obj);
        Form& operator=(const Form& obj);
        ~Form();

        void    increment_grade();
        void    decrement_grade();
        const std::string& getName() const;
        int getGrade() const;
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
};

std::ostream& operator<<(std::ostream& os, const Form& b);