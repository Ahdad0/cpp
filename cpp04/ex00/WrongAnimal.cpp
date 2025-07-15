#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "";
    std::cout << "default Constructor WrongAnimal is called!\n";
}

WrongAnimal::WrongAnimal(std::string str)
{
    type = "";
    std::cout << str << " Constructor WrongAnimal is called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    *this = obj;
    std::cout << "Copy constructor WrongAnimal is called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Hoooooooooooow!\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Deconstructor WrongAnimal is called!\n";
}