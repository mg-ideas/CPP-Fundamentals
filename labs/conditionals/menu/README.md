# CS1 Lab - Conditionals and Unittest

Possible Points: 100

Write a C++ program to implement a menu-driven program that performs various operations such as finding max, min, sum, average, etc. on two numbers based on user choice. Use functions to modularize your code.

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
menu/
├── data/
├── includes/
│   └── utils.hpp
├── src/
│   └── utils.cpp
│   └── main.cpp
├── tests/
│   └── test_utils.cpp
├── Makefile
└── README.md
└── screenshots/
```

- kattis template command may create some of these files and folders for you.

```bash
kattis template -l cpp -p <problemid> -s
```

2. Type the contents provided in `.hpp` and `.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Manual Whole program test

1. Test the whole program manually. Follow the menu options to read data, find max & min, calculate sum & average, and delete data.
2. Create screenshots of your tests showing the input and output for each functionality and save them to the **screenshots** folder.

## Unit testing with Doctest

1. If not done before, create **doctest** folder in the **labs** root folder and copy the `doctest.h` file into it from [https://github.com/doctest/doctest/tree/master/doctest ](https://github.com/doctest/doctest/tree/master/doctest)
2. Set the doctest rule in the Makefile and run the tests. Fix any issues if found.

```bash
make doctest
```

## Submission

1. Create at least 2 screenshots showing your local manual tests and make doctest and save them to the **screenshots** folder. (10 points).
2. Update the `README.md` file (10 points) as shown here: https://github.com/rambasnet/csXXX-rbasnet

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
