#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point& obj) : x(obj.x), y(obj.y)
{
}

Point::~Point()
{
}

Point Point::operator=(const Point& obj)
{
    Point temp(obj);
    
    if (this != &obj)
        return temp;
    return *this;
}

int Point::get_x() const
{
    return x;
}

int Point::get_y() const
{
    return y;
}
