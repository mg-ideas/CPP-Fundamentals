# CS1 Lab - Vectors - Number System - B

Possible Points: 100

Write a C++ program to that converts decimal number to various number systems (binary, octal, and hex) Read the problem statement carefully to design a correct solution.

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
whatdoesthefoxsay/
├── data/
├── includes/
│   └── num_system.hpp
├── src/
│   └── num_system.cpp
│   └── main.cpp
├── tests/
│   └── test_num_system.cpp
├── Makefile
└── README.md
└── screenshots/
```

2. Type the contents provided in `*.hpp` and `*.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Unit testing with Doctest

1. Create **doctest** folder in the **labs** root folder and copy the `doctest.h` file into it from [https://github.com/doctest/doctest/tree/master/doctest ](https://github.com/doctest/doctest/tree/master/doctest)
2. Set the doctest rule in the Makefile and run the tests. Fix any issues if found.

```bash
make doctest
```

## Submission

1. Create at least 3 screenshots showing your local tests (kattis test and make doctest) and the kattis final **Accept** verdict and save them to the **screenshots** folder. (10 points).
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
