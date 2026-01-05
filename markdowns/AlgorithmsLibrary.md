# Algorithms Library

- https://www.cppreference.com/w/cpp/algorithm.html
- The standard library provides implementations of various algorithms in C++. 
- Some commonly used algorithms include sorting, searching, and manipulating sequences of elements.

## Common functions defined in `<algorithm>`
- `std::sort`: Sorts a range of elements.
- `std::is_sorted`: Checks if a range is sorted.
- `std::find`: Searches for a specific value in a range.
- `std::copy`: Copies elements from one range to another.
- `std::accumulate`: Computes the sum of a range of elements.
- `std::transform`: Applies a function to a range of elements and stores the result in another range.

## Example Usage

## Numberic Operations



```python
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
```


```python
vector<float> data{1.5, 2.5, 3.5};
float sum = accumulate(data.begin(), data.end(), 0.0f);
cout << "Sum: " << sum << endl;
```

    Sum: 7.5



```python
int a = 5;
int b = 10;
swap(a, b);
cout << "a: " << a << ", b: " << b << endl;
```

    a: 10, b: 5



```python
cout << max(10, 20) << endl;
cout << min({10, 20, 30, -1, -100}) << endl;
```

    20
    -100



```python
auto compare = [](const string& a, const string& b) {
    return a.size() < b.size(); // Max-heap based on the size of the first element
};
// create a initializer list of words
auto words = {"apple", "banana", "cherry", "date", "cat", "dog", "elephant"};
cout << max(words, compare) << endl;
cout << min(words, compare) << endl;
```

    elephant
    cat


### Sorting Operations


```python
vector<int> v{5, 3, 8, 1, 2};

// Sort the vector in ascending order
sort(v.begin(), v.end());
```


```python
v
```




    { 1, 2, 3, 5, 8 }




```python
is_sorted(v.begin(), v.end()) ? cout << "Sorted\n" : cout << "Not sorted\n";
```

    Sorted


### Binary Search Operations

- `std::binary_search`: Checks if a value exists in a sorted range.
- `std::lower_bound`: Returns an iterator to the first element that is not less than a given value.
- `std::upper_bound`: Returns an iterator to the first element that is greater than a given value.
- `std::equal_range`: Returns a pair of iterators to the range of elements equal to a given value.


```python
vector<string> words{"apple", "orange", "banana", "grape"};
sort(words.begin(), words.end());
```


```python
auto it = binary_search(words.begin(), words.end(), "banana");
if (it) {
    cout << "\"banana\" found in the list.\n";
} else {
    cout << "\"banana\" not found in the list.\n";
}
```

    "banana" found in the list.



```python
vector<int> nums{10, 20, 30, 40, 50};
auto it = lower_bound(nums.begin(), nums.end(), 25);
cout << "First element not less than 25 is: " << *it << endl;
```

    First element not less than 25 is: 30



```python
auto it_upper = upper_bound(nums.begin(), nums.end(), 25);
cout << "First element greater than 25 is: " << *it_upper << endl;
```

    First element greater than 25 is: 30


## Set Operations
- `std::set_union`: Computes the union of two sorted ranges.
- `std::set_intersection`: Computes the intersection of two sorted ranges.
- `std::set_difference`: Computes the difference between two sorted ranges.
- `std::includes`: Checks if one sorted range includes another.

- examples follow


```python
vector<int> nums{1, 2, 3, 4, 5};
vector<int> other{1, 2, 3, 4, 5, 6, 7, 8};


```


```python
bool includes_result = includes(other.begin(), other.end(), nums.begin(), nums.end());
cout << "other includes nums? " << (includes_result ? "Yes" : "No") << endl;
```

    other includes nums? Yes



```python
vector<int> intersection;
set_intersection(nums.begin(), nums.end(),
                 other.begin(), other.end(),
                 back_inserter(intersection));
```


```python
intersection
```




    { 1, 2, 3, 4, 5 }




```python
vector<int> union_result;
set_union(nums.begin(), nums.end(),
          other.begin(), other.end(),
          back_inserter(union_result));
```


```python
union_result
```




    { 1, 2, 3, 4, 5, 6, 7, 8 }



## Heap Operations
- heap is a specialized tree-based data structure that satisfies the heap property.
- heap is commonly used to implement priority queues.
- C++ provides max-heap operations in the `<algorithm>` header

- `std::make_heap`: Converts a range into a heap.
- `std::push_heap`: Adds a new element to the heap.
- `std::pop_heap`: Removes the largest element from the heap.
- `std::sort_heap`: Sorts the elements in the heap in ascending order.
- `std::is_heap`: Checks if a range is a valid heap.
- examples follow


```python
vector<pair<int, string>> items = {
    {3, "read"},
    {1, "write"},
    {4, "code"},
    {2, "play"}
};
```


```python
items
```




    { {3 , "read"}, {1 , "write"}, {4 , "code"}, {2 , "play"} }




```python
make_heap(items.begin(), items.end(),
          [](const auto& a, const auto& b) {
              return a.first < b.first; // Max-heap based on the first integer value
          });
```


```python
items
```




    { {4 , "code"}, {2 , "play"}, {3 , "read"}, {1 , "write"} }




```python
// first push a new item
items.push_back({5, "sleep"});
```


```python
items
```




    { {4 , "code"}, {2 , "play"}, {3 , "read"}, {1 , "write"}, {5 , "sleep"} }




```python
// then re-adjust the heap
push_heap(items.begin(), items.end(),
               [](const auto& a, const auto& b) {
                   return a.first < b.first;
               });
```


```python
items
```




    { {5 , "sleep"}, {4 , "code"}, {3 , "read"}, {1 , "write"}, {2 , "play"} }




```python
is_heap(items.begin(), items.end(),
         [](const auto& a, const auto& b) {
             return a.first < b.first;
         }) ? cout << "items is a heap\n" : cout << "items is not a heap\n";
```

    items is a heap



```python
while (!items.empty()) {
    // Move the largest element to the end
    pop_heap(items.begin(), items.end(),
             [](const auto& a, const auto& b) {
                 return a.first < b.first;
             });
    cout << "Process largest item: {" << items.back().first << ", " << items.back().second << "}" << endl;
    // Remove the last element (the largest)
    items.pop_back();
    cout << "After popping, items size: " << items.size() << endl;
}
```

    Process largest item: {5, sleep}
    After popping, items size: 4
    Process largest item: {4, code}
    After popping, items size: 3
    Process largest item: {3, read}
    After popping, items size: 2
    Process largest item: {2, play}
    After popping, items size: 1
    Process largest item: {1, write}
    After popping, items size: 0



```python

```

## Permutation Operations

- `std::next_permutation`: Generates the next lexicographical permutation of a range.
- `std::prev_permutation`: Generates the previous lexicographical permutation of a range.
- `std::is_permutation`: Checks if two ranges are permutations of each other.

- examples follow


```python
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
```


```python
string dna = "AGT";
string dna1 = "TAG";
if (is_permutation(dna.begin(), dna.end(), dna1.begin())) {
    cout << "dna and dna1 are permutations of each other." << endl;
} else {
    cout << "dna and dna1 are not permutations of each other." << endl;
}
```

    dna and dna1 are permutations of each other.



```python
next_permutation(dna.begin(), dna.end());
cout << dna << endl;
```

    AGT



```python
while (next_permutation(dna.begin(), dna.end())) {
    cout << dna << endl;
}
```

    ATG
    GAT
    GTA
    TAG
    TGA


## Other operations
- `std::transform`: Applies a function to a range of elements and stores the result in another range.
- `std::remove_if`: Removes elements from a range that satisfy a given condition.


```python
char to_uppercase(unsigned char& c)
{
    c = std::toupper(c);
}
```


```python
string hello("hello");
transform(hello.begin(), hello.end(), hello.begin(), to_uppercase);
cout << hello << endl;
```

    HELLO



```python
bool is_vowel(char c)
{
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string text = "Hello, World!";
text.erase(remove_if(text.begin(), text.end(), is_vowel), text.end());
cout << text << endl;
```

    Hll, Wrld!



```python
std::vector<int> v {1, 2, 3};
std::reverse(v.begin(), v.end());

```


```python
v
```




    { 3, 2, 1 }




```python
int a[] = {10, 4, 5, 6, 7};
// array doesn't have member functions for begin() and end()
std::reverse(std::begin(a), std::end(a));
```


```python
a
```




    { 7, 6, 5, 4, 10 }



## Exercises

- But I want to Win - https://open.kattis.com/problems/butiwanttowin
- CD - https://open.kattis.com/problems/cd


