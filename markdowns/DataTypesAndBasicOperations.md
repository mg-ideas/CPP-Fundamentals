# Data Types and Basic Operations

## Topics
- Keywords and Operations
- Operators for numbers and strings
- Order of Precedence

## External Resources

- C++ Operators: [https://cplusplus.com/doc/tutorial/operators/](https://cplusplus.com/doc/tutorial/operators/)
- Operators and precedence rule: [https://en.cppreference.com/w/cpp/language/operator_precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)
- Arithmetic operators: [https://en.cppreference.com/w/cpp/language/operator_arithmetic](https://en.cppreference.com/w/cpp/language/operator_arithmetic)
- YouTube Video - C++ Basic Operators and Precedence: [https://youtu.be/II8_4Se9Pk0](https://youtu.be/II8_4Se9Pk0)
- YouTube Podcast - C++ Basic Operators and Precedence: [https://youtu.be/vl4WC47TiKM](https://youtu.be/vl4WC47TiKM)
- NotebookLM learning materials: [https://notebooklm.google.com/notebook/d8c4d430-f71f-4461-8c1e-b3ee7c714466](https://notebooklm.google.com/notebook/d8c4d430-f71f-4461-8c1e-b3ee7c714466)

## Operators
- special symbols used to represent simple computations
    - like addition, multiplication, modulo, etc.
- C++ has operators for numbers, characters, and strings
- operators and precedence rule: https://en.cppreference.com/w/cpp/language/operator_precedence
- arithmetic operators: https://en.cppreference.com/w/cpp/language/operator_arithmetic

### Unary operators
- takes one operand
- operands are values that operators work on
- there are two unary operators for numeric operands

| Operator | Symbol | Syntax | Operation |
|--- | --- | --- | --- |
| positive | + | +100 | positive 100 (default) |
| negative | - | -23.45 | negative 23.45 |


### Binary operators
- binary operators take two operands (left operator right)
- the following table shows the binary operators for numeric operands

| Operator | Symbol | Name | Syntax | Operation |
|--- | --- | --- | --- | --|
| add | + | plus |x + y | add the value of y with the value of x
| subtract | - | hyphen | x - y | subtract y from x |
| multiply | \* | asterick | x \* y | product of x and y |
| divide | / | slash | x / y | divide x by y (int division if x and y are both ints) |
| modulo | % | percent | x % y | remainder when x is divided by y |

### Adding numbers
- `+` symbol is used to add literal values or variables


```C++17
// adding literal integer values
+1 + (-1)
```




    0




```C++17
// adding literal floating points
99.9 + 0.1
```




    100.00000




```C++17
// adding int variables
int num1, num2, sum;
```


```C++17
num1 = 10;
num2 = 5;
sum = num1 + num2;
```


```C++17
sum
```




    15




```C++17
// adding float variables
float n1 = 3.5;
float n2 = 2.5;
float total = n1+n2;
```


```C++17
total
```




    6.00000f



### Subtracting numbers
- `-` symbol is used to subtract literal numbers or variables


```C++17
// subtracting literal integers
10-1
```




    9




```C++17
// subtracting literal floating points
99.99 - 10.99
```




    89.000000




```C++17
// subtracting variables
num1-num2
```




    5



### Dividing numbers
- `/` symbol is used to divide literal numbers or variables


```C++17
// dividing literal integers
10/2
```




    5




```C++17
9/2 // integer division; remainder is discarded
```




    4




```C++17
// dividing literal floats
// if one of the operands is floating point number, C++ performs float division
9.0/2
```




    4.5000000




```C++17
// dividing numeric variables
n1/n2
```




    1.40000f



### Multiplying numbers
- `*` asterick symbol is used to multiply literal numbers and variables


```C++17
// multiplying literal integers
2*3
```




    6




```C++17
// multiplying literatl floats
2.5 * 2.0
```




    5.0000000




```C++17
// multiplying numeric variables
n1*n2
```




    8.75000f




```C++17
// multiply integer by float literal
3*7.9
```




    23.700000



### Capturing remainder from a division
- use modulo or remainder ( **%** ) operator to find the remainder of literal values or variables
- only works on positive integers


```C++17
// // modulo or remainder operator
// testing for even number
4%2
```




    0




```C++17
5%2 // testing for odd number
```




    1




```C++17
10%11 // what's the remainder? Hint: can't divide 10 by 11
```




    10




```C++17
12%11
```




    1




```C++17
// expressions with variables and literals
// declare some variables
int hour, minute;
```


```C++17
// assign some values
hour = 11;
minute = 59;
```


```C++17
// Number of minutes since midnight
hour * 60 + minute
```




    719




```C++17
// Fraction of the hour that has passed
minute/60
```




    0



### Exercise
- How many hours and minutes are in 121 minutes?

### Bitwise operators
- https://www.learncpp.com/cpp-tutorial/38-bitwise-operators/
- bitwise operators work on binary (bits) representation of integers 
    - integers are implicitly converted into binary and then bitwise operations are applied
- bitwise operations are used in lower-level programming such as device drivers, low-level graphics, communications protocol packet assembly, encoding and decoding data, encryption technologies, etc.
- a lot of integer arithmetic computations can be carried our much more efficiently using bitwise operations

| Operator | Symbol | Symbol Name | Syntax |	Operation |
|------| ------ | ---- | ---- | --- |
|bitwise left shift	| << |	left angular bracket | x << y	| all bits in x shifted left y bits; multiplication by $2^y$ |
|bitwise right shift |	>> | right angular bracket |x >> y	| all bits in x shifted right y bits; division by $2^y$ |
bitwise NOT	| ~	| tilde | ~x	| all bits in x flipped |
|bitwise AND |	& |	ampersand | x & y |	each bit in x AND each bit in y |
|bitwise OR	| \| |	pipe | x \| y	| each bit in x OR each bit in y |
bitwise XOR | ^ |	caret | x ^ y |	each bit in x XOR each bit in y |

### Truth Table for bitwise operations

#### & - bitwise AND
| x | y | x & y |
|:---:|:---:|:---:|
| 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 |

#### | - bitwise OR
| x | y | x \| y |
|:---:|:---:|:---:|
| 1 | 1 | 1 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 0 | 0 | 0 |

#### ~ - bitwise NOT
| x | ~x |
|:---:|:---:|
| 1 | 0 |
| 0 | 1 |

#### ^ - bitwise XOR
| x | y | x ^ y |
|:---:|:---:|:---:|
| 1 | 1 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 0 | 0 | 0 |

#### bitwise left shift examples


```C++17
// convert 1 decimal to binary and shift left by 4 bits
1 << 4 // same as 1*2*2*2*2; result is in decimal
```




    16



#### Explanation
- Note: in the explaination, we use 32-bit binary to represent decmial

- $1_{10} = 00000000000000000000000000000001_2$
- $1 << 4$ = $000000000000000000000000000010000 = 2^4 = 16_{10}$


```C++17
3 << 4 // same as 3*2*2*2*2 or 3*2^4
```




    48



#### Explanation

- $3_{10} = 00000000000000000000000000000011_2$
- $3 << 4 = 00000000000000000000000000110000_2 = 2^5+2^4 = 32+16 = 48_{10}$

#### Bitwise right shit examples


```C++17
1024 >> 10 // same as 1024/2/2/2/2/2/2/2/2/2/2
```




    1



#### Explanation

- $1024_{10} = 00000000000000000000010000000000_2$
- $1024 >> 10 = 00000000000000000000000000000001 = 2^0 = 1_{10}$

#### Bitwise NOT examples


```C++17
~0 // Note: result shown is in decimal!
```




    -1




```C++17
~1 // Note: 1 in binary using 32-bit width (31 0s and 1) 00000....1
// result shown is in decimal
```




    -2



#### Explanation
- use 32-bit to repesent integer

- $0_{10} = 00000000000000000000000000000000_2$
- $1_{10} = 00000000000000000000000000000001_2$
- $-1_{10} = 11111111111111111111111111111111_2$
- $2_{10} = 00000000000000000000000000000010_2$
- $-2_{10} = 11111111111111111111111111111110_2$
- Note: -ve numbers are stored in Two's complement
    - 2's complement is calculated by flipping each bit and adding 1 to the binary of positive integer

#### Bitwise AND examples


```C++17
1 & 1
```




    1




```C++17
1 & 0
```




    0




```C++17
0 & 1
```




    0




```C++17
0 & 0
```




    0



#### Bitwise OR examples


```C++17
1 | 1
```




    1




```C++17
1 | 0
```




    1




```C++17
0 | 1
```




    1




```C++17
0 | 0
```




    0



#### Bitwise XOR examples


```C++17
1 ^ 1
```




    0




```C++17
1 ^ 0
```




    1




```C++17
0 ^ 1
```




    1




```C++17
0 ^ 0
```




    0



## Order of operations
- expressions may have more than one operators
- the order of evaluation depends on the rules of precedence

### PEMDAS
- acronym for order of operations from highest to lowest
    1. **P** : Parenthesis
    - **E** : Exponentiation
    - **M** : Multiplication
    - **D** : Division
    - **A** : Addition
    - **S** : Subtraction
- when in doubt, use parenthesis!


```C++17
// computation is similar to what we know from Elementary Math
2+3*4/2-2
```




    6




```C++17
// same as
(2+((3*4)/2))-2
```




    6




```C++17
(2+3)*4/(2-1) // Note: must use * to multiply after ( )
```




    20




```C++17
// typical mistake
(2+3)4/(2-1) // error
```

    [1minput_line_100:3:6: [0m[0;1;31merror: [0m[1mexpected ';' after expression[0m
    (2+3)4/(2-1) // error
    [0;1;32m     ^
    [0m[0;32m     ;
    [0m


    Interpreter Error: 


## Operators for characters
- mathematical operators also work on characters
- characters' ASCII values are used in computations
- C++, when safe, implictly converts from one type to another; called type **coercion**
    - characters are converted into their corresponding integer ASCII values
    - **coercion** is safe when data is not lost, e.g. converting int to float or double


```C++17
'a'+1 // a -> 97
```




    98




```C++17
'A'-1 // A -> 65
```




    64




```C++17
'A'*10
```




    650




```C++17
'A'/10
```




    6




```C++17
'A'+'A'
```




    130



## Operators for strings
- certain operators are defined or overloaded for string types
    - more on user defined advanced types and operator overloading later
- `+` : concatenates or joins two strings giving a new longer string


```C++17
// variables can be declared and intitialized at the same time
#include <iostream>
#include <string>
using namespace std;

string fName = "John";
string lName = "Smith";
string space = " ";
string fullName = fName + space + lName;
```


```C++17
fullName
```




    "John Smith"




```C++17
pi
```




    3.1428571



### Floating point operation accuracy
- floating point calculations may not be always $100\%$ accurate
- you have to choose the accuracy upto certain decimal points to accept the results as correct
- [google area of circle](https://www.google.com/search?q=area+of+a+circle&oq=area+of+a+ci&aqs=chrome.0.0l2j69i57j0l5.1840j0j7&sourceid=chrome&ie=UTF-8)
    - use same radius $10.5$ and compare the results provided below


```C++17
// preprocessor directive to declare a named constant
#define PI 3.141592653589793238
```


```C++17
const double pi = 22/7;
```


```C++17
// let's use constants
double radius = 10.5;
double area_of_circle = PI*radius*radius;
```


```C++17
// value of area of circle
area_of_circle
```




    346.36059




```C++17
pi*radius*radius
```




    330.75000



## Labs

- Add Two Numbers Lab - see [../labs/math/addtwonumbers/README.md](../labs/math/addtwonumbers/README.md) for details
- D Fyrir Dreki - see [../labs/math/dfyrirdreki/README.md](../labs/math/dfyrirdreki/README.md) for details


## Kattis Problems

- Add Two Numbers - https://open.kattis.com/problems/addtwonumbers
    - Hint: read two numbers and print their sum
    
    
- Two-sum - https://open.kattis.com/problems/twosum
    - Hint: just add two number and print their sum
    

- R2 - https://open.kattis.com/problems/r2
    - Hint: simply output $2*S-R1$
    
    
- Spavanac - https://open.kattis.com/problems/spavanac
    - Hint: convert min+hour to minute; subtract 45 and convert the result back to hour and minute
    
 
- Triangle Area - https://open.kattis.com/problems/triarea
    - Hint: If you do not know the formula, Google: area of triangle given height and base

- Framtíðar FIFA - https://open.kattis.com/problems/fifa
    - Hint: 2022 + n/k
    

## Testing Kattis Provided Samples
- see [Kattis Notebook](Kattis.ipynb)

## Summary

- this notebook discussed basic operations that can be done on fundamental C++ data types
- only appropriate operations can be applied to given data
- data must be casted to correct type before applying the basic operations
    - you'll learn this in Data Types and Casting chapter
