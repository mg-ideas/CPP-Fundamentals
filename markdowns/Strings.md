# C++ Strings

## Topics
- string library
- string objects and methods
- string operators
- slicing string
- string traversal
- comparing and updating strings

## String review
- we've used string library to declare string variables in earlier chapters
- we've seen few examples of string applications over the chapters
- two different ways to declare and use string/text data in C++

### C-string
- uses array concept; which we don't know yet!
- C array may not be easy to work with, though important concept to master

### C-string example
- no need to include any library to use C-string


```c++
#include <iostream>

using namespace std;
```


```c++
// C way to declare string - painful to work with!
// array of characters
char text[] = "this is a c-string";
```


```c++
cout << "text = " << text << endl;
```

    text = this is a c-string


- `cin` and other operations on C-strings are not easier without knowing array and pointers well

### C++ string objects

- `std::string` is a `std::basic_string<char>` template type defined in **string** header
- more: [https://en.cppreference.com/w/cpp/string/basic_string](https://en.cppreference.com/w/cpp/string/basic_string)

- string is an advanced type of container with many member variables and member functions
    - variables of advanced type are called objects
    - objects may provide a number of member functions called methods
    - one can define any user-defined type using **struct** or **class** that we'll learn in later chapters


```c++
// C++ string
#include <iostream>
#include <string>

using namespace std;

// declare a string variable/object
string first;
```


```c++
// assigning string value to string object
first = "Hello, ";
```


```c++
// declare and initialize string object
string second = "World";
```


```c++
// concatenation
string whole = first + " " + second;
```

## Inputting and Outputting strings
- printing string objects and literal to standard output/console/monitor
- use `<iostream>` and `std namespace`
- syntax:
```cpp
    cout << strObject << "string literal" << ...;
```
- inputting string data from standard input/keyboard
- syntax:
```cpp
    cin >> strVar >> strVar2 >> ...; // read individual word
    getline(cin, strVar); // read a single line with spaces
```


```c++
// output string literals and objects
#include <iostream>
using namespace std;

cout << first << second << "!" << endl;
```

    Hello, World!



```c++
cout << whole << endl;
```

    Hello,  World



```c++
cout << "Enter your first name and last name: ";
cin >> first >> second;
cout << "Hello, " << first << " " << second << "!";
```

    Enter your first name and last name: John Smith
    Hello, John Smith!


```c++
cout << "Enter your full name: ";
getline(cin, whole);
cout << "Hello, " << whole << "!" << endl;
```

    Enter your full name: Jake Smith
    Hello, Jake Smith!


## C++ strings and variables
- this chapter goes more in depth on string data
- string variable is a container for a sequence of 0 or more characters
    - characters are anything from set of:
        - symbols (%, &, \$, etc.)
        - alphabets (a, B, x, etc.)
        - digits (1, 9, 0, etc.)
- in C++, string is represented using a pair of double quotes ("")   
- string is made up of ordered sequence of character elements as depicted in the following figure
- each character has an internal indexing or placing we can refer to it by its index

![](resources/string_rep.png)

## String object members

- we use `.` (dot) member access operator to access object's members
- we'll go over some commonly used methods with examples in this notebook
- syntax to access members of objects:

```cpp
    object_name.member_variable
    object_name.member_function()
```

## Element access
- string objects consists of sequence of characters called elements
- each character or element can be extracted or updated in place
- the following member functions/methods let's you access element:
    - **at(index)** - access the specified character at index with bounds checking
    - **operator[index]** - access the specified character at index without bounds checking
    - **front( )** - access the first character
    - **back( )** - access the last character
- index must be a valid index between **0 to length-1**


```c++
string fruit = "banana";
```


```c++
char first_letter;
```


```c++
// access the first character at index 0
first_letter = fruit.at(0);
```


```c++
cout << "first letter of " << fruit << " is " << first_letter << " = " << fruit[0];
```

    first letter of banana is b = b


```c++
//second character
cout << "second character = " << fruit[1] << " = " << fruit.at(1);
```

    second character = a = a


```c++
// there are 6 characters in banana
cout << "last character = " << fruit[6];
// [] - doesn't check the bound; output is undetermined
```


```c++
// at() - checks the bounds; throws runtime-error
cout << "last character = " << fruit.at(6);
```

    last character = 


    Error: 



```c++
cout << "front = " << fruit.front() << " and back = " << fruit.back();
```

    front = b and back = a

### Element update
- string is a mutable type that can be changed in place!
- using `[ index ]` - element access operator, we can assign new character at some index
    - index must be a valid value between **[0 ... length-1]**


```c++
// capitalize the first character by replacing 'b' with 'B'
fruit[0] = 'B';
```


```c++
cout << "I love, " << fruit << "!";
```

    I love, Banana!

## Capacity
- knowing the length of a string (numbers of characters) helps with many operations
- the following methods provide capacity of string objects:
    - **length()** or **size()** - returns the number of characters
    - **empty()** - checks whether the string is empty


```c++
cout << "length of " << fruit << " = " << fruit.size() << " = " << fruit.length();
```

    length of Banana = 6 = 6


```c++
cout << "is fruit empty? " << boolalpha << fruit.empty();
```

    is fruit empty? false

## Traversal
- traversing a string is a common task where you access every character from first to the last
- there are several ways to traverse a string


```c++
// using capacity to traverse/iterate over a string
for(int i=0; i<fruit.length(); i++) {
    cout << "fruit[" << i << "] = " << fruit[i] << endl;
}
```

    fruit[0] = B
    fruit[1] = a
    fruit[2] = n
    fruit[3] = a
    fruit[4] = n
    fruit[5] = a



```c++
#include <cctype>

for(auto ch: fruit)
    cout << ch << " -> " << char(toupper(ch)) << endl;
```

    B -> B
    a -> A
    n -> N
    a -> A
    n -> N
    a -> A


## Iterators
- iterators are special pointers that let you iterate over or traverse a string
- the following methods return an iterator:
    - **begin( )** - returns a forward iterator to the beginning
    - **end( )** - returns a forward iterator to the end
    - **rbegin( )** - returns a reverse iterator to the beginning
    - **rend( )** - returns a reverse iterator to the end
- the following figure demonstrates begin() and end() iterators

![](resources/range-begin-end.png)

- the following figure demonstrates rbegin() and rend() iterators

![](resources/range-rbegin-rend.png)



```c++
// automatically determine the type of iter which is a forward iterator
auto iter = fruit.begin();
```


```c++
// what is iter pointing to?
cout << *iter;
```

    B


```c++
// increment iterator by one element
iter += 1;
```


```c++
cout << *iter;
```

    a


```c++
// forward iterator
for(auto it=fruit.begin(); it != fruit.end(); it += 1) {
    cout << *it << " ";
}
```

    B a n a n a 


```c++
// reverse iterator
for(auto it=fruit.rbegin(); it!=fruit.rend(); it++) {
    cout << *it << " ";
}
```

    a n a n a B 

## Operations
- string objects can be concatenated with `+` operator
- string objects also have a bunch of methods to perform various common operations on string data
- the following are some commonly used operations:

### clear
- clears the contents making string object empty!


```c++
string strData = "Pirates of the Carribean!";
```


```c++
// clear the content
strData.clear();
```


```c++
cout << "strData = " << strData;
```

    strData = 

### insert
- insert a character or string at a given index
- **insert(index, count, char)** insert `count` `char`acters at some `index`
- **insert(index, string)** - insert some `string` at `index`


```c++
strData = "Pirates of the Carribean!";
```


```c++
// insert 1 $ character at index 0
strData.insert(0, 1, '$');
```


```c++
cout << "strData = " << strData;
```

    strData = $Pirates of the Carribean!


```c++
// insert 5 astersisks at index 5
strData.insert(5, 5, '*');
```


```c++
cout << "strData = " << strData;
```

    strData = $Pira*****tes of the Carribean!


```c++
strData.insert(0, "The ");
```


```c++
cout << "strData = " << strData;
```

    strData = The $Pira*****tes of the Carribean!

### erase
**erase(index, count)** - erases `count` characters starting from `index`


```c++
// erase all 5 asterisks starting at index 9
strData.erase(9, 5);
```


```c++
strData
```




    "The $Pirates of the Carribean!"



### append
- the following methods append characters to the end of string objects
    - **push_back(ch)** - appends a character to the end
    - **append(str)** - appends string to the end
    - **operator+=** - appends string to the end


```c++
string some_str;
```


```c++
some_str = "";
```


```c++
some_str.push_back('1');
some_str.append("2");
some_str += "3456";
```


```c++
some_str
```




    "123456"



## Search
- searching for a substring is often a common task performed with strings data
- also refered to as "finding a needle in the haystack"
- `find` and `rfind` methods help in finding a substring in some string

### find( str, [pos] )
- finds the first `str` in the string starting from `pos`
    - if no `pos` is provided, first index, 0 is used
- if `str` is found, returns begining position/index of `str`
- if str is not found, returns `npos` constant defined in `string::` namespace
    - `npos` is the largest possible value for **size_t**; system dependent


```c++
// what is npos?
cout << string::npos;
```

    18446744073709551615


```c++
string haystack, search_str;
size_t found;
```


```c++
haystack = "There are maanny needles or just a few needle in the haystack!";
```


```c++
search_str = "needle"; // TODO: change this to "Needle" and find
```




    "needle"




```c++
found = haystack.find(search_str);
```


```c++
cout << found;
```

    17


```c++
// check if substring is found or not
if (found == string::npos)
    cout << search_str << " NOT found!\n";
else
    cout << search_str << " found at: " << found << endl;
```

    needle found at: 17


### rfind( str, [pos] )
- search the first substring in backward direction starting from `pos`
    - if no `pos` is provided, last index is used


```c++
found = haystack.rfind(search_str);
// check if substring is found or not
if (found == string::npos)
    cout << search_str << " NOT found!\n";
else
    cout << search_str << " found at: " << found << endl;
```

    needle found at: 39


### Replace
- replaces the part of string indicated by `index` with a new string
- **replace(index, count, newStr)**
    - replace some string from `index` to `index+count` by `newStr`


```c++
some_str = "12345abc";
```


```c++
some_str.replace(0, 1, "A");
```


```c++
some_str
```




    "A2345abc"




```c++
some_str.replace(1, 5, "B");
```


```c++
some_str
```




    "ABbc"




```c++
// insert with replacing 0 character
some_str.replace(1, 0, "WXYZ");
```


```c++
some_str
```




    "AWXYZBbc"



### Search and replace application
- a commmon feature provided by text editors


```c++
// let's see the contents of haystack
haystack
```




    "There are maanny needles or just a few needle in the haystack!"




```c++
// let's search misspelled word "maanny" and replace with "many"
size_t wordIndex = haystack.find("maanny")
```


```c++
wordIndex
```




    10




```c++
haystack.replace(wordIndex, string("maanny").length(), "many")
```




    "There are many needles or just a few needle in the haystack!"




```c++
// replace the first needle with poodle
haystack.replace(haystack.find("needle"), 6, "poodle")
```




    "There are many poodles or just a few needle in the haystack!"



## Sub string
- **substr(pos, count)** returns a substring from `pos` index to `pos+count` index
    - if count is not provided, returns to the end or **npos**
    - `npos` is a constant value defined in `string::` namespace


```c++
// return from index 1 to the end or npos
cout << some_str.substr(1);
```

    WXYZB


```c++
// return 4 characters starting from 1
cout << some_str.substr(1, 4);
```

    WXYZ

## String comparisons
- two string values can be compared using comparison operators
- all comparison operators (==, !=, <, <=, >, >=) are overloaded to work with string types
- strings are compared character by character using ASCII value


```c++
string a = "apple";
```


```c++
string b = "ball";
```


```c++
string c = "Apple";
```


```c++
// both size and values must be equal!
if (a == b) // every character in var 'a' must equal to corresponding character in var 'b'
    cout << a << " equals to " << b << endl;
else
    cout << a << " is NOT equal to " << b << endl;
```

    apple is NOT equal to ball



```c++
if (a <= b)
    cout << a << " comes before " << b << endl;
else
    cout << a << " doesn't come before " << b << endl;
```

    apple comes before ball



```c++
if (a <= c)
    cout << a << " comes before " << c << endl;
else
    cout << a << " doesn't come before " << c << endl;
```

    apple doesn't come before Apple


## Numeric conversions
- strings can be converted into numeric values (integers or floating points) as appropriate

### string to signed integers
- **stoi( ), stol( ), stoll( )** - converts a string to a signed integers


```c++
cout << stoi("123");
```

    123


```c++
cout << stoi("-454532") << " " << stol("-45352343441 asdf") << " " << stoll("552353253 adsfasf");
```

    -454532 -45352343441 552353253

### string to unsigned integers
**stoul( ), stoull( )** - converts a string to unsigned integer


```c++
cout << stoul("454532") << " " << stoull("-45352343441 text");
```

    454532 18446744028357208175

### string to floaing point value
- **stof( ), stod( ), stold( )** - converts a string to floating point value


```c++
cout << stof("-454532") << " " << stof("-453.123 text") << " " << stof("552.34 adsfasf");
```

    -454532 -453.123 552.34


```c++
// throws run-time error
cout << stof("a5235");
```


    Standard Exception: stof: no conversion



```c++
cout << stod("-454532") << " " << stod("-453.123 text") << " " << stod("552.34 adsfasf");
```

    -454532 -453.123 552.34

### integral or floating point value to string
- **to_string( )** converts integral or floats to string


```c++
string new_str = to_string(123).append("456"); 
```


```c++
new_str
```




    "123456"




```c++
cout << (to_string(345.44545)).append(" some text");
```

    345.445450 some text

## Dynamic string variables
- pointers can point to string types
- string pointers can be used to allocate dynamic memory in heap


```c++
#include <iostream>
#include <string>

using namespace std;
```


```c++
string full_name = "John Doe";
string * ptr_full_name = &full_name;
```


```c++
// dereference ptr_full_name
cout << full_name << " == " << *ptr_full_name;
```

    John Doe == John Doe


```c++
// allocate dynamic memory in heap and initialize it with data
string * ptr_var = new string("Jake Smith");
```


```c++
cout << *ptr_var;
```

    Jake Smith


```c++
// assign new value to *ptr_var
*ptr_var = "Jane Fisher";
```

### String Application - Convert Decimal into Binary

- Define a function that takes an integer and returns the binary representation of the integer.
    - e.g. $10_{10} = 1010_2$


- let's use algorithm defined in Chapter 02 and the partial code in Chapter 03:
    1. repeteadly divide the decimal number by base 2 until the quotient becomes 0
    2. collect the remainders in reverse order
        - the first remainder becomes the last bit (least significant) in binary
        
 


```c++
#include <iostream>
#include <string>

using namespace std;
```


```c++
string binary(unsigned int decimal) {
    // decimal to binary conversion requires to calculate both quotient and remainder
    const int divisor = 2; // divisor is contant name whose value can't be changed once initialized with
    int dividend;
    int quotient, remain;
    string answer = ""; // collect remainders by prepending as a string
    quotient = decimal;
    
    while(quotient != 0) { // we can programatically check when the loop should exit
        // repeated computation
        dividend = quotient;
        remain = dividend%divisor;
        quotient = dividend/divisor;
        // print intermediate results; help us see and plan further computation
        //cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
        answer = to_string(remain) + answer; // prepend remainder to answer
    }
    if (answer == "")
        return "0";
    return answer;
}
```


```c++
cout << "10 decimal in binary = " << binary(10) << endl; 
```

    10 decimal in binary = 1010


### Convert Binary into Decimal

- algorithm steps as provided in Data, Variable and Operations chapter:
    1. multiply each binary digit by its place value in binary
    2. sum all the products
    
    
- Define a function that takes a binary number provided in string and converts into decimal representation
    - E.g. $1010_2 = 10_{10}$


```c++
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
```


```c++
unsigned int decimal(string binary) {
    int answer = 0;
    int digitCount = binary.size();
    for(int i=0; i<digitCount; i++) {
        if (binary[i] == '0') continue;
        int placeValue = digitCount-i-1;
        answer += pow(2.0, placeValue);
    }
    return answer;
}
```


```c++
cout << "1010 in binary = " << decimal("1010") << " in decimal." << endl;
```

    1010 in binary = 10 in decimal.


## Labs

1. Read and solve the Kattis problem Hissing Microphone - [https://open.kattis.com/problems/hissingmicrophone](https://open.kattis.com/problems/hissingmicrophone)
    - use partial solution provided in [labs/strings/hissingmicrophone](./labs/strings/hissingmicrophone) folder
    - use Makefile provided to compile the file
    - fix all the FIXMEs and write #FIXED# next to each FIXME if fixed
    
2. Solve the Kattis problem Simon Says - https://open.kattis.com/problems/simonsays
    - use partial solution provided in [labs/strings/simonsays](./labs/strings/simonsays) folder
    - fix all the FIXMEs and write #FIXED# next to each FIXME if fixed

## Exercises

1. Write a function that checks if a given string has at least one digit (0-9) in it.
    - Write 3 automated test cases


```c++
// Exercise 1 Sample Solution
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;
```


```c++
bool hasDigit(string text) {
    for(char ch: text) {
        if (isdigit(ch)) return true;
    }
    return false;
}
```


```c++
// test hasDigit
void test_hasDigit() {
    assert(hasDigit("some text with d1g1t!") == true);
    assert(hasDigit("this text has no digit") == false);
    assert(hasDigit("24242") == true);
    cerr << "all test cases passed for hasDigit()\n";
}
```


```c++
test_hasDigit();
```

    all test cases passed for hasDigit()


2. Convert Exercise 1 into a complete program
    - prompt user to enter some text
    - make program continue to run until the user wants to quit
    
    
3. Write a function that checks if a given string is a palindrome. Palindromes are words and phrases that read the same backward as forward such as **madam, race car, etc.**
    - more on Palindromes: https://en.wikipedia.org/wiki/Palindrome
    - it's okay if the function works for word only
    - challenge yourself to make it work for phrases as well
    - ignore cases (i.e., A equals a)
    - write at least 3 automated test cases



```c++
// Sample solution for exercise #3
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;
```


```c++
/*
palindromic texts: A, AA, ABA, ABBA

Algorithm steps:
1. for each character up to the middle one in a given phrase
    ii. compare the corresponding characters from left and right of the phrase
        a. do a case insensitve comparision
    iii. if a single corresponding pair does not match, the phrase is NOT palindrome
    iv.  if all the corresponding pairs match, the word is palindrome
*/

bool isPalindrome(string word) {
    int left_index = 0; // index from the beginning of the word
    int right_index = word.length()-1; // index from the end of the word
    int mid = word.length()/2; // mid index to stop the comparison
    bool mismatched = false;
    while(left_index < mid && !mismatched) { // stop before the mid index or any pair mismatched
        // convert to lowercase to make case insensitive comparison
        char left_char = tolower(word[left_index]); 
        char right_char = tolower(word[right_index]);
        // if no match, set the mismatched flag to true;
        if (left_char != right_char) mismatched = true;
        // if they match, move the indices to point the next pair
        left_index++;
        right_index--;
    }
    // if mismatched return false; else all pairs must have matched, return true
    return mismatched? false : true;
}
```


```c++
void test_isPalindrome() {
    assert(isPalindrome("") == true); // empty string is a plindrome!?
    assert(isPalindrome("A") == true);
    assert(isPalindrome("AB") == false);
    assert(isPalindrome("ABA") == true);
    assert(isPalindrome("ABBA") == true);
    assert(isPalindrome("racecar") == true);
    assert(isPalindrome("race car") == false);
    cerr << "all test cases passed for isPalindrome()\n";
}
```

4. Convert Exercise 3 into a complete program.
    - program prompts user to enter a string
    - determines and lets the user know if the string is a palindrome or not
    - program continues to run until the user wants to quit
    
    
5. Improve Exercise 4 to ignore punctuations including spaces!
    - if you named the improved isPalindrome function as isPalaindromeV1,
        - the following test cases must pass!


```c++
/*
palindromic texts: A, AA, ABA, ABBA, "race car"

Algorithm steps:
1. for each character up to the middle one in a given phrase
    i. ignore all the non-alphabetic characters on both ends of the phrase
    ii. compare the corresponding characters from left and right of the phrase
    iii. if a single pair is not equal, the phrase is NOT reversible
    iv.  if all the pairs match, the word is reversible
*/
bool isPalindromeV1() {
    // FIXME: implement the above algorithm
    return true;
}
```


```c++
void test_isPalindromeV1() {
    assert(isPalindromeV1("") == true); // empty string is a plindrome!?!?
    assert(isPalindromeV1("A") == true);
    assert(isPalindromeV1("AB") == false);
    assert(isPalindromeV1("ABA") == true);
    assert(isPalindromeV1("ABBA") == true);
    assert(isPalindromeV1("racecar") == true);
    assert(isPalindromeV1("race car") == true); // ignore white spaces...
    cerr << "all test cases passed for isPalindromeV1()\n";
}
```

6. Write a program that counts the number of vowels (a, e, i, o, u) and consonants (alphabets except vowels) in a given text.
    - program promps user to enter the text
    - program should account for both upper and lower case alphabets
    - program should continue to run until the user wants to quit
    
    
7. Write a program that checks the strength of the given password.
    - use a scoring system based on the varieties of character type present as described below:
    - 1 point if it contains at least 1 lowercase
    - 1 point if it contains at least 1 uppercase
    - 1 point if it contains at least 1 digit
    - 1 point if it contains at least 1 symbol from the group (~!@#\$%^&*()_-+={})
    - 1 point if the length of the password is 8 characters or long
    - interpretation of total points (max 5):
    - if points is 5 or more - Excellent
    - if points is 3 or more - Good
    - if points is 2 or less - Bad

## Kattis Problems for Demo

- Password Filter - https://open.kattis.com/problems/lykilordasia
    - Hint: parse word by word, check for digit in each word using isdigit() from <cctype>
    - can also use regular expressions from <regex> library to match a digit pattern

- Web Page - https://open.kattis.com/problems/slatkisi
    - Hint: starting at each index, use string method substr to compare 2-byte icelandic characters
    - for (size_t i = 0; i < line.length( ); ) {
        if (line.substr(i, 2) == "Á" || line.substr(i, 2) == "á") {
            cout << "a";
            i += 2;
        }
        ...
    }

- Rock, Paper, Scissors - https://open.kattis.com/problems/rps
    - Hint: Loops and two strings
 

## Kattis problems
- there are a lot of Kattis problems on text/string manipulation
- some simple problems are listed below
- solve each problem using fruitful function(s) so that you can write at least 3 test cases for function(s) used as part of the solution

- Password Filter - https://open.kattis.com/problems/lykilordasia
- Passport Dates - https://open.kattis.com/problems/vegabrefadagsetningar
- Hissing Microphone - https://open.kattis.com/problems/hissingmicrophone
- Avion - https://open.kattis.com/problems/avion
- Apaxiaaaaans! - https://open.kattis.com/problems/apaxiaaans
- Alphabet Spam - https://open.kattis.com/problems/alphabetspam
- Simon Says - https://open.kattis.com/problems/simonsays
- Simon Says - https://open.kattis.com/problems/simon
- Fifty Shades of Pint - https://open.kattis.com/problems/fiftyshades
- Quick Brown Fox - https://open.kattis.com/problems/quickbrownfox
- Encoded Message - https://open.kattis.com/problems/encodedmessage
- Trik - https://open.kattis.com/problems/trik
- Digit Product - https://open.kattis.com/problems/sifferprodukt
- Magic Trick - https://open.kattis.com/problems/magictrick
- FYI - https://open.kattis.com/problems/fyi
- Methodic Multiplication - https://open.kattis.com/problems/methodicmultiplication
    - Hint: simple multiplication
- E-clips - https://open.kattis.com/problems/eclips
- Hexaphobic Square - https://open.kattis.com/problems/hexaphobicsquare
- Danish Date Format - https://open.kattis.com/problems/danishdateformat
- Attempted Alphabet - https://open.kattis.com/problems/attemptedalphabet
- Alphabet Soup - https://open.kattis.com/problems/alphabetsoup
- Culture Shock - https://open.kattis.com/problems/cultureshock
- "lv"-able - https://open.kattis.com/problems/lvable
- Dickensian Dictionary - https://open.kattis.com/problems/dickensiandictionary
- Easier Done than Said? - https://open.kattis.com/problems/easierdonethansaid

## Summary
- this chapter covered C++ string type
- delcare and use string type
- various operations and member functions or methods provided to string objects
- exercises and sample solutions


```c++

```
