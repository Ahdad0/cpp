#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const int x;
        const int y;
    public:
        Point();
        Point(const Point& obj);
        Point(const float x, const float y);
        Point operator=(const Point& obj);
        ~Point();
        int get_x() const;
        int get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);