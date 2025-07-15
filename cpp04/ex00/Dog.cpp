#include "Dog.hpp"

void    Dog::Set_typeDog()
{
    type = "Dog";
}

Dog::Dog()
{
    Set_typeDog();
    std::cout << "Constructor Dog is called!\n";
}

Dog::Dog(std::string str) : Animal(str)
{
    Set_typeDog();
    std::cout << str << "Constructor Dog is called!\n";
}

Dog::Dog(const Dog& obj)
{
    *this = obj;
    std::cout << "Copy constructor Dog is called!\n";
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Hoooow!\n";
}

Dog::~Dog()
{
    std::cout << "Deconstructor Dog is called!\n";
}