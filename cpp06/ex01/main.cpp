#include "Serializer.hpp"

int main()
{
    Data a;
    a.i = 66;

    uintptr_t raw = Serializer::serialize(&a);
    Data *b = Serializer::deserialize(raw);
    if (&a == b)
    {
        std::cout << "Equal!\n";
        std::cout << "a has " << &a << "\n";
        std::cout << "b has " << b << "\n";
    }
    std::cout << "b.i == " << b->i << "\n";
    return 0;
}