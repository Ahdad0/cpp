#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        ~Cat();

        void    makeSound() const;

        void    print_ideas();
        void    set_ideas(std::string str);
};