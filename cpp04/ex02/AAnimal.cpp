#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "";
    std::cout << "default Constructor AAnimal is called!\n";
}

AAnimal::AAnimal(std::string str)
{
    type = "";
    std::cout << str << " Constructor AAnimal is called!\n";
}

AAnimal::AAnimal(const AAnimal& obj)
{
    std::cout << "Copy constructor AAnimal is called!\n";
    *this = obj;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << "Copy assignement AAnimal is called!\n";
    return *this;
}

std::string AAnimal::getType() const
{
    return type;
}

AAnimal::~AAnimal()
{
    std::cout << "Deconstructor AAnimal is called!\n";
}