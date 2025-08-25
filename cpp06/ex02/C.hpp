#pragma once

#include "Base.hpp"

class C : public Base
{
    public:
        void func()
        {
            std::cout << "C talks\n";
        }
        ~C() {};
};
