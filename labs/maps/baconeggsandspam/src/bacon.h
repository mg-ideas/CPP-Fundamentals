#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

using map_str_set = map<string, set<string>>;

// function prototypes
vector<string> split_string(const string &line);
map_str_set read_items(int n);
void print_items(const map_str_set &items);
void solve();
