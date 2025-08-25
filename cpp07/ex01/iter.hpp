#pragma once

#include <iostream>

template <typename T>

void forr(T *address_array, int lenght, void (*func)(T&))
{
    int i = 0;
    while (i < lenght)
    {
        func(*address_array);
        address_array++;
        i++;
    }
}
