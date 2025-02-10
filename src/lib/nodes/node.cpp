#include "oxidian.h"

namespace simple_node {

    node_t* init(void* data) {
        /**
         * The ‘malloc’ function calls an ‘allocator’ to reserve memory of the size indicated
         * by the ‘sizeof’ function, this memory reservation does not initialize the allocated memory,
         * i.e. memory blocks can be reused and contain “garbage values”.

         */
        node_t* ptr_node = (node_t*) std::malloc(sizeof(node_t));
        /**
         * If ‘malloc’ cannot allocate the memory it returns ‘NULL’.
         */
        if (ptr_node == nullptr) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            return nullptr;
        }
        /**
         * The ‘malloc’ function does not modify the contents of the allocated memory,
         * i.e. it does not initialize the memory. malloc' is designed to be fast and efficient,
         * therefore, it omits this step to save time.
         * 
         * It is necessary to initialize the memory manually after making a memory allocation.
         */
        ptr_node->data = data;
        ptr_node->next = nullptr;

        /**
         * Callback members.
         */
        ptr_node->get_data = &simple_node::get_data;

        return ptr_node;
    }

    void drop(node_t* node) {
        /**
         * Frees a previously allocated block of memory. Does nothing if the pointer is `NULL`.
         * After calling `free`, the pointer must be set to `NULL` to avoid dangling pointers.
         */
        free(node);
        node = nullptr;
    }

    static void* get_data(node_t* node) {
        return node->data;
    }

    static node_t* get_next(node_t* node) {
        if (node == nullptr) {
            return nullptr;
        }
        return node->next;  
    }
}