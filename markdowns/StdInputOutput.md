# Standard Input and Output

## Topics
- common way to input and output data
- printing variables and values onto monitor or console
- reading data from keyboard
- composing programs

## Input and output (IO)
- IO operations are fundamental to computer programs
- C++ IO occurs in streams (sequence of bytes)
- programs must be able to read data from varieties of input devices (**input operation**)
    - streams of bytes flow from keyboard, disk drive, network devices, etc. to main memory, RAM (Random Access Memory)
- programs must be able to write data to varieties of output devices (**output operation**)
    - stream of bytes flow from RAM to monitor, disk drive, network devices, etc.
- this chapter covers how C++ handle standard input and output
- reading from and writing to disk drive or files is covered in File IO chapter

## Standard output stream

- a prgram may need to display data or results of computation to users
- a common way to display results is by printing them to common output called monitor
    - also called console
- we've printed `hello world` and some other strings to console in Chapter 1
- similarly, we can print any literal values or data stored in variables to standard output
- use `cout` statement defined in `<iostream>` library and `std namespace`
- output statement syntax:

    ```cpp
    cout << varName1 << varName2 << "literal values" << ' ' << 100 << '\n';
    ```
    
- `<<` **stream insertion operator** inserts values to output stream
- multiple values are separated by `<<` operator
- `endl` operator or `\n` escape character end line to continue writing in next line
- the following code demonstrates standard output stream


```c++
// include required library
#include <iostream> // cout

// use required namespace
using namespace std; //std namespace defines cout, endl, etc.
```


```c++
cout << "Hello World!" << endl;
cout << 100 << 2.5f << ' ' << 3.99 << 'A' << "some text as string";
cout << "continue printing stuff in next line...?" << endl;
```

    Hello World!
    1002.5 3.99Asome text as stringcontinue printing stuff in next line...?



```c++
// declaring and printing variables
#include <string>

string name = "John Doe";
char MI = 'A';
int age = 25;
```


```c++
// outputting variables
cout << "name = " << name << endl;
cout << "MI = " << MI << " and age = " << age << endl;
```

    name = John Doe
    MI = A and age = 25



```c++
bool done = false;
float temperature = 73;
float richest_persons_networth = 120000000000; // 120 billion
float interestRate = 4.5;
float length = 10.5;
float width = 99.99f; // can end with f for representing floating point number
double space_shuttle_velocity = 950.1234567891234567 // 16 decimal points
```


```c++
// cout can continue in multilines
cout << "temperature: " << temperature << " age: " << age 
    << " richest person's worth: "
    << richest_persons_networth << endl;
cout << "interest rate: " << interestRate << endl;
cout << "length: " << length << " and width = " << width << endl;
cout << "space_shuttle_velocity: " << 950.1234567891234567 << endl;
```

    temperature: 73 age: 25 richest person's worth: 1.2e+11
    interest rate: 4.5
    length: 10.5 and width = 99.99
    space_shuttle_velocity: 950.123



```c++
// outputting string variables
cout << "Hello there, " << name << '!' << endl;
```

    Hello there, John Doe!



```c++
// more string variables
string address1 = "1100 North Ave";
string state_code = "CO";
string country = "USA";
```


```c++
cout << "CMU's address:\n"
     << address1 << endl
     << "Grand Junction, " << state_code << ' ' << 81501 << endl
     << country << endl;
```

    CMU's address:
    1100 North Ave
    Grand Junction, CO 81501
    USA


## Standard input stream
- often, data must be read from standard input stream or keyboard
    - e.g. most interactive programs with Graphical User Interface (GUI) or Command Line Interface (CLI)
- must include `<iostream>` library for standard input
- must use **std** namespace
- use **cin >>** statement
- syntax:

    ```cpp
    cin >> var1 >> var2 >> ...;
    ```
    
- `>>` stream extraction operator extracts data/value from input stream
- must always use variables of appropriate types
- while scanning input stream, `>>` ignores leading whitespaces and stops at a trailing whitespace
- let's say we have a stream of data separated by whitespaces: `10 11 15.5 A`
    - we can parse and extract it as following:
    ```cpp
    cin >> num1 >> num2 >> num3 >> alpha;
    ```
        - given num1 and num2 are of type int or long, num3 is float or double and alpha is char
    
### Inputting numerical data
- we must store the extracted numerical input data into appropriate numerical variables
- `>> int variables` : extracts whole numbers from input stream; stops at anything else
- `>> float or double variables` : extracts numbers including decimal points; stops at anything else


```c++
// include required libraries
#include <iostream> //cin, cout

using namespace std;
```


```c++
int num1;
// prompt user to enter a whole number
cout << "enter a whole number: ";
cin >> num1;
cout << "You entered: " << num1 << endl;
```

    enter a whole number: 10
    You entered: 10



```c++
// can extract multiple integers
int num2;
cout << "enter two whole numbers separated by space: ";
cin >> num1 >> num2;
cout << num1 << '+' << num2 << '=' << num1+num2 << endl;
```

    enter two whole numbers separated by space: 10 20
    10+20=30



```c++
// extracting int and float
float num3;
cout << "enter a whole number and a floating point number separated by space: ";
cin >> num1 >> num3;
cout << num1 << " + " << num3 << " = " << num1+num3 << endl;
```

    enter a whole number and a floating point number separated by space: 5 9.9
    5 + 9.9 = 14.9



```c++
// let's enter 10 11 15.5 A and store them into corresponding variables
int n1, n2;
float n3;
char alpha;
```


```c++
// let's not prompt; but simply enter 10 11 15.5 A
cin >> n1 >> n2 >> n3 >> alpha;
```

    10 11 15.5 A



```c++
// let's echo the entered values
cout << n1 << " " << n2 << " " << n3 << " " << alpha;
```

    10 11 15.5 A

### Input failure
- if input data and variable type mismatched, `cin` will not be able to extract the data from the stream
    - `cin` will enter into a fail state
    - won't be able to extract data anymore
- Note: Jupyter Notebook may crash or simply not work as expected when input fails
    - if the Jupyter crashes or stops working, your must restart the Kernel: `Kernel -> Restart`


```c++
// variable to store whole number
int number;
```


```c++
cout << "Enter a number: ";
cin >> number;
cout << "You entered " << number;
// Play with it:
// try entering an integer then whole number and characters then characters and number, etc.
```

    Enter a number: dsf
    You entered 0




    @0x1102e0558



### Inputting string data
- we can read string data in two ways depending on if the string has a space (phrase) or not (word)
- string without space or single word can be extracted using `>>` stream extraction operator
- a single string data or line with spaces must be extracted using `getline( )` function
- reading syntax:

    ```cpp
    getline(cin, strVar); // reading a line from std input and storing into strVar
    ```
    
- `getline()` reads the entire line including whitespaces including the `\n` newline
    - newline is extracted from the input stream and discarded


```c++
string player_name;
```


```c++
cout << "Enter your first name: ";
cin >> player_name;
cout << "Hello there, " << player_name << endl;
// run it wih just firstname and then with fullname; notice the value of player_name
```

    Enter your first name: 
    John Smith
    Hello there, John





    @0x107733ec0




```c++
// string with spaces
cout << "Enter your full name: ";
getline(cin, player_name);
cout << "Hello there, " << player_name << endl;
```

    Enter your full name: John Smith
    Hello there, John Smith


### Note
- getline( ) reads, discards and stops at newline character (`\n`)
- `>>` stops before the trailing newline character leaving it in the input stream
- must explictly read and discard newline character if getline is used after `>>`
- use **ws** whitespace manipulator
    - ws operator extracts as many whitespace characters as possible from the current position in the input stream
    - extraction stops as soon as a non-whitespace character is found
    ```cpp
    cin >> number >> ws;
    ```
    - reads and discards whitespace(s) including `\n` after number value in input stream
    
### demo program
- program that demonstrates the above caveat is found here [demos/stdio/demo1/main.cpp](demos/stdio/demo1/main.cpp)

## Labs

1. Standard IO Lab 
    - write a C++ program that produces the following output on console
    - use the partial solution provided in [labs/stdio/main.cpp](labs/stdio/main.cpp)
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
1. Write a C++ program including algorithm steps that calculates area and perimeter of a circle.
2. Write a C++ program including algorithm steps that calculates Body Mass Index (BMI) of a person.
    - More information on BMI - https://www.nhlbi.nih.gov/health/educational/lose_wt/BMI/bmicalc.htm
    - Formula [here]( https://www.cdc.gov/healthyweight/assessing/bmi/childrens_bmi/childrens_bmi_formula.html#:~:text=The%20formula%20for%20BMI%20is,to%20convert%20this%20to%20meters.&text=When%20using%20English%20measurements%2C%20pounds%20should%20be%20divided%20by%20inches%20squared).
    - a sample solution is provided here [exercises/stdio/BMI/main.cpp](exercises/stdio/BMI/main.cpp)
3. Write a C++ program including algorithm steps that calculates area and perimeter of a triangle given three sides.
    - Hint: use Heron's formula to find area with three sides.
4. Write a C++ program that converts hours into seconds.
    - e.g. given 2 hours, program should print 7200 as answer.
5. Write a C++ program that converts seconds into hours, minutes and seconds.
    - e.g. given 3600 seconds, program should print 1 hour, 0 minute and 0 second.
    - e.g. given 3661 seconds, program should print 1 hour, 1 minute and 1 second.
    - Hint: use series of division and module operators
6. Convert your full name into binary code using Jupyter Notebook.
    
## Kattis Problems     
 
- Solving for Carrots - https://open.kattis.com/problems/carrots
    - a simple standard input/output problem; just print the second number in first line
    - Hint: simply print P
    - see sample solution in [demos/stdio/carrots](demos/stdio/carrots) folder
    
- Echo Echo Echo - https://open.kattis.com/problems/echoechoecho
    - Hint: read the word; print the word three times

- Mona, Mona, Mona - https://open.kattis.com/problems/monamonamona
    - Hint: read and print the first word 3 times
    
- The Last Problem - https://open.kattis.com/problems/thelastproblem
    - Hint: read the name (may have spaces in between) and print the name as stated

- Leggja saman - https://open.kattis.com/problems/leggjasaman
    - Hint: read two integers and print their sum

- Hipp Hipp - https://open.kattis.com/problems/hipphipp
    - without using loops, print 20 lines of "Hipp hipp hurra!"
    
## Testing Kattis Provided Samples
- see [Kattis Notebook](Kattis.ipynb)

## Summary
- this chapter covered reading data from common input stream (standard input)
- this chapter covered writing data to common output stream (standard output)
- covered escape character, sequences and their usage
- we also learned about composing more meaningful programs with two examples
- exercises and problems with sample solutions


```c++

```
