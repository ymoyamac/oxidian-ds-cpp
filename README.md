# Data Structures in C

## Overview
This project implements fundamental **data structures in C**, including linked lists, stacks, queues, trees, and graphs. The goal is to provide efficient and reusable implementations with a focus on memory management and performance.

## Features
- **Linked Lists** (Singly & Doubly Linked Lists)
- **Stacks** (Array-based & Linked List-based)
- **Queues** (FIFO, Circular, and Priority Queues)
- **Trees** (Binary Search Trees, AVL Trees)
- **Graphs** (Adjacency List & Adjacency Matrix representation)
- **Sorting Algorithms** (Bubble Sort, Quick Sort, Merge Sort)
- **Searching Algorithms** (Linear Search, Binary Search)
- Memory-efficient implementation
- Well-documented C code

## Prerequisites
- GCC Compiler (or any C compiler)
- C Standard Library
- Basic knowledge of C and pointers

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ds-c.git
   cd ds-c
   ```
2. Compile the project:
   ```sh
   gcc -o main main.c linkedlist.c stack.c queue.c -Wall
   ```
3. Run the executable:
   ```sh
   ./main
   ```

## Usage
Each data structure has its own implementation file. To use a specific data structure, include its header file in your C program.

Example usage of a **linked list**:
```c
#include "linkedlist.h"

int main() {
    LinkedList* list = init_linkedlist();
    push_back(list, 10);
    push_back(list, 20);
    print_list(list);
    free_list(list);
    return 0;
}
```

## File Structure
```
.
├── Makefile
├── README.md
├── main.o
└── src
    ├── include
    │   ├── ccpp.h
    │   ├── lib
    │   │   ├── ox_linkedlist.h
    │   │   └── ox_node.h
    │   └── oxidian.h
    ├── lib
    │   ├── lists
    │   │   └── linkedlist.cpp
    │   └── nodes
    │       └── node.cpp
    └── main.cpp
```

## Contributions
Contributions are welcome! Feel free to open issues and submit pull requests.

## License
This project is licensed under the MIT License.

## References
- "The C Programming Language" - Brian W. Kernighan, Dennis M. Ritchie
- "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss
- MIT OpenCourseWare - [Data Structures Course](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms/)

---
Happy coding! 🚀

