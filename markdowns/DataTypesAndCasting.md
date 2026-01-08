# Data and Type Casting

## Topics
- converting one type into another
- bulit-in type casting functions
- converting strings to numbers
- converting numbers to strings
- converting char to numbers and numbers to chars

## External Resources

- YouTube Video - C++ Data Type Casting: [https://youtu.be/xqCg64Fvja0](https://youtu.be/xqCg64Fvja0)
- YouTube Podcast - C++ Data Type Casting: [https://youtu.be/mybgevwCDYk](https://youtu.be/mybgevwCDYk)
- NotebookLM learning materials: [https://notebooklm.google.com/notebook/bc8211a9-e35a-4745-923e-edc2bc9f0815](https://notebooklm.google.com/notebook/bc8211a9-e35a-4745-923e-edc2bc9f0815)

## Type casting
- data values need to be converted from one type to another to get correct results
- explictly converting one type into another is called **type casting**
- implicit conversion is called **coercion**
- of course, not all values can be converted from one type to another!

### Converting numeric types int C++ string type
- use `to_string(value)` function to convert `value` to C++ `string`
- must include `<string>` header and **std** namespace


```c++
#include <string>
using namespace std;
```


```c++
// converting literal 99 to C++ string
string str_val = to_string(99); // 99 is casted "99" and the value is assigned to str_val
```


```c++
str_val
```




    "99"




```c++
// converting integer variable into C++ string
int whole_num = 1234;
string str_val1 = to_string(whole_num);
```


```c++
str_val1
```




    "1234"




```c++
float float_num = 129.99f;
string str_num1 = to_string(float_num);
```


```c++
str_num1
```




    "129.990005"




```c++
string str_val2 = to_string('A'); // uses ASCII value
```


```c++
str_val2
```




    "65"



### Converting string values to numeric types
- certain values can be converted into numeric types such as int, float, double, etc.
- `<cstdlib>` provides some functions for us to convert c-string to numeric data
- more on `<cstdlib>`: http://www.cplusplus.com/reference/cstdlib
- `atoi("value")` converts string `value` to integer
    - converts all leading consecutive digits as integer
- `atof("value")` converts string `value` to double
- must include `<cstdlib>` library to use its functions
    - converts all leading consecutive digits and period as floating point number


```c++
#include <cstdlib> //atoi and atof
```


```c++
// converting c-string literal to integers
atoi("120")
```




    120




```c++
// extracting integer out from c-string literal
atoi("43543 alphabets")
```




    43543




```c++
// can't extract from suffix
atoi("text 123")
```




    0




```c++
// converting c-string literal to float
atof("23.55")
```




    23.550000




```c++
// extracting float from c-string literal
atof("132.68 text")
```




    132.68000




```c++
// can't extract from suffix
atof("text 4546.454")
```




    0.0000000



### Converting C++ strings into numeric types

- Reference on C++ string type: http://www.cplusplus.com/reference/string/

- **&lt;string&gt;** library provides many functions to convert std::string into numeric types
- **stoi( )** - converts std:string type to integer
- **stof( )** - converts std::string type to float
- **stol( )** - converts std::string type to long int
- **stoul( )** - converts std::string to unsigned long integer


```c++
#include <string>
using namespace std;
```


```c++
string int_num = "99";
string float_num = "100.99";
```


```c++
// typecast string int and string float to corresponding numeric types
// do + operation on numeric types
float result = stoi(int_num) + stof(float_num);
```


```c++
result
```




    199.990f



### Type casting among numeric types
- at times, you may need to convert integers to floating points and vice versa
- use **int(value)** to convert float to int
- use **float(value)** to convert int or double to float
- use **double(value)** to convert int or float to double
- don't need to include any library to use these built-in functions


```c++
int(10.99) // convert double to int; discard decimal points or round down
```




    10




```c++
int(345.567f) // discard decimal points or round down
```




    345




```c++
float(19)
```




    19.0000f




```c++
double(3.33f) // convert float to double
```




    3.3299999




```c++
double(3)
```




    3.0000000



### Type casting between char and int
- use `char(intValue)` to convert ASCII `int` to `char`
- use `int(charValue)` to convert `char` to ASCII `int`


```c++
char(65) // ASCII code to char
```




    'A'




```c++
int('A') // char to ASCII code
```




    65



## Composition
- similar to composing an essay or music
    - start with basic elements and combine them to build something bigger and meaningful work
- we use the same basic principle of **composition** in programming
    - take small building blocks
        - variables, values, expressions (operators), statements (input, output), etc.
    - compose something meaningful or solve a problem
    
### example 1: find area and perimeter of a rectangle
- algorithm steps:
    1. get values for length and width of a rectangle
    2. calculate area and perimeter using the following equations
        - area = length x width
        - perimeter = 2 x (length + width)
    3. display the results


```c++
#include <iostream>
using namespace std;
```


```c++
// ex.1 program
// variables to store length and width
float rect_length, rect_width;
```


```c++
// step 1 get length and width values 
// a. can be hardcoded literal values
rect_length = 10.5; //hardcoded
rect_width = 5.5;
```


```c++
// step 1.b or can be read from std input
cout << "Enter length and width of a rectangle separated by space: ";
cin >> rect_length >> rect_width;
```

    Enter length and width of a rectangle separated by space: 


```c++
cout << "Rectangle's length = " << rect_length << " and width = " << rect_width;
```

    Rectangle's length = 10 and width = 5


```c++
// step 2 and 3: calculate and display the area and perimeter
cout << "area of the rectangle: " << rect_length * rect_width << endl;
cout << "perimeter of the rectangle: " << 2*(rect_length+rect_width) << endl;
```

    area of the rectangle: 50
    perimeter of the rectangle: 30


### demo programs
- see the complete program here [demos/stdio/rectangle/main.cpp](demos/stdio/rectangle/main.cpp)

### example 2: convert decimal number to binary
- let's convert $(13)_{10}$ to binary $(?)_2$?
    - from manual calculation in Chapter 02, we know: $(13)_{10}$ -> $(1101)_2$
- let's use algorithm defined in Chapter 02:
    1. repeteadly divide the decimal number by base 2 until the quotient becomes 0
    2. collect the remainders in reverse order
        - the first remainder becomes the last bit (least significant) in binary
- let's try to convert the above algorithm into C++ code


```c++
#include <iostream> // cin, cout
#include <string> // basic_string, to_string

using namespace std; // std::cin, std::cout, std::endl, etc.
```


```c++
// decimal to binary conversion requires to calculate both quotient and remainder
const int divisor = 2; // divisor is contant name whose value can't be changed once initialized
int dividend;
int quotient, remain;
string answer; // collect remainders by prepending as a string
```


```c++
answer = ""; // variable to collect the binary answer
quotient = 13; //start with the decimal 13
```




    13




```c++
// copy the quotient into dividend to divide it
dividend = quotient;
remain = dividend%divisor; // find the remainder
quotient = dividend/divisor; // find the quotient
// print intermediate results; help us see and plan further computation
cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
answer = to_string(remain) + answer; // prepend remainder to answer
// is quotient 0?
```

    13/2 => quotient: 6 remainder: 1





    "1"




```c++
// further divide quotient
dividend = quotient;
remain = dividend%divisor;
quotient = dividend/divisor;
// print intermediate results; help us see and plan further computation
cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
answer = to_string(remain) + answer; // prepend remainder to answer
// is quotient 0?
```

    6/2 => quotient: 3 remainder: 0





    "01"




```c++
// further divide quotient
dividend = quotient;
remain = dividend%divisor;
quotient = dividend/divisor;
// print intermediate results; help us see and plan further computation
cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
answer = to_string(remain) + answer; // prepend remainder to answer
// is quotient 0?
```

    3/2 => quotient: 1 remainder: 1





    "101"




```c++
// further divide quotient
dividend = quotient;
remain = dividend%divisor;
quotient = dividend/divisor;
// print intermediate results; help us see and plan further computation
cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
answer = to_string(remain) + answer; // prepend remainder to answer
// is quotient 0?
```

    1/2 => quotient: 0 remainder: 1





    "1101"




```c++
// stop division; display the answer
cout << "13  decimal = " << answer << " binary " << endl;
```

    13  decimal = 1101 binary 


### Above code as a complete C++ program

- see [demos/stdio/decToBin/main.cpp](demos/stdio/decToBin/main.cpp)

### A generic C++ program to convert any decimal to binary

- basic building blocks covered so far is able to find the solution using Jupyter notebook
    - however, we've not learned enough to write a generic program that can convert any integer into binary, just yet!
- we'll revisit this problem as we learn more concepts, such as conditional statements and loops

## Summary
- data must be converted into right types for correct operations
- C++ provides various library functions to convert one type into another appropriate type
- not every type of data can be converted into another type of data
- composition helps solve bigger problems by breaking them into smaller ones and putting them together
