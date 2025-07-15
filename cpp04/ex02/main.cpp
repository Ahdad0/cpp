#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    {
        AAnimal *a = new Cat();
        a->makeSound();
        delete a;
    }
    std::cout << "------------------\n";
    {
        AAnimal *a = new Dog();
        a->makeSound();
        delete a;
    }
}