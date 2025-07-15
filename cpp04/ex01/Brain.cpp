#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "default Constructor Brain is called!\n";
}

Brain::Brain(std::string str)
{
    std::cout << str << " Constructor Brain is called!\n";
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Copy constructor Brain is called!\n";
    *this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = obj.ideas[i];
            i++;
        }
    }
    std::cout << "Copy assignement Brain is called!\n";
    return *this;
}

void Brain::makeSound() const
{
    std::cout << "No Sound!\n";
}

Brain::~Brain()
{
    std::cout << "Deconstructor Brain is called!\n";
}

void    Brain::print_ideas()
{
    int i = 0;
    while (i < 100)
    {
        std::cout << i << ": " << ideas[i] << std::endl;
        i++;
    }
}

void    Brain::set_ideas(std::string str)
{
    int i = 0;
    while (i < 100)
    {
        ideas[i] =  str;
        i++;
    }
}