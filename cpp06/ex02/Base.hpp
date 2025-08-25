#pragma once

class A;
class B;
class C;

#include <iostream>

class Base
{
    public:
        virtual void func()
        {
            std::cout << "Base talks\n";
        }
        virtual ~Base() {};
};
