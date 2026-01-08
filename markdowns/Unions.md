# Unions

## Topics

- Union type definition
- Defining and using union type
- Demonstration of how union type works

## External Resources

- CPP Reference: [https://en.cppreference.com/w/cpp/language/union](https://en.cppreference.com/w/cpp/language/union)
- YouTube Video: [https://youtu.be/thIiMmk6quE](https://youtu.be/thIiMmk6quE)
- YouTube Podcast: [https://youtu.be/KabzR-J_ccE](https://youtu.be/KabzR-J_ccE)
- NotebookLM learning materials: [https://notebooklm.google.com/notebook/c04b563b-c6f0-4780-9177-020553bbe82c](https://notebooklm.google.com/notebook/c04b563b-c6f0-4780-9177-020553bbe82c)


## Union

- a union type is burrowed from C
- it's a user-defined type that allows you to store different data types in the same memory location
- union is usually defined with many members similar to structure, but only one member will be active and valid at a time
- it's an efficient way of using the same memory location for multiple purpose or different data types
    - only primitive types (C-types, char, int, float, double, etc.) are allowed
    - user-defined compound types such as string, structs are not allowed as a member
- see CPP reference for more: [https://en.cppreference.com/w/cpp/language/union](https://en.cppreference.com/w/cpp/language/union)
- syntax to define **union** type:


```cpp
union UnionName {
    type1 memberName1;
    type2 memberName2;
    ...
    typeN memberNameN;
};
```
- defining and using union type is syntatcially similar to `struct` type
- member is accessed using `.` member access operator

```
UnionName object;
object.memberName = [value];
```

### Visualize it in [Pythontutor.com](https://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%20%0A//%20Define%20Union%20type%0Aunion%20Data%20%7B%0A%20%20char%20ch%3B%0A%20%20int%20ID%3B%0A%20%20float%20price%3B%0A%20%20char%20fullName%5B100%5D%3B%0A%7D%3B%0A%0Aint%20main%28%20%29%20%7B%0A%0A%20%20Data%20data%3B%20%20%20%20%20%20%20%20%0A%20%20%0A%20%20printf%28%22sizeof%20data%3A%20%25d%5Cn%22,%20sizeof%28data%29%29%3B%0A%20%20data.ch%20%3D%20'A'%3B%0A%20%20data.ID%20%3D%20100%3B%0A%20%20data.price%20%3D%209.99%3B%0A%20%20strncpy%28data.fullName,%20%22John%20Smith%22,%2010%29%3B%0A%0A%20%20printf%28%22data.ch%3A%20%25c%5Cn%22,%20data.ch%29%3B%0A%20%20printf%28%22data.ID%20%3A%20%25d%5Cn%22,%20data.ID%29%3B%0A%20%20printf%28%22data.price%20%3A%20%25f%5Cn%22,%20data.price%29%3B%0A%20%20printf%28%22data.fullName%20%3A%20%25s%5Cn%22,%20data.fullName%29%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)


```c++
#include <iostream>
#include <cstring>

using namespace std;
```


```c++
// Define Union type
union Data {
  char ch;
  int ID;
  float price;
  char fullName[100];
};
```


```c++
// declare objects
union Data data;
```


```c++
sizeof(data)
// size of data object is the size of the largest memember variable
```




    100




```c++
// only one member is active at a time
data.ch = 'A'
```




    'A'




```c++
// ch member is active
cout << data.ch << endl;
```

    A



```c++
data.ID = 100;
```


```c++
// ID member is active
cout << data.ID << endl;
```

    100



```c++
// ch is now not valid
cout << data.ch;
```

    d


```c++
// price member is active
data.price = 9.99;
```


```c++
cout << data.price;
```

    9.99


```c++
// both ch and ID not active and valid
cout << data.ch << " " << data.ID;
```

    
     1092605706


```c++
// data.fullName is now active
strncpy(data.fullName, "John Smith", 10);
```


```c++
cout << data.fullName;
```

    John Smith


```c++
// all other 3 members are not active and valid
cout << data.ch << " " << data.ID << " " << data.price;
```

    J 1852337994 1.79838e+28

## Applications

- union has limited and very specific application in real world
- could be used to save memory in network applications for serializing and deserializing data, etc.

## Kattis problems

- union is not a strict requirement to solve Kattis problems

## Summary

- learnd what union types are
- learned how to define and use union types


```c++

```
