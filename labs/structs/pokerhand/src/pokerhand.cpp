#include "pokerhand.hpp"

size_t pokerhand::find_max_same_rank(const Hand &h)
{
    size_t max_count = 1;
    for (size_t i = 0; i < 5; ++i)
    {
        size_t count = 1;
        for (size_t j = i + 1; j < 5; ++j)
        {
            if (h.cards[i].rank == h.cards[j].rank)
                ++count;
        }
        // FIXME4 - update max_count if count is greater than max_count
    }
    return max_count;
}