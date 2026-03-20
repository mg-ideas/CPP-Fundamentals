#include "triangle.hpp"

float triangle::find_area(triangle::Triangle &t)
{
    return (t.base * t.height) / 2.0;
}