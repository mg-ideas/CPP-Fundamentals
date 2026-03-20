#pragma once
#include <cstddef>

namespace pokerhand
{
    struct Card
    {
        char rank;
        char suit;
    };

    struct Hand
    {
        Card cards[5];
        size_t max_same_rank;
    };

    size_t find_max_same_rank(const Hand &);
}