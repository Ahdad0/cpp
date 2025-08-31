#include "Span.hpp"

Span::Span(unsigned int i) : max_int(i)
{
}

Span::Span() : max_int(0)
{
}

Span::Span(const Span &obj) : max_int(obj.max_int)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        if (numbers.size() != 0)
            numbers.clear();
        size_t i = 0;
        while (i < obj.numbers.size())
        {
            numbers.push_back(obj.numbers[i]);
            i++;
        }
    }
    return *this;
}

void Span::addNumber(int i)
{
    if (numbers.size() == max_int)
        throw std::exception();
    numbers.push_back(i);
}

void Span::addInumber(int many)
{
    int i = 0;
    while (i < many)
    {
        addNumber(std::rand());
        i++;
    }
}

int Span::longestSpan()
{
    if (numbers.size() == 0 || numbers.size() == 1)
        throw std::exception();
    std::sort(numbers.begin(), numbers.end());
    int big = numbers.back() - numbers.front();
    return big;
}

int Span::shortestSpan()
{
    if (numbers.size() == 0 || numbers.size() == 1)
        throw std::exception();
    std::sort(numbers.begin(), numbers.end());
    size_t i = 0;
    std::vector<int> n;
    while (i < numbers.size())
    {
        if (i + 1 == numbers.size())
            break;
        n.push_back(numbers[i + 1] - numbers[i]);
        i++;
    }
    std::vector<int>::iterator it = std::min_element(n.begin(), n.end());
    int small = *it;
    return small;
}

Span::~Span()
{
}