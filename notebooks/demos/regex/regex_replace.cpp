#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string text = "abc123 hello 456 test9 pureWord 99bottles";

    regex pattern("\\b(?=\\w*[A-Za-z])(?=\\w*\\d)\\w+\\b");

    smatch m;
    string result;
    auto search_start = text.cbegin(); // const iterator to the beginning of the string

    while (regex_search(search_start, text.cend(), m, pattern))
    {
        result.append(m.prefix());              // append the part of the string before the match
        result.append(string(m.length(), '*')); // append a string of asterisks with the same length as the match
        search_start = m.suffix().first;        // update the search start position to the end of the match
    }
    result.append(search_start, text.cend()); // append the remaining part of the string after the last match
    cout << result << endl;
}