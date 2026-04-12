#include "refrigerator.hpp"
#include <iostream>

bool Referigerator::eat(DAY current_day)
{
    if (oats.empty())
        return false;         // No oats to eat; consider this as expired
    DAY added = oats.front(); // Get the day the oldest cup of oats was prepared
    if (current_day - added > this->shelf_life)
        // Oldest oat is expired!
        return false; // Oats are expired
    oats.pop_front(); // Eat the oats (remove from the front of the deque)
    return true;      // Successfully ate the oats
}

void Referigerator::add(DAY current_day)
{
    // add a new cup at the end of the deque with the current day
    // FIXME: add the current day to the back of the deque
}