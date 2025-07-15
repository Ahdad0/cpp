#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // {
    //     const Animal* meta = new Animal();
    //     const Animal* j = new Dog();
    //     const Animal* i = new Cat();
    //     std::cout << j->getType() << " " << std::endl;
    //     std::cout << i->getType() << " " << std::endl;
    //     i->makeSound();
    //     j->makeSound();
    //     meta->makeSound();
    //     delete j;
    //     delete i;
    //     delete meta;
    // }
    // {
    //     const   WrongAnimal* cat = new WrongCat();
    //     cat->makeSound();
    //     delete cat;
    // }
    // {
    //     int i = 0;
    //     const Animal* a[10];
    //     while (i < 5)
    //     {
    //         a[i] = new Dog();
    //         i++;
    //     }
    //     while (i < 10)
    //     {
    //         a[i] = new Cat();
    //         i++;
    //     }
    //     std::cout << "-----------------\n";
    //     a[0]->makeSound();
    //     a[6]->makeSound();
    //     std::cout << "-----------------\n";
    //     i = 0;
    //     while (i < 10)
    //     {
    //         delete a[i];
    //         i++;
    //     }
    // }
    {
        Brain a;
        a.set_ideas("aaaaaaaaa");
        Brain b = a;
        b.print_ideas();
    }
}