# Arrays and Unit Testing: Tic Tac Toe

In this lab, you will implement a simple game of tic tac toe. You will use arrays to represent the game board and unit testing to verify that your implementation is correct.

## Learning Objectives

- Learn how to use arrays to represent a game board
- Implement game logic for tic tac toe
- Write unit tests to verify the correctness of your implementation
- Practice writing clean and modular code

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
tictactoe/
├── includes/
│   ├── tictactoe.hpp
├── src/
│   └── tictactoe.cpp
│   └── main.cpp
├── tests/
│   └── test_tictactoe.cpp
├── Makefile
└── README.md
└── screenshots/
```

2. Type the contents provided in `.h`, `.hpp` and `.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Whole program test

- Test the program mannually by running the executable file. Take a screenshot of the output and save it to the **screenshots** folder (10 points).

```bash
make all
```

## Unit testing with Doctest

1. Create **doctest** folder in the **labs** root folder and copy the `doctest.h` file into it from [https://github.com/doctest/doctest/tree/master/doctest ](https://github.com/doctest/doctest/tree/master/doctest)
2. Set the doctest rule in the Makefile and run the tests. Fix any issues if found.

```bash
make doctest
```

## Submission

1. Create at screenshots showing manual tests and doctest and save them to the **screenshots** folder. (10 points).
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
