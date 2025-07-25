#pragma once

#include "AForm.hpp"
#include <cstdlib> 
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

