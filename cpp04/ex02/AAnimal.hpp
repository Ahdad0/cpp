#pragma once

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string str);
        AAnimal(const AAnimal& obj);
        AAnimal& operator=(const AAnimal& obj);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string getType() const;
};