#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "dog";
    brain = new Brain();
    std::cout << "Constructor Dog is called!\n";
}

Dog::Dog(std::string str) : Animal(str)
{
    type = "dog";
    brain = new Brain(str);
    std::cout << str << "Constructor Dog is called!\n";
}

Dog::Dog(const Dog& obj) : brain(NULL)
{
    std::cout << "Copy constructor Dog is called!\n";
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    std::cout << "copy assignement Dog is been called!\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Hoooow!\n";
}

Dog::~Dog()
{
    if (brain)
        delete brain;
    std::cout << "Deconstructor Dog is called!\n";
}

void    Dog::print_ideas()
{
    int i = 0;
    while (i < 100)
    {
        std::cout << i << ": " << brain->ideas[i] << std::endl;
        i++;
    }
}

void    Dog::set_ideas(std::string str)
{
    int i = 0;
    while (i < 100)
    {
        brain->ideas[i] = str;
        i++;
    }
}