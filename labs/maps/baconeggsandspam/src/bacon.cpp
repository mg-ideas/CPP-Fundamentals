#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include "bacon.h"

using namespace std;

vector<string> split_string(const string &line)
{
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        // FIXME1: add each word to words vector
    }
    return words;
}

map_str_set read_items(int n)
{
    map_str_set items_guests;
    string line;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        vector<string> tokens = split_string(line);
        // FIXME2: for each menu item in tokens after the first token (customer name),
        // add the customer name to the set of names for that item in the map
    }
    return items_guests;
}

void print_items(const map_str_set &items)
{
    for (auto e : items)
    {
        cout << e.first;
        // FIXME3: print all customer names in the set associated with the menu item
        cout << endl;
    }
}

void solve()
{
    string line;
    string word;
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cin.get(); // consume/discard newline character
        map_str_set items;
        items = read_items(n);
        print_items(items);
        cout << endl;
    }
}