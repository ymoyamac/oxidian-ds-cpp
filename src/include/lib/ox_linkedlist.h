/**
 * ox_linkedlist.h
 * 
 * DOCUMENTATION:
 * 
 *      A linked list is a linear data structure which can store a collection of "nodes" connected together via links
 *      i.e. pointers. Linked lists nodes are not stored at a contiguous location, rather they are linked using pointers
 *      to the different memory locations.
 * 
 *      A linked list is a dynamic linear data structure whose memory size can be allocated or de-allocated at run time based on
 *      the operation insertion or deletion.
 * 
 *      This is the representation of the `linked-list` data structure
 * 
 *              Linkedlist
 *              +-----------------------------------------------------------------------------------------+
 *              |        Head                                              Tail                           |
 *              |        +-------+-------+        +-------+-------+        +-------+-------+              |
 *              |        | data  |  ptr  +------->| data  |  ptr  +------->| data  |  ptr  +------->      |
 *              |        +-------+-------+        +-------+-------+        +-------+-------+              |
 *              +-----------------------------------------------------------------------------------------+
 * 
 *      This is a representation of what the `linked-list` data structure looks like stored in dynamic memory by `malloc`.
 * 
 *              +-------+-------+
 *              | node_t* head  +-------->
 *              +-------+-------+
 *              | node_t* tail  +-------->
 *              +-------+-------+
 *              |    int size   |
 *              +-------+-------+
 * 
 * 
 * IDENTIFICATION:
 *      src/include/lib/ox_linkedlist.h
 */
#ifndef _OX_LINKEDLIST_H
#define _OX_LINKEDLIST_H

#include "oxidian.h"

namespace linked_list {

    /**
     * Opaque type representing a `linked-list`.
     */
    typedef struct linkedlist_s linkedlist_t ;

    struct linkedlist_s {
        simple_node::node_t* head;
        simple_node::node_t* tail;
        int size;
    };

    /**
     * The init function creates a new empty `linked-list`.
     */
    linkedlist_t* init();

    /**
     * Frees the memory of a `linked-list` and its `nodes`.
     */
    void drop(linkedlist_t* list);
    int size(linkedlist_t* list);
    void rprint_list(linkedlist_t* list);

    /**
     * Inserts a node at the end of the list, if the list is empty it inserts it
     * at the beginning, head and tail are worth the same as the new node.
     */
    void push_back(linkedlist_t* list, void* data);

    /**
     * Inserts a node at the beginning of the list, if the list is empty it is inserted
     * at the beginning, head and tail are worth the same as the new node.
     */
    void push_front(linkedlist_t* list, void* data);

    /**
     * Inserts a new node in which the position is indicated.
     */
    void push_at(linkedlist_t* list, void* data, int position);

    /**
     * Removes the last node in the list and returns the data it stores.
     */
    void* pop(linkedlist_t* list);

    /**
     * Gets the data of a node where the position is indicated.
     */
    void* get(linkedlist_t* list, int index);

    /**
     * Remove a node from position and returns the data.
     */
    void* remove(linkedlist_t* list, int index);

}

#endif