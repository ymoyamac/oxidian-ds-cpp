#include "oxidian.h"

int main() {

    printf("Hello Makefile\n");

    char data = 'Y';
    simple_node::node_t* node = simple_node::init(&data);
    int from = *(int*)node->get_data(node);
    printf("Value: %c\n", from);

    simple_node::drop(node);

    return 0;
}