# Loops or Iterations

## Topics
- increment and decrement operators
- iteration and types of iterations
- iteration applications
- iterations inside functions

## External Resources

- YouTube Video - Loops or Iterations - [https://youtu.be/3TNLT_uRsuQ](https://youtu.be/3TNLT_uRsuQ)
- YouTube Podcast - Loops or Iterations - [https://youtu.be/hEDrRI8jeAI](https://youtu.be/hEDrRI8jeAI)
- NotebookLM learning materials - [https://notebooklm.google.com/notebook/860e5075-f57a-4267-a02d-78bac6926e4e](https://notebooklm.google.com/notebook/860e5075-f57a-4267-a02d-78bac6926e4e)

## Increment and decrement operators
- in programming adding and subtracting an integer value by 1 is done frequently
- loops counter uses them all the time
- C++ provides increment and decrement operators to make our life easier
- there are two types of increment or decrement
    1. post
    2. pre
    
### post increment and post decrement
- syntax:
```cpp
    varName++;
    varName--;
```
- value of variable varName is used first in the current operation
- value of varialbe varName is then increased or decreased by 1 for the next operation
    - value is incremented or decremented after its usage
    - hence: post increment or post decrement


```C++14
// post increment example
#include <iostream>
using namespace std;

int x;
```


```C++14
// store 10 in x
x = 10;
```


```C++14
// use the current value of x and then increment it
cout << x++ << endl;
```

    10



```C++14
// value of x should be incremented by 1
cout << x;
```

    11


```C++14
// post decrement
x--
```




    22




```C++14
x
```




    10



### pre increment or decrement
- syntax:

```cpp
    ++varName;
    --varName;
```

- value of varialbe varName is first increased or decreased by 1
- new value of variable varName is used in the same operation
    - value is incremented or decremented before its usage
    - hence: pre increment or pre decrement


```C++14
// pre increment and decrement examples
x = 10;
```


```C++14
--x
```




    9




```C++14
++x
```




    10



## Loop
- our real life is full of loops
    - routine works one does day after day
    - e.g. wake up, get ready, eat breakfast, commute to school/work, eat lunch, commute back home, eat dinner, sleep; repeat!
- computer is really good at automatically doing repeative tasks (millions and billions of repititions)
    - repeating identical or similar tasks without errors or boredom is something computers do well and people do poorly
    - computers can also do those tasks many times faster than humans
- iteration starts at a starting point and repeats or loops from the same starting point
    - a block of code can be repeateadly executed using just a one or two lines of loop structure
- just like in real-life, loop must end/exit at some point; otherwise you'll get into infinite loop

## Types of C++ loops
- there are 4 types of loops in C++
    1. for loop
    2. range-based for loop
    3. while loop
    4. do while loop

## for loop
- very common repitition control structure 
- normally executes a specific/fixed number of times
- syntax:

```cpp
    for(initialization; condition; updatation) {
        // body of the loop
    }
```

- interpreting for loop:
```
    1. initialization: initialize loop counter variables
    2. condition - check condition to execute body or not
    3. exit or execute loop body
        3.a if condition is true, execute code in body of the loop
        3.b exit the loop otherwise
    4. updation: update the loop variables
    5. repeat from step 2
```
- the following figure depicts the execution flow of **for loop**

![](resources/For-Loop.png)


```C++14
// example 1 - the hard way of repeating code!
// write a program that counts "Mississippi!" 10 times
// if you didn't know loop, one could still do it, rather painfully!
// typing one statement at a time for 10 times!

#include <iostream>

using namespace std;

cout << "1. Mississippi!\n";
cout << "2. Mississippi!\n";
cout << "3. Mississippi!\n";
cout << "4. Mississippi!\n";
cout << "5. Mississippi!\n";
cout << "6. Mississippi!\n";
cout << "7. Mississippi!\n";
cout << "8. Mississippi!\n";
cout << "9. Mississippi!\n";
cout << "10. Mississippi!\n";
// phew... gets worse, when you need to do it for 100 or 1000 or more times... Yikes!!
// you might just quit programming right now!
```

    1. Mississippi!
    2. Mississippi!
    3. Mississippi!
    4. Mississippi!
    5. Mississippi!
    6. Mississippi!
    7. Mississippi!
    8. Mississippi!
    9. Mississippi!
    10. Mississippi!





    @0x10597fed0




```C++14
// Let's make our life a little easier!
// using for loop, let's tell the computer to repeatedly print "Mississippi!" 10 times 
// so we don't have to type 10 different statements!
for(int i=1; i<=10; i++) {
    // it's common practice that i, j, k are used as loop counter variables
    // you can use any identifier
    cout <<  i << ". Mississippi!\n";
}
// how about counting "Mississippi!" 100 times or even 1000 and more?
```

    1. Mississippi!
    2. Mississippi!
    3. Mississippi!
    4. Mississippi!
    5. Mississippi!
    6. Mississippi!
    7. Mississippi!
    8. Mississippi!
    9. Mississippi!
    10. Mississippi!


### visualize for loop execution in [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20for%20loop%20visualization%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20cout%20%3C%3C%20%22before%20for%20loop%22%20%3C%3C%20endl%3B%0A%20%20for%28int%20i%3D1%3B%20i%3C%3D5%3B%20i%2B%2B%29%0A%20%20%20%20cout%20%3C%3C%20i%20%3C%3C%20%22.%20Hello%20World!%5Cn%22%3B%0A%20%20%0A%20%20cout%20%3C%3C%20%22after%20for%20loop%5Cn%22%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

### intialization, condition and updation statements are optional and independent
- the intitialization, condtion and updation expressions in the **for loop** statment are all optional
- these can also have multiple statments separated by comma
    - e.g., you can have multiple initialization statements
    - you can have multiple update statements
    - you can have complex logical statement for condition

### infinite loop
- a common mistake a programmer can make while constructing a loop
- happens when you forget to update the loop counter variable or use condition that is always true


```C++14
// infinite loop example
// if you run this, computer will not stop executing the loop body!
// you've to manually interrupt the Kernel in Jupyter notebook
// Click Kernel -> Interrput
for( ; ; ) { // infinite loop; no condition that stops the for loop
    cout << "Hello World!" << endl;
}
```


```C++14
// if the kernel restarts; must include all the libraries again
#include <iostream>
using namespace std;
```


```C++14
// for loop with multiple statements for initialization; condition and updation
for(int i=1, j=10; i<=10 && j>=1; i++, j--) {
    cout << i << " + " << j << " = " << i+j << endl;
}
```

    1 + 10 = 11
    2 + 9 = 11
    3 + 8 = 11
    4 + 7 = 11
    5 + 6 = 11
    6 + 5 = 11
    7 + 4 = 11
    8 + 3 = 11
    9 + 2 = 11
    10 + 1 = 11


## `break` and `continue`
- two commonly used statements inside the loop body
- `break` statement breaks/exits the loop immidiately when executed
    - any code after `break` inside the loop body will be ignored
- `continue` statement makes next loop or iteration to execute immidiately
    - any code after `continue` inside the loop body will be skipped
- `break` and `continue` are typically used based on some condition
    - with the reason to exit the loop body or continue with next iteration skipping the rest of the loop body


```C++14
// example of break and continue
// comment and uncomment break and continue to see how each works
for(int i=1; i<=10; i++) {
    cout <<  i << ". Mississippi!\n";
    break;
    cout << i << ". Hello World!\n";
    // continue;
}
```

    1. Mississippi!



```C++14
// break example
cout << "before loop\n";
for(int i=1; i<=10; i++) {
    if (i == 5)
        break;
    cout << i << ". Hello World!" << endl;
}
cout << "after loop... all done!\n";
```

    before loop
    1. Hello World!
    2. Hello World!
    3. Hello World!
    4. Hello World!
    after loop... all done!



```C++14
// continue example
// print odd numbers between 1 and 20
cout << "before loop\n";
for(int i=1; i<=20; i++) {
    if (i%2 == 0) // skip every even i
        continue;
    cout << i << " ";
}
cout << "\nafter loop... all done!\n";
```

    before loop
    1 3 5 7 9 11 13 15 17 19 
    after loop... all done!



```C++14
// breaking infinite loop!
int i=1, j=10;
for( ; ; ) { // you could write int i=1, j=10; as initialization
    if (i<=10 && j>=1)
        cout << i << " + " << j << " = " << i+j << endl;
    else
        break;
    
    i++, j--;
}
```

    1 + 10 = 11
    2 + 9 = 11
    3 + 8 = 11
    4 + 7 = 11
    5 + 6 = 11
    6 + 5 = 11
    7 + 4 = 11
    8 + 3 = 11
    9 + 2 = 11
    10 + 1 = 11



```C++14
// Countdown to Blast-off using for loop
#include <iostream>
#include <unistd.h>

using namespace std;

```


```C++14
for(int i=10; i>=0; i--) {
    if (i == 0)
        cout << "Blast Off!!!" << endl;
    else {
        cout << i << endl;
        usleep(1000000); // sleep for 1e6 microseconds = 1 second 
    }
}
```

    10
    9
    8
    7
    6
    5
    4
    3
    2
    1
    Blast Off!!!


### Countdown demo program - [demos/loops/countdown/countdown.cpp](demos/loops/countdown/countdown.cpp)

## Range-based for loop
- executes a for loop over a range of values
- typically used with container types such as array, vector, set, etc.
    - more readable alternative to the for loop operating over all elements in a container
- syntax:
```cpp
    for (range_declaration : range_expression) {
        // loop body
    }
```
- `range declaration`:
    - declares a range variable, whose type is the type of the element in the sequence in range_expression
- `range expression`:
    - represents a suitalbe sequence of elements such as array or container with begin and end member functions


```C++14
// example of range-based for loop
cout << "before range-based loop...\n";
for(int num: {1, 2, 4, 5, 6, 8, 9, 10}) {
    cout << num << ". Mississippi!\n";
}
cout << "after range-based loop... all done!";
```

    before range-based loop...
    1. Mississippi!
    2. Mississippi!
    4. Mississippi!
    5. Mississippi!
    6. Mississippi!
    8. Mississippi!
    9. Mississippi!
    10. Mississippi!
    after range-based loop... all done!


```C++14
// example 2: iterate over each character in string using range-based loop
string text = "This is a sentence!";
```


```C++14
#include <cstring> // touppper

// recall: auto can be used to automatically determine type based on value assigned
for(auto ch: text) {
    cout << ch << " -> ASCII: " << int(ch) << " UPPER: " << char(toupper(ch)) << endl;
}
```

    T -> ASCII: 84 UPPER: T
    h -> ASCII: 104 UPPER: H
    i -> ASCII: 105 UPPER: I
    s -> ASCII: 115 UPPER: S
      -> ASCII: 32 UPPER:  
    i -> ASCII: 105 UPPER: I
    s -> ASCII: 115 UPPER: S
      -> ASCII: 32 UPPER:  
    a -> ASCII: 97 UPPER: A
      -> ASCII: 32 UPPER:  
    s -> ASCII: 115 UPPER: S
    e -> ASCII: 101 UPPER: E
    n -> ASCII: 110 UPPER: N
    t -> ASCII: 116 UPPER: T
    e -> ASCII: 101 UPPER: E
    n -> ASCII: 110 UPPER: N
    c -> ASCII: 99 UPPER: C
    e -> ASCII: 101 UPPER: E
    ! -> ASCII: 33 UPPER: !



```C++14
// convert text into uppercase
string upper_text = ""; // variable to collect uppercase characters
for(auto ch: text) {
    upper_text += char(toupper(ch));
}
cout << text << " -> " << upper_text << endl;
```

    This is a sentence! -> THIS IS A SENTENCE!


## while loop
- `while` keyword is used to create `while` statment
    - a loop that iterates 0 or more times
- if you're not sure how many times the loop should iterate, you use `while` loop
- while statement can be read as if it were English
    - e.g. while you're not tired, keep running the track
    - as opposed to `for` loop that says, run the track 10 times
- syntax:
```cpp
    while(condition) {
        // body of loop
    }
```
- execute the body of loop as long as the condition is true
- the following figure depicts while loop execution

![](resources/While-Loop.png)


```C++14
// example 1 - print a log table from 1 to 10
#include <iostream>
#include <cmath> // log, log2, log10
#include <iomanip>

using namespace std;

int x;
```


```C++14
cout << "x\tlog(x)\tlog2(x)\tlog10(x)\n";
cout << setw(35) << setfill('=') << "\n";
cout << fixed << setprecision(4);
x = 1; // while loop initialization
while(x <= 10) {
    // natural log base e, base 2 and base 10
    cout << x << '\t' << log(x) << '\t' << log2(x) << '\t' << log10(x) << endl;
    x += 1; // update loop variable
}
```

    x	log(x)	log2(x)	log10(x)
    ==================================
    1.0000	0.0000	0.0000	0.0000
    2.0000	0.6931	1.0000	0.3010
    3.0000	1.0986	1.5850	0.4771
    4.0000	1.3863	2.0000	0.6021
    5.0000	1.6094	2.3219	0.6990
    6.0000	1.7918	2.5850	0.7782
    7.0000	1.9459	2.8074	0.8451
    8.0000	2.0794	3.0000	0.9031
    9.0000	2.1972	3.1699	0.9542
    10.0000	2.3026	3.3219	1.0000



```C++14
// example 2 - run around the track until you're tired
int lapCount = 0;
string tired_response;
bool tired = false; // while loop initialization
```


```C++14
while(not tired) {
    lapCount += 1;
    cout << "lap count = " << lapCount << endl;
    cout << "Are you tired yet? [y|yes] or [n\no]: ";
    cin >> tired_response;
    if (tired_response == "y" or tired_response == "yes")
        tired = true; // update loop variable
}
```

    lap count = 1
    Are you tired yet? [y|yes] or [n
    o]: n
    lap count = 2
    Are you tired yet? [y|yes] or [n
    o]: no
    lap count = 3
    Are you tired yet? [y|yes] or [n
    o]: yes



```C++14
// using break and continue statements in while loop
// NOTE: they don't have to be used together!
lapCount = 0;
while(true) {
    lapCount += 1;
    if (lapCount == 2) continue; // skip the rest of the code
    cout << "lap count = " << lapCount << endl;
    cout << "Are you tired yet? [y|yes] or [n\no]: ";
    cin >> tired_response;
    if (tired_response == "y" or tired_response == "yes")
        break;
}
```

    lap count = 1
    Are you tired yet? [y|yes] or [n
    o]: n
    lap count = 3
    Are you tired yet? [y|yes] or [n
    o]: no
    lap count = 4
    Are you tired yet? [y|yes] or [n
    o]: yes


### visualize while loop in [pythontutor.com](http://pythontutor.com/cpp.html#code=//%20while%20loop%20visualization%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20cout%20%3C%3C%20%22before%20while%20loop%22%20%3C%3C%20endl%3B%0A%20%20int%20i%3D%201%3B%0A%20%20while%20%28i%20%3C%3D%205%29%20%7B%0A%20%20%20%20cout%20%3C%3C%20i%20%3C%3C%20%22.%20Hello%20World!%5Cn%22%3B%0A%20%20%20%20i%2B%2B%3B%0A%20%20%7D%0A%20%20%0A%20%20cout%20%3C%3C%20%22after%20while%20loop%5Cn%22%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D)

## do-while loop
- do while loop is an extension of while loop
- makes a block of code execute 1 or more times
- syntax:
```cpp
do {
    // body of loop
} while (condition);
```
- notice the semi-colon after while statement
- interpreting do-while loop
    1. do execute the block of code at least once
    2. while the condition is true go to step 1
        - exit the loop otherwise
- the following figure depicts the execution flow of **do-while loop**

![](resources/Do-While-Loop.png)


```C++14
// example 1 - game play simulation
// initialize loop variables
int counter = 0; // keep track of no. of times game is played
string play_again; // player's response after each game
```


```C++14
// play game at least once
do {
    // call game() function or implement game here...
    counter++;
    cout << "played " << counter << " times.\n";
    cout << "want to play again? [y|n]: ";
    cin >> play_again;
    if (play_again != "y") break;
    else continue; // not necessary!
} while (true);
```

    played 1 times.
    want to play again? [y|n]: y
    played 2 times.
    want to play again? [y|n]: y
    played 3 times.
    want to play again? [y|n]: n



```C++14
// example 2 - input validation
int input; // variable to store user input
```


```C++14
do {
    cout << "Enter a whole number between 1 and 20: ";
    cin >> input;
    if (cin.fail()) { // if cin failed; wrong type is entered e.g.
        cin.clear(); // clear the error flag
        cin.ignore(INT_MAX, '\n'); // extract and discard upto INT_MAX characters or upto '\n' in std input stream
        cout << "Invalid input. Try again!\n";
        continue;
    }
    else if (input < 1 || input > 20) {
        cout << "input must be a whole number between 1 and 20\n";
    }
    else break;
} while (true);
```

    Enter a whole number between 1 and 20: -1
    input must be a whole number between 1 and 20
    Enter a whole number between 1 and 20: 21
    input must be a whole number between 1 and 20
    Enter a whole number between 1 and 20: asdf
    Invalid input. Try again!
    Enter a whole number between 1 and 20: sdfaf12
    Invalid input. Try again!
    Enter a whole number between 1 and 20: 15



```C++14
cout << "Great! You entered: " << input << endl;
```

    Great! You entered: 15


### see example 2  input validation as a function here [demos/loops/input_validate/input_validation.cpp](demos/loops/input_validate/input_validation.cpp)

## Loops and functions
- all the loop statements can be used inside a function
- in fact, any fundamental concepts (io, math, operations, conditionals, loops, etc.) can be used inside loop and function
- functions can be called inside loop body

### write a function that prints a multiplication table from 1 to 10 as shown below
- use composition and incremental development

```
    1    2    3    4    5    6    7    8    9   10
    2    4    6    8   10   12   14   16   18   20
    3    6    9   12   15   18   21   24   27   30
    4    8   12   16   20   24   28   32   36   40
    5   10   15   20   25   30   35   40   45   50
    6   12   18   24   30   36   42   48   54   60
    7   14   21   28   35   42   49   56   63   70
    8   16   24   32   40   48   56   64   72   80
    9   18   27   36   45   54   63   72   81   90
   10   20   30   40   50   60   70   80   90  100
```


```C++14
#include <iostream>
#include <iomanip>

using namespace std;
```


```C++14
// function that multiplies two numbers
int multiply(int n1, int n2) {
    return n1*n2;
}
```


```C++14
// function prints multiples of N from 1 to 10
void print_multiples(int N) {
    for(int i=1; i<=10; i++)
        cout << setw(5) << multiply(N, i);
    cout << endl;
}
```


```C++14
print_multiples(1);
```

        1    2    3    4    5    6    7    8    9   10



```C++14
print_multiples(2);
```

        2    4    6    8   10   12   14   16   18   20



```C++14
// now print_mutiples need to be called 10 times
// print_multiples function is used as an inner loop
void printMultipleTable() {
    for(int i=1; i<=10; i++)
        print_multiples(i);
}
```


```C++14
printMultipleTable();
```

        1    2    3    4    5    6    7    8    9   10
        2    4    6    8   10   12   14   16   18   20
        3    6    9   12   15   18   21   24   27   30
        4    8   12   16   20   24   28   32   36   40
        5   10   15   20   25   30   35   40   45   50
        6   12   18   24   30   36   42   48   54   60
        7   14   21   28   35   42   49   56   63   70
        8   16   24   32   40   48   56   64   72   80
        9   18   27   36   45   54   63   72   81   90
       10   20   30   40   50   60   70   80   90  100


## Nested loops
- a loop can be nested inside another
- outer loop repeats everything inside inner loop
- a lot of advanced algorithms and problems require many nested double and even tripple loops


```C++14
// function prints multiplication table using nested loop
// print_multiples function is replaced with its actual code
void multiplicationTable() {
    for(int i=1; i<=10; i++) { // for each i... (row)
        for(int j=1; j<=10; j++) // for each column
            cout << setw(5) << multiply(i, j);
        cout << endl;
    }
}
```


```C++14
multiplicationTable();
```

        1    2    3    4    5    6    7    8    9   10
        2    4    6    8   10   12   14   16   18   20
        3    6    9   12   15   18   21   24   27   30
        4    8   12   16   20   24   28   32   36   40
        5   10   15   20   25   30   35   40   45   50
        6   12   18   24   30   36   42   48   54   60
        7   14   21   28   35   42   49   56   63   70
        8   16   24   32   40   48   56   64   72   80
        9   18   27   36   45   54   63   72   81   90
       10   20   30   40   50   60   70   80   90  100


### Define a function that prints a right-traingle shape with some symbol such as * of given height N
- e.g. the following is a right triangle of height 5 printed with `*`

```
    * 
    * * 
    * * * 
    * * * * 
    * * * * * 
```


```C++14
// solution
void printTriangle(char ch, int height) {
    for(int i=1; i<=height; i++) { // could you start i from 0?
        for(int j=1; j<=i; j++)
            cout << ch << " ";
        cout << endl;
    }
}
```


```C++14
// call the function to manually test it
printTriangle('*', 5);
```

    * 
    * * 
    * * * 
    * * * * 
    * * * * * 


### Rectanlge - demo program
- Write a complete C++ that computes area and perimeter of a rectangle given length and width
- write at least 3 test cases for each function
- program must calculate area and perimeter of as many rentangles as the user wants
- see sample solution here: [demos/loops/rectangle/](demos/loops/rectangle/)

## Labs

1. The following lab demonstrates the use of loop structures in C++ by drawing various geometric shapes with ASCII characters.
    - Use the code stub in `loops.cpp` file in [labs/loops](./labs/loops/ ) as a hint to complete the program
    - Use Makefile to compile and build the program
    - Fix all the FIXMEs and write FIXED next to each fixme once fixed

## Exercises
1. Write a function that prints multiplication table from 1 to some value N.
    - program only prints the lower half of the table ignoring all the redundant upper half values


2. Write a C++ program including algorithm steps that calculates area and circumference of a circle.
    - must write functions to compute area and perimeter and automatically test each function with atleast 3 test cases
    - **program finds area and perimeter of as many circle as the user wishes**
    
    
3. Write a C++ program including algorithm steps that calculates Body Mass Index (BMI) of a person.
    - must use as many functions as possible
    - write at least 3 test cases for each function
    - more info on BMI - https://www.nhlbi.nih.gov/health/educational/lose_wt/BMI/bmicalc.htm
    - formula found [here]( https://www.cdc.gov/healthyweight/assessing/bmi/childrens_bmi/childrens_bmi_formula.html#:~:text=The%20formula%20for%20BMI%20is,to%20convert%20this%20to%20meters.&text=When%20using%20English%20measurements%2C%20pounds%20should%20be%20divided%20by%20inches%20squared)
    - **program must calculate BMI of as many patients as user wants**
    - a sample solution is provided at [exercises/loops/BMI/BMI_v4.cpp](exercises/loops/BMI/BMI_v4.cpp)


4. Write a C++ program including algorithm steps that computes area and perimeter of a triangle given three sides.
    - must write and use separate functions to calculate area and perimeter
    - write at least 3 test cases for each function
    - **program computes area and perimeter of as many triangles as user wishes**
    - Hint: use Heron's formula to find area with three sides
    
    
5. Write a C++ program that converts hours into seconds.
    - must write and use function(s) to computer answer(s)
    - must write at least 3 test cases for each function
    - e.g. given 2 hours, program should print 7200 as answer
    - **program continues to run converting as many hours into seconds as the user wishes without restaring it**
    
    
6. Write a C++ program that converts seconds into hours, minutes and seconds.
    - must define and use function(s)
    - write at least 3 test cases for each function
    - sample input: 3600 sample output: 1 hour, 0 minute and 0 second
    - sample input: 3661 sample output: 1 hour, 1 minute and 1 second
    - Hint: use series of division and module operations
    **program will continue to run converting multiple inputs**
    
    
7. Write a C++ program that counts a number of even digits in a given integer.
    - must write function and write atleast 3 test cases
    - **program must continue to run as many times as the user wishes**
    
    
8. Write a C++ program that converts decimal number into binary. See Chapter 2 and 3 for the algorithm and partial solution.
    - **program will continue to run converting as many decmial number as the user wishes**
    
    
9. Write a C++ program that converts binary number into decimal. See Chapter 2 and 3 for the algorithm.


10. Write a C++ program that determines if the given integer is prime.


11. Write a C++ program that does countdown for rocket launch. Must use for loop.
    - prints count down from 10 to 1 and finally prints "Blast Off!"
  
  
12. Write a C++ program that does countdown for rocket launch. Must use while loop.
    - prints count down from 10 to 1 and finally prints "Blast Off!"
    
    
13. Write a program that prints a right-traingle shape with some symbol such as * and given height N
    - e.g. the following is a righ-right triangle of height 5 printed with *

```
* * * * *
* * * *
* * * 
* *  
* 
```


14. Write a program that prints a square shape with some symbol such as * and given height N
    - e.g. the following is a square of height 5 printed with *

```
* * * * *
* * * * *
* * * * *
* * * * * 
* * * * *
```

## Kattis Problems

- with all the fundamental concepts covered so far, one should be equipped to solve a lot more problems in Kattis.
- all most every Kattis problem needs loop to process large amount of data or test cases
- some of the Kattis problems that require loop (and of course other concepts that have been covered from Chapter 1-7 are listed below)


### Clas Demo problems
- Duck Debugging - https://open.kattis.com/problems/duckydebugging
    - Hint: loop, getline, cout and flush!
- Lots of Liquid - https://open.kattis.com/problems/lotsliquid
    - Hint: loop, cbrt cmath and cout formatting with iomanip (fixed and setprecision)


    
### solve the following Kattis problems 
- must as many functions as needed with at least 3 automated test cases for each function
- test case should try to address the corner/edge cases
- use your own test data other than the ones provides by the problem

- Hille Climbing - https://open.kattis.com/problems/hillclimbracing
- More or Less - https://open.kattis.com/problems/moreorless
- Oddities - https://open.kattis.com/problems/oddities
    - a sample solution can be found here: 
    - https://github.com/rambasnet/KattisDemos/tree/master/oddities
- Cold-puter Science - https://open.kattis.com/problems/cold
    - a sample solution can be found here: 
    - https://github.com/rambasnet/KattisDemos/tree/master/cold
- Help a PhD Candidate Out! - https://open.kattis.com/problems/helpaphd
    - a sample solution can be found here:
    - https://github.com/rambasnet/KattisDemos/tree/master/helpaphd    
- Egypt - https://open.kattis.com/problems/egypt
    - a sample solution can be found here:
    - https://github.com/rambasnet/KattisDemos/tree/master/egypt
- FizzBuzz - https://open.kattis.com/problems/fizzbuzz
- Stuck In A Time Loop - https://open.kattis.com/problems/timeloop
- Heart Rate - https://open.kattis.com/problems/heartrate
- Reversed Binary Numbers - https://open.kattis.com/problems/reversebinary
- Modulo - https://open.kattis.com/problems/modulo
- Quality-Adjusted Life-Year - https://open.kattis.com/problems/qaly
- Tarifa - https://open.kattis.com/problems/tarifa
- Judging Moose - https://open.kattis.com/problems/judgingmoose
- Tower Construction - https://open.kattis.com/problems/tornbygge
- Stop Watch - https://open.kattis.com/problems/stopwatch
- Jumbo Javelin - https://open.kattis.com/problems/jumbojavelin
- Rating Problems - https://open.kattis.com/problems/ratingproblems
- Stopwatch - https://open.kattis.com/problems/stopwatch
- Forced Choice - https://open.kattis.com/problems/forcedchoice
- Speeding - https://open.kattis.com/problems/speeding
- From A to B - https://open.kattis.com/problems/fromatob
- Curve Speed - https://open.kattis.com/problems/curvespeed
- No Stragglers - https://open.kattis.com/problems/nostragglers
- Sum of the Year - https://open.kattis.com/problems/sumoftheyear
- km/h - https://open.kattis.com/problems/kmh
- Is Everybody Appy - https://open.kattis.com/problems/appy
- Fancy Frames - https://open.kattis.com/problems/fancyframes
    - Hint: Loop and string
- Exact Change - https://open.kattis.com/problems/exactchange
    - Hint: use two loops, division and modulo
- DRIP - https://open.kattis.com/problems/drip
    - Hint: Loop and math
- Win Streak - https://open.kattis.com/problems/winstreak
- Prime Drive - https://open.kattis.com/problems/primedrive
- Pythagorean Problem - https://open.kattis.com/problems/pythagoreanproblem

## Summary
- learned another fundamental programming concept: iteration or loop
- learned that there are 4 types of loops (2 are for loops and 2 are while loops)
- leaned two import keywords break and continue that are used inside loops
- learned that functions can be called inside loop body and loops can be written inside functions
- learned about nested loop with some example applications
- exercise and example solutions


```C++14

```
