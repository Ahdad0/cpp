#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(3);
        sp.addNumber(1323);
        sp.addNumber(30);
        sp.addNumber(1);
        std::cout << "small: " << sp.shortestSpan() << std::endl;
        std::cout << "long: " << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}