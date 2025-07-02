#include "Point.hpp"

float   calculate_area(Point const a, Point const b, Point const c)
{
    float area = 0.5 * abs(a.get_x() * (b.get_y() - c.get_y())
                   + b.get_x() * (c.get_y() - a.get_y())
                   + c.get_x() * (a.get_y() - b.get_y()));
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float total_area = calculate_area(a, b, c);
    float pab_area = calculate_area(point, a, b);
    float pbc_area = calculate_area(point, b, c);
    float pca_area = calculate_area(point, c, a);

    if (total_area == pab_area + pbc_area + pca_area)
        return true;
    else
        return false;
}