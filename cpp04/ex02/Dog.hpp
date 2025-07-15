#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain* brain;
    public:
        Dog();
        Dog(std::string str);

        Dog(const Dog& obj);
        Dog& operator=(const Dog& obj);
        ~Dog();

        void    Set_typeDog();
        void    makeSound() const;
        void    print_ideas();
        void    set_ideas(std::string str);
};