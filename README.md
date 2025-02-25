# Data Structures in Cpp

## Overview
This project implements fundamental **data structures in Cpp**, including linked lists, stacks, queues, trees, and graphs. The goal is to provide efficient and reusable implementations with a focus on memory management and performance.

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

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/ymoyamac/oxidian-ds-cpp.git
   cd ds-c
   ```
2. Compile the project:
   ```sh
   make -f Makefile
   ```
3. Run the executable:
   ```sh
   ./main.o
   ```

## Usage
Each data structure has its own implementation file. To use a specific data structure, include its header file in your C program.

Example usage of a **linked list**:
```c
#include "linkedlist.h"

int main() {
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
