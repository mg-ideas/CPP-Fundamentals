/*
Kattis - What does the fox say?
Vector Lab
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve the Kattis problem: https://open.kattis.com/problems/whatdoesthefoxsay

Algorithm Steps:
  1. For each test case do the following:
    i. Read all the recorded sounds into a vector
    ii. Read individual animal sound until 'What does the fox say?' line
      a) Erase all the matching animal sounds from the recorded sounds vector
    iv. Print the sounds that's left in the recorded sounds vector
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include "util.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  size_t T;
  cin >> T >> ws; // read the number of test cases and discard the newline

  while (T--)
  {
    cerr << "T = " << T << endl;
    vector<string> recordings;
    string sounds, animal_sound;
    getline(cin, sounds);
    cerr << sounds << endl;
    split_string(recordings, sounds);
    // read and parse animal sounds
    // don't know how many animals are there

    while (true)
    {
      getline(cin, animal_sound);
      // check for the question
      if (animal_sound == "what does the fox say?")
        break;
      istringstream iss(animal_sound);
      string animal, goes, sound;
      // parse three words
      iss >> animal >> goes >> sound;
      erase_animal_sound(recordings, sound);
    }
    // FIXME2: call fox_says function and print the returned answer
  }
  return 0;
}
