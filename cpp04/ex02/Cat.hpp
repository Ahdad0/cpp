#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        ~Cat();

        void    Set_typeCat();
        void    makeSound() const;

        void    print_ideas();
        void    set_ideas(std::string str);
};