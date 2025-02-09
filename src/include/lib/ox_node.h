/**
 * ox_node.h
 * DOCUMENTATION:
 *      The nodes are the fundamental unit to operate a data structure in ‘oxidian’.
 *      A node is a data structure that stores information of any type and only contains
 *      a reference to the next node.
 *      
 *      Nodes must not contain logic beyond their own implementation.
 * 
 *      This is the representation of the `simple-node` data structure
 * 
 *              Simple node
 *              +-------+-------+
 *              | data  |  ptr  +------->
 *              +-------+-------+
 * 
 *      This is what the `simple-node` data structure looks like stored in dynamic memory by `malloc`.
 *      The `malloc` function reserves a contiguous memory block of the size of struct node_s:
 * 
 *      sizeof(struct node_s): Calculates the total size of the structure including:
 * 
 *          sizeof(void*): Size of the data pointer (4 bytes in 32 bits, 8 in 64 bits).
 *          sizeof(node_t*): Size of the next pointer (same as void*).
 *          sizeof(void* (*)(node_t*)): Size of the function pointer (same as a normal pointer).
 * 
 *          Allocated memory:
 *          In 64-bit systems, each pointer occupies 8 bytes.
 * 
 *              +-------+-------+
 *              |  void* data   |
 *              +-------+-------+
 *              | node_t* next  +-------->
 *              +-------+-------+
 *              |   get_data()  |
 *              +-------+-------+
 * 
 * IDENTIFICATION:
 *      src/include/lib/ox_node.h
 */
#ifndef _OX_NODE_H
#define _OX_NODE_H

#include "oxidian.h"

namespace simple_node {

    /**
     * Opaque type representing a generic node.
     */
    typedef struct node_s node_t;

    struct node_s {
        /**
         * Represents the information stored by the node. data type (`void*`).
         */
        void* data;

        /**
         * Pointer to the next node of the structure.
         */
        node_t* next;
        
        /**
         * Function pointer that allows accessing the node data in an encapsulated way.
         * Get the current data from node.
         * Returns a pointer to the information contained in the current node (`void*`).
         */
        void* (*get_data)(node_t* node);
    };

    /**
     * The `init` function creates a new node in memory. This function reserves memory for the simple struct node.
     * Memory is allocated for the node structure reserves a total memory space of the sum of all its parts
     * 
     * Pointer to the created node `node_t*`, or `NULL` if memory allocation fails.
     */
    node_t* init(void* data);

    /**
     * Frees memory for a node
     */
    void drop(node_t* node);
    
    static void* get_data(node_t* node);
    static node_t* get_next(node_t* node);
}

#endif