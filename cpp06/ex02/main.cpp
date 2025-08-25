#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    Base *tmp = NULL;

    std::srand(std::time(0));
    int a = std::rand() % 3;

    if (a == 0)
    {
        tmp = new A();
    }
    else if (a == 1)
    {
        tmp = new B();
    }
    else if (a == 2)
    {
        tmp = new C();
    }
    return tmp;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        (void)a;
    }
    catch (std::exception&) {}

    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        (void)b;
    }
    catch (std::exception&) {}
    
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C\n";
        (void)c;
    }
    catch (std::exception&) {}
}

int main()
{
    Base *tmp = generate();
    tmp->func();
    identify(tmp);
    delete tmp;
}
