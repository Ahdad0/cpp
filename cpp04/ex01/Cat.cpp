#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "cat";
    brain = new Brain();
    std::cout << "Constructor Cat is called!\n";
}

Cat::Cat(std::string str) : Animal(str)
{
    type = "cat";
    brain = new Brain(str);
    std::cout << str << " Constructor Cat is called!\n";
}

Cat::Cat(const Cat& obj) : brain(NULL)
{
    std::cout << "Copy constructor Cat is called!\n";
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    std::cout << "copy assignement Cat is been called!\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meooow!\n";
}

Cat::~Cat()
{
    if (brain)
        delete brain;
    std::cout << "Deconstructor Cat is called!\n";
}

void    Cat::print_ideas()
{
    int i = 0;
    while (i < 100)
    {
        std::cout << i << ": " << brain->ideas[i] << std::endl;
        i++;
    }
}

void    Cat::set_ideas(std::string str)
{
    int i = 0;
    while (i < 100)
    {
        brain->ideas[i] =  str;
        i++;
    }
}