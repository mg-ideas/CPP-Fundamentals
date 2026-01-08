# User Defined Functions and Testing

## Topics
- adding new functions
- using functions
- function types
- ways to pass data to functions
- function prototypes and their purpose
- debugging and automatically testing functions
- scopes and name resolution process

## External Resources
- YouTube Podcast - User Defined Functions [https://youtu.be/-8eoUGNT1wo](https://youtu.be/-8eoUGNT1wo)
- YouTube Video - User Defined Functions [https://youtu.be/KqPq2CqGUU8](https://youtu.be/KqPq2CqGUU8)
- NotebookLM learning resources - [https://notebooklm.google.com/notebook/2b778673-804f-41a4-9f9e-72daa165f2e1](https://notebooklm.google.com/notebook/2b778673-804f-41a4-9f9e-72daa165f2e1)

## Adding new functions

- we've used several functions provided in various standard libraries
- **main( )** is a function that is required for any C++ program
    - indicates where the execution of the program begins
- one can add as many functions as required in the program
- function is a block of code that execute as a group
- the ultimate goal of the function is to break the given problem into smaller sub-problems
    - solve each sub-problem with a function
- if you have many tasks/steps in algoritm steps, function can be used to solve each task/step
- using function is a two-step process
    1. define a function
    2. call or use the function

### Why functions?

- dividing a program into functions or sub-programs has several advantages:
    - each sub-problem can be solved using a function
    - makes it easier to design a solution to a big problem
    - makes the solution modular
    - helps reuse the code
        - function once defined can be used many times!
    - makes the solution or main() concise
    - helps test and update a part of program without affecting the rest
    - makes it easier to work in a team where each member can focus on a function


### Syntax to define a function

- function gives a block of code (body) a name of your choice

```cpp
    type FUNCTION_NAME ( ) {
       // body 
    }
```

- new function naming conventions:
    - can't call it main()
    - can't reuse identifiers or keywords
    - plus same as variable naming conventions!
  
### Syntax to call a function

- functions are called by their name

```cpp
    NAME();
```

- typically, functions are defined outside **main( )** in global scope and called inside **main( )**
- however, one function can call another function
- the function that calls another function is called **caller**
- the function being called is called **callee**
- let's define some functions and use them...


```c++
#include <iostream>
using namespace std;
```


```c++
//1. define a function that prints Hello World!
void sayHello() {
    cout << "Hello World!" << endl;
}
```


```c++
// 2. call sayHello
sayHello();
```

    Hello World!



```c++
// define a function that prints Hello World! three times
// caller function
void sayHelloThrice() {
    // caller calls other functions
    sayHello(); // callee
    sayHello(); // callee
    cout << "Hello World!" << endl;
}
```


```c++
// call sayHelloThrice
sayHelloThrice();
```

    Hello World!
    Hello World!
    Hello World!


## Parameters and arguments

- functions are sub-programs/sub-routines that can take some data/values to manipulate
- we've used some built-in functions that take arguments
    - `float(val)`, `int(val)`, `char(val)`, `setw(arg)`, etc.
- `parameter` is the way to send/pass data to function so the function can do its job
    - placeholders for data to be copied into
    - also called **formal parameters**
- in algebra we may define equations as:

```
    y = f(x) = x^2 + x + 2
    find y, given x = 1: f(1) = 1^2 + 1 + 2 = 4
    find y, given x = -10: f(-10) = (-10)^2 + (-10) + 2 = 92
```

- programming functions burrow the notion from algebraic functions
- parameters help us define generic functions that computes answer based on the given data value
- the data/value that is passed into the parameter is called argument
- `x` is parameter and `1` and `-10` are arguments
- functions with parameters are more useful because they can work on a range of different values
- syntax to define function with parameters:
```cpp
    type NAME(type PARAMETER1, type PARAMETER2, ...) {
        // body
    }
```
- parameters are variables (have types and names)
    - eventually will have values of same type when the function is called
- syntax to call function with parameters:
```cpp
    NAME(argument1, argument2, ...);
```
- function must be called passing the same number of arguments as the no. of parameters
- types of corresponding arguments and parameters must match from left to right
- arguments can be literal values or variables
- by default values of arguments are copied to corresponding parameters
    - value/argument1 is copied to PARAMETER1
    - value/argument2 is copied to PARAMETER2, and so on...
- arguments passed to functions are also called **actual parameters**
    - represent the actual data that are acutally passed


```c++
// define a function that greets a person by their name
#include <string>

// name is the only parameter of type string
void greeting(string name) {
    cout << "Hello there, " << name << endl;
}
```


```c++
// wrong way... calling greeting without argument will generate error!
greeting();
```

    [1minput_line_16:3:1: [0m[0;1;31merror: [0m[1mno matching function for call to 'greeting'[0m
    greeting();
    [0;1;32m^~~~~~~~
    [0m[1minput_line_15:2:6: [0m[0;1;30mnote: [0mcandidate function not viable: requires single argument 'name', but no arguments were provided[0m
    void greeting(string name) {
    [0;1;32m     ^
    [0m


    Interpreter Error: 



```c++
// right way: calling greeting with one string argument
greeting("John"); // passing literal value
```

    Hello there, John



```c++
// wrong way to call greeting passing wrong type of argument
greeting(123);
```

    [1minput_line_18:3:1: [0m[0;1;31merror: [0m[1mno matching function for call to 'greeting'[0m
    greeting(123);
    [0;1;32m^~~~~~~~
    [0m[1minput_line_15:2:6: [0m[0;1;30mnote: [0mcandidate function not viable: no known conversion from 'int' to 'std::__1::string' (aka
          'basic_string<char, char_traits<char>, allocator<char> >') for 1st argument[0m
    void greeting(string name) {
    [0;1;32m     ^
    [0m


    Interpreter Error: 



```c++
// calling greeting with passing the data in variable
// name of the argument has nothing to do with name of the parameter
// only the type needs to match!
string somename;
```


```c++
somename = "Jake";
greeting(somename); // access the value of somename and pass/copy to greeting
```

    Hello there, Jake



```c++
// define a function that takes two numbers and prints the sum as result
void sum(int num1, int num2) {
    long total = num1 + num2;
    cout << num1 << " + " << num2 << " = "  << total << endl; 
}
```


```c++
// call sum passing to int values
sum(10, 20);
```

    10 + 20 = 30


## Types of functions
- functions can be roughly divided into two types:
    1. void functions or fruitless functions
        - functions that do not return any value
        - all the functions defined previously in this notebook are void functions
        - NOTE: printing result/value is NOT the same as returning value
    2. type functions or fruitful functions
        - functions that return a value
- syntax of fruitful functions

```cpp
    type NAME(type PARAMETER1, ...) {
        // body
        return someValue;
    }
```

- type of the return value must match the type of the function NAME
- fruitful parameterized functions are the most useful ones
    - can use the returned value however you want!
    - can automatically test the results from the functions
    - most library functions are fruitful and parameterized


```c++
// define a function that takes two numbers and returns their sum
long find_sum(int num1, int num2) {
    long total = num1 + num2;
    return total;
}
```


```c++
// call function with values
find_sum(12, 8);
// where is the returned value or result?
```




    20




```c++
// you must find a way to use the returned value
// print the returned value from find_sum function
cout << find_sum(12, 8) << endl;
```

    20



```c++
// assign the returned value from find_sum(...) to a variable
long ans = find_sum(99, 1);
```


```c++
// let's see the value of ans
ans
```




    100



## Passing data/value or reference
- C++ provides two ways to pass data to functions:
    1. pass by value
    2. pass by reference
    
### Pass by value
 - data of argument or actual parameter is copied into formal parameter
 - the default way of passing data/values to the functions
 - easier to understand; no side effect
     - changing the formal parameter doesn't affect the actual parameter
 - slower, however, to copy large amount of data
 - since the data is copied, anything done to the data via parameter doesn't affect the data in actual argument
     - if the formal parameter is modified, the actual parameter or argument is not modified!


```c++
// function to demonstrate pass by value
// num1 and num2 are also called formal parameters
long another_sum(int num1, int num2) {
  num1 += 10; // we don't do this, but only to demonstrate pass by value
  num2 += 20;
  long total = num1 + num2;
  return total;
}
```


```c++
// pass data stored in variables; declare variables
int n1, n2;
long answer;
```


```c++
n1 = 20;
n2 = 30;
// n1 and n2 are actual parameters or arguments
answer = another_sum(n1, n2);
cout << n1 << " + " << n2 << " = " << answer << endl;
// gives wrong answer because another_sum() is not correctly implemented
// at least values of n1 and n2 remain intact, because of the way pass by value works!
```

    20 + 30 = 80





    @0x10b918558



### Visualize pass by value on [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20pass%20by%20value%20demo%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Along%20sum%28int%20num1,%20int%20num2%29%20%7B%0A%20%20num1%20%2B%3D%2010%3B%0A%20%20num2%20%2B%3D%2020%3B%0A%20%20long%20total%20%3D%20num1%20%2B%20num2%3B%0A%20%20return%20total%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20n1,%20n2%3B%0A%20%20n1%20%3D%2020%3B%0A%20%20n2%20%3D%2030%3B%0A%20%20cout%20%3C%3C%20n1%20%3C%3C%20%22%20%2B%20%22%20%3C%3C%20n2%20%3C%3C%20%22%20%3D%20%22%20%3C%3C%20sum%28n1,%20n2%29%20%3C%3C%20endl%3B%0A%20%20//%20n1%20and%20n2%20still%20have%20same%20original%20values%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

### Pass by reference
- copying data is expensive/slow operation in terms of memory usage and CPU time
    - avoid copying data with **pass by reference** technique
- pass by reference occurs when the parameter has **&** symbol in-between the type and name
- syntax for pass by reference:

```cpp
    // function definition
    type NAME(type & PARAMETER1, type & PARAMETER2,...) {
        // body
    }
    // function call
    NAME(argument1, argument2, ...);
```

- data is not copied but the reference (memory address of data) is passed to function's parameters
    - meaning actual and formal parameter reference the same memory location
- ONLY variable arguments (NOT literal) can be passed to the reference parameters
- if the formal parameter is modified, the actual parameter is also modified!
- it's efficient (only memory address of actual parameter is passed)
    - but may have unintended side effect
    - if the formal parameter is modified, the actual parameter is also modified
- it also provides a way to retrieve data from functions!


```c++
// function to demonstrate pass by reference
// num1 and num2 are also called formal parameters that are passed by reference
long yet_another_sum(int & num1, int & num2) {
  num1 += 10; // for whatever reason we modify formal parameters;
  num2 += 20; // could be a mistake
  long total = num1 + num2;
  return total;
}
```


```c++
// ERROR: can't pass literals for pass by reference parameters
yet_another_sum(20, 30)
```

    [1minput_line_37:3:1: [0m[0;1;31merror: [0m[1mno matching function for call to 'yet_another_sum'[0m
    yet_another_sum(20, 30)
    [0;1;32m^~~~~~~~~~~~~~~
    [0m[1minput_line_36:3:6: [0m[0;1;30mnote: [0mcandidate function not viable: expects an l-value for 1st argument[0m
    long yet_another_sum(int & num1, int & num2) {
    [0;1;32m     ^
    [0m


    Interpreter Error: 



```c++
// n1 and n2 are already declared as integers above
n1 = 20;
n2 = 30;
// n1 and n2 are actual parameters or arguments
answer = yet_another_sum(n1, n2);
cout << n1 << " + " << n2 << " = " << answer << endl;
// gives right answer n1 and n2 values are modified
```

    30 + 50 = 80





    @0x10b918558




```c++
// swap function 
// swaps/exchanges the values of two variables
void intSwap(int & n1, int & n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
```


```c++
// let's swap the values of these two variables
int value1 = 10;
int value2 = 1000;
```


```c++
intSwap(value1, value2);
```


```c++
cout << value1 << " " << value2 << endl;
```

    1000 10


### Visualize pass by reference on [pythontutor.com](http://pythontutor.com/cpp.html#code=void%20intSwap%28int%20%26%20n1,%20int%20%26%20n2%29%20%7B%0A%20%20%20%20int%20temp%20%3D%20n1%3B%0A%20%20%20%20n1%20%3D%20n2%3B%0A%20%20%20%20n2%20%3D%20temp%3B%0A%7D%0Aint%20main%28%29%20%7B%0A%20%20//%20let's%20swap%20the%20values%20of%20these%20two%20variables%0A%20%20int%20value1%20%3D%2010%3B%0A%20%20int%20value2%20%3D%201000%3B%0A%20%20intSwap%28value1,%20value2%29%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)


### Constant parameters
- C++ allows constant parameters
    - prevents the formal parameters' values from being changed inside the function
    - thus, prevents the unintended side effects
- constant parameters are READ ONLY
- the following example doesn't compile due to syntax error


```c++
long sum_with_const_parameters(const int & n1, const int n2){
    // modifying n1 and n2 constants are not allowed
    n1 += 10;
    n2 += 20;
    return n1 + n2;
}
```

    [1minput_line_44:3:8: [0m[0;1;31merror: [0m[1mcannot assign to variable 'n1' with const-qualified type 'const int &'[0m
        n1 += 10;
    [0;1;32m    ~~ ^
    [0m[1minput_line_44:1:44: [0m[0;1;30mnote: [0mvariable 'n1' declared const here[0m
    long sum_with_const_parameters(const int & n1, const int n2){
    [0;1;32m                               ~~~~~~~~~~~~^~
    [0m[1minput_line_44:4:8: [0m[0;1;31merror: [0m[1mcannot assign to variable 'n2' with const-qualified type 'const int'[0m
        n2 += 20;
    [0;1;32m    ~~ ^
    [0m[1minput_line_44:1:58: [0m[0;1;30mnote: [0mvariable 'n2' declared const here[0m
    long sum_with_const_parameters(const int & n1, const int n2){
    [0;1;32m                                               ~~~~~~~~~~^~
    [0m


    Interpreter Error: 


### Retrieving data from void functions
- pass-by-reference can be used to retrieve one or more values/results from functions
- since, C++ function can only return one value, pass-by-reference technique can be used to retrive more than one values from a function
- typically, if the function's return value is too large to copy, use pass-by-reference instead of return 


```c++
// extracting value from a function with passed by reference technique
// num1 is passed by value num2 and sum are passed by reference
void computeSum(int num1, int& num2, long &sum) {
    sum = num1 + num2; // sum is modified
    // notice void function, no return value!
}
```


```c++
n1 = 100;
n2 = 300;
ans = 0; // initilize ans to 0; just in case!
// n1, n2, and ans are actual parameters or arguments
computeSum(n1, n2, ans);
cout << n1 << " + " << n2 << " = " << ans << endl;
```

    100 + 300 = 400



```c++
// define a function that computes and returns both area and perimeter
// C++ doesn't allow returning multiple values from a function
// use pass-by-reference technique!
void area_and_perimeter(const float & l, const float & w, float & area, float & peri) {
    area = l*w;
    peri = 2*(l+w);
}
```


```c++
float len = 4.5;
float width = 3.99;
float area, perimeter;
```


```c++
area_and_perimeter(len, width, area, perimeter);
```


```c++
area
```




    17.9550f




```c++
perimeter
```




    16.9800f



### Visualize retrieving data from function using pass-by-reference on [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20pass%20by%20value%20demo%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0A//%20extracting%20value%20from%20a%20function%20with%20passed%20by%20reference%20technique%0A//%20num1%20is%20passed%20by%20value%20num%202%20and%20sum%20are%20passed%20by%20reference%0Avoid%20computeSum%28int%20num1,%20int%26%20num2,%20long%20%26sum%29%20%7B%0A%20%20%20%20sum%20%3D%20num1%20%2B%20num2%3B%20//%20sum%20is%20modified%0A%20%20%20%20//%20notice%20void%20function,%20no%20return%20value!%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20n1,%20n2%3B%0A%20%20n1%20%3D%2020%3B%0A%20%20n2%20%3D%2030%3B%0A%20%20long%20ans%20%3D%200%3B%0A%20%20computeSum%28n1,%20n2,%20ans%29%3B%0A%20%20cout%20%3C%3C%20n1%20%3C%3C%20%22%20%2B%20%22%20%3C%3C%20n2%20%3C%3C%20%22%20%3D%20%22%20%3C%3C%20ans%20%3C%3C%20endl%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## Dead code
- code in the program that computer will never execute
- e.g., returning from function prematurely from the middle of the body
- visualize dead code example on [pythontutor.com](https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Along%20sum%28int%20n1,%20int%20n2%29%20%7B%0A%20%20return%200%3B%0A%20%20long%20result%20%3D%20n1%20%2B%20n2%3B%0A%20%20return%20result%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20cout%20%3C%3C%20sum%2810,%2020%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)

## Function prototype

- we know functions must be defined before they're called
- function signature or prototype can be used to tell the compiler that the function body will be defined later
- helps us write the main function towards the top of the source file
- define the actual functions after main without having to worry about the order of definitions
- syntax of function prototype:

```cpp
type NAME(type, type, ...);
```

- only the function type, name and parameter types are required
- can provide prameter names but are meaningless
- NOTE: function prototype demostration doesn't work in Jupyter
- see [demos/functions/func_prototype/func_prototype.cpp](demos/functions/func_prototype/func_prototype.cpp)



## Function overloading and templating
- often times we do similar operations on different data types
- e.g., we add floating point numbers and integers or concatenate strings
- e.g. we want to add two numbers or strings using functions called add( )
    - `add(10, 20);` // adding two integers
    - `add(20.5, 5);` // adding double and int
    - `add(5.6f, 6.1f);` // adding two floats
    - `add(56.66, 4646.444);` // adding two doubles
    - `add(12.23f, 32.343);` // adding two doubles
    - `add("hello", "world");` // returns "helloworld"
 
- you'd need to define 6 `add()` function for adding each pair of data types stated above
- what about adding various combination of types? such as adding `int` and `float`, `short` and `double`... etc.
- two solutions:
    1. function overloading
    2. function templating


```c++
// Problem: just this one function doesn't correctly add all numeric types
int addNumbers(int n1, int n2) {
    return n1+n2;
}
```


```c++
// gives correct answer!
cout << addNumbers(10, 20) << endl;
```

    30



```c++
// gives wrong answer!
cout << addNumbers(10.5f, 30);
```

    [1minput_line_12:3:20: [0m[0;1;35mwarning: [0m[1mimplicit conversion from 'float' to 'int' changes value from 10.5 to 10 [-Wliteral-conversion][0m
    cout << addNumbers(10.5f, 30);
    [0;1;32m        ~~~~~~~~~~ ^~~~~
    [0m

    40

### Function overloading
- functions can be redefined as long as the prototypes are different
    - same function name can be used with different parameter types


```c++
// function overloading for float type
float addNumbers(float n1, float n2) {
    return n1+n2;
}
```


```c++
// overaloading for double type
double addNumbers(double n1, double n2) {
    return n1 + n2;
}
```


```c++
// now we can add two floating point numbers
cout << addNumbers(10.5f, 30.0f);
```

    40.5


```c++
// we can also add two doubles
cout << addNumbers(10.1, 8.9);
```

    19


```c++
// how about adding int and float?
// compiler gets confused, as we don't have addNumbers defined for int and float
addNumbers(5, 10.5)
```




    15.500000



### Function templates
- ways to create functions that work with **generic types**
- better approach as we write one template function that works for any types
    - without having to repeat the function for each type
- can be achieved using **template parameters**
- template parameter allows us to pass actual types to a function
- syntax to define a template function:

```cpp
    template <class type1, class type2,...>
    type1 functionName(type1 PARAMETER1, type2 PARAMETER2, ...) {
        // body
    }
```
- type1 and type2 in definitions are identifiers
    - you can choose any names
    
- syntax to call template function:

```cpp
    functionName<type1, type2,...>(arg1, arg2, ...);
```
- type1 and type2 in function call are actual data types that C++ understands


```c++
// define a function that adds two values
// let's assume T2 is the bigger type if T1 and T2 are differnt types
template<class T1, class T2>
T2 addTwo(T1 val1, T2 val2) {
    return val1 + val2;
}
```


```c++
// call addTwo providing types and arguments
cout << addTwo<int, int>(10, 5);
```

    15


```c++
cout << addTwo<int, float>(5, 10.9f);
```

    15.9


```c++
cout << addTwo<int, double>(56, 99.90);
```

    155.9


```c++
// can also add two chars
cout << addTwo<char, char>('1', '1');
```

    b


```c++
// let's add two strings
#include <string>
using namespace std;

cout << addTwo<string, string>("hello", "world");
```

    helloworld

## Scope and name resolution
- scope is the area of visibility of identifiers such as variables and constants within the program
    - scope determines where the variables and identifiers are valid
- scopes can be conceptualized as nested box frames
- C++ provides 3 common types of identifiers' scopes
    1. global scope
    2. local scope
    3. block scope
    
### Global scope
- any identifiers (variables, constants, functions) decalared outside any function have global scope
- most functions have global scopes
- can be used anywhere in the program

### Local scope
- any variables and constants defined inside function scope
    - including parameters have local scope
- local identifiers can be used anywhere within the function scope

### Block scope
- smallest region that is enclosed inside curly braces `{ }`
- any identifiers declared inside curly braces can be used only withing that block
- very limited scope and rarely used

### Name resolution
- program needs to know and resolve what different names are
    - where the names are declared and their scope or visibility
- compiler first looks into the current scope or frame then the frame it's immidiately inside and so on until global frame to try to resolve any name used in the program

- the following figure depicts the various scopes and name resolution in C++

![](resources/scopesandnameresolution.png)


### visualize identifiers' scopes on [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20program%20to%20demonstrate%20variable%20scope%0A//%20libraries%20have%20global%20scope%0A%23include%20%3Ciostream%3E%0A%23include%20%3Cstring%3E%0A%0Ausing%20namespace%20std%3B%0A%0A//%20global%20identifiers%0Aint%20global_var%20%3D%2010%3B%0Aconst%20double%20PI%20%3D%203.141592653589793238%3B%0A%23define%20LF%20'%5Cn'%0A%0Aint%20area_of_circle%28const%20float%20radius%29%20%7B%0A%20%20global_var%20%3D%20200%3B%0A%20%20return%202*PI*radius%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20float%20rad%20%3D%202.5%3B%0A%20%20global_var%20%3D%20100%3B%0A%20%20cout%20%3C%3C%20%22area%20of%20circle%20%3D%20%22%20%3C%3C%20area_of_circle%28rad%29%20%3C%3C%20LF%3B%0A%20%20cout%20%3C%3C%20%22global%20var%20%3D%20%22%20%3C%3C%20global_var%20%3C%3C%20LF%3B%0A%20%20%7B%0A%20%20%20%20char%20block_var%20%3D%20'A'%3B%0A%20%20%20%20cout%20%3C%3C%20%22block_var%20within%20block%20%3D%20%22%20%3C%3C%20block_var%20%3C%3C%20LF%3B%0A%20%20%20%20rad%20%3D%2010.99f%3B%0A%20%20%7D%0A%20%20//%20trying%20to%20access%20block%20variable%20outside%20block%0A%20%20//%20TODO%3A%20uncomment%20the%20following%20and%20compile%0A%20%20//%20block_var%20%3D%20'a'%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## Labs

- Library and Functions Lab - See [../labs/functions/library/README.md](../labs/functions/library/README.md) for details.
- The Last Problem Lab - See [../labs/functions/thelastproblem/README.md](../labs/functions/thelastproblem/README.md) for details.

## Exercises
        
- Write a C++ program including algorithm steps that calculates area and circumference of a circle.
    - must write functions to compute area and perimeter and automatically test each function with atleast 3 test cases
    
    
- Write a C++ program including algorithm steps that calculates Body Mass Index (BMI) of a person.
    - must use as many functions as possible
    - write at least 3 test cases for each function
    - more info on BMI - https://www.nhlbi.nih.gov/health/educational/lose_wt/BMI/bmicalc.htm
    - Formula [here]( https://www.cdc.gov/healthyweight/assessing/bmi/childrens_bmi/childrens_bmi_formula.html#:~:text=The%20formula%20for%20BMI%20is,to%20convert%20this%20to%20meters.&text=When%20using%20English%20measurements%2C%20pounds%20should%20be%20divided%20by%20inches%20squared).
    - a sample solution is provided at [exercises/functions/BMI](exercises/functions/BMI)


- Write a C++ program including algorithm steps that calculates area and perimeter of a triangle given three sides.
    - must write and use separate functions to calculate area and perimeter
    - write at least 3 test cases for each function
    - Hint: use Heron's formula to find area with three sides.
    
    
- Write a C++ program that converts hours into seconds.
    - must write and use function(s) to computer answer(s)
    - must write at least 3 test cases for each function
    - e.g. given 2 hours, program should print 7200 as answer.
   
   
- Write a C++ program that converts seconds into hours, minutes and seconds.
    - must define and use function(s)
    - write at least 3 test cases for each function
    - sample input: 3600 sample output: 1 hour, 0 minute and 0 second
    - sample input: 3661 sample output: 1 hour, 1 minute and 1 second
    - Hint: use series of division and modulo operations
    
    
- Write a C++ program that finds area and perimeter of a rectangle.
    - must define and use function(s)
    - write at least 3 test cases for each function
    - a sample solution is provided her [demos/functions/rectangle](demos/functions/rectangle)
    
    
## Kattis Problems
- functions are not required to solve Kattis problems
- however, it's best practices to use function to learn to be able to sovle harder and bigger problems


- Hello World! - https://open.kattis.com/problems/hello
    - solve the problem using function(s)
    - write a test case for the function using assert
    
    
- Solving for Carrots - https://open.kattis.com/problems/carrots
    - solve the problem using function(s)
    - using assert write at least three test cases for each function
    
    
- R2 - https://open.kattis.com/problems/r2
    - solve the problem using function(s)
    - using assert write at least three test cases for each function
    
    
- Spavanac - https://open.kattis.com/problems/spavanac
    - solve the problem using function(s)
    - using assert write at least three test cases for each function
    
    
- Add Two Numbers - https://open.kattis.com/problems/addtwonumbers
    - solve the problem using function(s)
    - using assert write at least three test cases for each function
    
    
- Solve rest of the problems from previous chapters using as many functions as possible.
    - using assert write at least three test cases for each function

## Summary
- this chapter covered concepts on functions; how to create new functions and use them
- went over various types of functions (fruitful and fruitless)
- learned about why and how to pass data to functions
- learned about debugging using assert(), cerr (stderr stream)
- learned about important foundation concept of automatically testing functions
- covered function overloading and templating
- finally, exercises and sample solutions


```c++

```
