#include <sstream>
#include <string>
#include <vector>
#include "util.hpp"

using namespace std;

string fox_says(vector<string> &recordings)
{
    // return the answer string
    ostringstream oss;
    bool first = true;
    for (int i = 0; i < recordings.size(); i++)
    {
        if (first)
        {
            oss << recordings[i];
            first = false;
        }
        else
            oss << " " << recordings[i];
    }
    return oss.str();
}

void erase_animal_sound(vector<string> &recordings, string sound)
{
    // see how erase works here: https://en.cppreference.com/w/cpp/container/vector/erase
    // FIXME3 - use iterator to erase all matching sound
    // if iterator points to sound, erase it and update it with the next element pointer
    // otherwise, just increment the iterator
}

// function splits given string text into vector of words
void split_string(vector<string> &words, string text)
{
    string word;
    stringstream ss(text);
    while (ss >> word)
    {
        words.push_back(word);
    }
}