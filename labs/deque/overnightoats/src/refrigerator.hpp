#pragma once
#include <deque>
#include <string>
#include <cstddef>

using DAY = size_t;

struct Referigerator
{
    std::deque<DAY> oats; // stores the day each cup of oats was prepared
    DAY shelf_life;       // number of days before oats expire
    bool eat(DAY current_day);
    void add(DAY current_day);
};