/*
Kattis - Simon Says

Updated By: FIXME
Date: FIXME

Problem Statement: https://open.kattis.com/problems/simonsays
Algorithm steps:
1. Read N
2. Loop N times:
  i. Read a line
  ii. If the line starts with "Simon says",
    print the rest of the string. Note: print the leading space after says as well!
  iii. Otherwise, skip the line
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main(int argc, char *argv[])
{
  string ans = "", line = "";
  int N;
  cin >> N;
  // FIXME4 : read and discard \n left behind
  while (N--)
  {
    // Note: i. string consists of phrase with spaces
    // ii. don't print an empty line if the line doesn't start with "Simon says"
    // FIXME5: read the whole line into line
    // FIXME6: call answer function and store the returned value into ans
    if (ans == "")
      continue;
    // FIXME7: print ans
  }
}
