# Conditional Execution

## Topics
- conditional executions
- comparison operators
- types of conditional statements
- switch statement
- using conditional statements in functions
- ternary conditional operator
- logical operators
- passing arguments to `main()` and using them

## Conditional execution
- so far, our programs executed top to bottom starting from **main( )**
    - statement by statement
    - functions change the execution flow from call to definition
- it's important that computer skips or executes certain block of code
    - computer needs to decide to do that to produce useful programs
- **conditional statements** let computer think or make decisions based on data
    - similar to what humans do!
    - e.g. what are the criteria/conditions that help you pick a college?
        - which major or class should I pick? 
        - should I go to class today?
- conditional statements compare data values to create conditions
    - the outcome of which is boolean `true` or `false`

### Comparison operators
- **comparison operators** are used to compare data values
    - thus, creating a condition with a boolean outcome
- comparison operators are binary operators that take two operands
- following table shows comparison operators that compare left hand side value with the right hand side

| symbol | example | description |
| :---- | :--- | :--- |
| == | x == y | is x equal to y? |
| != | x != y | is x not equal to y? |
| >  | x > y  | is x greater than y ? |
| >= | x >= y | is x greater than or equal to y? |
| <  | x < y  | is x less than y ? |
| <= | x <= y | is x less than or equal to y? |

- result of comparison expression (condition) is **true** or **false** boolean value
    - technically, it's **1** and **0**
    - where, **1** -> true and **0** -> false


```python
#include <iostream> // for std io
#include <cassert> // for assert()
#include <string> // for C++ string
using namespace std;
```


```python
// comparison operators examples
1 == 1
```




    true




```python
int x = 10;
int y = 20;
```


```python
// is x eqal to y?
cout << (x == y);
```

    0


```python
// let's print true of false using io manipulator
// is x not equal to y?
cout << boolalpha << (x != y);
```

    true


```python
cout << (x > y);
```

    false


```python
cout << (x < y);
```

    true


```python
cout << (x >= y);
```

    false


```python
cout << (x <= y);
```

    true

## Types of conditional statements
- there are 3 types of conditional statements:
    1. one-way selector
    2. two-way selector
    3. multi-way selector

### one-way selector
- simplest form of conditional statement
- syntax:

```cpp
    if (condition) {
        // body of if
        // block of code to execute
    }
```
- the block of code inside if statement executes iff condition evalutes to true
    - skips the block, otherwise!
- the following flow-chart demonstrates the flow of if statment execution

![](resources/ifstatement.png)



```python
// examples
cout << "stuff before if\n";
if (true) { // true is always true; same as true == true
    cout << "body of if\n";
}
cout << "stuff after if\n";
```

    stuff before if
    body of if
    stuff after if



```python
cout << "stuff before if\n";
if (false) { // false always evaluates to false; same as false == true
    cout << "body of if\n";
}
cout << "stuff after if\n";
```

    stuff before if
    stuff after if



```python
// check if a given number is positive
int num;
```


```python
cout << "enter a whole number: ";
cin >> num;
if (num > 0) {
    cout << num << " is positive\n";
}
cout << "Good bye!";
```

    enter a whole number: 100
    100 is positive
    Good bye!

### Visualize one-way selector in [pythontutor.com](http://pythontutor.com/cpp.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20num%20%3D%20-9%3B%0A%20%20if%20%28num%20%3E%200%29%20%7B%0A%20%20%20%20cout%20%3C%3C%20num%20%3C%3C%20%22%20is%20positive%5Cn%22%3B%0A%20%20%7D%0A%20%20cout%20%3C%3C%20%22Good%20bye!%22%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

### Two-way selector
- provides alternative execution
- analogy is a true/false type question
    - you have to pick one or the other
- syntax:
```cpp
    if (condition) {
        // body of if
    }
    else {
        // otherwise, body of else
    }
```
- if the condition is true, body of if executes
- oterwise, body of else executes
- the following flowchart demonstrates the flow of if else statement

![](resources/ifelsestatement.png)



```python
// determine if the given number is positive or negative
cout << "Enter a whole number: ";
cin >> num;
if (num > 0) {
    cout << num << " is positive\n";
}
else {
    cout << num << " is negative\n";
}
cout << "Good bye!";
// run it few times providing +ve and -ve numbers
```

    Enter a whole number: 99
    99 is positive
    Good bye!




    @0x10c49bed0



### Visualize two-way selector in [pythontutor.com](http://pythontutor.com/cpp.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20num1%20%3D%20100%3B%0A%20%20int%20num2%20%3D%20200%3B%0A%20%20if%20%28num1%20%3E%3D%20num2%29%0A%20%20%20%20cout%20%3C%3C%20num1%20%3C%3C%20%22%20is%20greater%20than%20or%20equal%20to%20%22%20%3C%3C%20num2%20%3C%3C%20endl%3B%0A%20%20else%0A%20%20%20%20cout%20%3C%3C%20num2%20%3C%3C%20%22%20is%20greater%20than%20%22%20%3C%3C%20num1%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20cout%20%3C%3C%20%22Good%20Bye!%22%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

### Multi-way selector
- sometimes one may have to pick one outcome from several options
    - analogy is multiple-choice question with only one correct answer!
- we can achieve this by chaining a series of `else if`s
- also called chained conditionals
- syntax:
```cpp
    if (condition) {
        // first if block
    }
    else if(condition) {
        // 2nd if block
    }
    else if(condition) {
        // 3rd if block
    }
    ...
    else {
        // alternative
    }
```
- check condition starting from the first **if statement**
- if the condition is true, execute the corresponding if block
    - skip the rest of the chained conditions if any
- otherwise, check next condition
    - so on and so forth...
- execute else alternative if not a single condition is evaluated true
- the following flowchart depicts the chained conditional execution

![](resources/multi-wayselector.png)

### NOTE:
- since the condition is checked from top to bottom, the order of checking condition matters in some problems!


```python
// determine if a given number is 0, positive, or negative
cout << "enter a whole number: ";
cin >> num;
if (num > 0)
    // if a block has only one statment; {} can be ignored!
    cout << num << " is positive\n";
else if (num < 0)
    cout << num << " is negative\n";
else
    cout << "the entered number is 0\n";

cout << "Good bye!";
```

    enter a whole number: -9
    -9 is negative
    Good bye!

### Demo program that determines letter grade (A-F) given numeric grade (0-100)
- write a program that converts numeric grade into the corresponding letter grade
- letter grade criteria:
```
    grade >= 90 -> A
    grade >= 80 -> B
    grade >= 70 -> C
    grade >= 60 -> D
    grade < 60  -> F
```


```python
// variable to store the numeric grade
float grade;
```


```python
// Implementation I
// does this solution give correct answer?
// order of checking condition matters!
cout << "Enter a grade: ";
cin >> grade;

if (grade < 60)
    cout << grade << "is an F!\n";
else if(grade >= 60)
    cout << grade << " is a D.\n";
else if(grade >= 70)
    cout << grade << "is a C.\n";
else if (grade >= 80)
    cout << grade << " is a B.\n";
else if (grade >= 90)
    cout << grade << " is an A!\n";

cout << "Good bye!";
```

    Enter a grade: 90
    90 is a D.
    Good bye!


```python
// Implementation II
// how about this solution; does this give correct answer?
cout << "Enter a grade: ";
cin >> grade;

if (grade >= 90) {
    cout << grade << " is an A! :))\n";
    cout << "Awesome job!\n";
}
else if(grade >= 80) {
    cout << grade << " is a B. :)\n";
    cout << "Great job! So close to acing... keep working!\n";
}
else if(grade >= 70) {
    cout << grade << " is a C. :|\n";
    cout << "Good job! work harder to get a B or an A\n";
}
else if(grade >= 60) {
    cout << grade << " is a D. :(\n";
    cout << "Sorry, D isn't good enought to move on to CS2\n. Work very hard!";
}
else {
    cout << grade << " is an F. :((\n";
    cout << "Sorry, that's a fail. Work really really hard to pass!!\n";
}

cout << "Good bye!\n";
```

    Enter a grade: 90
    90 is an A! :))
    Awesome job!
    Good bye!



```python
// Implementation III - using function
char find_letter_grade(float grade) {
    if (grade >= 90)
        return 'A';
    else if(grade >= 80)
        return 'B';
    else if(grade >= 70)
        return 'C';
    else if(grade >= 60)
        return 'D';
    else
        return 'F';
}
```


```python
// manually test find_letter_grade function
cout << "Enter a numeric grade: ";
cin >> grade;
char l_grade = find_letter_grade(grade);
cout << grade << " is equivalent to " << l_grade << endl;
if (l_grade == 'A')
    cout << "Awesome job! :))\n";
```

    Enter a numeric grade: 75
    75 is equivalent to C



```python
// automatically test find_letter_grade function
void test_find_letter_grade() {
    assert(find_letter_grade(100) == 'A');
    assert(find_letter_grade(40) == 'F');
    assert(find_letter_grade(89) == 'B');
    // TODO: test for every possible outcome
    cerr << "all test casses passed!" << endl;
}
```


```python
test_find_letter_grade();
```

    all test casses passed!


### Visualize multi-way selector in [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20program%20to%20determine%20day%20of%20the%20week%20given%20number%0A//%201-7%20%28sunday%20to%20saturday%29%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20day%20%3D%200%3B%0A%20%20if%20%28day%20%3D%3D%201%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Sunday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%202%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Monday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%203%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Tuesday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%204%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Wednesday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%205%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Thursday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%206%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Friday%5Cn%22%3B%0A%20%20else%20if%20%28day%20%3D%3D%207%29%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20Saturday%5Cn%22%3B%0A%20%20else%0A%20%20%20%20cout%20%3C%3C%20day%20%3C%3C%20%22%20is%20not%20a%20valid%20day!%22%3B%0A%20%20%20%20%0A%20%20cout%20%3C%3C%20%22Good%20bye...%5Cn%22%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## Nested conditionals
- one or more type of conditional statements can be nested inside another conditional statement
- syntax:

```cpp
    if (condition) {
        // do something
        if (condition) {
            // do something..
        }

        if (condition) {
            // do something
        }
        else {
            // do something else
        }

    }
    else {
        // do something else...
        if (condition) {
            // do something
        }
    }
```


```python
// a program that determines if a given number is 0, even or odd and positive or negative
// the order of condition doesn't matter in this example
cout << "enter a whole number: ";
cin >> num;
if (num > 0) {
    cout << num << " is positive ";
    // check if the number is even or odd
    if (num %2 == 0)
        cout << "and even\n";
    else
        cout << "and odd\n";
}
else if (num < 0) {
    cout << num << " is negative ";
    // check if the number is even or odd
    if (num %2 == 0)
        cout << "and even\n";
    else
        cout << "and odd\n";
}
else
    cout << "the entered number is 0\n";

cout << "Good bye!";
```

    enter a whole number: -75
    -75 is negative and odd
    Good bye!

### Visualize nested conditional execution in [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20program%20to%20determine%20day%20of%20the%20week%20given%20number%0A//%201-7%20%28sunday%20to%20saturday%29%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20num%20%3D%20-99%3B%0A%20%20if%20%28num%20%3E%200%29%20%7B%0A%20%20%20%20cout%20%3C%3C%20num%20%3C%3C%20%22%20is%20positive%20%22%3B%0A%20%20%20%20//%20check%20if%20the%20number%20is%20even%20or%20odd%0A%20%20%20%20if%20%28num%20%252%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22and%20even%5Cn%22%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22and%20odd%5Cn%22%3B%0A%20%20%7D%0A%20%20else%20if%20%28num%20%3C%200%29%20%7B%0A%20%20%20%20%20%20cout%20%3C%3C%20num%20%3C%3C%20%22%20is%20negative%20%22%3B%0A%20%20%20%20%20%20//%20check%20if%20the%20number%20is%20even%20or%20odd%0A%20%20%20%20%20%20if%20%28num%20%252%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22and%20even%5Cn%22%3B%0A%20%20%20%20%20%20else%0A%20%20%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22and%20odd%5Cn%22%3B%0A%20%20%7D%0A%20%20else%0A%20%20%20%20%20%20cout%20%3C%3C%20%22the%20entered%20number%20is%200%5Cn%22%3B%0A%20%20%20%20%0A%20%20%20%20cout%20%3C%3C%20%22Good%20bye!%22%3B%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)


```python
// TODO: Convert the above program as a function
```

## Conditional operator
- C++ provies a ternary conditional operator
- takes 3 operands
- syntax:
```cpp
    (condition) ? expression1 : expression2;
```
- the value of (condition) is evaluated
- if the condition is true, expression1 is used as the result
- otherwise expression2 is uesed as the result
- simply, a shortcut for:

```cpp
    if (condition) {
        expression1;
    }
    else {
        expression2;
    }
```


```python
// application of conditional operator
// write a program that determines if a given number is odd or even

#include <iostream>
#include <string>
using namespace std;

```


```python
int number;
```


```python
cout << "Enter an Integer number: ";
cin >> number;
cout << number << " is " << ((number%2 == 0) ? "even" : "odd");
```

    Enter an Integer number: 45
    45 is odd

## Logical operators
- often times programs need to evaluate complex logics involving two or more logical expressions (conditions)
- C++ provides three logical operators to evaluate complex boolean expressions

| operator | alternative | example | description |
| :--- | :--- | :--- | :--- |
| && | and | cond1 && cond2 | Is condition 1 true AND condition 2 is also true? |
| \|\| | or | cond1 \|\| cond2 | Is condition 1 is true OR condition 2 is true? |
| ! |  not | !condition | Is NOT condition true or false? |

- `&&` and `||` are binary operators
- `!` is an unary operator
- can also use alternative names `and` and `or` and `not` in-place of the symbols
- symbols usage are more common compared to names in C/C++

- let's say if **a** and **b** are logical expression resulting **true (T)** or **false (F)**
    - the following truth table provides the final outcome of these logical operators
    
### Truth table for && (and)
| a | b  | a **&&** b |
| --- | --- | --- |
| T | T |  T |
|T | F |  F |
|F | T |  F |
|F | F |  F |

### Truth table for || (or)
| a | b  | a **\|\|** b |
| --- | --- | --- |
| T | T |  T |
|T | F |  T |
|F | T |  T |
|F | F |  F |

### Truth table for ! (not)
|a  |  ! a |
|---|---|
|T  |   F |
|F  |   T |

### Order of evaluation
- if all three operators are found in the same expression:
    - `!` is evaluated first, `&&` second and finally `||`
- complete C++ operator precedence order can be found here: https://en.cppreference.com/w/cpp/language/operator_precedence


```python
// && examples
// determine if a number is even and positve
cout << "enter a whole number: ";
cin >> num;
if (num > 0 and num%2 == 0)
    cout << "number is even and positve\n";
else
    cout << "I don't know much about " << num << " except that it's an integer\n";
```

    enter a whole number: 50
    number is even and positve



```python
// || or example
// write a program that determines if somone can retire.
// if a person owns a Ferrari or has 1 Million dollors in savings then the person can retire
string has_ferrari;
long savings;
```


```python
cout << "Do you own a Ferarrai? Enter [y|yes]: ";
cin >> has_ferrari;
cout << "How much in savings do you have in dollars? ";
cin >> savings;
if (has_ferrari == "yes" or has_ferrari == "y" or savings >= 1000000)
    cout << "Congratulations, you can retire now!\n";
else
    cout << "Sorry, no cigar! Keep working...\n";
```

    Do you own a Ferarrai? Enter [y|yes]: yes
    How much in savings do you have in dollars? 0
    Congratulations, you can retire now!



```python
// ! example
// redo retirement calculator
cout << "Do you own a Ferarrai? Enter [y|yes]: ";
cin >> has_ferrari;
cout << "How much in savings do you have in dollars? ";
cin >> savings;
if (!(has_ferrari == "yes" || has_ferrari == "y" or savings >= 1000000))
    cout << "Sorry, no cigar! Keep working...\n";
else
    cout << "Congratulations, you can retire now!\n";
```

    Do you own a Ferarrai? Enter [y|yes]: no
    How much in savings do you have in dollars? 10
    Sorry, no cigar! Keep working...


## Passing arguments to main

- `main( )` can also take arguments
- since main is never called, arguments are provided when the program is ran from a terminal
- the program doesn't have to interactively prompt user to enter required data
- syntax:
```cpp
    int main(int argc, char* argv[]) {
        // argc is total no. of arguments provided to the program
        // automatically calcuated by the system based on the no. of arguments
        // argc is atleast 1
        // argv is an array of char* (c_string; similar in concept to C++ string)
        // contains name of the program and all the user provided arguments

        // body of main
        return 0;
    }
```

- pass space separated arguments to main or program
- use double quotes for arguments with spaces
- all the arguments are treated as C-string
    - must convert numeric arguments to numeric types

```bash
    $ programName.exe arg1 arg2 arg3 "multiple word arguments" ...
    $ git add "Filename.cpp" # add and "Filename.cpp" are arguments to git's main()
```

### demo programs
1. simple demo [demos/conditionals/main_arg1/main_arg1.cpp](demos/conditionals/main_arg1/main_arg1.cpp)
2. more useful demo: [demos/conditionals/main_arg2.cpp](demos/conditionals/main_arg2/main_arg2.cpp)
3. Kattis Hello World problem with test case: [hello](https://github.com/rambasnet/KattisDemos/blob/master/hello/C%2B%2B/hello.cpp)


## Switch statement
- switch statment is very similar to chained conditional or multi-way selector
- allows a variable to be tested for equality against a list of values
- each value is called a case
- syntax:
```cpp
    switch(integral-expression) {
        case constant-expression:
            statement(s);
            break; // optional
        case constant-expression:
            statements(s);
            break; // optional
        // more case statements
        default: // Optional
            statements(s);
    }
```
- switch only works on integral type variables (int, char, long, etc.)
- when break statement is reached, switch terminates
- if no break statement is encountered, the statements following that case will execute until a break statement is reached or switch statments terminates
- the following figure demonstrates the flow of execution in switch statement

![](resources/switch.png)



```python
// e.g. of a switch statement
// determine name of the day given the number 1-7
unsigned int day;
```


```python
cout << "Enter day of the week 1-7: ";
cin >> day;
```

    Enter day of the week 1-7: 6



```python
// comment out break; and see the result
switch(day) {
    case 1: 
        cout << "Day is Sunday\n";
        break;
    case 2:
        cout << "Day is Monday\n";
        break;
    case 3:
        cout << "Day is Tuesday\n";
        break;
    case 4:
        cout << "Day is Wednesday\n";
        break;
    case 5:
        cout << "Day is Thursday\n";
        break;
    case 6:
        cout << "Day is Friday\n";
        break;
    case 7:
        cout << "Day is Saturday\n";
        break;
    default:
        cout << day << " is not a valid day!\n";
        //break; not required!
}
```

    Day is Friday


### Menu-driven CLI interface
- command-line interface (CLI), though not as intuitive as Graphical User Interface (GUI), is still used widely
- airline reservation systems, check-in and printing boarding passes, point-of-sale (POS) terminals at big companies such as Lowe's, Home Depot, etc. use CLI
- a lot of text-based games used CLI as well

- a good application of switch statement is in developing menu-driven CLI

### write a menu-driven C++ program that calculates various statistics of any 2 numbers


```python
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
```


```python
template<class T>
T add(T val1, T val2) {
    return val1 + val2;
}
```


```python
template<class T>
T subtract(T val1, T val2) {
    return val1 - val2;
}
```


```python
template<class T>
T larger(T val1, T val2) {
    return val1 >= val2 ? val1 : val2;
}
```


```python
template<class T>
double average(T val1, T val2) {
    return add(val1, val2)/2.0;
}
```


```python
int getMenuOption() {
    // A Smiple CLI-based calculator
    int option;
    cout << "Enter one of the following menu options: [1-6]\n"
        "1 -> Add\n"
        << "2 -> Subtract\n"
        << "3 -> Larger\n"
        << "4 -> Average\n"
        << "5 -> Multiply\n"
        << "6 -> Quit\n";
    cin >> option;
    return option;
}
```


```python
void program() {
    float n1, n2;
    int option;
    option = getMenuOption();
    if (option == 6) {
        cout << "Good bye...\n";
        return;
    }
    cout << "Enter two numbers separated by space: ";
    cin >> n1 >> n2;
    switch(option) {
        case 1:
            cout << n1 << " + " << n2 << " = " << add<float>(n1, n2) << endl;
            break; // terminate switch
        case 2:
            cout << n1 << " - " << n2 << " = " << subtract<float>(n1, n2) << endl;
            break;
        case 3:
            cout << "larger between: " << n1 << " and " << n2 << " is " << larger<float>(n1, n2) << endl;
            break;
        case 4:
            cout << "average of " << n1 << " and " << n2 << " = " << average<float>(n1, n2) << endl;
            break;
        default:
            cout << n1 << " x " << n2 << " = " << n1*n2 << endl;
            break;
    }
}
```


```python
// TODO: run this many times...
program();
```

    Enter one of the following menu options: [1-6]
    1 -> Add
    2 -> Subtract
    3 -> Larger
    4 -> Average
    5 -> Multiply
    6 -> Quit
    1
    Enter two numbers separated by space: 3 105
    3 + 105 = 108


### Note: a loop would work better for menu-driven program

- loop is covered in next chapter

### A complete demo program is here: [demos/conditionals/menu/menu.cpp](demos/conditionals/menu/menu.cpp)

### Rectangle demo program [demos/conditionals/rectangle/main.cpp](demos/conditionals/rectangle/main.cpp)
- An improvded Rectangle program from previous chapter that calls automated test when user wants to by passing argument to the main

## Exercises
1. Write a program that helps someone decide where to go eat lunch depending on amount of money one has in their pocket.


2. Improve exercise 1 by using function(s) and writing at least 3 test cases for each function.


3. Write a program that determines whether someone is eligible to vote in the US federal election.
    - see sample solution here [exercises/conditionals/vote1/voting_eligibility.cpp](exercises/conditionals/vote1/voting_eligibility.cpp)


4. Improve exercise 3 by using function(s) and writing at least 3 test cases for each function.
    - see sample solution here [exercises/conditionals/vote2/voting_eligibility_v2.cpp](exercises/conditionals/vote2/voting_eligibility_v2.cpp)


5. Write a function day_name that converts an integer number 0 to 6 into the name of a day. Assume day 0 is "Sunday". Return "Invalid Day" if the argument to the function is not valid.


```python
// code stub for Exercise 5
string day_name(int day) {
    // FIXME - complete the rest
    return "";
}
```


```python
// Here are some tests that should pass for day_name function defined above
void test_day_name() {
    assert(day_name(3) == "Wednesday");
    assert(day_name(6) == "Saturday");
    assert(day_name(42) == "Invalid Day");
    cout << "all test cases passed for day_name()\n";
}
```

6. Improve exercise 5 as a complete program with algorithm stepts, main(), etc.

7. Write a function that helps answer questions like "Today is Wednesday. I leave on holiday in 19 days time. What day will that be?" So, the function must take a day name and a delta argument (the number of days to add) and should return the resulting day name.


```python
// Exercise 6 hints
string day_add(string dayName, int delta) {
    // FIXME
}
```


```python
// Exercise 6 test function
// here are some tests that should pass
void test_day_add() {
    assert(day_add("Monday", 4) ==  "Friday");
    assert(day_add("Tuesday", 0) == "Tuesday");
    assert(day_add("Tuesday", 14) == "Tuesday");
    assert(day_add("Sunday", 100) == "Tuesday");
    assert(day_add("Sunday", -1) == "Saturday");
    assert(day_add("Sunday", -7) == "Sunday");
    assert(day_add("Tuesday", -100) == "Sunday");
    cout << "all test cases passed for day_add()";
}
```

8. Improve Exercise 7 as a complete program with algorithm steps, main(), etc.


9. Write a C++ program including algorithm steps that calculates area and perimeter of a triangle given three sides.
    - must define and use separate functions to calculate area and perimeter
    - write at least 3 test cases for each function
    - Hint: use Heron's formula to find area with three sides.
    - define and use function to determine if 3 sides form a triangle
    
    
10. Write a C++ program including algorithm steps that calculates Body Mass Index (BMI) of a person.
    - must use as many functions as possible
    - write at least 3 test cases for each function
    - more info on BMI - https://www.nhlbi.nih.gov/health/educational/lose_wt/BMI/bmicalc.htm
    - Formula [here]( https://www.cdc.gov/healthyweight/assessing/bmi/childrens_bmi/childrens_bmi_formula.html#:~:text=The%20formula%20for%20BMI%20is,to%20convert%20this%20to%20meters.&text=When%20using%20English%20measurements%2C%20pounds%20should%20be%20divided%20by%20inches%20squared).
    - a sample solution is provided at [exercises/conditionals/BMI/BMI_v3.cpp](exercises/conditionals/BMI/BMI_v3.cpp)
        - **an improved version that interprets the BMI result**

## Kattis Problems for Demo

- For, against, or on the Fence - https://open.kattis.com/problems/foragainstoronthefence
    - Hint: use unsigned __int128 type, 0 <= u >= 4*10^18

-  Tic-Tac-Toe AI - https://open.kattis.com/problems/tictactoeai
    - Hint: check the position for every possible winning condition; many (24) if statements

## Labs

- Menu Driven Program - See [../labs/conditionals/menu/README.md](../labs/conditionals/menu/README.md) for details.
- Two Stones - See [../labs/conditionals/twostones/README.md](../labs/conditionals/twostones/README.md) for details.


## Kattis Problems for Practice

- almost all Kattis problems require conditional statements
- following are some problems that can be solved based on the concepts learned from Ch1-6
- solve each problem using function(s)
- write at least 3 test cases for each function
- Take Two Stones - https://open.kattis.com/problems/twostones
    - Hint: check even or odd
- Laptop Sticker - https://open.kattis.com/problems/laptopsticker
    - Hint: basic math
- Sort Two Numbers - https://open.kattis.com/problems/sorttwonumbers
    - Hint: compare two numbers and print their order
- FYI - https://open.kattis.com/problems/fyi
    - Hint: string.find() and condition
- Astrological Sign - https://open.kattis.com/problems/astrologicalsign
    - Hint: 12 outer conditions; for each month check two data ranges
- Right-of-Way - https://open.kattis.com/problems/vajningsplikt
    - Hint: many cases just follow the cases for yield as required and everything else is No yield 
- Knight Packing - https://open.kattis.com/problems/knightpacking
    - Hint: check even or odd
- Chocolate Division - https://open.kattis.com/problems/chocolatedivision
    - Hint: check even or odd
- Elevators - https://open.kattis.com/problems/elevators
- L33T H4X0R - https://open.kattis.com/problems/l33th4x0r
- Ski Traffic - https://open.kattis.com/problems/skitraffic

## Summary
- we learned about another fundamental concepts: conditional execution
- learned with examples 3 different types of conditional statements
- learned how to use conditional statements in functions
- learned about ternary conditional operator (condition) ? exp1 : exp2
    - a short cut for alternative execution
- learned about comparision and logical operators; order of precedence
- learned passing and using arguments to main( )
- finally, exercise and sample solutions


```python

```
