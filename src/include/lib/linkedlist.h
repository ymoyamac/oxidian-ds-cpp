#ifndef _LIB_OXIDIAN_LINKEDLIST_H
#define _LIB_OXIDIAN_LINKEDLIST_H

#include "../oxidian.h"

namespace linked_list {
    struct linkedlist_t {
        simple_node::Node* head;
        simple_node::Node* tail;
        int size;
    };

    typedef struct linkedlist_t LinkedList;

    LinkedList* init();
    LinkedList* init(int* val);
    void drop(LinkedList* list);
    int size(LinkedList* list);
    void rprint_list(LinkedList* list);
    void push_back(LinkedList* list, int data);
    void push_front(LinkedList* list, int data);
    void push_at(LinkedList* list, int data, int position);

}

#endif