#pragma once

#include <iostream>

class Brain
{
    // private:
    public:
        std::string ideas[100];
        Brain();
        Brain(std::string str);
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        virtual ~Brain();

        virtual void makeSound() const;
        void    print_ideas();
        void    set_ideas(std::string str);

};