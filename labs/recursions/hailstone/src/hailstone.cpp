#include <cinttypes>
#include "hailstone.hpp"

// unitt4_t = fixed unsigned 64-bit integer type in C; unsigned long long int (C++)
uint64_t hailstone::h_sum(uint64_t n)
{
    if (n == 1)
        return 1;
    else if (n % 2 == 0)
        return n + h_sum(n / 2);
    // FIXME5 - add the case for odd n
    else
        return 0;
}
