#include "iter.hpp"

template <typename T>
void func(T &a)
{
    a = 'a';
}

int main()
{
    char a[] = "None";
    int i = 0;
    while (i < 4)
    {
        std::cout << a[i] << std::endl;
        i++;
    }
    ::forr(a, 4, func);
    std::cout << "-------------------\n";
    i = 0;
    while (i < 4)
    {
        std::cout << a[i] << std::endl;
        i++;
    }
}