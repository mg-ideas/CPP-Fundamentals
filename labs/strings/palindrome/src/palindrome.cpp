#include <string>
#include <cctype>
#include <iostream>
#include "../includes/palindrome.hpp"

// function definition for isPalindrome
// takes some string phrase and returns true if it is palindrome otherwise
// returns false
bool palindrome::naive(const std::string &phrase)
{
    bool isPalin = true;
    std::string reversedPhrase = "";
    // FIXME3: copy the characters of phrase in reverse order to reversedPhrase variable
    // compare the original phrase and reversedPhrase
    // if they are the same then it is a palindrome otherwise it is not
    return isPalin;
}

bool palindrome::optimized(const std::string &phrase)
{
    bool isPalin = true; // empty string is a palindrome
    int forward_i = 0, backward_i = phrase.size() - 1;
    // index of the middle character, if the size of the phrase is odd then it will be the index of the middle character
    // otherwise it will be the index of the first character in the second half of the phrase
    int mid_i = phrase.size() / 2;
    // check the characters at forward_i and backward_i indices until they reach the middle index
    while (forward_i < mid_i && backward_i >= mid_i)
    {
        std::cerr << phrase[forward_i] << " " << phrase[backward_i] << std::endl;
        // FIXME3: skip non-alphanumeric characters and move the indices accordingly
        // make case insensitive comparison
        isPalin = (tolower(phrase[forward_i]) == tolower(phrase[backward_i]));
        if (!isPalin)
            break;
        forward_i += 1;
        backward_i -= 1;
    }
    return isPalin;
}
