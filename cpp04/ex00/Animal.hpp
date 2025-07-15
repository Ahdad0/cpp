#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string str);
        Animal(const Animal& obj);
        Animal& operator=(const Animal& obj);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};