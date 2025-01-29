#ifndef _LIB_OXIDIAN_NODE_H
#define _LIB_OXIDIAN_NODE_H

#include "../oxidian.h"

namespace simple_node {
    struct node_t {
        int data;
        struct node_t* next;
    };

    typedef struct node_t Node;

    /**
     * Returns a pointer of type node. memory is allocated for the node structure
     * reserves a total memory space of the sum of all its parts
     */
    Node* init(int data);

    /**
     * Frees memory for a node
     */
    void drop(Node* node);

    /**
     * Get the current data from node
     */
    int get_data(Node* node);

    Node* get_next(Node* node);
}

#endif