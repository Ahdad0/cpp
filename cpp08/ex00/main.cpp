#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> a;
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    std::list<int> b;
    b.push_back(2);
    b.push_back(1);
    b.push_back(5);
    easyfind(b, 1);
    easyfind(a, 12);
}