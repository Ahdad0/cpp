#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T container, int i)
{
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        std::cout << "Found It" << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}
