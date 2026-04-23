#pragma once
#include <string>
#include <unordered_map>

struct SevenWonders
{
    // Map to count the occurrences of each card C, T, G
    std::unordered_map<char, size_t> card_count;
    void update_card_count(char card);
    size_t calculate_points() const;
    size_t calculate_bonus() const;
    size_t calculate_total_points() const;
};