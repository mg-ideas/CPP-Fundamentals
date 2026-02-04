# CS1 Lab - Functions and Basic Unittest Lab - 1

Possible Points: 100

Write a C++ program that implements functions to wrap various math functions provided by the C++ standard library.
Goal of the lab is to learn to modularize your code using user-defined functions and write unit tests to automatically test your code.

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
library/
├── data/
├── include/
│   └── my_math.hpp
├── src/
│   └── my_math.cpp
│   └── main.cpp
├── tests/
│   └── test_my_math.cpp
├── Makefile
└── README.md
└── screenshots/
```

2. Type the contents provided in `.hpp` and `.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Manual Whole program test

1. Fix and use Makefile to build, run, test the program manuall. Fix any issues found.
2. Create screenshots of your tests showing all the results and save them to the **screenshots** folder.

## Unit testing with assert function

1. Set the asserttest target in the Makefile and run the tests. Fix any issues found.

```bash
make asserttest
```

2. Create screenshots of your assert test results and save them to the **screenshots** folder.

## Submission

1. Add at least 2 screenshots showing your local manual tests and automated make assert unittest and save them to the **screenshots** folder. (10 points).
2. Update the `README.md` file (10 points) with self-grade as shown here: https://github.com/rambasnet/csXXX-rbasnet

```bash
cd <main repo folder>
ls
git pull
git status
git add <each file in the red that is part of this lab>
git status
git commit -m "write brief description of what was done"
git push
git status
```

3. Make sure the files are actually pushed to your remote GitHub repo.
