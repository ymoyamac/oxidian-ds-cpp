#ifndef _OX_NODE_H
#define _OX_NODE_H

#include "../oxidian.h"

namespace simple_node {
    struct node_t {
        int data;
        struct node_t* next;
    };

    typedef struct node_t node_t;

    /**
     * Returns a pointer of type node. memory is allocated for the node structure
     * reserves a total memory space of the sum of all its parts
     */
    node_t* init(int data);

    /**
     * Frees memory for a node
     */
    void drop(node_t* node);

    /**
     * Get the current data from node
     */
    int get_data(node_t* node);

    node_t* get_next(node_t* node);
}

#endif