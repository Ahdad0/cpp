#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "";
    std::cout << "default Constructor WrongCat is called!\n";
}

WrongCat::WrongCat(std::string str) : WrongAnimal(str)
{
    type = "";
    std::cout << str << " Constructor WrongCat is called!\n";
}

WrongCat::WrongCat(const WrongCat& obj)
{
    *this = obj;
    std::cout << "Copy constructor WrongCat is called!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

std::string WrongCat::getType() const
{
    return type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meeeeeeeeeoooooooow!\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Deconstructor WrongCat is called!\n";
}