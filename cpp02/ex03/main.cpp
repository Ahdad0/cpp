#include "Point.hpp"

int main( void )
{
     Point a(2, 1);
     Point b(3, 2);
     Point c(5, 1);
     Point p(3, 3);

    if (bsp(a, b, c, p) == true)
        std::cout << "p is in the triangle\n";
    else
        std::cout << "is not\n";
    return 0;
}
