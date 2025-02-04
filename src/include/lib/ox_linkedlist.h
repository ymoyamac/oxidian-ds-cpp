#ifndef _OX_LINKEDLIST_H
#define _OX_LINKEDLIST_H

#include "../oxidian.h"

namespace linked_list {
    struct linkedlist_t {
        simple_node::node_t* head;
        simple_node::node_t* tail;
        int size;
    };

    typedef struct linkedlist_t linkedlist_t ;

    linkedlist_t* init();
    linkedlist_t* init(int* val);
    void drop(linkedlist_t* list);
    int size(linkedlist_t* list);
    void rprint_list(linkedlist_t* list);
    void push_back(linkedlist_t* list, int data);
    void push_front(linkedlist_t* list, int data);
    void push_at(linkedlist_t* list, int data, int position);
    simple_node::node_t* pop(linkedlist_t* list);
    simple_node::node_t* remove_at(linkedlist_t* list, int at);

}

#endif