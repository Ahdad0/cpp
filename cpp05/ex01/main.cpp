#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a;
    }
    catch(const std::exception& e)
    {
        std::cerr << "throw an exception : " << e.what() << '\n';
    }
    {
        try
        {
            Bureaucrat b0("abdo", 150);
            Form f0("regular form", 100, 100);
            std::cout << b0 << std::endl;
            std::cout << f0 << std::endl;
            b0.decrement_grade();
            b0.signForm(f0);
            b0.increment_grade();
            std::cout << b0 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat b1("Alice", 3);
            Bureaucrat b2("Bob", 148);
            Form f1("TopSecret", 4, 10);
            Form f2("Basic", 150, 150);
            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;
            std::cout << f1 << std::endl;
            std::cout << f2 << std::endl;
            b1.increment_grade();
            b2.decrement_grade();
            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;
            b1.signForm(f1);
            b2.signForm(f2);
        }
        catch(const std::exception& e)
        {
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat b("Multi", 5);
            Form f1("A", 5, 10);
            Form f2("B", 4, 10);
            Form f3("C", 6, 10);

            b.signForm(f1);
            b.signForm(f2);
            b.signForm(f3);
        }
        catch(const std::exception& e)
        {
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat b0("abdo", 3);
            Form f0("reguler", 4, 100);
            std::cout << b0 << std::endl;
            b0.decrement_grade();
            std::cout << b0 << std::endl;
            b0.decrement_grade();
            std::cout << b0 << std::endl;
            b0.signForm(f0);
        }
        catch(const std::exception& e)
        {
            std::cerr << "throw an exception : " << e.what() << '\n';
        }
    }
}