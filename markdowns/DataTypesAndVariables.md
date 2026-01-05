# Data, Types and Variables

## Topics
- data and values
- C++ fundamental data types
- digital units and number systems
- variables and data assignment
- keywords and operators
- order of operations
- operators for numbers and strings
- constants
- type casting

## Data and values
- data and values are the fundamentals to any computer language and program
- a value is one of the fundamental things -- like a letter or a number -- that a program manipulates
- almost all computer programs use and manipulate some data values

## Literal values and representations
- at a high level, we deal with two types of data values: Numbers and Texts
- most programming languages need to represent and use these data correctly
- numbers can be further divided into two types:
    - Whole number literal values: 109, -234, etc.
    - Floating point literal values: 123.456, -0.3555, etc.
- text is a collection of 1 or more characters (symbols, digits or alpahabets)
    - single character is represented using a pair of single quotes ( ' ' )
        - char literal values: 'A', 'a', '%', '1', etc.
    - 2 or more characters are called string
        - represented using a pair of double quotes ( " " )
        - string literal values: "CO", "John Doe", "1100", "9.99", etc.
    
    
## C++ Fundamental Types
- there are many fundamental types based on the size of the data program needs to store
    - most fundamental types are numeric types
- see here for all the supported types: https://en.cppreference.com/w/cpp/language/types
- the most common types we use are:

| Type | Description | Storage size | Value range |
| :---| :--- | :---|---|
| **void**   | an empty set of values; no type | system dependent: 4 or 8 bytes | NA |
|**bool** | true or false | 1 byte or 8 bits | true or false <br /> 1 or 0 |
| **char** | one ASCII character | 1 byte or 8 bits | $-2^7$ to $2^7-1$ |
| **unsigned char** | one ASCII character | 1 byte or 8 bits | 0 to $2^8-1$ |
| **int** | +/-ve integers  | 4 bytes | $-2^{31}$ to $2^{31}-1$|
| **unsigned int** | only positive integers | 4 bytes or 32 bits | 0 to $2^{32}-1$ |
| **long** | +ve and -ve big integers | 8 bytes or 64 bits| $-2^{63}$ to $2^{63}-1$|
| **unsigned long** | positive big integers | 8 bytes or 64 bits | 0 to $2^{64}-1$ |
| **float** | single precision floating points | 32 bits | 7 decimal points |
| **double** | double precision floating points | 64 bits |  15 decimal points |


- in C++, there's no fundadamental type available to work with string data
- two common ways to store string data:
    - use C-string or array of characters
    - use basic_string defined in `<string>` library
        - more on basic_string: https://en.cppreference.com/w/cpp/string/basic_string
        - must include `<string>` library and **std** namespace
- we'll dive into string more in depth in **Strings** chapter
   
### sizeof operator
- one may want to know the size of memory allocated for the fundamental types
    - some of these types are system dependent (e.g., long is 32 bit in x86 and 64 bit in x64)
- **sizeof(type)** operator gives size of fundamental types in bytes
- let's check the size of some fundamental types on my 64-bit MacBook Pro laptop


```c++
sizeof(bool)
```




    1




```c++
sizeof(char)
```




    1




```c++
sizeof(int)
```




    4




```c++
sizeof(long)
```




    8




```c++
sizeof(float)
```




    4




```c++
sizeof(double)
```




    8



## Units of digital data
- digital computers use binary number system consisting of two digits (0 and 1)
- every data and code is represented using binary values
    - hence the name binary or byte code for executable programs
    - letter A is encoded as 1000001 (7 binary digits)
- humans use decimal number system with 10 digits (0 to 9)
    - we have ways to represent texts using alphabets for English language e.g.: Hello Bond 707!
    - texts must be encoded into numbers, if we lived in the world that only understood numbers
- the following table shows the various units of digital data

| Unit | Equivalent |
|---|---|
| 1 bit (b) | 0 or 1 |
| 1 byte (B) | 8 bits (b) |
| 1 kilobyte (KB)  | 1,024 B |
| 1 megabyte (MB) | 1,024 KB |
| 1 gigabtye (GB) | 1,024 MB |
| 1 terabyte (TB) | 1,024 GB |
| 1 petabyte (PB) | 1,024 TB |
| ... | ... |

## Number systems
- there are several number systems based on the base digits
    - base is number of unique digits number system uses to represent numbers
- binary (base 2), octal (base 8), decimal (base 10), hexadecimal (base 16), etc.

### Decimal number system
- also called Hindu-Arabic number system
- most commonly used number system that uses base 10
    - has 10 digits or numerals to represent numbers: 0..9
    - e.g., 1, 79, 1024, 12345, etc.
- numerals representing numbers have different place values depending on position:
    - ones ($10^0$), tens($10^1$), hundreds($10^2$), thousands($10^3$), ten thousands($10^4$), etc.
    - e.g., 543.21 = $(5\times10^2)+(4\times10^1)+(3\times10^0)+(2\times10^{-1})+(1\times10^{-2})$
    
## Number system conversion
- since computers understand only binary, everything (data, code) must be converted into binary
- all characaters (alphabets and symbols) are given decimal codes for electronic communication
    - these codes are called ASCII (American Standard Code for Information Interchange)
    - $A \rightarrow 65; Z \rightarrow 90; a \rightarrow 97; z \rightarrow 122, * \rightarrow 42$, etc.
    - see ASCII chart: https://en.cppreference.com/w/c/language/ascii

### Converting decmial to binary number

- algorithm steps:
    1. repeteadly divide the decimal number by base $2$ until the quotient becomes $0$
        - note remainder for each division
    2. collect all the remainders in reverse order
        - the first remainder is the last (least significant) digit in binary
    
- example 1: what is decimal $(10)_{10}$ in binary $(?)_2$ ?
    - step 1:
    
        $\frac{10}{2}$ = quotient: $5$, remainder: $0$ <br /><br />
        $\frac{5}{2}$  = quotient: $2$, remainder: $1$ <br /><br />
        $\frac{2}{2}$  = quotient: $1$, remainder: $0$ <br /><br />
        $\frac{1}{2}$  = quotient: $0$, remainder: $1$ <br /><br />
     
    - step 2: 
         - collect remainders from bottom up: $1010$
    - so, $(10)_{10}$ = $(1010)_2$
     
     
- example 2: what is decimal $(13)_{10}$ in $(?)_2$ ?
    - step 1:
    
        $\frac{13}{2}$ = quotient: $6$, remainder: $1$ <br /><br />
        $\frac{6}{2}$  = quotient $3$, remainder: $0$ <br /><br />
        $\frac{3}{2}$  = quotient: $1$, remainder: $1$ <br /><br />
        $\frac{1}{2}$  = quotient: $0$, remainder: $1$ <br /><br />
        
    - step 2:
         - collect remainders from bottom up: $1101$
    - so, $(13)_{10}$ = $(1101)_2$
     
### Converting binary to decimal number
- once the computer does the computation in binary, it needs to convert the results back to decimal number system for humans to understand
- algorithm steps:
    1. multiply each binary digit by its place value in binary
    2. sum all the products

- example 1: what is binary $(1010)_2$ in decimal $(?)_{10}?$
    - step 1:
    
        - $0\times2^0 = 0$
        - $1\times2^1 = 2$
        - $0\times2^2 = 0$
        - $1\times2^3 = 8$
    - step 2:
        - $0 + 2 + 0 + 8 = 10$
    - so, $(1010)_2$ = $(10)_{10}$
    
    
- example 2: what is binary $(1101)_2$ in decimal $(?)_{10}?$
    - step 1:
    
        - $1\times2^0 = 1$
        - $0\times2^1 = 0$
        - $1\times2^2 = 4$
        - $1\times2^3 = 8$

    - step 2:
        - $1+0+4+8 = 13$
    - so, $(1101)_2$ = $(13)_{10}$
- we got the same decimal vales we started from in previous examples
- food for thought: think how you'd go about writing a program to convert any positive decimal number into binary and vice versa!

## Negative (signed) integers - Two's complement
- most common method of storing negative numbers on computers is a mathematical operation called Two's complement
- Two's complement of an N-bit number is defined as its complement with respect to $2^N$
    - the sum of a number and its two's complement is $2^N$
- e.g.: for the 3-bit binary number $010_2$, the two's complement is $110_2$
    - because $010_2 + 110_2 = 1000_2 = 2^3_{10}$
- Two's complement of N-bit number can be found by flipping each bit and adding one to it
- e.g. find two's complement of $010$
    - Algorithm steps:
        1. flipped each bit; $0$ is flipped to $1$ and $1$ is flipped to $0$

        $010 \rightarrow  101$

        2. add 1 to the flipped binary 

        ```bash
            101
             +1
           -----
            110
        ```

### Example: What is -3 decimal in 8-bit binary representation?
- convert $3_{10}$ to an 8-bit binary
    - $3_{10} \rightarrow 00000011_{2}$
    
1. find Two's complement of 8-bit binary
    - $00000011_{2} \rightarrow 11111100_{2} + 1 = 11111101_{2}$

2. Sanity check:
    - $00000011_{2} + 11111101_{2} = 100000000_{2} = 2^8_{10}$

- So, $-3_{10} = 11111101_{2}$ in an 8-bit representation

## Exercise
1. Convert decimal integer 7 into binary with 16 bits.

2. Convert -7 decimal integer into binary with 16 bits.

## Variables
- programs must load data values into memory to manipulate them
- data may be large and used many times during the program
    - typing the data values literally all the time is not efficient and fun
    - most importantly error prone due to typos
    - you may not even know what values may be if they're read from standard input, files, etc.
- variables are named memory location where data can be stored for easy access and manipulation
- one can declare and use as many variables as necessary
- C++ is a static and strongly typed programming language
    - variables are tied to their specific data types that must be explictly declared when declaring variables

### Variable declaration
- statements that create variables/identifiers to store some data values
- as the name says, value of variables can vary/change over time
- syntax:
```c
type varName;
type varNam1, varName2, ...; //declare several variables all of the same type
```

![](resources/VariablesAndMemory.png)

### Rules for creating variables
- variable names are case sensitive
- must declare variables before they can be used
- can't define variable with the same name more than once
- can't use keywords as variable names
- data stored must match the type of variable
- variable names can't contain symbols (white spaces, #, &, etc.) except for _ and \$ (underscore and dollar)
- variable names can contain digits but can't start with a digit
- variable names can start with only alphabets (lower or upper) and _ symbol

### Best practices
- use descriptive and meaningful but concise name
    - one should know quickly what data you're storing
- use lowercase; camelCase or ( _ underscore ) to combine multiple words

### C++ keywords
- keywords are reserved names and words that have specific purpose in C++
    - they can only be used what they're intended for
- e.g., char, int, unsigned, signed, float, double, bool, if, for, while, return, struct, class, operator, try, etc.
- all C++ keywords are listed here: https://en.cppreference.com/w/cpp/keyword


```c++
// examples of variable declaration
bool done;
char middleInitial;
char middleinitial; // hard to read all lowercase name
int temperature;
unsigned int age;
long richest_persons_networth;
float interestRate;
float length;
float width;
double space_shuttle_velocity;
```


```c++
// TODO:
// Declare 10 variables of atleast 5 different types
```

### String variables
- declare variables that store string data
    - 1 or more string of characters
- an easy way to use string is by using C++ advanced type defined in `<string>` header file
- must include `<string>` header file or library to use string type
- must also use **std** namespace
- strings are represented using a pair of double quotes ("string")
- more on string type is covered in **Strings** chapter
- the following are some examples of string variables


```c++
// string variables
#include <string>

using namespace std;

string fullName;
string firstName;
string address1;
string country;
string state_name;
std::string state_code; // :: name resolution operator
```


```c++
// TODO:
// Declare 5 string variables
```

## Assignment operator ( = )

- once variables are declared, data can be stored using assignment operator, $ = $
- **assignment statements** have the following syntax:

```cpp
varName = value;
```
- since C++ is a strongly typed language, the type of value must match the type of variable
    - strongly typed languages enforces type safety and matching during the compile time


```c++
// assignment examples
done = false;
middleInitial = 'J'; // character is represent using single quote
middleinitial = 'Q';
temperature = 73;
age = 45;
richest_persons_networth = 120000000000; // 120 billion
interestRate = 4.5;
length = 10.5;
width = 99.99f; // number can end with f to represent as float
space_shuttle_velocity = 950.1234567891234567; // 16 decimal points
```




    950.12346




```c++
// string assignment examples
fullName = "John Doe";
firstName = "John";
address1 = "1100 North Avenue"; // number as string
country = "USA";
state_name = "Colorado";
state_code = "CO";
```


```c++
// TODO: assign different values to variables defined above
```

### Variable declartion and initialization
- variables can be declared with an initial value at the time of construction
- if you know what value a variable should start with, this saves you typing
- often times it's the best practice to initialize variable with default value
- several ways to initialize variables: https://en.cppreference.com/w/cpp/language/initialization
- two common ways:
    1. Copy initialization (using `=` operator)
    2. Value initialization (using `{ }` curley braces)
        - also called uniform initialization
        - useful in initializing advanced types such as arrays, objects, etc.


```c++
// Copy initialization
float price = 2.99f;
char MI = 'B'; //middle initial
string school_name = "Grand Junction High";
```


```c++
// Value/uniform initialization
char some_letter{'U'};
int some_length{100};
float some_float{200.99};
string some_string = {"Hello World!"}; // can also combine the two!
```

### Variable's value can be changed
- variable's value can vary through out the program
    - hence the name variable
- however, type of the value must be same as the type of the variable at the time of declaration
- C++ is a strongly and static typed programming language!


```c++
price = 3.99;
price = 1.99;
MI = 'Q';
school_name = "Fruita Monument High";
some_string = "Goodbye, World!";
```


```c++
price = "4.99"; // is this valid?
```

    [1minput_line_34:2:10: [0m[0;1;31merror: [0m[1massigning to 'float' from incompatible type 'const char [5]'[0m
     price = "4.99"; // is this valid?
    [0;1;32m         ^~~~~~
    [0m


    Interpreter Error: 


### auto type
- if variable is declared and initialized in one statement, you can use **auto** keyword to let compiler determine type of variable based on the value it's initialized with


```c++
auto var1 = 10; // integer
auto var2 = 19.99f; // float
auto var3 = 99.245; // double
auto var4 = '@'; // char
```


```c++
// char * (pointer) type and not string type
auto full_name = "John Doe";
```


```c++
// can automatically declare string type
#include <string>
using namespace std;

auto full_name1 = string("Jake Smith"); // string type!
```


```c++
// use typeid function to find the name of the types
// typeid is defined in typeinfo library
#include <typeinfo>
```


```c++
typeid(full_name1).name()
```




    "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE"




```c++
// should print "i" -> short for integer
// Note: may also print invalid memory address in Jupyter notebook!
typeid(var1).name()
```




    0x7fff67b6373c <invalid memory address>



### Visualize variables and memory with [pythontutor.com](http://pythontutor.com/cpp.html#code=%23include%20%3Cstring%3E%0Ausing%20namespace%20std%3B%0A%0Aconst%20double%20PI%20%3D%203.141592653589793238%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20char%20MI%3B%0A%20%20int%20temperature%3B%0A%20%20float%20width%3B%0A%20%20double%20space_shuttle_velocity%3B%0A%20%20string%20fullName%3B%0A%20%20MI%20%3D%20'A'%3B%0A%20%20temperature%20%3D%20-10%3B%0A%20%20float%20length%20%3D%2015.5%3B%0A%20%20double%20distance%7B199.999%7D%3B%0A%20%20space_shuttle_velocity%20%3D%209.9%3B%0A%20%20MI%20%3D%20'Z'%3B%0A%20%20length%20%3D%2099.99f%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## Constants
- constants are named values that remain unchanged through out the program
- useful for declaring values that are fixed
    - e.g. value of $\pi$, earth's gravity, unit conversions, etc.
- two ways to define constants in C++
    1. use **const** keyword infront of an identifier
        - syntax:
        ```cpp
        const type identifier = value;
        ```
    2. use **#define** preprocessor directive
        - syntax:
        ```cpp
        #define identifier value
        ```
        - after an identifier has been defined with a value, preprocessor replaces each occurances of PI with value


```c++
const double pi = 22/7.0; // evaluate 22/7.0 and use it as the const value for pi
const float earth_gravity = 9.8; // m/s^2 unit
```


```c++
// try to assign different value to the constant pi
pi = 3.141592653589793238;
```

    [1minput_line_13:3:4: [0m[0;1;31merror: [0m[1mcannot assign to variable 'pi' with const-qualified type 'const double'[0m
    pi = 3.141592653589793238;
    [0;1;32m~~ ^
    [0m[1minput_line_8:2:15: [0m[0;1;30mnote: [0mvariable 'pi' declared const here[0m
     const double pi = 22/7.0; // evaluate 22/7.0 and use it as the const value for pi
    [0;1;32m ~~~~~~~~~~~~~^~~~~~~~~~~
    [0m


    Interpreter Error: 


### Escape sequences
- some letters or sequence of letters have special meaning to C++
    - e.g., pair of single quote is used to represent a character data, e.g. 'A' or ' ' (space)
    - and pair of double quotes is used to represent a string type, e.g., "Hello World!"
- how can we store single or double quotes as part of data?
    - e.g., we need to print: **"Oh no!", Alice exclaimed, "Bob's bike is broken!"**
    - we use backslash `\` (escape character) to escape the special meaning of single and double quotes or other characters
- characters represented using escape character are called escape sequences
    - \\n - new line
    - \\\\ - back slash
    - \\t - tab
    - \\r - carriage return
    - \\' - single quote
    - \\" - double quote


```c++
// string variables
#include <iostream>
#include <string>

using namespace std;
```


```c++
string greeting = "What's up\n Shaq\tO'Neal?"
```


```c++
greeting
```




    "What's up
     Shaq	O'Neal?"




```c++
char single_quote = '\''
```


```c++
single_quote
```




    '''




```c++
char double_quote = '"'
```


```c++
double_quote
```




    '"'




```c++
// need to scape the " inside strings
string line = "\"Oh no!\", Alice exclaimed, \"Bob's bike is broken!\""
```


```c++
line
```




    ""Oh no!", Alice exclaimed, "Bob's bike is broken!""




```c++
cout << "how many back slashes will be printed? \\\\";
```

    how many back slashes will be printed? \\

## Labs

1. Variables Lab 
    - write a C++ program that produces the following output on console
    - use the partial solution provided in [labs/variables/main.cpp](labs/variables/main.cpp)
    - observe and note how the special symbols such as single quote, double quotes and black slashes
    - run the program as it is using the provided make file in the stdio folder
    - complete the rest of the ASCII Art by fixing all the FIXMEs
    - write #FIXED next to each FIXME
    
    ```
        |\_/|       *******************************     (\_/)
       / @ @ \      *      ASCII Art              *    (='.'=)
      ( > 0 < )     *      Author: <Your Name>    *  ( " )_( " )
        >>x<<       *      CS Foundation Course   *
        / O \       *******************************
   ```

## Exercises
1. Declare some variables required to store information about a student for a university banner system. Assign some values to those variables.
    - see sample answer here [exercises/variables/exercise1](exercises/variables/exercise1)

2. Declare some variables required to store information about an employee at a university. Assign some values to those variables.

3. Declare some variables required to store information about a mechandise for an inventory management system of a store. Assign some values to those variables.

4. Declare some variables required to store infomration about a rectangular shape. Calculate area and perimeter of a rectangle. Assign some values to those variables.

5. Declare variables required to store information about a circle to calculate its area and perimeter. Assign some values to those variables. Calculate area and perimeter.

6. Declare some variables required to store information about a hotel room for booking management system.

7. Declare some variables required to store length of sides of a triangle. Calculate area using Herons' formula.
    - Search for Heron's formula, if you're not sure what it is.

8. Using pencil and paper or Jupyter Notebook, write your full name in binary. 
 - e.g., Ram Basnet in Binary is: 
 - 01010010 01100001 01101101 00100000 01000010 01100001 01110011 01101110 01100101 01110100 

## Summary
- this notebook discussed data and C++ fundamental data types
- variables are named memory location that store data values
- C++ variables are static and strongly typed
- learned that constants are used to store values that should not be changed in program
- looked into exercises and sample solutions on data types and variables


```c++

```
