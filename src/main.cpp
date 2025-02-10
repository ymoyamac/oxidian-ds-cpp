#include "oxidian.h"

int main() {

    printf("1Hello Makefile\n");

    linked_list::linkedlist_t* ll = linked_list::init();
    printf("2Hello Makefile\n");

    int numbers[] = {1};
    printf("3Hello Makefile\n");

    for (size_t i = 0; i < 1; i++) {
        printf("4Hello Makefile\n");

        linked_list::push_back(ll, &numbers[i]);

    }
    printf("5Hello Makefile\n");
    linked_list::rprint_list(ll);
    printf("6Hello Makefile\n");
    int front = 99;
    int back = 101;
    linked_list::push_front(ll, &front);
    linked_list::push_back(ll, &back);
    linked_list::rprint_list(ll);
    

    printf("Size: %i\n", linked_list::size(ll));
    linked_list::drop(ll);

    return 0;
}