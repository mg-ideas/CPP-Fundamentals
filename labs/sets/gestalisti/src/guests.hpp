#pragma once

#include <string>
#include <unordered_set>
using namespace std;

struct Guests
{
    unordered_set<string> guests;
    void add_guest(const string &name);
    void remove_guest(const string &name);
    bool is_guest_present(const string &name) const;
};