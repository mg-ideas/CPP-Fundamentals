#pragma once

#include <string>
#include <vector>
using namespace std;

// function prototypes
void solve();
// function splits given string into vector of words
void split_string(vector<string> &, string);
// function erases sound from recordings vector
void erase_animal_sound(vector<string> &, string);
// function returns what the fox says
string fox_says(vector<string> &);