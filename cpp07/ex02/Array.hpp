#pragma once

#include <iostream>

template <typename T>
class Array
{
    private:
        T *a;
        unsigned int i;

    public:
        Array() : a(NULL), i(0)
        {
            a = new T[0]();
        }

        Array(unsigned int i) : a(NULL), i(i)
        {
            a = new T[i]();
        }

        Array(const Array& obj) : a(NULL), i(obj.i)
        {
            *this = obj;
        }

        Array& operator=(const Array& obj)
        {
            if (this != &obj)
            {
                if (a)
                    delete[] a;
                a = new T[obj.i]();
                unsigned int j = 0;
                while (j < i)
                {
                    a[j] = obj.a[j];
                    j++;
                }
            }
            return *this;
        }

        void init(T value) const
        {
            std::fill(a, a + i, value);
        }

        void print() const
        {
            unsigned int j = 0;
            while (j < i)
            {
                std::cout << a[j] << std::endl;
                j++;
            }
        }

        T& operator[](size_t index) const
        {
            if (index >= i)
                throw std::exception();
            return a[index];
        }

        unsigned int size() const
        {
            return i;
        }
        
        ~Array()
        {
            delete[] a;
        }
};