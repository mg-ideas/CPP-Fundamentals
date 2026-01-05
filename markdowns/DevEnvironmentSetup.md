# C++ Dev Environment

- the following tools are recommended for this course
    1. Visual Studio (VS) Code editor
        - light weight cross-platform editor for many programming languages; has rich extensions
    2. git client for version control
        - Note: VS Code provides GUI-based git
    3. g++ compiler
    
- follow the instructions from https://github.com/rambasnet/DevEnvSetup to setup Jupyter Notebook on various platforms 

## Using g++ compiler on Windows WSL, Mac and Linux
- the steps provided here assumes that you're using the recommended C++ dev environment above
- open a Terminal program
- be familiar with the terminal and some [basic bash commands](https://sites.tufts.edu/cbi/files/2013/01/linux_cheat_sheet.pdf)
- change current working directory to where the right folder where the .cpp file is
    - use `ls` commad to see all the contents of the directory
    - use `cd <dir_name>` command to change directory to the given dir_name
- make sure the current working directory is where your `.cpp` file is
    - use `pwd` command on a `*nix` terminal to know the current working directory
- compile using g++
- run the executable
- the following sequence of commands are worth remembering
    - can use these commands on repl.it cloud-based IDE as well

```bash
$ cd project_folder # change working directory to the project folder
$ pwd # print current working directory
$ ls # list contents of current directory
$ g++ -std=c++17 -o output_program input_file.cpp  # compile input_file.cpp to output_program
$ ./output_program  # run output program
```


```c++

```
