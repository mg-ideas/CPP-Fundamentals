# Maps and Unordered Maps - Associative Containers

## External Resources

- YouTube Video - [https://youtu.be/lPL7ItkiyVA](https://youtu.be/lPL7ItkiyVA)
- YouTube Podcast - [https://youtu.be/h7FfD6kOhhk](https://youtu.be/h7FfD6kOhhk)
- C++ Reference for Map Associative Containers [https://en.cppreference.com/w/cpp/container.html](https://en.cppreference.com/w/cpp/container.html)
- NotebookLM learning materials - [https://notebooklm.google.com/notebook/6afcc53d-54f3-43e1-9f76-0cb9f71b19b1](https://notebooklm.google.com/notebook/6afcc53d-54f3-43e1-9f76-0cb9f71b19b1)

## Topics
- Map definition
- Declare map
- Access elements
- Map Modifiers
- Aggregate operations
- Iterators
- Lookup operations
- Applications


## Map

- Map Documentation: [https://en.cppreference.com/w/cpp/container/map.html](https://en.cppreference.com/w/cpp/container/map.html)
- in previous chapters we have seen various sequence containers such as **array**, **vector**, **deque**, **list**, etc.
- those containers are linear and the keys are fixed integer indices or positions specifying the location of elements in the container
- at times problems may require a dictionary like data-structure where you need to select your own key that is associated with some value
- **map** is such a data structure where you store key-value pairs of your choosen types
- **map** is also called associative container that contains key-value pairs with unique keys
    - map is automatically sorted based on keys
    - all keys are of the same type and all values are of the same type
    - key and value can be of the same type or can be different types
- the following figure depicts a map data structure that maps English numbers (string) to Spanish numbers (string)

![](assets/Map.png)

- keys are mapped to values (one-way)
    - values are not mapped to the keys
- under the hood **map** is implemented as [red-black trees](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
- the complexity (efficiency) of common operations such as search, removal, and insertion operations is $O(log_2 n)$
    - simply put, if there are about 4 billion key-value pairs in a map, these common tasks can be completed in about 32 iterations (operations)
    - oder of operations is something discussed in more details in Data structures and Algorithm courses

## Map objects
- must include header file **&lt;map&gt;** and use namespace std
- a template class designed to store key of any data type that can be compared
    - value can be of any type
- map objects must be declared before they can be used
- syntax

```cpp
map<type, type> object;
```


```c++
// include header files
#include <iostream>
#include <string>
#include <map>

using namespace std;
```


```c++
// declare map containers without initialization
map<string, string> eng2Span;
map<char, int> charToNum;
map<int, char> numToChar;
```


```c++
// declare and initialize
map<string, int> words = {
        {"i", 10},
        {"love", 20},
        {"C++", 30},
        {"!", 40},
    };
map<string, float> prices = {{"apple", 1.99}, {"orange", 1.99}, {"banana", 2.99}, {"lobster", 20.85}};
map<string, float> dupPrices = prices;
```


```c++
// contents of words
words
```




    { "!" => 40, "C++" => 30, "i" => 10, "love" => 20 }




```c++
// prices contents: 
prices
```




    { "apple" => 1.99000f, "banana" => 2.99000f, "lobster" => 20.8500f, "orange" => 1.99000f }



### values can be user-defined type


```c++
// define Rectangle type
// Note - the word Type is redundant! Rectangle by itself would mean a type
struct RectangleType {
    float length, width;
};
```


```c++
// create a map that maps ints to RectangleType
map<int, RectangleType> myRects;
```


```c++
// declare and initialize
map<char, RectangleType> rectMap = {{'A', {20, 10}}, {'x', {3.5, 2.1}}};
```

## Accessing existing elements
- elements are accessed using keys and NOT the values
    - must know the key to get the corresponding values
    - can't get key from its value
- **at(key)** : access specified element with bounds checking
- **operator[key]** : access or insert specified element based on key
- similar to vector, but use actual key not index


```c++
// accessing elements using [] bracket operator
cout << "love = " << words["love"] << endl;
cout << "apple = " << prices["apple"] << endl;
cout << "ball = " << prices["ball"] << endl; // "ball doesn't exist; returns 0"
```

    love = 20
    apple = 1.99
    ball = 0





    @0x10645a558




```c++
// key must exist; value is unpredictable if key doesn't exist
cout << "cost of kite = " << prices["kite"];
```

    cost of kite = 0


```c++
// accessing elements using at() member function
cout << "love = " << words.at("love") << endl;
cout << "apple = " << prices.at("apple") << endl;
cout << "ball = " << prices.at("ball") << endl; // "ball doesn't exist; returns 0"
```

    love = 20
    apple = 1.99
    ball = 0





    @0x10645a558




```c++
// key must exist; value is unpredictable if key doesn't exist
cout << "cost of kite = " << prices.at("kite");
```

    cost of kite = 0


```c++
// declared above, but should be empty map
eng2Span
```




    {}




```c++
// accessing user-defined type as value
rectMap['x'].length
```




    3.50000f




```c++
cout << "area of rectangle x = " << rectMap['x'].length * rectMap['x'].width;
```

    area of rectangle x = 7.35

### inserting key->value pairs
- new key value pairs can be inserted to a map container
- if the key exists, existing value will be replaced with the new value
- if the key doesn't exist, new key-value pair will be inserted in the right location making sure keys are always sorted


```c++
// add new elements
eng2Span["one"] = "uno";
eng2Span["two"] = "dos";
eng2Span["three"] = "tres";
eng2Span["four"] = "cuatro";
eng2Span["five"] = "sinco";
```


```c++
eng2Span // sorted based on key
```




    { "five" => "sinco", "four" => "cuatro", "one" => "uno", "three" => "tres", "two" => "dos" }




```c++
// sinco is misspelled; let's correct its spelling
eng2Span["five"] = "cinco";
```


```c++
cout << " five in English is " << eng2Span["five"] << " in Spanish.";
```

     five in English is cinco in Spanish.

## Capacity
- similar to vecotr, map provides member functions to find the capacity of map containers
- **empty()** : checks whethere the container is empty
- **size()** : returns the number of elements
    - recall, each element of map is key->value pair
- **max_size()** : returns the maximum possible number of elements


```c++
cout << boolalpha; // convert boolean to text true/false
cout << "is eng2Span empty? " << eng2Span.empty() << endl;
cout << "is prices map empty? " << prices.empty() << endl;
cout << "total number of key->value pairs in prices: " << prices.size() << endl;
cout << "max_size of prices: " << prices.max_size() << endl;
```

    is eng2Span empty? false
    is prices map empty? false
    total number of key->value pairs in prices: 6
    max_size of prices: 288230376151711743


## Modifying maps
- map objects also provide some member functions to modify the contents of the containers
- **clear()** : clears the contents
- **[key]** : modifies value at the specified key


```c++
map<string, int> adults_age = {{"John", 21}, {"Maya", 74}, {"Jenny", 46}, {"Jordan", 48}, {"Mike", 46}};
```


```c++
// can't cin/cout map objects as a whole
adults_age
```




    { "Jenny" => 46, "John" => 21, "Jordan" => 48, "Maya" => 74, "Mike" => 46 }




```c++
//increment John's age by 1
adults_age["John"]++;
```


```c++
// should be empty
adults_age
```




    { "Jenny" => 46, "John" => 22, "Jordan" => 48, "Maya" => 74, "Mike" => 46 }




```c++
// delete all the elements
adults_age.clear()
```


```c++
// check the content to make sure adults_age is empty!
adults_age
```




    {}




```c++
// check if adults_age is empty
adults_age.empty()
```




    true



## Aggregate operations
- comparison operators ==, !=, <, >, <=, and >= are overloaded and work between two maps
    - elements are compared lexicographically
- cin/cout doesn't work as a whole
- math operations don't work as a whole

## Traversing maps
- map containers can be traveresed from the first element to the last (similar to array, string and vector)
- map provides iterators similar to iterators in string or vector
    - let's you iterate over all the elements
- iterator of map is a special pointer that has two elements **first** and **second**
    - first is the key and second is the value
- **begin** - returns an iterator to the beginning (first element)
- **end** - returns an iterator to the end (past the last element)
- **rbegin** - returns a reverse iterator to the beginning (past the last element)
- **rend** - returns a reverse iterator to the end (past the first element)

![](resources/range-rbegin-rend.png)



```c++
map<int, string> amap = {{10, "val1"}, {15, "val2"}, {20, "val3"}, {30, "val4"}, {35, "val5"}};
```


```c++
for(auto iterator = amap.begin(); iterator != amap.end(); iterator++)
    cout << (*iterator).first << " => " << iterator->second << endl;
```

    10 => val1
    15 => val2
    20 => val3
    30 => val4
    35 => val5



```c++
// iterate using range-based loop
for (auto e : amap)
    cout << e.first << " -> " << e.second << endl;
```

    10 -> val1
    15 -> val2
    20 -> val3
    30 -> val4
    35 -> val5



```c++
// type alias
using mii = map<int, int>;
```


```c++
mii map1 = {{1,10}, {2,20}, {3,30}, {4,40}, {5,50}};
```


```c++
map1
```




    { 1 => 10, 2 => 20, 3 => 30, 4 => 40, 5 => 50 }



## Lookup lements
- map containers provide member functions to search for element with given key in a map container
    - is typically used if you're not sure if a given key exists or not
- **count(key)** : returns the number of elements matching specific key (always 1 if exists, 0 otherwise)
- **find(key)** : finds elements with specific key, returns iterator


```c++
// map char to its ASCII value
map<char, int> mapci = {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}, {'A', 'A'}, {'B', 'B'}, {'1', '1'}};
```


```c++
mapci
```




    { '1' => 49, 'A' => 65, 'B' => 66, 'a' => 97, 'b' => 98, 'c' => 99 }




```c++
cout << mapci.count('a') << endl;
```

    1



```c++
cout << mapci.count('z') << endl;
```

    0



```c++
if (mapci.count('a') == 1)
    cout << "Found!";
else
    cout << "Not found!";
```

    Found!


```c++
// find method; returns iterator
auto it = mapci.find('c');
if (it != mapci.end())
    cout << "found " << it->first << " => " << it->second << endl;
else
    cout << "NOT found!";
```

    found c => 99



```c++
// erase using iterator
it = mapci.erase(it);
```


```c++
// it points to key 'c', so it must be erased
mapci
```




    { '1' => 49, 'A' => 65, 'B' => 66, 'a' => 97, 'b' => 98 }



## Passing map objects to functions
- map objects can be passed by value and by reference
- pass by reference is preferred to prevent copying all the elements unless it's necessary
- pass by const reference is preferred if the function doesn't need to modify the map object
    - prevent accidental modification/side effects and improve performance



```c++
// linear search function that returns true if key is found in someMap
// better to use map.find()
bool searchMap(const map<char, int> & someMap, char key) {
    for (auto element : someMap)
        if (element.first == key) return true;
    return false;
}
```


```c++
cout << boolalpha << "A exists as key? " << searchMap(mapci, 'A');
```

    A exists as key? true


```c++
cout << boolalpha << "$ exists as key? " << searchMap(mapci, '$');
```

    $ exists as key? false

## Returning map objects from functions
- map objects can be returned from functions
- return by value is preferred for clarity
- RVO (Return Value Optimization) in modern C++ makes returning by value efficient
    - C++17 and later versions support move semantics, which further optimize returning by value
👉 If your function is creating or computing a map, return it.
👉 If your function updates an existing map, pass it by reference.


```c++
// create an empty map
map<int, string> numbers;
```


```c++
// let's create the map using function
createMap(numbers);
```


```c++
// check the contents if the function inserted elements into map
numbers
```




    { 1 => "one", 2 => "two", 3 => "three", 4 => "four" }



<a id="applications"></a>

## Applications
- map is a fast data structure that can help us solve many problems

#### Keep track of menu items and the customers who ordered those items
- e.g. https://open.kattis.com/problems/baconeggsandspam


```c++
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
```


```c++
map<string, vector<string> > items;
```


```c++
// bacon is ordered by John
items["bacon"].push_back("John");
```


```c++
// bacon is ordered by Jim
items["bacon"].push_back("Jim");
```


```c++
// see all the custumers who ordered bacon
items["bacon"]
```




    { "John", "Jim" }




```c++
// menu is an element with (key, value) pair
for (auto menu : items) {
    cout << menu.first; // print key  (menu item)
    // sort value (vector of customers)
    sort(menu.second.begin(), menu.second.end());
    // print each value in the vector which is the second element of p
    for (auto customer: menu.second)
        cout << " " << customer;
}
```

    bacon Jim John


```c++
// sort the vector with the key 'bacon' in descending (non-increasing) order
sort(items["bacon"].begin(), items["bacon"].end(),  greater<string>());
```


```c++
// see the sorted vector
items["bacon"]
```




    { "John", "Jim" }



## Unordered Map
- https://www.cppreference.com/w/cpp/container/unordered_map.html
- A collection of key-value pairs, where each key is unique and mapped to a specific value. The elements are not sorted and are organized into buckets based on their hash values.
- item lookup, insertion, and deletion have average time complexity of O(1)
- Example usage:


```c++
#include <iostream>
#include <unordered_map>
using namespace std;
```


```c++
unordered_map<string, int> age_map = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};
```


```c++
// add a new key-value pair
age_map["Dave"] = 28;
```


```c++
// retrieve value by key
age_map["Dave"]
```




    28




```c++
// update value for existing key
age_map["Alice"] = age_map["Alice"] + 1;
```


```c++
age_map["John"]
```




    0




```c++
age_map
```




    { "Dave" => 28, "John" => 0, "Alice" => 31, "Bob" => 25, "Charlie" => 35 }




```c++
// find the age of Bob
if (age_map.find("Bob") != age_map.end()) {
    cout << "Bob's age is " << age_map["Bob"] << endl;
} else {
    cout << "Bob not found in the map." << endl;
}
```

    Bob's age is 25



```c++
// traverse the unordered_map
for (const auto& pair : age_map)
{
    cout << pair.first << ": " << pair.second << endl;
}
```

    Dave: 28
    John: 0
    Alice: 31
    Bob: 25
    Charlie: 35


## Labs

- 1. The following lab demonstrates the usage of map data structure.
    - use partial solution `main.cpp` file in `./labs/maps/sevenwonders/` folder
    - update and use `Makefile` to compile and debug the program
    - fixe all the FIXMEs and write #FIXED# next to each FIXME once fixed
    - submit the fixed solution to Kattis to get Accepted verdict

## Exercises
1. Write a function that finds and returns the letter frequency in a given word.
    - write 3 automated test cases


```c++
// Sample solution for Exercise 1
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;
```


```c++
// returns true if key is found; false otherwise
bool searchMap1(const map<char, int> m, char key) {
    auto find = m.find(key);
    return (find != m.end());
}
```


```c++
void test_searchMap() {
    assert(searchMap1({{'a', 1}, {'b', 5}, {'!', 1}}, 'a') == true);
    assert(searchMap1({{'q', 2}, {'Z', 1}}, 'm') == false);
    cerr << "all test cases passed for searchMap\n";
}
```


```c++
test_searchMap();
```

    all test cases passed for searchMap



```c++
// function finds and returns frequency of each character
void letterFrequency(string text, map<char, int> & freq) {
    for (char ch: text) {
        ch = char(tolower(ch)); // make case insensitive
        // find each c in freq map
        if (searchMap1(freq, ch)) // found
            freq[ch] += 1; // update frequency by 1
        else
            freq[ch] = 1; // add new element
    }
}
```


```c++
void test_letterFrequency() {
    map<char, int> ans;
    letterFrequency("Hi!", ans);
    map<char, int> expected = {{'!', 1}, {'h', 1}, {'i', 1}};
    assert(ans == expected);
    ans.clear();
    letterFrequency("Yo yO", ans);
    map<char, int> expected1 = {{' ', 1}, {'o', 2}, {'y', 2}};
    assert(ans == expected1);
    ans.clear();
    letterFrequency("Mississippi", ans);
    map<char, int> expected2 = {{'i', 4}, {'m', 1}, {'p', 2}, {'s', 4}};
    assert(ans == expected2);
    cerr << "all test cases passed for letterFrequency()\n";
}
```


```c++
test_letterFrequency();
```

    all test cases passed for letterFrequency()



```c++
string input;
```


```c++
cout << "Enter some text:";
getline(cin, input);
```

    Enter some text:This is some text!



```c++
input
```




    "This is some text!"




```c++
map<char, int> answer;
```


```c++
letterFrequency(input, answer);
```


```c++
answer
```




    { ' ' => 3, '!' => 1, 'e' => 2, 'h' => 1, 'i' => 2, 'm' => 1, 'o' => 1, 's' => 3, 't' => 3, 'x' => 1 }



### complete sample solution for Exercise 1 is at `demos/maps/letter_frequency/`


2. Write a function that finds and returns the frequency of vowels in a given word.
    - write 3 automated test cases

3. Write a program that reads some text data and prints a frequency table of the letters in alphabetical order. Case and punctionals should be ignored. A sample output of the program when the user enters the data "ThiS is String with Upper and lower case Letters", would look this:
<pre>
a  2
c  1
d  1
e  5
g  1
h  2
i  4
l  2
n  2
o  1
p  2
r  4
s  5
t  5
u  1
w  2
</pre>
- design your program in such a way that you write automated test cases
- prompt user to enter some text
- use as many functions as possible
- write at least 3 test cases for each function that computes some results

## Kattis Problems for demo
- Car Racing - https://open.kattis.com/problems/carracing
    - Steps:
        1. read number of data points
        2. use map to store car id to vector of int for positions
        3. use accumulator to sum positions and get average for each car
        4. store the results in vector of pair
        5. use min_element to find the car with best average position
        6. print the pair pointed to by the iterator returned by min_element
    
- Dialling Digits - https://open.kattis.com/problems/diallingdigits
    - Steps:
        1. create unordered_map to map each character to digit including for 1 and 0
        2. create a map of each number to set of neumonics
        3. read all neumonics and store in the map
        4. for each number in the input, print count and all the possible neumonics


## Kattis problems for practice

- several problems in Kattis can be solved easier if map or unordered_map is used

- here are some of the problems that can be solved using map data structure

- Taking Inventory - https://open.kattis.com/problems/takinginventory
- QWERTY - https://open.kattis.com/problems/qwerty
- I've Been Everywhere, Man -  https://open.kattis.com/problems/everywhere
- Seven Wonders - https://open.kattis.com/problems/sevenwonders
- ACM Contest Scoring - https://open.kattis.com/problems/acm
- Stacking Cups - https://open.kattis.com/problems/cups
- A New Alphabet - https://open.kattis.com/problems/anewalphabet
- Words for Numbers - https://open.kattis.com/problems/wordsfornumbers
- Babelfish - https://open.kattis.com/problems/babelfish
- Popular Vote - https://open.kattis.com/problems/vote
- Adding Words - https://open.kattis.com/problems/addingwords
- Grandpa Bernie - https://open.kattis.com/problems/grandpabernie
- Judging Troubles - https://open.kattis.com/problems/judging
- Not Amused - https://open.kattis.com/problems/notamused
- Engineering English - https://open.kattis.com/problems/engineeringenglish
- Hardwood Species - https://open.kattis.com/problems/hardwoodspecies
- Conformity - https://open.kattis.com/problems/conformity
- Galactic Collegiate Programming Contest - https://open.kattis.com/problems/gcpc
- Simplicity - https://open.kattis.com/problems/simplicity
- Accounting - https://open.kattis.com/problems/bokforing
- Soundex - https://open.kattis.com/problems/soundex
- Nicknames - https://open.kattis.com/problems/nicknames
- Minor Setback - https://open.kattis.com/problems/minorsetback
- Sort - https://open.kattis.com/problems/sort
    - two unordered_maps; one to count frequencies, 
- Trending Topic - https://open.kattis.com/problems/trendingtopic
    - unordered map
- FizzBuzz - https://open.kattis.com/problems/fizzbuzz2
    - unordered map
- Traing Boarding - https://open.kattis.com/problems/trainboarding
    - unordered map
- Course Scheduling - https://open.kattis.com/problems/coursescheduling
    - unordered map
- Zipf's Law - https://open.kattis.com/problems/zipfslaw
    - Use unordered_map to store frequency of each word
    - parse character by character and ignore words with length 1
    - words contain only alphabets; ignore case; multiple test cases in input
- Morse Numbers - https://open.kattis.com/problems/morsenumbers
- Morse Code Palindromes - https://open.kattis.com/problems/morsecodepalindromes
- Margrethe 2. - https://open.kattis.com/problems/margrethe2
- Alliteration - https://open.kattis.com/problems/alliteration


## Summary
- learned a very useful associative data structure called map
- each element of map is a key-value pair
- elements of map are sorted based on key
- went through various member functions of map objects and their applications
- learned that maps can be passed to functions and can be returned from them as well
- exercises and sample solutions


```c++

```
