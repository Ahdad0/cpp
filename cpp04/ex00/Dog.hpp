#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string str);

        Dog(const Dog& obj);
        Dog& operator=(const Dog& obj);
        ~Dog();

        void    Set_typeDog();
        void    makeSound() const;
};