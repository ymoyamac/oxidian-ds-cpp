#include "oxidian.h"

namespace simple_node {
    node_t* init(int data) {
        /**
         * La función ´malloc´ llama a un ´allocator´ para reservar memoria del tamaño
         * indicado con la función ´sizeof´, esta reserva de memoria no inicializa la
         * memoria asignada, es decir, que se pueden reutilizar los bloques de memoria
         * y contener "valores basura"
         */
        node_t* ptr_node = (node_t*) std::malloc(sizeof(node_t));
        /**
         * Si ´malloc´ no puede asignar la memoria retorna ´NULL´
         */
        if (ptr_node == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            exit(EXIT_FAILURE);
        }
        /**
         * La función ´malloc´ no modifica el contenido de la memoria asignada, es decir,
         * no inicializa la memoria. ´malloc´ esta diseñado para ser rapido y eficiente,
         * por lo tanto, omite este paso para ahorrar tiempo.
         * 
         * Es necesario inicializar la memoria manualmente despues de hacer una asignacion
         */
        ptr_node->data = data;
        ptr_node->next = nullptr;
        return ptr_node;
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

    int get_data(node_t* node) {
        return node->data;
    }

    node_t* get_next(node_t* node) {
        return node->next;  
    }
}