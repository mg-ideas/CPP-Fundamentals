# Problem Banks and Online Judges

## External Resources
- YouTube video -  [https://youtu.be/H4cLJ690CL0](https://youtu.be/H4cLJ690CL0)
- YouTube Podcast -  [https://youtu.be/7vEmtWBU8m0](https://youtu.be/7vEmtWBU8m0)
- NotebookLM learning materials - [https://notebooklm.google.com/notebook/4fb7d7f3-e452-47e3-a37a-60b5cc3e549f](https://notebooklm.google.com/notebook/4fb7d7f3-e452-47e3-a37a-60b5cc3e549f)

## Overview
- there are many online judges and problem banks that provide a wide variety of programming problems to practice and hone your programming and problem solving skills
- some of the popular ones are:
    - Kattis [https://open.kattis.com](https://open.kattis.com)
    - Codeforces [https://codeforces.com](https://codeforces.com)
    - LeetCode [https://leetcode.com](https://leetcode.com)
    - HackerRank [https://www.hackerrank.com](https://www.hackerrank.com)
    - AtCoder [https://atcoder.jp](https://atcoder.jp)
    - CodeChef [https://www.codechef.com](https://www.codechef.com)
    - Sphere Online Judge [https://www.spoj.com](https://www.spoj.com)
    - UVa Online Judge (https://onlinejudge.org)
- among these, Kattis is widely used in competitive programming contests such as ICPC and is a great resource to learn programming and problem solving skills
- businesses also use these online judges to screen potential candidates for programming jobs
- professionals use these online judges to practice for job interviews and keep their programming skills sharp

## Kattis [https://open.kattis.com](https://open.kattis.com)

- throughout these notebooks, you'll find Kattis problems listed under each chapter where appropriate
- Kattis is a free problem bank and online judge that is widely used in International Collegiate Programming Contest (ICPC) [https://icpc.global/](https://icpc.global/) around the world
- Kattis is a great tool to learn various programming languages while solving myriad of intuitive algorithmic problems and developing problem solving skills that are sought after by many potential employers
- research [https://rambasnet.github.io/pdfs/kattis.pdf](https://rambasnet.github.io/pdfs/kattis.pdf) has shown that by introducing and assigning Kattis problems motivates students to continuously use Kattis and solve more problems there by becoming an effective problem solver -- a hallmark skill of computer scientist
- here's a repository of some sample solutions provided in various languages with automated test cases: [https://github.com/rambasnet/KattisDemos](https://github.com/rambasnet/KattisDemos)
    - eventually (by Chapter 7), you'll be able to understand and use the all the programming concepts used in those demo solutions
- use Kattis provided help to get your started: [https://open.kattis.com/help](https://open.kattis.com/help)
- you must create a free acount here: [https://open.kattis.com/login](https://open.kattis.com/login) to be able to submit your solution so the Kattis can judge it providing you the verdict


### Testing Kattis provided samples
- one way to check for the sample input and output is by manually typing the input and comparing the results
    - input can be long and output can be tedious to compare
    - Kattis expects output to be 100% accuracte to the space (except for floating point numbers)

## Using Kattis-CLI tool
- Kattis provides a command line tool to download problems, test your solution against sample test cases, and submit your solution directly from the terminal
- Setup kattis-cli for the Lab Codespace by clicking on and following [https://github.com/rambasnet/kattis-cli/blob/main/SETUP.md](https://github.com/rambasnet/kattis-cli/blob/main/SETUP.md)

### Download problem sample data and metadata
- you neeed problem id to download the problem samples and metadata
    - problem id can be found in the URL of the problem page, e.g. for https://open.kattis.com/problems/carrots, the problem id is `carrots` the part after `/problems/`
- kattis-cli will create a folder with the problem id name and download all the sample input and output files along with problem metadata inside that folder
- steps to download and test Kattis problems using kattis-cli:

```bash
cd <path to your working directory>
ls
kattis get <problem_id>
ls
cd <problem_id>
ls
touch <problem_id>.cpp
# create your solution in the above .cpp file using your favorite editor
kattis info
kattis test
```

### Manually Downloading and Testing Kattis problems
- download the samples provided in a compressed `.zip` file
- unzip the file; it'll create a folder with the same name as the problem name or zip file name
- create a `problem_id.cpp` solution file inside the same folder where the sample files are
- then do the following steps:
    - open a terminal on Mac/Linux/WSL
    - change working directory to a problem folder, e.g. carrots

        ```bash
        pwd
        cd <path to carrots folder>
        ls
        ```

    - directly compile using g++ or create and use a Makefile

        ```bash
        g++ -std=c++17 carrots.cpp
        ```

    - run Kattis provided sample test cases e.g. if 1.in and 1.ans are corresponding sample test files
    - read the sample 1.in and pipe it to `a.out` program and pipe the answer from the program to diff to compare against 1.ans

        ```bash
        cat 1.in | ./a.out | diff - 1.ans
        cat 2.in | ./a.out | diff - 2.ans
        ```
    - if the program's answer is correct, you'll not see any difference or output on the terminal
    
- Morevoer, you can add these commands into your Makefile
    - create a rule let's say kattis
    
    ```bash
    kattis:
        cat 1.in | ./a.out | diff - 1.ans
        cat 2.in | ./a.out | diff - 2.ans
        @echo "All test cases passed!"
    ```
    - run the rule from Terminal
    
    ```bash
    make kattis
    ```
    
- once your program provides correct result as shown in the corresponding output, upload your `.cpp` source file to the Kattis to test against all the hidden test samples

- Kattis will compile and execute your program to test against other samples
- Kattis will either accept your solution or reject with some simple feedback such as wrong answer


