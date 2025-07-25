#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("mpsy", 150);
        std::cout << b << std::endl;
        Bureaucrat a = b;
        std::cout << a << std::endl;
        b.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "throw an exception : " << e.what() << '\n';
    }
}
