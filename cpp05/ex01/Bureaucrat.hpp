#pragma once

#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
         std::string const name;
         int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        ~Bureaucrat();

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

        void signForm(Form &obj);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);