#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "";
    std::cout << "default Constructor WrongCat is called!\n";
}

WrongCat::WrongCat(std::string str)
{
    type = "";
    std::cout << str << " Constructor WrongCat is called!\n";
}

WrongCat::WrongCat(const WrongCat& obj)
{
    std::cout << "Copy constructor WrongCat is called!\n";
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << "Copy assignement WrongCat is called!\n";
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