#include "oxidian.h"
/**
 * Los ´nodes´ es la pieza fundamental para operar una estructura de
 * datos en ´oxidian´. La estructura ´LinkedList´ se debe de encargar
 * de tener toda la logica
 */

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#define SIZE 3

namespace linked_list {
    /**
     * El parametro ´size´ es el numero de nodos que tendra la ´LinkedList´
     */
    LinkedList* init() {
        LinkedList* ptr_ll = (LinkedList*) std::malloc(sizeof(LinkedList));
        if (ptr_ll == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            exit(EXIT_FAILURE);
        }        
        ptr_ll->head = nullptr;
        ptr_ll->tail = nullptr;
        ptr_ll->size = 0;
        return ptr_ll;
    }

    LinkedList* init(int* val) {
        LinkedList* ptr_ll = (LinkedList*) std::malloc(sizeof(LinkedList));
        if (ptr_ll == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            exit(EXIT_FAILURE);
        }        
        ptr_ll->head = nullptr;
        ptr_ll->tail = nullptr;
        ptr_ll->size = 0;
        return ptr_ll;
    }

    void drop(LinkedList* list) {
        simple_node::Node* tmp;

        while (list->head != nullptr) {
            tmp = list->head;
            list->head = list->head->next;
            free(tmp);
        }

        free(list->head);
        free(list->tail);
        free(list);
        list = nullptr;
        tmp = nullptr;
    }

    int size(LinkedList* list) {
        return list->size;
    }

    void rprint_list(LinkedList* list) {
        std::cout << "$ ";
        while (list->head) {
            std::cout << list->head->data;
            if (list->head->next != nullptr) {
                std::cout << ", ";
            }
            list->head = list->head->next;
        }
        std::cout << std::endl;
    }

    void push_back(LinkedList* list, int data) {
        simple_node::Node* new_node = simple_node::init(data);
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            assert(list->head->next == nullptr);
            list->tail = new_node;
            assert(list->tail->next == nullptr);
        } else {
            while (list->tail->next != nullptr) {
                list->tail = list->tail->next;
            }
            list->tail->next = new_node;            
        }
        list->size++;
    }

    void push_front(LinkedList* list, int data) {
        simple_node::Node* new_node = simple_node::init(data);
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            assert(list->head->next == nullptr);
            list->tail = new_node;
            assert(list->tail->next == nullptr);
        } else {
            simple_node::Node* current = simple_node::init(data);
            current = list->head;
            list->head = new_node;
            list->head->next = current;
        }
        list->size++;
    }

    void push_at(LinkedList* list, int data, int position) {
        
    }


}
