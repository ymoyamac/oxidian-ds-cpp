#include "oxidian.h"

namespace simple_node {

    node_t* init(void* data) {
        /**
         * The ‘malloc’ function calls an ‘allocator’ to reserve memory of the size indicated
         * by the ‘sizeof’ function, this memory reservation does not initialize the allocated memory,
         * i.e. memory blocks can be reused and contain “garbage values”.

         */
        node_t* node = (node_t*) std::malloc(sizeof(node_t));
        /**
         * If ‘malloc’ cannot allocate the memory it returns ‘NULL’.
         */
        if (node == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            return NULL;
        }
        /**
         * The ‘malloc’ function does not modify the contents of the allocated memory,
         * i.e. it does not initialize the memory. malloc' is designed to be fast and efficient,
         * therefore, it omits this step to save time.
         * 
         * It is necessary to initialize the memory manually after making a memory allocation.
         */
        node->data = data;
        node->next = nullptr;

        /**
         * Se inicializan las funciones miembro de la struct node
         */
        node->get_data = &simple_node::get_data;

        return node;
    }

    void drop(node_t* node) {
        /**
         * Libera un bloque de memoria previamente asignado. No hace nada si el puntero es NULL.
         * Después de llamar a free, el puntero debe ser asignado a NULL para evitar punteros
         * colgantes.
         */
        free(node);
        node = nullptr;
    }

    static void* get_data(node_t* node) {
        return node->data;
    }

    static node_t* get_next(node_t* node) {
        return node->next;  
    }
}