#include "guests.hpp"

void Guests::add_guest(const string &name)
{
    guests.insert(name);
}

void Guests::remove_guest(const string &name)
{
    guests.erase(name);
}

bool Guests::is_guest_present(const string &name) const
{
    return guests.find(name) != guests.end();
}