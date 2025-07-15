#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        ~Cat();

        void    Set_typeCat();
        void    makeSound() const;
};