#include <iostream>
#include <unordered_map>
#include <string>
#include "sevenwonders.h"

using namespace std;

void SevenWonders::update_card_count(char card)
{
    // check if a card is already in wonders map
    auto find = card_count.find(card);
    if (find == card_count.end()) // card not found
        // add it to the wonders map
        card_count[card] = 1;
    else
    {
        // FIXME5: update value/count of card
        cerr << "FIXME\n";
    }
}

size_t SevenWonders::calculate_points() const
{
    // algorithm step 3 - calculate regular points
    size_t points = 0;
    for (auto pair : card_count)
    { // pair = <card, count>
        // FIXME6 - Update the points by adding count^2
        cerr << "FIXME\n";
    }
    return points;
}

size_t SevenWonders::calculate_bonus() const
{
    // algorithm step 4 - calculate bonus points
    // find # of sets of three different cards and mulitiply it by 7
    // and add it to the total bonus
    size_t bonus = 0;
    size_t min_card_count = 999999;
    size_t unique_cards = this->card_count.size();
    if (unique_cards == 3)
    {
        for (auto pair : card_count)
        {
            min_card_count = pair.second < min_card_count ? pair.second : min_card_count;
        }
        // FIXME7: set bonus to min_card_count x 7
        cerr << "FIXME\n";
    }
    return bonus;
}

size_t SevenWonders::calculate_total_points() const
{
    // calculate total points by adding regular points and bonus points
    size_t total_points = 0;
    // FIXME8: set total_points to the sum of regular points and bonus points
    cerr << "FIXME\n";
    return total_points;
}