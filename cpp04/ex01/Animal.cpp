#include "Animal.hpp"

Animal::Animal()
{
    type = "";
    std::cout << "default Constructor Animal is called!\n";
}

Animal::Animal(std::string str)
{
    type = "";
    std::cout << str << " Constructor Animal is called!\n";
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Copy constructor Animal is called!\n";
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << "Copy assignement Animal is called!\n";
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "No Sound!\n";
}

Animal::~Animal()
{
    std::cout << "Deconstructor Animal is called!\n";
}