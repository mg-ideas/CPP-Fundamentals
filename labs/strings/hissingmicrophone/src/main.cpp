/*
Kattis - Hissing Microphone Problem

Updated By: FIXME1
Date: FIXME2

Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read a string
2. Search for "ss" substring in the string
    i. if found, print "hiss"
    ii. otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>
#include "util.hpp"

using namespace std;

void solve();

int main(int argc, char *argv[])
{
    string line;
    // Note: string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5 - read string into line
    cout << answer(line) << endl;
}
