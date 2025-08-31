#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
    private:
        unsigned int max_int;
        std::vector<int> numbers;
    public:
        Span(unsigned int i);
        Span();
        Span(const Span& obj);
        Span& operator=(const Span& obj);

        void addNumber(int i);
        int shortestSpan();
        int longestSpan();
        void addInumber(int many);

        ~Span();
};
