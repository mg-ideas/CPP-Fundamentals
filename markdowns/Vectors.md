# Vector Containers

## Topics
- what is and why vectors
- how to use vectors
- various operations and methods provided by vectors
- applications and examples using vectors
- sorting vectors

## External Resources

- YouTube Video - [https://youtu.be/PiOTav8LPso](https://youtu.be/PiOTav8LPso)
- YouTube Podcast - [https://youtu.be/tfFzPUF7Krk](https://youtu.be/tfFzPUF7Krk)
- C++ Reference for Vectors: [https://en.cppreference.com/w/cpp/container/vector](https://en.cppreference.com/w/cpp/container/vector)
- NotebookLM learning materials - [https://notebooklm.google.com/notebook/9216396a-3848-4e83-83de-f76cf6ce1e54](https://notebooklm.google.com/notebook/9216396a-3848-4e83-83de-f76cf6ce1e54)

## Vectors
- vector is a collection of values where each value is identified by a number (index)
- anything that can be done by C-array (Array chapter) can be done using vectors
    - unlike C-array, vector is an advanced type like C++ string
- vector is defined in the C++ Standard Template Library (STL)
    - vector is one of my containers library - https://en.cppreference.com/w/cpp/container
    - array, set, map, queue, stack, priority_queue are some other containers provided in STL
- learning vector is similar to learning C++ string container
    - main difference is vector can store any type of element
    - learn all the operations provided by vector
        - what they are; what they do; how to use them...
    - apply vectors to solve problems
- vector and other containers provided in STL are templated, hence "Template" in STL
    - the actual type that you're storing in those containers need to be specified
    - very similar to template struct types covered in **Structures** chapter
    - to learn STL containers and more, follow these notebooks: https://github.com/rambasnet/STL-Notebooks
- must include `<vector>` header to use vector type

## Vector objects
- C++ vector is an advanced type defned in `<vector>` header and the `std namespace`
- objects must be instantiated or declared to allocate memory before we can store data into them
- since vector uses template type, you must provide the actual type of the data
- syntax:

```cpp
#include <vector>

vector<type> objectName;

using namespace std;
```


```C++14
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;
```


```C++14
// declare empty vectors
vector<string> names;
vector<float> tests;
vector<int> numbers;
```


```C++14
// let's see the contents
names
```




    {}




```C++14
// declare and initialize vectors
vector<string> words = {"i", "love", "c++", "vectors"};
vector<float> prices = {1.99, 199, 2.99, 200.85, 45.71};
```


```C++14
// let's see the contents
words
```




    { "i", "love", "c++", "vectors" }




```C++14
prices
```




    { 1.99000f, 199.000f, 2.99000f, 200.850f, 45.7100f }



## Accessing elements
- elements accessed mostly using index just like in C-array or string
- index starts from 0 and goes to 1 less than the vector size or length
- the following methods are available:
    - **at(index)** : access specified element with bounds checking
    - **operator[index]** : access specified element by index
    - **front( )** : access the first element
    - **back( )** : access the last element

- *do they sound familiar? same method names as accessing characters in string objects*


```C++14
// access elements
// change i to I in words
words[0] = "I";
cout << words[1] << endl; // print 2nd word
cout << prices.at(3) << endl;
cout << prices.front() << endl;
cout << prices.back() << endl;
```

## Capacity
- unlike C-array, vector provides member functions to work with the capacity of the vector objects
- the following are the commonly used methods:
    - **empty( )** : checks whether the container is empty; returns true if empty; false otherwise
    - **size( )** : returns the number of elements or length of the vector
    - **max_size( )** : returns the maximum possible number of elements that can be stored


```C++14
cout << boolalpha; // convert boolean to text true/false
cout << "is prices vector empty? " << prices.empty() << endl;
cout << "size of words: " << words.size() << endl;
cout << "size of prices: " << prices.size() << endl;
cout << "max size of words: " << words.max_size() << endl;
```

## Modifiying vectors
- vectors once created can be modified using various member functions or methods
- some commonly used methods are:
    - **clear( )** : clears the contents
    - **push_back(element)** : adds an element to the end
    - **pop_back( )** : removes the last element

- *Note: if C-array was used, programmers would be have to implement these functions*


```C++14
vector<int> age = {21, 34, 46, 48, 46};
```


```C++14
// see the initial contents
age
```


```C++14
// let's clear age vector
age.clear();
```


```C++14
// is age cleared?
age
```


```C++14
// double check!
age.empty()
```


```C++14
// let's add element into the empty age vector
age.push_back(25);
```


```C++14
age.push_back(39);
```


```C++14
age.push_back(45.5); // can't correctly add double to int vector
```


```C++14
age
```


```C++14
// let's see the last element
age.back()
```


```C++14
// let's remove the last element
age.pop_back();
```


```C++14
// check if last element is gone
age
```

## Traversing vectors
- similar to string and C-array, vectors can be traversed from the first to last element
- can use loop with index or iterators


```C++14
for(auto val: words)
    cout << val << "; ";
```


```C++14
for(int i=0; i<words.size(); i++) {
    cout << words[i] << " is " << words[i].length() << " characters long." << endl;
}
```

## Iterators
- similar to string iterators, vector provides various iterators 
- iterators are special pointers that let you manipulate vector
- several member function of vector uses iterator to do its operation
- let's revist the iterators we went over in string chapter

![](resources/range-rbegin-rend.png)

- **begin( )** - returns iterator to the first element
- **end( )** - returns iterator to the end (past the last element)
- **rbegin( )** - returns reverse iterator to the last element
- **rend( )** - returns a reverse iterator to the beginning (prior to the first element)


```C++14
// let's use iterator to traverse vectors
// very similar to using for loop with index
for(auto iter = words.begin(); iter != words.end(); iter++)
    cout << *iter << "; "; // iter is a pointer; so must derefernce to access value pointed to by iter
```


```C++14
// let's reverse traverse
for(auto iter = words.rbegin(); iter != words.rend(); iter++)
    cout << *iter << "; "; // iter is a pointer; so must derefernce to access value pointed to by iter
```

## Aggregagte operations
- some aggegate operators such as assignment (=) and comparison (>, ==, etc.) are overloaded and work out of the box on vector objects as a whole
- sorta works! - depends on what type of vector and if there's a predfined ordering of values in that type for sorting!
- input, output (`<<`, `>>`) operators do not work on vector objects as a whole


```C++14
// create words_copy vector with copy assignment
vector<string> words_copy = words; // deep copies words into words_copy
```


```C++14
// string can be compared out of the box
if (words == words_copy)
    cout << "two vectors are equal!";
else
    cout << "two vectors are not equal!";
```

## Passing vectors to functions
- vector can be passed to functions by value or by reference
- unless required, it's always efficient to pass containers type such as vectors to function by reference
    - copying data can be costly (can take a long time) depending on the amount of data vector is storing


```C++14
// given a vector of values find and return average 
float findAverage(const vector<int> & v) {
    float sum = 0;
    for (auto val: v)
        sum += val;
    return sum/v.size();
}
```


```C++14
// let's see the values of age vector
age
```


```C++14
cout << "average age = " << findAverage(age);
```


```C++14
// printVector function
template<class T>
void printVector(const vector<T>& v) {
    char comma[3] = {'\0', ' ', '\0'};
    cout << '[';
    for (const auto& e: v) {
        cout << comma << e;
        comma[0] = ',';
    }
    cout << "]\n";
}
```


```C++14
// can't cout and cin into a vector as awhole
cout << words;
```


```C++14
printVector(words);
```


```C++14
printVector(age)
```


```C++14
age
```

## Returning vector from functions
- since vector supports `=` copy operator, returning vector from functions is possible
- since returned vector needs to be copied it can be costly
    - it's best practice to pass vector as reference to get the data/results out of functions


```C++14
// function that gets vector of integers from standard input
void getNumbers(vector<int> & numbers) {
    cout << "Enter as many whole numbers as you wish.\nEnter 'done' when done:\n";
    int num;
    while(cin >> num) // cin returns false when it fails to parse 'done'
        numbers.push_back(num);
}
```


```C++14
// create an empty vector
vector<int> my_numbers;
```


```C++14
getNumbers(my_numbers);
```


```C++14
my_numbers
```

## Two-dimensional vector
- if we insert vectors as an element to a vector, we essentially get a 2-D vector
    - works similar to 2-D array


```C++14
// let's declare a 2-d vector of integers
vector< vector<int> > matrix;
```


```C++14
// add the first vector - first row
matrix.push_back({1, 2, 3, 4});
```


```C++14
matrix[0]
```


```C++14
// let's add an empty vector as the second element or 2nd row
matrix.push_back(vector<int>());
```


```C++14
// let's add elements to the 2nd vector or 2nd row
matrix[1].push_back(5);
matrix[1].push_back(6);
matrix[1].push_back(7);
matrix[1].push_back(8);
```


```C++14
matrix[1]
```


```C++14
// access element of vector elements
// first row, first column
matrix[0][0]
```


```C++14
// 2nd row, fourth column
matrix[1][3]
```

## Sort vector
- vector like array needs to be sorted often to solve many problems
- let's use built-in `sort` function in `algorithm` library
    - `sort` function implements one of the fastest sorting algorithms


```C++14
#include <vector>
#include <algorithm> // sort()
#include <iterator> // begin() and end()
#include <functional> // greater<>();
#include <iostream>

using namespace std;
```


```C++14
vector<int> some_values = { 100, 99, 85, 40, 1233, 1};
```


```C++14
// let's sort some_values 
sort(begin(some_values), end(some_values));
```


```C++14
some_values
```


```C++14
sort(some_values.begin(), some_values.end(), greater<int>());
```


```C++14
printVector(some_values);
```


```C++14
matrix[0]
```


```C++14
// sort in increasing order
sort(matrix[0].begin(), matrix[0].end());
```


```C++14
matrix[0]
```


```C++14
// sort in non-increasing order
sort(matrix[0].begin(), matrix[0].end(), greater<int>());
```


```C++14
matrix[0]
```

## Labs

1. The following lab demonstrates the usage of vector data structure and some operations on vectors.
    - use partial solution `numberSystem.cpp` file in [labs/vectors/numSystem](./labs/vectors/numSystem/) folder
    - use Makefile to compile and debug the program
    - fixe all the FIXMEs and write #FIXED# next to each FIXME once fixed

## Exercises

### Sove all exercises listed in Array chapter using vector instead.

### More exercises
1. Write a function that splits a given text/string into a vector of individual words
    - each word is sequence of characters separated by a whitespace
    - write 3 test cases


```C++14
// Solution to Exercise 1
void splitString(vector<string> &words, string text) {
    string word;
    stringstream ss(text);
    while (ss >> word) {
        words.push_back(word);
    }
}
```


```C++14
void test_splitString() {
    vector<string> answer;
    splitString(answer, "word");
    vector<string> actual = {"word"};
    assert(answer == actual);
    answer.clear();
    splitString(answer, "two word");
    vector<string> actual1 = {"two", "word"};
    assert(answer == actual1);
    answer.clear();
    splitString(answer, "A sentence with multiple words!");
    vector<string> actual2 = {"A", "sentence", "with", "multiple", "words!"};
    assert(answer == actual2);
    answer.clear();
    cerr << "all test cases is passed for splitString()\n";
}
```


```C++14
test_splitString();
```


```C++14
vector<string> tokens;
```


```C++14
// not needed but just in case!
tokens.clear();
```


```C++14
splitString(tokens, "This is a long sentence so long that it's hard to comprehend!");
```


```C++14
tokens
```

### complete program can be found in [demos/vectors/splitString/](./demos/vectors/splitString/)

2. Airline Reservation System
    - Write a C++ menu-driven CLI-based program that let's an airline company manage airline reservation on a single aircraft they own with the following requirements:
    - aircraft has 10 rows with 2 seat on each row
    - program provieds menu option to display all the avaialable seats
    - program provides menu option to let user pick any available seat
    - program provides menu option to creates total sales report
    - program provides menu option to update price of any seat
    
3. Triangle
    - write a program to compute area and perimeter of a triangle given 3 sides using vector
    - prompt user to enter 3 sides of a triangle
        - implement input validation and validate the triangle
    - use as many function(s) as possible
    - write at least 3 test cases for each computing functions
    - a sample solution can be found in [demos/vectors/triangle/](./demos/vectors/triangle/)

## Kattis problems
- problems that require to store large amount of data in sequential order in memory can use vector very effectively
- design your solutions in a way that it can be tested writing automated test cases


- Dice Game - https://open.kattis.com/problems/dicegame
- Falling Apart - https://open.kattis.com/problems/fallingapart
- Height Ordering - https://open.kattis.com/problems/height
- What does the fox say? - https://open.kattis.com/problems/whatdoesthefoxsay
- Army Strength (Easy) - https://open.kattis.com/problems/armystrengtheasy
- Army Strength (Hard) - https://open.kattis.com/problems/armystrengthhard
- Black Friday - https://open.kattis.com/problems/blackfriday
- Bacon, Eggs and Spam - https://open.kattis.com/problems/baconeggsandspam
- Toflur - https://open.kattis.com/problems/toflur
- Free-Form Input - https://open.kattis.com/problems/freeforminput

### sorting vectors with two keys
- Roll Call - https://open.kattis.com/problems/rollcall
- Cooking Water - https://open.kattis.com/problems/cookingwater
- Multiple Choice - https://open.kattis.com/problems/multiplechoice


## Summary
- this chapter covered C++ vector container STL
- vector is an easier alternative to C-array
- vector is and advanced type that you can create/instantiate bojects from
- the type of the data must be mentioned as a template parameter while declaring vectors
- provides many out-of the box common operations in the form of member functions or methods
- vector can be passed to functions; returning a large vector may not be effective due to copying of data
- probems and sample solutions


```C++14

```
