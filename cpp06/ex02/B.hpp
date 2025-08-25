#pragma once

#include "Base.hpp"

class B : public Base
{
    public:
        void func()
        {
            std::cout << "B talks\n";
        }
        ~B() {};
};
