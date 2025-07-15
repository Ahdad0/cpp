#include "Cat.hpp"

void    Cat::Set_typeCat()
{
    type = "Cat";
}

Cat::Cat()
{
    Set_typeCat();
    std::cout << "Constructor Cat is called!\n";
}

Cat::Cat(std::string str) : Animal(str)
{
    Set_typeCat();
    std::cout << str << "Constructor Cat is called!\n";
}

Cat::Cat(const Cat& obj)
{
    *this = obj;
    std::cout << "Copy constructor Cat is called!\n";
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meooow!\n";
}

Cat::~Cat()
{
    std::cout << "Deconstructor Cat is called!\n";
}