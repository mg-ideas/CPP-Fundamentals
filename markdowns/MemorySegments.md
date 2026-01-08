# Computer Hadware and Software Fundamentals
- understanding how computer hardware and software work together is crucial for any programmer
- this knowledge helps you write efficient code, debug issues, and optimize performance

## External Resources
- YouTube Podcast - C++ Memory Segments [https://youtu.be/KbikT3YhOY4](https://youtu.be/KbikT3YhOY4)
- YouTube Video - C++ Memory Segments [https://youtu.be/9mHXkLwnShM](https://youtu.be/9mHXkLwnShM)
- NotebookLM learning resrouces - [https://notebooklm.google.com/notebook/fa2bccd7-eaeb-43bd-b240-6a043a219a52](https://notebooklm.google.com/notebook/fa2bccd7-eaeb-43bd-b240-6a043a219a52)

## Computer Hardware
- **Central Processing Unit (CPU)**: the brain of the computer that executes instructions
- **Memory (RAM)**: temporary storage for data and instructions that the CPU needs while executing
- **Storage (HDD/SSD)**: long-term/secondary storage for data and programs
- **Input/Output Devices**: peripherals like keyboard, mouse, monitor, joystick, stylus, etc.
- **Motherboard**: the main circuit board that connects all hardware components
- **Bus**: a communication system that transfers data between components inside a computer
- **Cache**: a smaller, faster type of volatile memory that provides high-speed data access to the CPU
- **Registers**: small storage locations within the CPU that hold data temporarily during processing

## Computer Software
- **Operating System (OS)**: manages hardware resources and provides services for computer programs
- **Application Software**: programs that perform specific tasks for users (e.g., web browsers, word processors)
- **System Software**: software that provides core functions like OS, utilities, and device drivers
- **Firmware**: low-level software programmed into hardware devices to control their functions
- **Compilers/Interpreters**: tools that translate high-level programming languages into machine code
- **Libraries**: collections of pre-written code that developers can use to optimize tasks and improve efficiency
- **APIs (Application Programming Interfaces)**: sets of protocols and tools for building software applications and enabling communication between different software components


<a id="segments"></a>

# Primary Memory segments in C/C++ programs

- a program's memory is divided into different segments to store different types of data
- main memory (RAM) is typically divided into 2 main spaces:
    1. kernel space - reserved for running the kernel (OS background processes, device drivers, etc.)
        - loaded in lower addresses
    2. user space - user-mode applications are loaded
        - loaded in higher addresses
    
- in C/C++ programs, user space is divided into 5 different areas, called segments
- from lower (at the top) to higher memory addresses (towards the bottom), the segments are:

| Text - code segment          |
|------------|
| Data - initialized globals/static   |
| BSS - uninitialized globals/static  |
| Heap - dynamically allocated |
| Stack - local variables      |

- theText segment is at the lowest memory address, followed by Data, BSS, Heap, and Stack segments at the highest memory addresses

<img src="./assets/MemorySegments.png">

- Command line arguments and environment variables are stored towards the bottom of the stack segment.

### Stack segment
- also called scratch pad
- function parameters, local variables, and other function-related register variables are stored
- grows and shrinks based on program needs
- Last In First Out (LIFO) data structure that grows from higher to lower memory addresses
- stack overflow can occur when too much memory is used on the stack (e.g., infinite recursion, large local variables, etc.)
- if more data is insecurely pushed/copied onto the stack than it can hold, it can overwrite adjacent memory locations, leading to unpredictable behavior, crashes or arbitrary code execution (stack buffer overflow attack)
- stack size is normally much smaller compared to heap size

### Heap segment
- dynamically allocated variables (using pointers) are allocated from this segment
- Heap size is normally much larger compared to stack size
- size (actual) grows and shrinks based on program needs
- heap grows from lower to higher memory addresses
- heap overflow can occur when too much memory is allocated on the heap (e.g., memory leaks, excessive allocations, etc.)
- programer must manually manage memory allocation and deallocation using `new` and `delete` keywords in C++
    
### BSS segment (Block Started by Symbol)
- also called the uninitialized data segment
- zero-initialized or uninitialized global and static variables are stored
- overflow in this segment can occur if the program tries to copy more data than allocated for uninitialized global/static variables
    
### Data segment
- also called the initialized data segment
- initialized global and static variables are stored
- overflow in this segment can occur if the program tries to copy more data than allocated for initialized global/static variables

### Text segment (also called a code segment)
- compiled program/code is loaded
- code segment is typically read-only.

Programmers primarily focus on the heap and the stack, as that is where most of the interesting stuff takes place where data is stored and manipulated during program execution.

<a id="demo1"></a>

## Demo program

- compile and run `demos/memory/memory_segments.cpp` for a demo program that illustrates the use of various memory segments in a C++ program.
- `size` command can be used to display the size of various segments in the compiled executable.


```python
! cat demos/memory/memory_segments.cpp
```

    // Program that demonstrates various memory semgments
    #include <iostream>
    #include <string>
    #include <cstdio>
    using namespace std;
    
    int globalNum = 100;                   // Data segment
    static double globalStaticNum = 100.1; // data segment
    int globalNum1;                        // bss segment
    
    void myFunction() // code segment
    {
        int num = 10;            // stack segment
        int nums[3] = {1, 2, 3}; // stack segment
        int *ptr = new int;      // p is in stack but point to a address in heap segment
        cout << "\nLocal Variables in myFunction:" << endl;
        printf("\theap: value of pointer p= %p\n", ptr);
        printf("\tstack: address of a= %p\n", &num);
        printf("\tstack: base address of nums= %p\n", nums);
        printf("\tstack: address of pointer ptr= %p\n", &ptr);
    }
    
    int main() // code segment
    {
        int num = 100;      // stack segment
        int *ptr = new int; // Heap segment
        printf("Code segment: \n \taddress of main= %p\n", &main);
        printf("\taddress of myFunction= %p\n", &myFunction);
        printf("Data segment: \n\taddress of globalNum= %p\n", &globalNum);
        printf("\taddress of globalStaticNum= %p\n", &globalStaticNum);
        printf("bss segment: \n\taddress of globalNum1= %p\n", &globalNum1);
        cout << "\nLocal variabiles in main:" << endl;
        printf("\theap: value of pointer ptr= %p\n", ptr);
        printf("\tstack: address of a= %p\n", &num);
        printf("\tstack: address of ptr= %p\n", &ptr);
        myFunction();
        return 0;
    }


```python
! g++ demos/memory/memory_segments.cpp -o memory_segments.exe
```


```python
! ./memory_segments.exe
```

    Code segment: 
     	address of main= 0x1042dc7f4
    	address of myFunction= 0x1042dc620
    Data segment: 
    	address of globalNum= 0x1042e4000
    	address of globalStaticNum= 0x1042e4008
    bss segment: 
    	address of globalNum1= 0x1042e4010
    
    Local variabiles in main:
    	heap: value of pointer ptr= 0x11f605e30
    	stack: address of a= 0x16bb228e8
    	stack: address of ptr= 0x16bb228e0
    
    Local Variables in myFunction:
    	heap: value of pointer p= 0x11f605fa0
    	stack: address of a= 0x16bb22894
    	stack: base address of nums= 0x16bb22898
    	stack: address of pointer ptr= 0x16bb22888



```python

! size -m -l memory_segments.exe
```

    Segment __PAGEZERO: 4294967296 (zero fill)  (vmaddr 0x0 fileoff 0)
    Segment __TEXT: 16384 (vmaddr 0x100000000 fileoff 0)
    	Section __text: 3580 (addr 0x100000620 offset 1568)
    	Section __stubs: 228 (addr 0x10000141c offset 5148)
    	Section __gcc_except_tab: 108 (addr 0x100001500 offset 5376)
    	Section __const: 12 (addr 0x10000156c offset 5484)
    	Section __cstring: 430 (addr 0x100001578 offset 5496)
    	Section __unwind_info: 240 (addr 0x100001728 offset 5928)
    	total 4598
    Segment __DATA_CONST: 16384 (vmaddr 0x100004000 fileoff 16384)
    	Section __got: 184 (addr 0x100004000 offset 16384)
    	total 184
    Segment __DATA: 16384 (vmaddr 0x100008000 fileoff 32768)
    	Section __data: 16 (addr 0x100008000 offset 32768)
    	Section __common: 4 (addr 0x100008010 zerofill)
    	total 20
    Segment __LINKEDIT: 16384 (vmaddr 0x10000c000 fileoff 49152)
    total 4295032832



```python
! man size
```

    SIZE(1)                     General Commands Manual                    SIZE(1)
    
    NAME
           size - print the size of the sections in an object file
    
    SYNOPSIS
           size [ option ... ] [ object ... ]
    
    DESCRIPTION
           Size (without the -m option) prints the (decimal) number of bytes
           required by the __TEXT, __DATA and __OBJC segments.  All other segments
           are totaled and that size is listed in the `others' column.  The final
           two columns is the sum in decimal and hexadecimal.  If no file is
           specified, a.out is used.
    
           The options to size(1) are:
    
           -      Treat the remaining arguments as name of object files not
                  options to size(1).
    
           -m     Print the sizes of the Mach-O segments and sections as well as
                  the total sizes of the sections in each segment and the total
                  size of the segments in the file.
    
           -l     When used with the -m option, also print the addresses and
                  offsets of the sections and segments.
    
           -x     When used with the -m option, print the values in hexadecimal
                  (with leading 0x's) rather than decimal.
    
           -arch arch_type
                  Specifies the architecture, arch_type, of the file for size(1)
                  to operate on when the file is a universal file.  (See arch(3)
                  for the currently know arch_types.)  The arch_type can be "all"
                  to operate on all architectures in the file.  The default is to
                  display only the host architecture, if the file contains it;
                  otherwise, all architectures in the file are shown.
    
    SEE ALSO
           otool(1)
    
    BUGS
           The size of common symbols can't be reflected in any of the numbers for
           relocatable object files.
    
    Apple Computer, Inc.             July 28, 2005                         SIZE(1)

