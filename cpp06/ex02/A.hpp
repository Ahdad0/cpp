#pragma once

#include "Base.hpp"

class A : public Base
{
    public:
        void func()
        {
            std::cout << "A talks\n";
        }
        ~A() {};
};
