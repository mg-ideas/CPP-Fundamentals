# Data Structures and Records in C++

## Topics
- compound and heterogeneous types
- structures and record types
- examples of structures and objects
- aggregate operations on objects
- passing structure to and and returing from functions
- array of structures
- structures in another structure

## External Resources

- Data Structures Tutorial - [https://cplusplus.com/doc/tutorial/structures/](https://cplusplus.com/doc/tutorial/structures/)
- YouTube Video - [https://youtu.be/11o1KpaHGVQ](https://youtu.be/11o1KpaHGVQ)
- YouTube Podcast - [https://youtu.be/pYadFY6oSXI](https://youtu.be/pYadFY6oSXI)
- NotebookLM learning materials - [https://notebooklm.google.com/notebook/de5fe6ff-2f39-4f7a-b024-33c0a738509c](https://notebooklm.google.com/notebook/de5fe6ff-2f39-4f7a-b024-33c0a738509c)

## Compound and heterogeneous types

- most of the data types we've worked with so far represent a single value
    - an interger, floating-point value, char, etc.
- we've also worked with array of similar values such as string, array of integers or array of strings
- array, vector and string can be considered as compound types but all elements are **homogeneous (same) type**
- C++ possibly can't provide all the types of data that programs need to efficiently represent and handle
- e.g. Complex numbers, Points in coordinates, various records (student records, police records, etc.)
- a large number of these types are compound but mixture of **heteregenous (mixed) types**
    - e.g. student records may have integer for ID, string for names and addresses, float for GPA and grades, etc.
- the following figure shows some sample student records in a spreadsheet document that a program may have to represent:

![](assets/records.png)

- two records displayed in the figure have the same heteregeneous structure
    - we can represent these records and store them in memory using array of structure
- via **struct** and **class** constructs, C++ allows us to create any type of heteregeneous data records that we want to represent
- we do not include any library to use **struct** and **class** keywords
- **class** is a big topic typically covered in **Data Structures** and **Object Oriented Programming** courses
   
## Structures
- structrues are user-defined, compound and typically heterogenous types
- the following figure demonstrates student record represented using structure
<img src="assets/record.png" width="25%">
- allows us to organize many different types of data under ONE compound type
- each type of data is represented by its own name and is called a member of the structure
- makes it easier to manipulate and move the data records around in a program using a single object/variable
- using structures is a three-step process:
    1. define the new structure type
    2. declare objects using the new structrue type
    3. access members to store, update and read data
- keyword **struct** short for structure is used to define structure type   
- syntax to define structure:
```cpp
struct structureName {
    type1 memberName1;
    type2 memberName2;
    type3 memberName3;
    type4 memberName4;
    //...
};
```
- note the required semi-colon `;` after closing curley brace
- when defining struct, we don't initialize members; they are merely the blueprint (template) not actual variables

- syntax to declare objects of struct type:

```cpp
structureName objectName;
```

- exactly like declaring simple variables
- this step actually allocates all the memory required to store one record for some instance objectName
- the process of creating objects from `struct type` is called **instantiation**
- compound variables that could hold more than 1 values are typically called **objects**

- syntax to access members:

```cpp
objectName.memberName
```
- each member is used like a single variable; only difference is the way they're accessed
- member can be accessed only by its instance (object) name

## Define structure type to represent student records
- representing the student record displayed in the figure above
- TBD in class

## Declare objects to store students' records
- TBD in class
- declare and initialize using uniform initialization

## Access members of students' objects/records
- TBD in class

## Point structure definition
- a point in Cartesian coordinate (2-D geometry) is two numbers called coordinates
- there may be a large number of points on the plain, but each point is treated collectively as a single object
- e.g.(0, 0) indicates the origin, and $(x, y)$ indicates the point $x$ units from $x$-axis and $y$ units from the $y$-axis

![](resources/Cartesian-coordinates.png)

- how can we represent 2-D points in C++?
    - we can use structure!


```C++17
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
```


```C++17
// define a point structure
struct Point {
    // can be declared as int x, y;
    int x; // member 1
    int y; // member 2
    // any other member?
    // parenthesis are common on all points and used only for representation
    // we don't need members for parenthesis
};
// do not initialize members as the memory is not allocated just yet!
```

## Point objects
- recall Point structure is just the definition and doesn't actually store data
- need to declare Point objects to actaully store the data values (coordinates)
- we can also declare pointers to struct types
- syntax to declare struct objects and pointers is similar to declaring variables
    - afterall, struct is a user-defined type
    
```cpp
structName objectName;
```
- objects created are automatic or stored in stack memory segment


```C++17
// declare/instantiate some point objects
Point pt1, pt2;
```


```C++17
// declare and initialize point objects
// using uniform initialization
// members are initialized in the order they're defined
Point origin = {0, 0};
```


```C++17
// explictly casting two values as Point type
pt1 = Point({2, 3});
```


```C++17
// implicit coersion of two values as a Point type
pt2 = {3, 0};
```


```C++17
// declared a pointer of Point type and initialize with nullptr
Point * pt_ptr = nullptr;
```


```C++17
// assign value/address to pt_ptr
// recall, pointers store memory addressess only!
pt_ptr = &pt1;
```


```C++17
// two addresses must be equal!
cout << pt_ptr << " == " << &pt1 << endl;
```

    0x10f5422d8 == 0x10f5422d8


## Dynamic objects
- memory needed for any struct objects can be allocated in heap memory segment
- the syntax to allocate dynamic objects:

```cpp
structName * ptrName = new structName();
```

- the syntax is same as declaring dynamic variables covered in **Pointers** chapter


```C++17
// instantiate a pointer object
Point * pt_ptr1 = new Point;
```


```C++17
// instantiate and initialize a pointer object
Point * pt_ptr2 = new Point({100, -200});
```

## Point members
- each member of Point object can be accessed using `.` member access operator
- syntax:

```cpp
object.member;
ptrObject->member;
```

- members are same as variables that allow us to store and access data
- if a pointer object is used, `->` arrow/pointer operator is used to access member


```C++17
// access members using . (member access) operator
cout << "origin = (" << origin.x << "," << origin.y << ")" << endl;
```

    origin = (0,0)



```C++17
// assgin values to pt1 and pt2;
pt1.x = -3;
pt1.y = 1;
```


```C++17
// find the distance between pt1 and pt2
float dist;
```


```C++17
dist = sqrt(pow(pt1.x-pt2.x, 2) + pow(pt1.y-pt2.y, 2))
```




    6.08276f




```C++17
cout << "distance = " << dist << endl;
```

    distance = 6.08276



```C++17
// accessing members using pointer variables
pt_ptr1->x = -3;
pt_ptr1->y = 1;
```


```C++17
// we get the same result as above
dist = sqrt(pow(pt_ptr1->x-pt2.x, 2) + pow(pt_ptr1->y-pt2.y, 2))
```




    6.08276f



### Deferencing pointers to their objects
- cast as an object by deferencing pointer first and use `.` member access operator


```C++17
// accessing members using by dereferncing pointers
cout << (*pt_ptr1).x << " " << (*pt_ptr1).y;
```

    -3 1

### Visualize struct and objects in [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20struct%20demo%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Astruct%20Point%20%7B%0A%20%20%20%20int%20x%3B%20//%20member%201%0A%20%20%20%20int%20y%3B%20//%20member%202%0A%7D%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20//%20auto%20objects%0A%20%20Point%20pt1%3B%0A%20%20Point%20pt2%20%3D%20%7B3,%204%7D%3B%0A%20%20pt1.x%20%3D%205%3B%0A%20%20pt1.y%20%3D%2010%3B%0A%20%20//%20dynamic%20object%0A%20%20Point%20*%20pt3%20%3D%20new%20Point%28%29%3B%0A%20%20pt3-%3Ex%20%3D%2010%3B%0A%20%20pt3-%3Ey%20%3D%2020%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## Template structures
- notice that Point class defined above uses **int** as type for $x$ and $y$ coordinates
- what if we had a coordinate system that used floating point values
    - we'd have to define another struct to represent Point using floating point values
- similar to template function, we can use **template type** in struct definition
    - acts as a placeholder for type that will be passed when the objects are intantiated
- templated struct helps create one generic struct definition that meets all type requirments for its members
- syntax to define template struct type:
```cpp
template<class T1, class T2, ...>
struct structName {
    T1 member1;
    T2 member2;
    type member3;
    // more templated type or actual type members
};
```
- notice the syntax is same as the function template syntax
- `template<class, class, ... >1` construct let's you use 1 or more templated type/class separated by comma

- syntax to instantiate objects of template struct types:

```cpp
structName<actualType1, actualType2, ...> objectName;
```
- actualType1 replaces T1, acttualType2 replaces T2, and so on...

### Templated rectangle type
- sides of rectangle may be of various types such as integer, or float or double, etc.
- we define templated rectangle type to account for those types


```C++17
// assuming both length and width of any rectangle will have the same type T
template<class T>
struct Rectangle {
    T length, width;
    // could use an array of T type
    // T sides[2]; 
    // length and width are better names than array
};
```


```C++17
// instantiate some objects of Rectangle types
Rectangle<int> r1;
Rectangle<float> r2;
```


```C++17
// instantiate and initialize rectangle objects
Rectangle<int> r3 = {10, 5}; 
```


```C++17
Rectangle<float> r4 = {8.5f, 5.5f};
```


```C++17
Rectangle<double> r5 = {100.999, 55.898};
```

## Aggregate operations on struct objects
- for any type one has to wonder what operators work out of the box
    - e.g. on strings, we could use `operator+`, `operator=`, comparison operators (`operator>`, `operator==`, etc.)
- no aggregate operations such as input and output are allowed on struct objects as a whole
    - e.g. can't `cin >>` or `cout << ` objects as a whole
    - it may not make sense to compare two objects (however, compare based on which members?)
- for most operations (except for assignmet), objects must be accessed one member at a time!
    - Note, there are ways to explictly overload aggregate operations by writing extra code
    - that is usually covered in CS2 or *Object Oriented Programming* courses


```C++17
// try cout; can't!!
// pt1 is an object of Point type
// cout << pt1;
// cout may be broken if you run this! so restart the kernel if you get error
```

    [1minput_line_35:4:6: [0m[0;1;31merror: [0m[1minvalid operands to binary expression ('std::__1::ostream' (aka 'basic_ostream<char>') and 'Point')[0m
    cout << pt1;
    [0;1;32m~~~~ ^  ~~~
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:219:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const void *' for 1st argument; take
          the address of the argument with &[0m
        basic_ostream& operator<<(const void* __p);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/type_traits:4034:3: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'std::__1::ostream' (aka 'basic_ostream<char>') to
          'std::byte' for 1st argument[0m
      operator<< (byte  __lhs, _Integer __shift) noexcept
    [0;1;32m  ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:195:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'std::__1::basic_ostream<char>
          &(*)(std::__1::basic_ostream<char> &)' for 1st argument[0m
        basic_ostream& operator<<(basic_ostream& (*__pf)(basic_ostream&))
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:199:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'basic_ios<std::__1::basic_ostream<char,
          std::__1::char_traits<char> >::char_type, std::__1::basic_ostream<char, std::__1::char_traits<char>
          >::traits_type> &(*)(basic_ios<std::__1::basic_ostream<char, std::__1::char_traits<char>
          >::char_type, std::__1::basic_ostream<char, std::__1::char_traits<char> >::traits_type> &)' (aka
          'basic_ios<char, std::__1::char_traits<char> > &(*)(basic_ios<char, std::__1::char_traits<char> >
          &)') for 1st argument[0m
        basic_ostream& operator<<(basic_ios<char_type, traits_type>&
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:204:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'std::__1::ios_base
          &(*)(std::__1::ios_base &)' for 1st argument[0m
        basic_ostream& operator<<(ios_base& (*__pf)(ios_base&))
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:207:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'bool' for 1st argument[0m
        basic_ostream& operator<<(bool __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:208:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'short' for 1st argument[0m
        basic_ostream& operator<<(short __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:209:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'unsigned short' for 1st argument[0m
        basic_ostream& operator<<(unsigned short __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:210:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'int' for 1st argument[0m
        basic_ostream& operator<<(int __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:211:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'unsigned int' for 1st argument[0m
        basic_ostream& operator<<(unsigned int __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:212:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'long' for 1st argument[0m
        basic_ostream& operator<<(long __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:213:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'unsigned long' for 1st argument[0m
        basic_ostream& operator<<(unsigned long __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:214:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'long long' for 1st argument[0m
        basic_ostream& operator<<(long long __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:215:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'unsigned long long' for 1st argument[0m
        basic_ostream& operator<<(unsigned long long __n);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:216:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'float' for 1st argument[0m
        basic_ostream& operator<<(float __f);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:217:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'double' for 1st argument[0m
        basic_ostream& operator<<(double __f);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:218:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'long double' for 1st argument[0m
        basic_ostream& operator<<(long double __f);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:220:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to
          'basic_streambuf<std::__1::basic_ostream<char, std::__1::char_traits<char> >::char_type,
          std::__1::basic_ostream<char, std::__1::char_traits<char> >::traits_type> *' (aka
          'basic_streambuf<char, std::__1::char_traits<char> > *') for 1st argument[0m
        basic_ostream& operator<<(basic_streambuf<char_type, traits_type>* __sb);
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:223:20: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'std::nullptr_t' (aka 'nullptr_t') for
          1st argument[0m
        basic_ostream& operator<<(nullptr_t)
    [0;1;32m                   ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:760:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'char' for 2nd argument[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, char __cn)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:793:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'char' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, char __c)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:800:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'signed char' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, signed char __c)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:807:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'unsigned char' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, unsigned char __c)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:821:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const char *' for 2nd argument[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, const char* __strn)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:867:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const char *' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, const char* __str)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:874:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const signed char *' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, const signed char* __str)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:882:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const unsigned char *' for 2nd argument[0m
    operator<<(basic_ostream<char, _Traits>& __os, const unsigned char* __str)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1066:1: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'Point' to 'const std::__1::error_code' for 2nd
          argument[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __ec)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:753:1: [0m[0;1;30mnote: [0mcandidate template ignored: deduced conflicting types for parameter '_CharT' ('char' vs. 'Point')[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, _CharT __c)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1057:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'basic_string_view<type-parameter-0-0, type-parameter-0-1>'
          against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os,
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1086:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'unique_ptr<type-parameter-0-2, type-parameter-0-3>' against
          'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, unique_ptr<_Yp, _Dp> const& __p)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/iomanip:477:5: [0m[0;1;30mnote: [0mcandidate template ignored: could not match '__iom_t10<type-parameter-0-0>' against 'Point'[0m
        operator<<(basic_ostream<_Cp, _Traits>& __os, const __iom_t10<_Cp>& __x);
    [0;1;32m    ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/iomanip:572:33: [0m[0;1;30mnote: [0mcandidate template ignored: could not match '__quoted_output_proxy<type-parameter-0-0, type-parameter-0-2,
          type-parameter-0-1>' against 'Point'[0m
    basic_ostream<_CharT, _Traits>& operator<<(
    [0;1;32m                                ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/iomanip:592:33: [0m[0;1;30mnote: [0mcandidate template ignored: could not match '__quoted_proxy<type-parameter-0-0, type-parameter-0-1,
          type-parameter-0-2>' against 'Point'[0m
    basic_ostream<_CharT, _Traits>& operator<<(
    [0;1;32m                                ^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1039:1: [0m[0;1;30mnote: [0mcandidate template ignored: requirement '!is_lvalue_reference<basic_ostream<char> &>::value' was not
          satisfied [with _Stream = std::__1::basic_ostream<char> &, _Tp = Point][0m
    operator<<(_Stream&& __os, const _Tp& __x)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:814:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'const _CharT *' against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, const _CharT* __str)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1093:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'bitset<_Size>' against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, const bitset<_Size>& __x)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/valarray:4165:1: [0m[0;1;30mnote: [0mcandidate template ignored: substitution failure [with _Expr1 = std::__1::basic_ostream<char>, _Expr2 =
          Point]: no type named 'value_type' in 'std::__1::basic_ostream<char>'[0m
    operator<<(const _Expr1& __x, const _Expr2& __y)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/valarray:4180:1: [0m[0;1;30mnote: [0mcandidate template ignored: substitution failure [with _Expr = std::__1::basic_ostream<char>]: no type
          named 'value_type' in 'std::__1::basic_ostream<char>'[0m
    operator<<(const _Expr& __x, const typename _Expr::value_type& __y)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/valarray:4196:1: [0m[0;1;30mnote: [0mcandidate template ignored: substitution failure [with _Expr = Point]: no type named 'value_type' in
          'Point'[0m
    operator<<(const typename _Expr::value_type& __x, const _Expr& __y)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1049:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'basic_string<type-parameter-0-0, type-parameter-0-1,
          type-parameter-0-2>' against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os,
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/ostream:1074:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match 'shared_ptr<type-parameter-0-2>' against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, shared_ptr<_Yp> const& __p)
    [0;1;32m^
    [0m[1m/Users/rbasnet/anaconda3/envs/cpp/include/c++/v1/iomanip:362:1: [0m[0;1;30mnote: [0mcandidate template ignored: could not match '__iom_t8<type-parameter-0-2>' against 'Point'[0m
    operator<<(basic_ostream<_CharT, _Traits>& __os, const __iom_t8<_MoneyT>& __x)
    [0;1;32m^
    [0m


    Interpreter Error: 



```C++17
// read in/store data one member at a time
char ch;
Point pt3;
```


```C++17
cout << "Enter a point in (x, y) format: ";
cin >> ch >> pt3.x >> ch >> pt3.y >> ch;
// ch is just a place variable for unnecessary character to read and ignore
```

    Enter a point in (x, y) format: (10, 20)





    @0x10f4ee408




```C++17
// print the point in right format; accessing one member at a time
cout << "pt3 = (" << pt3.x << ", " << pt3.y << ")";
```

    pt3 = (10, 20)

### aggregate copy ( operator= ) is allowed
- one struct object can be copied into another out of the box
- object is copied member by member from source (right) to destination (left)


```C++17
Point pt4 = pt3;
```

## Passing struct objects to functions
- struct objects can be passed to functions both by value and by reference

### pass by value
- by default struct objects are passed by value
- struct objects can be copied into another same type of struct objects using `=` assignment operator
- this allows us to pass struct to functions by value (by copying the data)
    - though not recommended! why?


```C++17
// passing some constant Point
void printPoint(const Point pt) {
    cout << "(" << pt.x << ", " << pt.y << ")";
}
```


```C++17
printPoint(pt4);
```

    (10, 20)

### pass by reference
- any data type can be explictly passed by reference in C++
- recommended as it's more efficient (less memory, faster computation as no copy is required)


```C++17
void getPoint(Point & pt) {
    cout << "Enter a point in (x, y) format: ";
    cin >> ch >> pt.x >> ch >> pt.y >> ch;
    // Note: when using terminal, after the last character ) is read \n is left behind
    // getline() will fail!
    // good idea to read \n whitespace and ignore it!
}
```


```C++17
Point pt5;
```


```C++17
getPoint(pt5);
```

    Enter a point in (x, y) format: (9, -1)



```C++17
printPoint(pt5);
```

    (9, -1)


```C++17
// function finds the distance between two points
// sqrt( (x1-x2)^2 + (y1-y2)^2 )
float distance(const Point & p1, const Point & p2) {
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}
```


```C++17
cout << "distance between ";
printPoint(pt4);
cout << " and ";
printPoint(pt5);
cout << " = " << distance(pt4, pt5);
```

    distance between (10, 20) and (9, -1) = 21.0238

## Returning struct from functions
- as the `=` assignment works on structs, functions can return struct types
- though not recommended! why?
    - same reason as pass by value


```C++17
// function returns Point type object
Point getPoint() {
    Point pt;
    cout << "Enter a point in (x, y) format: ";
    cin >> ch >> pt.x >> ch >> pt.y >> ch;
    return pt;
}
```


```C++17
// assign the returned object from getPoint() to pt6 object
Point pt6 = getPoint();
```

    Enter a point in (x, y) format: 
    (5, 9)



```C++17
printPoint(pt6);
```

    (5, 9)

## Array/vectors of structs
- if more than one similar records/structs need to be stored
    - we can use array or vector of struct type
- let's say, we need to store a bunch of coordinate points in memory
    - array/vector of points is a natural choice!


```C++17
// declare and initialize array
Point points[] = {{1, 2}, {3, 4}, {6, 7}, {-1, -1}, {0, 0}};
```


```C++17
// declare array of points
Point points1[2];
```


```C++17
// accessing point element in array
printPoint(points[0]);
```

    (1, 2)


```C++17
// accessing point element's member in array
cout << "first point's x = " << points[0].x << endl;
```

    first point's x = 1



```C++17
// assiging values to array
points1[0] = getPoint();
```

    Enter a point in (x, y) format: (3, 2)



```C++17
points1[1] = getPoint();
```

    Enter a point in (x, y) format: (9, 8)


### vectors of struct type
- vectors, like arrays, can be used to store user-defined **struct** types


```C++17
// declare and initialize vector of Point
vector<Point> point_vector = {{0, 0}, {1, 1}, {2, 2}};
```


```C++17
// create vector of RectangleType
vector<Rectangle<int> > rects;
```


```C++17
// add r1 rectangle object to rects vector
rects.push_back(r1);
```


```C++17
// can't add Rectangle r2 because its type is float
rects.push_back(r3);
```


```C++17
// declare and initialize rectangles vector with two rectangles
vector<Rectangle<float> > rectangles = {{10, 5}, {8.5, 2.6}};
```


```C++17
// calculate area of first rectangle stored in rectangles vector
cout << "area = " << rectangles[0].length*rectangles[0].width << endl;
```

    area = 50



```C++17
// traversing vectors
// auto also works on user-defined type
for(auto rect: rectangles) {
    cout << "rectangle info - length x width: " << rect.length << " x " << rect.width << endl;
}
```

    rectangle info - length x width: 10 x 5
    rectangle info - length x width: 8.5 x 2.6



```C++17
// same as above
for(Rectangle<float> rect: rectangles) {
    cout << "rectangle info - length x width: " << rect.length << " x " << rect.width << endl;
}
```

    rectangle info - length x width: 10 x 5
    rectangle info - length x width: 8.5 x 2.6



```C++17
// using index
for(int i=0; i<rectangles.size(); i++) {
    cout << "rectangle area: " 
        << rectangles[i].length << "x" 
        << rectangles[i].width << " = " 
        << rectangles[i].length*rectangles[i].width << endl;
}
```

    rectangle area: 10x5 = 50
    rectangle area: 8.5x2.6 = 22.1


## Array/vector in struct
- array or vector of any type can be used as a member of a struct
- if there are several members of same types that don't need their own names, we can use an array/vector member
- having each member their own name makes program more readable and struct intuitive to use, however!


```C++17
#include <vector>
```


```C++17
// let's define a structure to store student record
struct Student {
    string firstName;
    char MI;
    string lastName;
    vector<float> test_scores; // each test doesn't have a unique name
    string pri_contact_fName;
    char pri_contact_MI;
    string pri_contact_lName;
    bool semester_finished[2]; // semesters though have names Freshman Fall, etc.; we can use 1st, 2nd etc.
};
```


```C++17
// declaration of st1
Student st1;
```


```C++17
st1.firstName = "John";
```


```C++17
// accessing an array member
// NOTE: array can be accessed one element at a time
st1.test_scores.push_back(100);
st1.test_scores.push_back(95.5);
```


```C++17
// accessing another array member
st1.semester_finished[0] = true;
st1.semester_finished[1] = false;
```


```C++17
// instantiate and initialize
// Note the order of values and how each member is initialized based on its type
Student st2 = {"Jane", 'A', "Smith", {0, 0, 0}, "Jim", 'J', "Smith", {false, false}};
```


```C++17
// Access student 2's first test score
st2.test_scores[0]
```




    0.00000f




```C++17
// Access student 2's last test score
st2.test_scores.back()
```




    0.00000f




```C++17
// student 1's first test socre
st1.test_scores.front()
```




    100.000f



## Struct inside another struct (aka nested strut)
- any struct type can be used as a member type in another struct type
- in Student structure above, firstName, MI and lastNames can be repeated for various names 
    - student name, primary contact, secondary contact, father's name, mother's name, etc.
- we can convert the repeating group of members into its own struct type


```C++17
// most people have three names
struct NameType {
    string firstName;
    char MI;
    string lastName;
};
```


```C++17
// let's redifine Student type with NameType
struct StudentType {
    NameType name;
    float test_scores[3];
    NameType primary_contact;
    bool semester_finished[2];
};
// Notice how shorter the StudentType has become using NameType?
// we can declare as many names of NameType as we wish
// makes the StudentType concise yet readable and intuitive
```


```C++17
// instantiate objects
StudentType st3;
```


```C++17
// assign values to name member
// "name" is a member of st3 object but it itself is a struct type object
// keep drilling down until we come to the actual member name that stores the data
st3.name.firstName = "David";
st3.name.MI = 'A';
st3.name.lastName = "Johnson";
```


```C++17
// shorter way to assign to a struct type object
st3.name = {"Dave", 'A', "Johnson"};
```


```C++17
// create an array of student records
StudentType students[2];
```


```C++17
students[0] = st3;
```


```C++17
// access member of array and member of struct
students[0].semester_finished[0] = true;
```

## Reading structured data from any input stream
- one must know the structure of data inorder to properly read/parse and store it into a program
- reading unstructured data is difficult
    - one way is to read line by line and process each line
    - another, read whole file and precess it byte by byte
- reading structured data is a bit easier
- let's read the structured data provided in [data/studentgrades.txt](data/studentgrades.txt) file
    - there are 3 rows or records and 5 columns (values) for each record
    - first 2 columns are string (names) and the rest 3 columns are integers (grades)
- most Kattis problems provide some structures in their input data so the programmers can correctly parse the data


```C++17
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;
```


```C++17
// struct type is a perfect way to read these student's grades
struct StudentGrade {
    string firstName;
    string lastName;
    int grades[3];
    float averageGrade;
    char letterGrade;
};
```


```C++17
// let's create a vector of Student type to store all the records
vector<StudentGrade> gradebook;
```


```C++17
ifstream fin;
```


```C++17
// let's read the data
// fin is ifstream object declared above
fin.open("data/studentgrades.txt");
```


```C++17
// let's compute average grade
float average(const StudentGrade & s) {
    float sum = s.grades[0] + s.grades[1] + s.grades[2];
    return sum/3.0;
}
```


```C++17
while(!fin.eof()) { // eof() checks if end-of-file has been reached
    // create Student object to hold the data temporarily
    StudentGrade temp;
    fin >> temp.firstName >> temp.lastName >> temp.grades[0] >> temp.grades[1] >> temp.grades[2];
    if (!fin.good()) break;
    temp.averageGrade = average(temp);
    // add the temp to gradebook
    gradebook.push_back(temp);
}
```


```C++17
// close file
fin.close();
```


```C++17
// let's write a function to print Student's info
void printStudent(const StudentGrade & s) {
    cout << s.firstName << " " << s.lastName << " " << s.grades[0] << " " 
        << s.grades[1] << " " << s.grades[2] << " avg: " << s.averageGrade;
}
```


```C++17
// let's print the first student's info
printStudent(gradebook[0]);
```

    John Smith 100 95 85 avg: 93.3333


```C++17
// print all the students' info
for(StudentGrade s: gradebook) {
    printStudent(s);
    cout << endl;
}
```

    John Smith 100 95 85 avg: 93.3333
    Jane Doe 85 89 99 avg: 91
    Jill Jones 56 89 99 avg: 81.3333



```C++17
// sort the student records based on average score?
// need to define a comparision function and pass it to sort
// compares two students' average grades in ascending order
bool compareSmaller(const StudentGrade & s1, const StudentGrade & s2) {
    return (s1.averageGrade < s2.averageGrade);
}
```


```C++17
// now we can sort the gradebook
sort(gradebook.begin(), gradebook.end(), compareSmaller);
```


```C++17
// print all the students' info
for(StudentGrade s: gradebook) {
    printStudent(s);
    cout << endl;
}
```

    Jill Jones 56 89 99 avg: 81.3333
    Jane Doe 85 89 99 avg: 91
    John Smith 100 95 85 avg: 93.3333



```C++17
// let's write a compare function for descending order
bool compareGreater(const StudentGrade & s1, const StudentGrade & s2) {
    return (s1.averageGrade > s2.averageGrade);
}
```


```C++17
// now we can sort the gradebook in descending order using our own compare function
sort(gradebook.begin(), gradebook.end(), compareGreater);
```


```C++17
// print all the students' info
// looks like this could go into a function...
for(StudentGrade s: gradebook) {
    printStudent(s);
    cout << endl;
}
```

    John Smith 100 95 85 avg: 93.3333
    Jane Doe 85 89 99 avg: 91
    Jill Jones 56 89 99 avg: 81.3333


## Writing structured data to an output stream
- print students' grades report in a tabular format to standard output or a filefile


```C++17
// let's create and open a file to write data to
ofstream fout("data/studentgradereport.txt");
```


```C++17
int colWidth;
```


```C++17
colWidth = 20;
```


```C++17
// print all the students' info to the fout stream

// write column headers
fout << setw(90) << setfill('=') << " " << setfill(' ') << endl;
fout << setw(colWidth) << left << "First Name" 
    << setw(colWidth) << left << "Last Name";
// students grades
for(int i=0; i<3; i++) {
    string testHeader = "test" + to_string(i+1);
    fout << setw(10) << right << testHeader;
}
    
fout << setw(15) << right << "Avgerage" << endl;
fout << setw(90) << right << setfill('=') << " " << endl;

// write records
fout << setfill(' ') << fixed << setprecision(1);
for(StudentGrade s: gradebook) {
    fout << setw(colWidth) << left << s.firstName
        << setw(colWidth) << left << s.lastName;
    for(int i=0; i<3; i++)
        fout << setw(10) << right << s.grades[i];
    fout << setw(15) << right << s.averageGrade << endl;
}
fout << setw(90) << setfill('*') << " " << endl;
```


```C++17
// convert the above code to a function!
// all the stream objects must be passed-by reference!
// out is a generic ostream parameter (can be cout or fout)
void writeResults(ostream & out) {
    // print all the students' info to the fout stream

    // write column headers
    out << setw(90) << setfill('=') << " " << setfill(' ') << endl;
    out << setw(colWidth) << left << "First Name" 
        << setw(colWidth) << left << "Last Name";
    // students grades
    for(int i=0; i<3; i++) {
        string testHeader = "test" + to_string(i+1);
        out << setw(10) << right << testHeader;
    }
    out << setw(15) << right << "Avgerage" << endl;
    out << setw(90) << setfill('=') << " " << endl;

    // write records
    out << setfill(' ') << fixed << setprecision(1);
    for(StudentGrade s: gradebook) {
        out << setw(colWidth) << left << s.firstName
            << setw(colWidth) << left << s.lastName;
        for(int i=0; i<3; i++)
            out << setw(10) << right << s.grades[i];
        out << setw(15) << right << s.averageGrade << endl;
    }
    out << setw(90) << setfill('*') << " " << endl;
}
```


```C++17
// write to standard output/console
writeResults(cout);
```

    ========================================================================================= 
    First Name          Last Name                test1     test2     test3       Avgerage
    ========================================================================================= 
    John                Smith                      100        95        85           93.3
    Jane                Doe                         85        89        99           91.0
    Jill                Jones                       56        89        99           81.3
    ***************************************************************************************** 



```C++17
// write to file output
writeResults(fout);
// check the contents of file
```


```C++17
// close the file
fout.close();
```

## Exercises

1. Write a program that computes distance between two points in Cartesian coordinates.
    - use struct to represent Point
    - prompt user to enter two points
    - use as many function(s) as possible
    - write at least 3 test cases for each computing functions
    - program continues to run until user wants to quit
    - most of the part is done in Jupyter Notebook demo
    
    
2. Write a program to compute area and circumference of a circle using struct.
    - use struct to represent Circle
    - prompt user to enter radius of a circle
    - use as many function(s) as possible
    - write at least 3 test cases for each computing functions
    - program continues to run until user wants to quit
    

3. Write a program to compute area and perimeter of a rectangle using struct.
    - use struct to represent Rectangle
    - prompt user to enter length and width of a rectangle
    - use as many function(s) as possible
    - write at least 3 test cases for each computing functions
    - program continues to run until user wants to quit
    
    
4. Write a program to compute area and perimeter of a triangle given 3 sides.
    - use struct to represent Triangle
    - prompt user to enter 3 sides of a triangle
    - use as many function(s) as possible
    - write at least 3 test cases for each computing functions
    - program continues to run until user wants to quit


```C++17
// Sample solution for #4
// using incremental development
// using functions as possible to break the problem
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>

using namespace std;
```


```C++17
// use struct to represent Triangle
// could be a templated struct
struct Triangle {
    float side1, side2, side3;
    // can be an array
    // float sides[3];
};
```


```C++17
// function to check if 3 sides form a triangle
bool validTriangle(float s1, float s2, float s3) {
    // sum of every pair must be greater than the third
    return (s1+s2 > s3 && (s2+s3 > s1) && (s1+s3 > s2))? true: false;
}
```


```C++17
void test_validTriangle() {
    assert(validTriangle(2, 3, 4) == true);
    assert(validTriangle(1, 2, 3) == false);
    assert(validTriangle(4, 5, 10) == false);
    cerr << "all test cases passed for validTriangle()\n";
}
```


```C++17
test_validTriangle()
```

    all test cases passed for validTriangle()



```C++17
// function prompts user to enter 3 sides of a triangle
// creates and returns a triangle
Triangle getTriangle() {
    float s1, s2, s3;
    // input validation
    do {
        cout << "Enter three sides of a triangle separated by space: ";
        cin >> s1 >> s2 >> s3;
        // check if three sides form a triangle
        if (!validTriangle(s1, s2, s3))
            cout << "3 sides do not form a traingle.\n"
                << "Sum of any 2 sides must be greater than the third!\n";
        else
            break;
    } while(true);
    return Triangle({s1, s2, s3});
}
```


```C++17
// let's manually test getTriangle
Triangle t1;
```


```C++17
t1 = getTriangle();
```

    Enter three sides of a triangle separated by space: 
    1 2 3
    3 sides do not form a traingle.
    Sum of any 2 sides must be greater than the third!
    Enter three sides of a triangle separated by space: 3 4 5



```C++17
float trianglePerimeter(const Triangle & t) {
    return t.side1 + t.side2 + t.side3;
}
```


```C++17
// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    assert(trianglePerimeter(Triangle({2, 3, 4})) == 9);
    assert(trianglePerimeter(Triangle({3, 4, 5})) == 12);
    assert(trianglePerimeter(Triangle({2.5, 3.5, 4.5})) == 10.5);
    cerr << "all test cases passed for trianglePerimeter()\n";
}
```


```C++17
test_trianglePerimeter();
```

    all test cases passed for trianglePerimeter()



```C++17
// function to compute area of a triangle
float triangleArea(const Triangle & t) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(t)/2;
    return sqrt(s*(s-t.side1)*(s-t.side2)*(s-t.side3));
}
```


```C++17
// wrapper function to test if two floating numbers are equal upto precision decimal points
void assertAlmostEqual(float value1, float value2, int precision) {
    ostringstream oss;
    // create output string stream with precision for floating-point values
    oss << fixed << setprecision(precision) << value1 << " " << value2;
    // create input string stream from output string stream
    istringstream iss(oss.str());
    float v1, v2;
    // extract the values as float
    iss >> v1 >> v2;
    assert(v1 == v2);
}
```


```C++17
// write 3 test cases for triangleArea
void test_triangleArea() {
    assert(triangleArea(Triangle({3, 4, 5})) == 6.0);
    float area = triangleArea({2, 4, 5}); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    assertAlmostEqual(triangleArea({3, 4, 6}), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}
```


```C++17
test_triangleArea();
```

    all test cases passed for triangleArea()



```C++17
// function to calculate and print the result on triangle
void printResult(const Triangle & t) {
    cout << "Triangle info: \n"
         << "3 sides length: " << t.side1 << " " << t.side2 << " " << t.side3
         << "\narea: " << triangleArea(t) 
         << "\nperimeter: " << trianglePerimeter(t);
}
```


```C++17
// complete program
void program() {
    Triangle t;
    string cont;
    do {
        t = getTriangle();
        printResult(t);
        cout << "\nWant to enter another triangle? [yes|y]: ";
        cin >> cont;
        if (cont == "yes" || cont == "y") continue;
        else break;
    }while(true);
    cout << "Good bye...";
}
```


```C++17
program();
```

    Enter three sides of a triangle separated by space: 1 2 3
    3 sides do not form a traingle.
    Sum of any 2 sides must be greater than the third!
    Enter three sides of a triangle separated by space: 4 5 6
    Triangle info: 
    3 sides length: 4 5 6
    area: 9.92157
    perimeter: 15
    Want to enter another triangle? [yes|y]: yes
    Enter three sides of a triangle separated by space: 4 5 6
    Triangle info: 
    3 sides length: 4 5 6
    area: 9.92157
    perimeter: 15
    Want to enter another triangle? [yes|y]: no
    Good bye...

#### see complete sample solution for exercise 4 in [demos/structs/triangle/triangle.cpp](demos/structs/triangle/triangle.cpp)


5. A Grade Book:
    - Write a C++ menu-driven program that let's professors keep track of students grades with the following requirements:
    - program must use struct to keep track of students grades
    - program prompts user to enter name of the input text file that contains students information in the following format
        - first name, last name, test1, test2, test3, test4, test5
    - program calculates avearge grade and the letter grade (A-F) based on the average grade
    - program sorts the student records based on grade in non-increasing order (highest to lowest)
    - program lets user add a new student
    - program lets user update existing student's information
    - program lets user delete existing student
    - program saves the data back into the same input file as a database
    - program creates a cleanly formatted report of students' grades

## Kattis problems
- struct is not a strict requirement to solve Kattis problems
- struct is generally used when the problems can be better solved using your own type

- some problems that can be easily solved using struct are listed below:
- Cards Sorting - https://open.kattis.com/problems/spilarodun
    - Hint: use struct to represent each card; sort using built-in sort method using the sorting order provided
    - since multiple sorting criteria are involved, sort the vector of struct in reverse order of criteria

## Summary
- this chapter covered a new concept of creating user-defined type using struct
- saw many examples of struct types and objects instantiated with those types
- learned that array can be a member of struct
- learned that a larger number of records (struct type) can be stored in an array
- learned about out-of-the-box aggregate operations on struct objects
    - assignment (=) is the only one that works out-of-the-box
- learned how to pass struct objects to functions and return from them as well
- exercises and a sample solutions using incremental development technique


```C++17

```
