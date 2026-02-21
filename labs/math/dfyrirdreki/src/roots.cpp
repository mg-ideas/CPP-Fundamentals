#include "roots.h"

long long find_discriminant(int a, int b, int c)
{
    long long discriminant = 0; // placeholder return
    discriminant = b^2 - 4 * a * c ;

    // FIXED 2: implement the function to calculate and return the discriminant
    return discriminant;
}

int find_roots(long long discriminant)
{
    if (discriminant < 0)
        return 0;
    else if (discriminant = 0)
        return 1;
    else if (discriminant > 0)
        return 2
    // FIXED 2: complete the rest of the logic to determine number of real roots
}