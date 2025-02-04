#include "oxidian.h"

int main() {

    printf("Hello Makefile\n");

    linked_list::linkedlist_t* ll = linked_list::init();


    linked_list::push_back(ll, 1);
    linked_list::push_back(ll, 3);
    linked_list::push_back(ll, 6);
    linked_list::push_back(ll, 9);
    linked_list::push_back(ll, 13);
    linked_list::push_back(ll, 24);
    linked_list::push_back(ll, 36);
    linked_list::rprint_list(ll);
    linked_list::pop(ll);
    linked_list::pop(ll);
    linked_list::rprint_list(ll);
    

    printf("Size: %i\n", linked_list::size(ll));
    // linked_list::drop(ll);

    return 0;
}