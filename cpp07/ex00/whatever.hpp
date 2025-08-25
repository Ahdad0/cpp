#pragma once

#include <iostream>

template <typename T>

void swap(T& arg0, T& arg1)
{
    T tmp = arg0;
    arg0 = arg1;
    arg1 = tmp;
}

template <typename T>

T min(T arg0, T arg1)
{
    if (arg0 > arg1)
        return arg1;
    else if (arg0 < arg1)
        return arg0;
    return arg1;
}

template <typename T>

T max(T arg0, T arg1)
{
    if (arg0 > arg1)
        return arg0;
    else if (arg0 < arg1)
        return arg1;
    return arg1;
}