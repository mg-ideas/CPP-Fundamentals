#include "guests.hpp"
#include <iostream>
using namespace std;

void Guests::add_guest(const string &name)
{
    cerr << " FIXME - Add the guest to the set of guests using the right method!" << endl;
}

void Guests::remove_guest(const string &name)
{
    cerr << "FIXME - Remove the guest from the set of guests using the right method!" << endl;
}

bool Guests::is_guest_present(const string &name) const
{
    return guests.find(name) != guests.end();
}