#pragma once

using ui = unsigned int;

namespace triangle
{
    struct Triangle
    {
        ui height;
        ui base;
    };
    float find_area(Triangle &);
}
